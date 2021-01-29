/*Функция, която ще принтира числата от
десетичен в бинарен вид*/

#include <stdio.h>
void bin (unsigned int n){
   	unsigned int i;
   	for (i = 1 << 7; i > 0; i = i >> 1)
   	n & i? printf("1"): printf("0");
   	printf("\n");
   	return;
}
int main (void){
	signed char x = -127;
	signed char y = 10;
	bin (x);
    	printf ("%d\n", x);
    	x = x + y;
    	printf ("%d\n", x);
    	bin (x);
    	return 0;
}
