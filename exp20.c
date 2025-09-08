#include<stdio.h>
void heapify(int a[],int n,int i){
 int l=2*i+1,r=2*i+2,b=i,t;
 if(l<n&&a[l]>a[b])b=l;if(r<n&&a[r]>a[b])b=r;
 if(b!=i){t=a[i];a[i]=a[b];a[b]=t;heapify(a,n,b);}
}
int main(){
 int n,i,t;scanf("%d",&n);int a[n];
 for(i=0;i<n;i++)scanf("%d",&a[i]);
 for(i=n/2-1;i>=0;i--)heapify(a,n,i);
 for(i=n-1;i>=0;i--){t=a[0];a[0]=a[i];a[i]=t;heapify(a,i,0);}
 for(i=0;i<n;i++)printf("%d ",a[i]);
}
