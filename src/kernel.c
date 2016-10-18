#include <initScreenFunc.h>
#include <stdio.h>
#include <gdt.h>
#include <io.h>
int wasp_kernel_main(){
	clear_screen();
	printf( "Welcome to Wasp OS\n" );
	if ( init_descriptor_tables() > 0 ) {
		for(;;) {}
	}
	if( irq_enabled() == true ) {
		printf("IRQ's enabled!\n");
	} else {
		printf("IRQ's not enabled!\n");
	}
	printf("Done");
}
