/*Напишете функция flipBitAt, която получава като
параметър число и индекс и обръща бита на
съответната позиция в числото (съответно от 0 на 1 или
от 1 на 0).*/

#include <stdio.h>
int flipBitAtPoz(unsigned int, int);
    
int main(){
    unsigned int n = 10;
    printf("%d\n", flipBitAtPoz(10, 1));
    return 0;
}       
int flipBitAtPoz(unsigned int n, int index){
    int mask = 1 << index;
    return n ^ mask;
}