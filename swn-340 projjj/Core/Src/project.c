
/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#include "project.h"
#include "printf.h"
#include "LED.h"
#include "systick.h"
#include "UART.h"
#include "string.h"
#include "stdio.h"
#include "LED.h"
#include "reader.h"
#include "song.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"
#include "interruptHandlers.h"
#include "main.h"

static int MAX_STRING_SIZE = 64;
volatile int isRemote = 1;
volatile int PLAY_PAUSE_TOG = 0;
char BUFFER[128];
int currentSongNum = -1;
volatile int lightState = 0;


void next_song(){
	//display next songs title and queue it
	currentSongNum++;
	if(currentSongNum == 5){
		currentSongNum = 0;
	}
	//title find
	char songTitle[128] = {};
	int titleIndex = 0;
	int numToCount = 0;
	int mtrkCnt = 0;

	song song = get_song(currentSongNum);
	int i = 0;
	while(0==0){
		if(song.p_song[i] == 255 && song.p_song[i+1] == 3){ //ff,03
			break;
		}
		i++;
		if(song.p_song[i] == 77 && song.p_song[i+1] == 84 && song.p_song[i+2] == 114 && song.p_song[i+3] == 107 ){//ff,03
			mtrkCnt++;
		}
	}
	//if mtrk second was not found title exists
	if(mtrkCnt != 2){
		int numToCount = song.p_song[i+2];
		i++;
		for(int p = i; p<=numToCount+i+1;p++){
			songTitle[titleIndex] = (char)(song.p_song[p]);
			titleIndex++;
		}
	}
	//copyright find
	char songCopyright[128] = {};
	int copyrightIndex = 0;
	i = 0;
	mtrkCnt = 0;
	while(0==0){
		if(song.p_song[i] == 255 && song.p_song[i+1] == 2 ){
			break;
		}
		if(song.p_song[i] == 77 && song.p_song[i+1] == 84 && song.p_song[i+2] == 114 && song.p_song[i+3] == 107 ){
					mtrkCnt++;
		}
		i++;
		if(mtrkCnt == 2){
			break;
		}
	}
	//if mtrk second was not found copyright exists
	if(mtrkCnt != 2){
		numToCount = song.p_song[i+2];
		i++;
		for(int p = i+2; p<=numToCount+i+1;p++){
			songCopyright[copyrightIndex] = (char)(song.p_song[p]);
			copyrightIndex++;
		}
	}
	printf("\r\n%s","Current Song:");
	printf("\r\n%s%s","Song Title: ",songTitle);
	printf("\r\n%s%s\r\n","Song Copyright: ",songCopyright);

}
//play song
void play_song(){
	PLAY_PAUSE_TOG = 1;
	lightState = 1;
	LED_On(EXTERN_LED);
}
//stop song
void stop_song(){
	lightState = 0;
	LED_Off(EXTERN_LED);
}
char* pause_song() {
	lightState = 2;
    char BUFFER[MAX_STRING_SIZE];  // Declare BUFFER as static
    PLAY_PAUSE_TOG = 0;
    init_systick();
    int cnt = 0;
    int index = 0;
    char ch = 0;
    int going = 1;
    while (going == 1 && lightState == 2) {
        cnt++;
			ch = USART_Read_Nonblocking(USART2);
			if (ch == '\r') {
				going = 0;
			} else {
				if (ch != 0) {
					printf("%c", ch);
					BUFFER[index] = ch;
					index++;
				}
       delay_systick();
       if (cnt == 1000) {
    	   LED_Toggle(EXTERN_LED);
    	   cnt = 0;
        }
        }
    }
    printf("\r\n");
    BUFFER[index] = 0;
    char* toReturn = BUFFER;  // Return a pointer to BUFFER
    return toReturn;
}

void manual_pause(){
	lightState = 2;// Declare BUFFER as static
	PLAY_PAUSE_TOG = 0;
	printf("\r\n%s\r\n","i am paused technically");
	int cnt = 0;
	while (cnt < 1000) {
		cnt++;
		delay_systick();
		if (cnt == 1000) {
			LED_Toggle(EXTERN_LED);
	     }
	}
	init_player();
}

void take_input_remote(char initialInput){
	char* input = 0;
	//if inital input exists set input equal to
		if(initialInput == 0){
			input = read_line();
			initialInput = *input;
		}
		*input = initialInput;
		//check input vs commands
		if(strcmp(input,"NEXT") == 0){
			next_song();
			printf("\r\n");

		}
		//call play song
		else if(strcmp(input,"PLAY") == 0){
			play_song();
			printf("\r\n");

		}
		//call play stop
		else if(strcmp(input,"STOP") == 0){
			stop_song();
			printf("\r\n");

		}
		//call play help
		else if(strcmp(input,"HELP") == 0){
			printf("\n\rAvailable User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
		}
		//call play pause
		else if(strcmp(input,"PAUSE") == 0){
			printf("\r\n");
			char* pausedI = pause_song();
			take_input_remote(*pausedI);

		}
		//if no command was entered print invalid
		else{
			if(isRemote == 0){
				printf("\r");
			}else{
			printf("\r\nInvalid Input");
			printf("\r\n");
			}
		}

}

void mode_print(){
	if(isRemote == 1){
			printf("\r\n%s","***REMOTE MODE ACTIVE***");
			printf("\n\rAvailable User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
		}else{
			 printf("\r\n%s\r\n","***MANUAL OVERRIDE MODE ACTIVE***");
	}
}

void init_player(){
	init_systick();
	//initialize the player
	while(0 == 0){
		if(isRemote == 1){
			take_input_remote(0);
		}else{
			if(lightState == 2){
				int cnt = 0;
					while (cnt < 1000) {
						cnt++;
						delay_systick();
						if (cnt == 1000) {
							LED_Toggle(EXTERN_LED);
							PLAY_PAUSE_TOG = 0;
					     }
					}
			}else if(lightState == 1){
				LED_On(EXTERN_LED);
			}else{
				LED_Off(EXTERN_LED);
			}
		}
	}
}
