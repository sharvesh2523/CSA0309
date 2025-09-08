#include <stdio.h>
int main(){
    int st[50],top=-1,n,ch;
    do{
        printf("1-Push 2-Pop 3-Peek 0-Exit: "); scanf("%d",&ch);
        if(ch==1){scanf("%d",&n);st[++top]=n;}
        else if(ch==2 && top>=0) top--;
        else if(ch==3 && top>=0) printf("Top=%d\n",st[top]);
    }while(ch!=0);
}
