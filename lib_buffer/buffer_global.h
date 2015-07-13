/*
 * buffer_global.h
 *
 *  Created on: 2015年5月21日
 *      Author: suntao
 */

// All the libs & .h files are included here, so every .c file just need include this global.h files.
// The other .h file just declare functions which are defined in the related .c file.
// So, in main.c we need include this global.h file only.

#ifndef LIB_BUFFER_BUFFER_GLOBAL_H_
#define LIB_BUFFER_BUFFER_GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer_test.h"
#include "singly_linked_list-jq.h"
#include "circular_linked_list_buffer-jq.h"
#include "stbuf_dclls.h"

//0 for OFF, 1 for ON
#define DEBUG 1  //to switch the print info in details
#define SLLB 0  //Singly Linked-list BUFFER
#define CLLB 0  //Circular Linked-list BUFFER
#define DCSB_ST 1	//Dynamic Circular linked-list Stream Buffer of Single Thread
#define DCSB_MT 0	//Dynamic Circular linked-list Stream Buffer of Multiple Thread

//const int BUFFER_SIZE=20;
#define BUFFER_SIZE 5
#define STR_SIZE 15   //the max length of a string
#define MSG_SIZE 81   //used in stbuf_dclls.c
#define BUFFER_FULL 1

#define BUF_MODE '\n'   //the buffer input mode, EOF (or -1) for the Full file input mode
						//                       '\n' for the line input mode
						// will be used in buffer_read function

//#define NULL 0
#define _NA -999  //Not Available
#define _S1 "abc"
#define _S2 "defgh"
#define _SL "0123456789ABC"  //Long String for test

//buffer mode:
//#define _IOFBF 1  //Full Buffer
//#define _IOLBF 2  //Line Buffer
//#define _IONBF 3  //No Buffer

#endif /* LIB_BUFFER_BUFFER_GLOBAL_H_ */
