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
#include <stdlib.h>
#define LED_PIN 5

char BUFFER[128];
int currentSongNum = -1;
void next_song(){
	//display next songs title and queue it
	currentSongNum++;
	if(currentSongNum == 6){
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
		if(song.p_song[i] == 255 && song.p_song[i+1] == 3){
			break;
		}
		i++;
		if(song.p_song[i] == 77 && song.p_song[i+1] == 84 && song.p_song[i+2] == 114 && song.p_song[i+3] == 107 ){
			mtrkCnt++;
		}
	}
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
	if(mtrkCnt != 2){
		numToCount = song.p_song[i+2];
		i++;
		for(int p = i; p<=numToCount+i+1;p++){
			songCopyright[copyrightIndex] = (char)(song.p_song[p]);
			copyrightIndex++;
		}
	}
	//tempo find
	uint32_t songTempo[128];
	uint32_t result = 120;
	int tempoFound = 0;
	int tempoIndex = 0;
	numToCount = 0;
	i = 0;
	while(0==0){
		if(song.p_song[i] == 81 && song.p_song[i+1] == 3){
			tempoFound = 1;
			break;
		}
		i++;
		}
	numToCount = 3;
	i++;
	if(tempoFound == 1){
		songTempo[0] = 0;
		for(int p = i+1; p<=numToCount+i+1;p++){
			songTempo[tempoIndex] = song.p_song[p];
			tempoIndex++;
		}
		result = (songTempo[0]<<16)| (songTempo[1]<<8) | songTempo[2];
	}
	printf("\n\r%d",strtol(result, NULL, 16));
	printf("\r\n%s","Current Song:");
	printf("\r\n%s%s","Song Title: ",songTitle);
	printf("\r\n%s%s","Copyright: ",songCopyright);
}
void play_song(){
	LED_On(LED_PIN);
}
void stop_song(){
	LED_Off(LED_PIN);
}
char* pause_song(){
	init_systick();
	int cnt = 0;
	int index = 0;
	char ch = 0;
	while(1          ){
		cnt++;
		ch = USART_Read_Nonblocking(USART2);
		if(ch == '\r'){
			break;
		}
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
			LED_Toggle(5);
			cnt = 0;
		}
	}
	printf("\r\n");
	LED_Off(LED_PIN);
	BUFFER[index - 1] = 0;
	return BUFFER;
}

void take_input(char* initialInput){
	char* input = 0;
	if(initialInput == NULL){
		input = read_line();
	}
	if(strcmp(input,"NEXT") == 0){
		next_song();
		printf("\r\n");
	}
	else if(strcmp(input,"PLAY") == 0){
		play_song();
		printf("\r\n");
	}
	else if(strcmp(input,"PAUSE") == 0){
		printf("\r\n");
		char * pausedI = pause_song();
		take_input(pausedI);

	}
	else if(strcmp(input,"STOP") == 0){
		stop_song();
		printf("\r\n");
	}
	else if(strcmp(input,"HELP") == 0){
		printf("\n\rAvailable User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
	}
	else{
		printf("Invalid Input");
		printf("\r\n");
	}
}
void init_player(){
	printf("Available User Commands\n\rNEXT - Show next song info\n\rPLAY - Play the song (LED on)\n\rPAUSE - Pause the song (LED flash)\n\rSTOP - Stop the song (LED off)\n\r");
	while(0 == 0){
		take_input(NULL);
	}
}




