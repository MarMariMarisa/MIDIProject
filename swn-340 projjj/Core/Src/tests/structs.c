///*
// * structs.c
// *
// *  Created on: Nov 28, 2023
// *      Author: Marisa
// */
//#include <stdio.h>
//#include <string.h>
//
//void structs(){
//	struct header* p_hdr;
//	//set header to the start of song 0
//	p_hdr = (struct header*)get_song (0).p_song;
//	//print each attribute
//	char buff[5];
//	strncpy(buff,p_hdr->type,4);
//	buff[4] = 0;
//
//	printf("Type: %s\n",buff);
//	printf("Len: %ld\n",p_hdr->length);
//	printf("Format: %d\n", p_hdr->format);
//	printf("NTracks: %d\n",p_hdr->tracks);
//	printf("Division: %d\n",p_hdr->division);
//}