#include <stdio.h>
#include <stdlib.h>
struct Node{int d;struct Node*l,*r;};
struct Node*newNode(int v){struct Node*n=malloc(sizeof *n);n->d=v;n->l=n->r=NULL;return n;}
void pre(struct Node*t){if(!t)return;printf("%d ",t->d);pre(t->l);pre(t->r);}
int main(){
    struct Node*root=newNode(1);root->l=newNode(2);root->r=newNode(3);
    root->l->l=newNode(4);root->l->r=newNode(5);
    pre(root);
}
