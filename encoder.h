
#ifndef Encoder_Polling_H_		// Include guard
#define Encoder_Polling_H_

#include "Arduino.h"	// Has just about everything in it


/*Functions Prototypes********************************************************************/

// This function sets up the library to decode a rotary encoder on pin_A and pin_B.
void encoder_begin(uint8_t pin_A, uint8_t pin_B);

// If the encoder has rotated, this function returns a 1 or -1 depending on the direction.
// It returns a 0 if it hasn't turned.
int8_t encoder_data(void);


#endif	// Part of the include guard
