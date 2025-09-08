#include <stdio.h>
int main(){
    int q[50],f=0,r=-1,n,ch;
    do{
        printf("1-Enq 2-Deq 3-Disp 0-Exit: "); scanf("%d",&ch);
        if(ch==1){scanf("%d",&n);q[++r]=n;}
        else if(ch==2 && f<=r) f++;
        else if(ch==3) for(int i=f;i<=r;i++) printf("%d ",q[i]);
    }while(ch!=0);
}
