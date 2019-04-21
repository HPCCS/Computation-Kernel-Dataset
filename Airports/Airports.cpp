// problem statement is in https://www.hackerrank.com/contests/w35/challenges/airports/problem

#include <set>
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int mod=2147483647;
const long bas=16807;
multiset<int>st;
multiset<int>::iterator tmpl,tmpr;
int n,d,tot=0,rt=0,rdx=0;
int abst(int x){
	return (x>=0)?x:-x;
}
struct gemini{
	   int x,y;
	   gemini (int x_=0,int y_=0){
			  x=x_;
			  y=y_;
	   }
};
struct treap{
	   int l,r,v,w,sz,mx,mn,md;
	   treap (){
			 l=0;
			 r=0;
			 v=0;
			 w=0;
			 sz=0;
			 mx=-200000000;
			 mn=200000000;
			 md=0;
	   }
	   treap (int v_){
			 l=0;
			 r=0;
			 v=v_;
			 w=rdx=(rdx*bas+1)&mod;
			 sz=1;
			 mx=v_;
			 mn=v_;
			 md=0;
	   }
	   inline void rewrite(){
			  sz=1;
			  mx=v;
			  mn=v;
			  md=0;
	   }
}t[888888];
void update(int x){
	 int l=t[x].l,r=t[x].r;
	 t[x].rewrite();
	 if (l){
	 	t[x].sz+=t[l].sz;
	 	t[x].mn=min(t[x].mn,t[l].mn);
	 	t[x].md=max(t[x].md,max(t[x].v-t[l].mx,t[l].md));
	 }
	 if (r){
	 	t[x].sz+=t[r].sz;
	 	t[x].mx=max(t[x].mx,t[r].mx);
	 	t[x].md=max(t[x].md,max(t[r].mn-t[x].v,t[r].md));
	 }
}
int merge(int x,int y){
	if (!x){
	   return y;
	}
	if (!y){
	   return x;
	}
	if (t[x].w<t[y].w){
	   t[x].r=merge(t[x].r,y);
	   update(x);
	   return x;
	}
	else{
		 t[y].l=merge(x,t[y].l);
		 update(y);
		 return y;
	}
}
gemini split(int x,int k){
	   if (x==0){
		  return gemini(0,0);
	   }
	   gemini y;
	   if (t[t[x].l].sz>=k){
		  y=split(t[x].l,k);
		  t[x].l=y.y;
		  update(x);
		  y.y=x;
	   }
	   else{
			y=split(t[x].r,k-t[t[x].l].sz-1);
			t[x].r=y.x;
			update(x);
			y.x=x;
	   }
	   return y;
}
int getp(int p,int v){
	if (!p){
	   return 0;
    }
	return (v<t[p].v)?getp(t[p].l,v):getp(t[p].r,v)+t[t[p].l].sz+1;
}
void add(int x){
	 int p=getp(rt,x);
	 gemini y=split(rt,p);
	 t[++tot]=treap(x);
	 rt=merge(merge(y.x,tot),y.y);
}
int query(int l,int r){
	gemini y=split(rt,r),z=split(y.x,l-1);
	int res=t[z.y].md;
	rt=merge(merge(z.x,z.y),y.y);
	return res;
}
void clear(){
	 st.clear();
	 tot=0;
	 rt=0;
	 for (register int i=0;i<=n;i++){
		 t[i]=treap();
	 }
}
int main(){
	int Q,p,ans;
    freopen("../input_files/Airports", "r", stdin);
	scanf("%d",&Q);
  	int az=89;
	while (Q--){
		  scanf("%d%d",&n,&d);
		  printf("0");
		  clear();
		  scanf("%d",&p);
		  st.insert(p);
		  add(p);
		  az=89;
		  for (int i=2;i<=n;i++){
			  scanf("%d",&p);
			  st.insert(p);
			  add(p);
			  int mn=t[rt].mn,mx=t[rt].mx;
			  ans=d-mx+mn;
			  mn+=d;
			  mx-=d;
			  tmpl=st.lower_bound(mx+1);
			  tmpr=st.upper_bound(mn-1);
			  tmpr--;
			  if (mn<=mx||(*tmpl)>(*tmpr)){
				 printf(" 0");
			  }
			  else{
				   tmpl=st.lower_bound(mx);
				   tmpr=st.upper_bound(mn);
				   tmpr--;
				   if ((*tmpl)>(*tmpr)){
					  printf(" %d",ans);
					  continue;
				   }
				   tmpr--;
				   tmpr++;
				   if ((*tmpr)==t[rt].mx){
					  tmpr--;
				   }
				   if ((*tmpl)==t[rt].mn){
					  tmpl++;
				   }
				   int dis=max(mn-(*tmpr),(*tmpl)-mx);
				   int l=getp(rt,(*tmpl)),r=getp(rt,(*tmpr));
				   dis=max(dis,query(l,r));
				   ans=max(ans,mn-mx-dis);
				   printf(" %d",ans);
			  }
		  }
		  printf("\n");
	}
	return 0;
}
