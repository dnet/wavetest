#include "mcpDac.h"

void setup() {
	mcpDacInit();	
}

inline void square_note(int freq, int length) { 
    int i;
    for(i=0; i<length*freq; i+=20) { 
        mcpDacSend(0xFFFF);
        delayMicroseconds(1000000 / freq / 2);
        mcpDacSend(0x0);
        delayMicroseconds(1000000 / freq / 2);
    } 
}

void loop() { 
	for (int i = 100; i < 300; i++) {
    	square_note(i, 1);
	}
	for (int i = 300; i > 100; i--) {
    	square_note(i, 1);
	}
}
