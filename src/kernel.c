#include "initScreenFunc.h"
#include "stdio.h"
int wasp_kernel_main(){
	clear_screen();
	write_string( 0x0A, "Welcome to Wasp OS\n" );
	

}
