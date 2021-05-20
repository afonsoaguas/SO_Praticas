#include <stdio.h>
 int main () {
     for(int i=0; i<=100; i++){
         printf("%4d", i);
         if (i%10 ==0) printf("\n");
     }
 }