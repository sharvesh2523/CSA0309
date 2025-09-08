#include<stdio.h>
void qs(int a[],int l,int r){
 int i=l,j=r,p=a[(l+r)/2],t;
 while(i<=j){while(a[i]<p)i++;while(a[j]>p)j--;
  if(i<=j){t=a[i];a[i]=a[j];a[j]=t;i++;j--;}
 }
 if(l<j)qs(a,l,j);if(i<r)qs(a,i,r);
}
int main(){
 int n,i;scanf("%d",&n);int a[n];for(i=0;i<n;i++)scanf("%d",&a[i]);
 qs(a,0,n-1);for(i=0;i<n;i++)printf("%d ",a[i]);
}
