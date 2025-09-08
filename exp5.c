#include <stdio.h>
int fact(int n){return n<=1?1:n*fact(n-1);}
int main(){int n; scanf("%d",&n); printf("Factorial=%d",fact(n));}
