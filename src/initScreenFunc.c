#include "initScreenFunc.h"

uint8_t x = 0, y = 0;
uint8_t maxx=80, maxy=25;

volatile char *video = (volatile char*)0xB8000;

void put_char(uint8_t colour, const char character) {
	uint16_t offset = 2 * ( (y * maxx) + x);
	if ( character == '\n')
	{
		y++; //new line
		x = 0; //return carrage back to start
	} else if( character == '\t')
	{
		if (x == (maxx-4)) {
			x = 0;
			y = y + 1;
		} else {
			x = x + 4;
		}
	} else {
		offset = 2 * ( (y * maxx) + x);
		*(video+offset) = character;
		*(video+offset+1) = colour;
		if (x == (maxx-1)) {
			x = 0;
			y = y + 1;
		} else {
			x = x + 1;
		}
	}
}

void write_string( int colour, const char *string )
{
	uint16_t offset = 2 * ( (y * maxx) + x);
	while( *string != 0 )
	{
		if ( *string == '\n')
		{
			*string++;
			y++; //new line
			x = 0; //return carrage back to start
		} else if( *string == '\t')
		{
			if (x == (maxx-4)) {
				x = 0;
				y = y + 1;
			} else {
				x = x + 4;
			}
			*string++;
		} else {
			if (y >= maxy) {
				scroll_screen();
			}
			offset = 2 * ( (y * maxx) + x);
			*(video+offset) = *string++;
			*(video+offset+1) = colour;
			if (x == (maxx-1)) {
				x = 0;
				y = y + 1;
			} else {
				x = x + 1;
			}
		}
	}
}

void scroll_screen(){
	uint32_t offset;
	uint32_t offset1;
	for (uint32_t dy = 0; dy == maxy; dy = dy + 1) {
		for (uint32_t dx = 0; dx == maxx; dx = dx + 1) {
			offset = 2 * ( (dy * maxx) + dx);
			offset1 = 2 * ( (dy + 1 * maxx) + dx);
			uint8_t c =*(video+offset1);
			uint8_t t =*(video+offset1+1);
			*(video+offset) = 0;
			*(video+offset+1) = 0;
		}
	}0;
	x = 0;
	y = maxy -1;
}

void clear_screen() {
	uint16_t offset;
	for(uint8_t y = 0; y < maxy; y++) {
		for(uint8_t x = 0; x < maxx; x++) {
			offset = 2 * ( (y * maxx) + x);
			*(video+offset) = 0;
			*(video+offset+1) = 0;
		}
	}
}
