#include <stdio.h>
int removePoz(unsigned int, int, int);
    
int main(){
    printf("%d\n",removePoz(126, 2, 5));
    return 0;
}       
int removePoz(unsigned int nNumber, int index1, int index2){
    int i = 1;
    int mask;
    -- index2;
    while(index1 < index2){
        mask = i << index2;
        nNumber = nNumber & ~mask;
        -- index2;
    };
    return nNumber;
}