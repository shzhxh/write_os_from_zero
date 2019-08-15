#include <stdint.h>
#include "uarths.h"
#include "stdio.h"

void printnum(uint64_t n){
    int mod;
    char s[17]={0}, hex[16]="0123456789abcdef";

    for(int i=15; i>=0 ; i--){
        if(n==0) s[i]=hex[0]; 
        else{
            mod = n % 16;
            n = n / 16;
            s[i]=hex[mod];
        }
    }
    uarths_puts(s);
}
