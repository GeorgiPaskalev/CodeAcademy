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