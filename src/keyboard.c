#include <drivers/keyboard.h>
#include <stdbool.h>
#include <drivers/8042.h>

bool initKeboard() {

	//make this so it selects correct driver
	return init8042();

}
