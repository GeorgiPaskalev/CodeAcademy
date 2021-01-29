/*Напишете функция raiseBitAt, която получава като
параметър число и индекс, и "вдига" бита на съответния
индекс в числото (под "вдига" ще разбираме да му
присвои стойност 1).*/

#include <stdio.h>
int raiseBitAtPoz(unsigned int, int);
    
int main(){
    unsigned int n = 10;
    printf("%d\n", raiseBitAtPoz(10, 2));
    return 0;
}       
int raiseBitAtPoz(unsigned int n, int index){
    int mask = 1 << index;
    return n | mask;
}