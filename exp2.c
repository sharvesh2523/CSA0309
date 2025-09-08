#include <stdio.h>
int main(){
    int n,i;
    printf("How many numbers? "); scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) printf("%d is %s\n",a[i],a[i]%2?"Odd":"Even");
}
