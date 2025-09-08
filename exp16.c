#include<stdio.h>
#define SIZE 10
int main(){
 int h[SIZE],i,n,x,pos;
 for(i=0;i<SIZE;i++)h[i]=-1;
 scanf("%d",&n);
 while(n--){scanf("%d",&x);pos=x%SIZE;
  while(h[pos]!=-1)pos=(pos+1)%SIZE;
  h[pos]=x;
 }
 for(i=0;i<SIZE;i++)printf("%d ",h[i]);
}
