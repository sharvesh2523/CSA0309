#include<stdio.h>
#include<stdlib.h>
struct N{int d,h;struct N*l,*r;};
int H(struct N*n){return n?n->h:0;}
int mx(int a,int b){return a>b?a:b;}
struct N*nn(int v){struct N*n=malloc(sizeof *n);n->d=v;n->l=n->r=NULL;n->h=1;return n;}
struct N*RR(struct N*y){struct N*x=y->l,*t=x->r;x->r=y;y->l=t;y->h=mx(H(y->l),H(y->r))+1;x->h=mx(H(x->l),H(x->r))+1;return x;}
struct N*LL(struct N*x){struct N*y=x->r,*t=y->l;y->l=x;x->r=t;x->h=mx(H(x->l),H(x->r))+1;y->h=mx(H(y->l),H(y->r))+1;return y;}
int B(struct N*n){return n?H(n->l)-H(n->r):0;}
struct N*ins(struct N*n,int k){
 if(!n)return nn(k);
 if(k<n->d)n->l=ins(n->l,k);
 else if(k>n->d)n->r=ins(n->r,k);
 n->h=1+mx(H(n->l),H(n->r));
 int b=B(n);
 if(b>1&&k<n->l->d)return RR(n);
 if(b<-1&&k>n->r->d)return LL(n);
 if(b>1&&k>n->l->d){n->l=LL(n->l);return RR(n);}
 if(b<-1&&k<n->r->d){n->r=RR(n->r);return LL(n);}
 return n;
}
int main(){
 struct N*root=NULL;int n,x;scanf("%d",&n);
 for(int i=0;i<n;i++){scanf("%d",&x);root=ins(root,x);}
 printf("Height=%d",H(root));
}

