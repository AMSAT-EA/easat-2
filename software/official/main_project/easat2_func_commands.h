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

#define ASK_COMMAND_LENGTH                    32 // command length in bits
// functions prototypes

// global variables

unsigned int global_command_buffer; 			// 32 bits = 8 bits 0x55 header + 24 golay bits //
unsigned int global_command_pending_check;               // flag that indicates if a command is pending decoding


#endif
