#include "header.h"
//strtol ilahi olay.
int main(void) {
	char pu[20] = "10101 oc pic";
	char *ptr;
	long ret;
	ret = strtol(pu,&ptr,2);
	printf("ret = %lu ptr = %s",ret,ptr);
}