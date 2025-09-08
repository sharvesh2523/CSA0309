#include <stdio.h>
#include <stdlib.h>
struct Node{int data;struct Node*next;};
int main(){
    struct Node*head=NULL,*t;int n,x;
    printf("How many nodes? "); scanf("%d",&n);
    for(int i=0;i<n;i++){t=malloc(sizeof(struct Node));scanf("%d",&x);t->data=x;t->next=head;head=t;}
    for(t=head;t;t=t->next) printf("%d ",t->data);
}
