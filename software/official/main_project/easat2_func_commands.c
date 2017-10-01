/*
 *                                                       
 * Project     : EASAT2                                            
 * File        : easat2_func_commands.c
 *
 * Description : Functions related to satellite commands
 * Last update : 18 January 2017                                              
 *                                                                            
*/

#include "easat2.h"
#include "easat2_func_commands.h"
#include "easat2_golay_CRCG.h"
#include "easat2_util_transmission.h"


/*
    Golay [24,12] Codeword 
    Parity bit (1) 	Check bits (11) 	Information bits (12)
    X 	XXX XXXX XXXX 	XXXX XXXX XXXX

*/

/* this function is called when global flag says there is a possible command
   to decode. 1 is returned if a command has been decodified, 0 otherwise  */

int func_command_decode(unsigned long candidate_command, unsigned int * decoded_command, unsigned int * decoded_value) {

unsigned int header;
unsigned long body;
unsigned long body_data, fixed_command;
int golay_errors;

	// candidate_command is 4 bytes long (32 bits)
	// first part of candidate_command is the header which is one byte long (8 bits) and should contain 0x55
	// second part is the 24 bits Golay command, formed by 1 paruty bit, 11 check bits and 12 data bits
	
	header = (candidate_command & 0x55000000) >> 24;
	
	// if header is not 0x55 we do not try to decode command
	
	if (header != ASK_COMMAND_HEADER_8BITS) return 0;
			
	// body is 3 bytes long (24 bits), we just set to 0 8 MSB of candidate command
	
	body   = candidate_command & 0x00FFFFFF;
	
	if (golay_syndrome(body) == 0) {

		// command seems correct, extract it
		
		// body command includes first bit as parity one, next 11 check bits and finally
		// last 12 bits are our data bits, being the 4 MSB for command code (0-16) and the 8 LSB for command value (0-255)
		
		body_data        = body & 0x000FFF;       	// take out first 12 bits (parity and 11 check bits) and get only 12 last ones
		
		*decoded_command = body_data & 0xF00 >> 8;	// first 4 bits are the command code	
		*decoded_value   = body_data & 0x0FF;		// last 8 bits are the command value
	
	} else {
	
		// there is an error, we try to fix it
		
		fixed_command = golay_correct(body, &golay_errors);
		
		if (golay_parity(fixed_command)) {
		
			fixed_command += 0x800000;

			body_data        = fixed_command & 0x000FFF;       	// take out first 12 bits (parity and 11 check bits) and get only 12 last ones

			*decoded_command = body_data & 0xF00 >> 8;	// first 4 bits are the command code	
			*decoded_value   = body_data & 0x0FF;		// last 8 bits are the command value
		
		}
	
	}

	return 1;
	
}


// this function checks if there is a candidate command to process
// if so, it decodes it and executes it

void func_command_management(void) {

	unsigned int decoded_command = 0;
	unsigned int decoded_command_value = 0;
	
	unsigned long int candidate_command = 0;
	
	// check if there is a candidate command pending decode
	
	if (global_command_pending_check) {
	
		candidate_command = global_command_buffer;
		
	//	if (func_command_decode(candidate_command, &decoded_command, &decoded_command_value)) {
		
			// execute command
		
		
			// transmit ack command beacon message
//			util_command_ack_transmission(decoded_command, decoded_command_value);
			
					
		
	//	} // else command could not be decoded
			
					
	}
	
	// turn off command check flag so other commands can be decodified
	
//	global_command_pending_check = 0;

}
