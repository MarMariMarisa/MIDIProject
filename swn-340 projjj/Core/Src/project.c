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

#define LED_PIN 6

char BUFFER[128];
int currentSongNum = -1;
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
	printf("\r\n%s%s","Song Copyright: ",songCopyright);

}
//play song
void play_song(){
	LED_On(LED_PIN);
}
//stop song
void stop_song(){
	LED_Off(LED_PIN);
}
char* pause_song(){
	init_systick();
	int cnt = 0;
	int index = 0;
	char ch = 0;
	int going = 1;
	while(going == 1){
		cnt++;
		ch = USART_Read_Nonblocking(USART2);
		if(ch == '\r'){
			going = 0;
		}else{
		if(ch != 0){
			printf("%c",ch);
			BUFFER[index] = ch;
			index++;
		}
		//change delay systick to only count to 1
		delay_systick();
		// Toggle LED
		//count to 10 then toggle led
		if(cnt == 1000){
			LED_Toggle(LED_PIN);
			cnt = 0;
		}
		}
	}
	printf("\r\n");
	BUFFER[index] = 0;
	char* toReturn[index];
	for(int x = 0;x< index;x++){
		*toReturn[x] = BUFFER[x];
	}
	return toReturn;
}

void take_input(char initialInput){
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
		printf("\n\rAvail9able User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
	}
	//call play pause
	else if(strcmp(input,"PAUSE") == 0){
		printf("\r\n");
		char* pausedI = pause_song();
		take_input(*pausedI);
	}
	//if no command was entered print invalid
	else{
		printf("\r\nInvalid Input");
		printf("\r\n");
	}
}
void init_player(){
	//initialize the player
	LED_Init(LED_PIN);
	printf("Available User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
	while(0 == 0){ //loop through the inputs
		take_input(0);
	}
}





