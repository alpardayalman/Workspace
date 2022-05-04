#include <stdio.h>
enum filo {
	monday = 1,
	tuesday,
	wednesday,
	thursday = 7,
	friday,
	saturday = 2,
	sunday,
};

int main() {
	int today = sunday;
	printf("%d",today);
}