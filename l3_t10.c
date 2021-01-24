#include <stdio.h>
int removeDigit(unsigned int, int);
    
int main(){
    printf("%d\n",removeDigit(45, 3));
    return 0;
}       
int removeDigit(unsigned int nNumber, int index){
    int i = 1;
    int mask;
    for( ; ; ++ index){
        mask = i << index;
        nNumber = nNumber & (~mask);
    };
    return nNumber;
}