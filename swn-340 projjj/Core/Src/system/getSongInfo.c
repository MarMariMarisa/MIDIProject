/*
 * getSongInfo.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Marisa
 */

#include "song.h"
#include "printf.h"
#include "getSongInfo.h"
#include "project.h"
#include "string.h"
#include "stdio.h"

char songCopyright[128] = {};
char songTitle[128] = {};
int getTempo(song song){
	int i = 0;
	while(0==0){
		if(song.p_song[i] == 255 && song.p_song[i+1] == 81 && song.p_song[i+2] == 3 ){
			return ((song.p_song[i + 3]) << 16) | ((song.p_song[i + 4]) << 8) | (song.p_song[i + 5]);
		}
		i++;
	}
	return 0;
}
int getDivision(song song){
	return ((song.p_song[12]) << 8) | (song.p_song[13]);
}

void getSongTitle(song song, int i){

	char songTitle[128] = {};
	int titleIndex = 0;
	int numToCount = song.p_song[i+2];
	i++;
	for(int p = i; p<=numToCount+i+1;p++){
		songTitle[titleIndex] = (char)(song.p_song[p]);
		titleIndex++;
	}
	strcpy(currSongTitle,songTitle);
}

void getCopyright(song song){
	char songCopyright[128] = {};
	int copyrightIndex = 0;
	int i = 0;
	int mtrkCnt = 0;
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
		i++;
		for(int p = i+2; p<=song.p_song[i+2]+i+1;p++){
			songCopyright[copyrightIndex] = (char)(song.p_song[p]);
			copyrightIndex++;
		}
	}
	strcpy(currSongCopyright,songCopyright);
}
