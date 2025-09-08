#include <stdio.h>
int main(){
    int n,key,l=0,h,mid; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&key); h=n-1;
    while(l<=h){mid=(l+h)/2;
        if(a[mid]==key){printf("Found at %d",mid);return 0;}
        else if(a[mid]<key) l=mid+1; else h=mid-1;}
    printf("Not Found");
}
