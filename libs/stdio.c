#include <stdint.h>
#include "uarths.h"
#include "stdio.h"

void printnum(uint64_t n){
    int mod;
    char s[16];

    for(int i=0; i<16 ; i++){
        if(n==0) s[15-i]='0'; 
        else{
            mod = n % 16;
            n = n / 16;
            if(mod < 10) s[15-i]='0'+mod;
            else s[15-i]='a'+mod-10;
        }
    }
    uarths_puts(s);
}
