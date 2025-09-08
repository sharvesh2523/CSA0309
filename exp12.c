#include <stdio.h>
#include <ctype.h>
int main(){
    char exp[50]; int st[50],top=-1;
    scanf("%s",exp);
    for(int i=0;exp[i];i++)
        if(isdigit(exp[i])) st[++top]=exp[i]-'0';
        else {int b=st[top--],a=st[top--];
              st[++top]=(exp[i]=='+')?a+b:(exp[i]=='-')?a-b:(exp[i]=='*')?a*b:a/b;}
    printf("Result=%d",st[top]);
}
