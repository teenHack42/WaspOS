#include <drivers/8042.h>
#include <stdbool.h>
#include <io.h>

bool init8042() {
	outb(0x64, 0xAD); //Disable Devices
	outb(0x64, 0xA7);
	inb(0x60); //flush
	

	return true;
}
