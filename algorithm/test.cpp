#include "common.h"

USESTD 

int main(int argc, char *argv[]) {
	char *str = (char *)malloc(12);
	sprintf(str, "Hello World");
	str[11] = '\0';
	
	printf("%p\n", str);
	
	string s = string(str);
	const char *str1 = s.c_str();
	
	printf("%p\n", str1);
	free(str);
	return 0;
}