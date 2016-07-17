#include "stdio.h"
#include "stdarg.h"
#include "stdint-gcc.h"
#include "initScreenFunc.h"

uint8_t defcolour = 0x0A;

int printf( const char* format, ... ) {
		const char *myformat;
		va_list argp;
		uint32_t prntdChars;
		int c;

		va_start(argp, format);
		for( myformat = format; *myformat != '\0'; myformat++) {
			if ( *myformat == '%' ) {
				switch( *++myformat ) {
					case 'c':
					c = va_arg(argp, int);
					put_char(defcolour, c);
					break;

					case 's':
					break;

					case 'd':
					break;

					case 'o':
					break;

					case 'x':
					break;

					case 'u':
					break;

					case 'f':
					break;

					case 'p':
					break;

					case '%':
					put_char(defcolour, '%');
					break;
				}
			} else {
				put_char(defcolour, *myformat);
				//print character normally
			}
		}
		va_end(argp);
		//return the number of characters printed if successful else negative
		return prntdChars;
}
