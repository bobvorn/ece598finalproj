/* Prints B for 5s */
/* Half of the traditional duo used to show multi-tasking is working */

#include <stddef.h>
#include <stdint.h>
#include "syscalls.h"
#include "vlibc.h"

#define RUNTIME	5

int main(int argc, char **argv) {

	printf("Printb arguments: %s %s %s\n",argv[0],argv[1],argv[2]);
	
	char* num = argv[1];
	int number = 0;
	int len = strlen(num);
	int i;
	for(i = 0; i < len; i++){
		int val = (num[i] - '0');
		number = number * 10 + val;
	}

	printf("Printb: %d %s\n", number, argv[2]);

	len = strlen(argv[2]);
	char* ptr = (char*)number;
	printf("Printb original: %s\n",ptr);
	for(i = 0; i < len; i++)
		ptr[i] = argv[2][i];
	ptr[i] = '\0';
	printf("Printb new: %s\n",ptr);

	sleep(20);

	return 0;
}
