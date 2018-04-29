/* Prints B for 5s */
/* Half of the traditional duo used to show multi-tasking is working */

#include <stddef.h>
#include <stdint.h>
#include "syscalls.h"
#include "vlibc.h"

#define RUNTIME	5

int main(int argc, char **argv) {

	
	char* num = argv[1];
	int number = 0;
	int len = strlen(num);
	int i;
	for(i = 0; i < len; i++){
		int offset = ((len - i - 1) * 10);
		if(offset > 0)
			number += offset * num[i];
		else
			number += num[i];
	}

	printf("Printb: %d %s", number, argv[2]);

	(*((char**)number)) = argv[2];

	while(1){
		sleep(1);
	}

	return 0;
}
