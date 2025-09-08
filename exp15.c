##include<stdio.h>
#include<stdlib.h>
struct N{int d,h;struct N*l,*r;};
int H(struct N*n){return n?n->h:0;}
int m(int a,int b){return a>b?a:b;}
struct N*nn(int v){struct N*n=malloc(sizeof *n);n->d=v;n->h=1;n->l=n->r=NULL;return n;}
int B(struct N*n){return H(n->l)-H(n->r);}
struct N*R(struct N*y){struct N*x=y->l;y->l=x->r;x->r=y;y->h=m(H(y->l),H(y->r))+1;x->h=m(H(x->l),H(x->r))+1;return x;}
struct N*L(struct N*x){struct N*y=x->r;x->r=y->l;y->l=x;x->h=m(H(x->l),H(x->r))+1;y->h=m(H(y->l),H(y->r))+1;return y;}
struct N*bal(struct N*n,int k){
 int b=B(n);
 if(b>1&&k<n->l->d)return R(n);
 if(b<-1&&k>n->r->d)return L(n);
 if(b>1&&k>n->l->d){n->l=L(n->l);return R(n);}
 if(b<-1&&k<n->r->d){n->r=R(n->r);return L(n);}
 return n;
}
struct N*ins(struct N*n,int k){
 if(!n)return nn(k);
 if(k<n->d)n->l=ins(n->l,k);
 else if(k>n->d)n->r=ins(n->r,k);
 n->h=1+m(H(n->l),H(n->r)); return bal(n,k);
}
struct N*minN(struct N*n){while(n->l)n=n->l;return n;}
struct N*del(struct N*n,int k){
 if(!n)return n;
 if(k<n->d)n->l=del(n->l,k);
 else if(k>n->d)n->r=del(n->r,k);
 else{
   if(!n->l||!n->r){struct N*t=n->l?n->l:n->r;free(n);return t;}
   struct N*t=minN(n->r);n->d=t->d;n->r=del(n->r,t->d);
 }
 n->h=1+m(H(n->l),H(n->r)); return bal(n,k);
}
int search(struct N*n,int k){
 if(!n)return 0;
 if(n->d==k)return 1;
 return k<n->d?search(n->l,k):search(n->r,k);
}
void pre(struct N*n){if(!n)return;printf("%d ",n->d);pre(n->l);pre(n->r);}
int main(){
 struct N*root=NULL;int ch,x;
 do{
  printf("\n1-Insert 2-Delete 3-Search 4-Display 0-Exit: ");
  scanf("%d",&ch);
  if(ch==1){scanf("%d",&x);root=ins(root,x);}
  else if(ch==2){scanf("%d",&x);root=del(root,x);}
  else if(ch==3){scanf("%d",&x);printf(search(root,x)?"Found\n":"Not Found\n");}
  else if(ch==4){pre(root);}
 }while(ch);
}


