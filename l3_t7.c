#include <stdio.h>
int removeOdd(unsigned int);
    
int main(){
    printf("%d\n", removeOdd(126));
    return 0;
}       
int removeOdd(unsigned int nNumber){
    int i = 1, index = 1;
    int mask;
    while(nNumber > mask){
        mask = i << index;
        nNumber = nNumber & ~mask;
        index += 2;
    };
    return nNumber;
}