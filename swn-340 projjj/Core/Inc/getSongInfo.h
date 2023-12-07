/*
 * getSongInfo.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Marisa
 */

#include "song.h"
#ifndef CORE_INC_GETSONGINFO_H_
#define CORE_INC_GETSONGINFO_H_

extern char songCopyright[128];;
extern char songTitle[128];;

#endif /* CORE_INC_GETSONGINFO_H_ */

int getTempo(song Song);
void getSongTitle(song song, int i);
void  getCopyright(song song);
