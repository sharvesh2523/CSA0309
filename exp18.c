#include<stdio.h>
void merge(int a[],int l,int m,int r){
 int i=l,j=m+1,k=0,t[r-l+1];
 while(i<=m&&j<=r)t[k++]=a[i]<a[j]?a[i++]:a[j++];
 while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];
 for(i=0;i<k;i++)a[l+i]=t[i];
}
void ms(int a[],int l,int r){
 if(l<r){int m=(l+r)/2;ms(a,l,m);ms(a,m+1,r);merge(a,l,m,r);}
}
int main(){
 int n,i;scanf("%d",&n);int a[n];for(i=0;i<n;i++)scanf("%d",&a[i]);
 ms(a,0,n-1);for(i=0;i<n;i++)printf("%d ",a[i]);
}
