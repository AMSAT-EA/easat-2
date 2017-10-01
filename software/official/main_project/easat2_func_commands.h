/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_func_commands.h
 *
 * Description : This file includes all the function prototypes
 * Last update : 07 October 2016                                              
 *                                                                            
*/

#ifndef EASAT2_FUNC_COMMANDS
#define EASAT2_FUNC_COMMANDS

#include "easat2.h"

#define ASK_COMMAND_LENGTH                    32 // command length in bits (55COMMAND)
#define ASK_COMMAND_HEADER_8BITS              0x55
#define ASK_COMMAND_HEADER_32BITS             (unsigned long)0x55000000
#define ASK_COMMAND_HEADER_MASK               (unsigned long)0xFF000000


// functions prototypes

int func_command_decode(unsigned long candidate_command, unsigned int * decoded_command, unsigned int * decoded_value);
void func_command_management(void);


// global variables

volatile unsigned long global_command_buffer;                       // 32 bits = 8 bits 0x55 header + 24 golay bits //
volatile unsigned int global_command_pending_check;               // flag that indicates if a command is pending decoding


#endif
