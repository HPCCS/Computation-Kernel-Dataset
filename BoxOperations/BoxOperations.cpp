// problem statement is in https://www.hackerrank.com/contests/world-codesprint-9/challenges/box-operations/problem
#include <bits/stdc++.h>
//
#include<bits/stdc++.h>


using namespace std;
const int maxn = 100010,MAX = 0x7f7f7f7f;

int n,m;

int A[maxn];

struct Node{
    int l,r;
    int mx,mn,st,bj;
    long long sm;
}T[maxn<<2];

void add(int i,int c){
    T[i].sm+=1LL*(T[i].r-T[i].l+1)*c;
    T[i].mx+=c;T[i].mn+=c;T[i].bj+=c;
}

void st(int i,int x){
    T[i].sm=1LL*(T[i].r-T[i].l+1)*x;
    T[i].mx=T[i].mn=T[i].st=x;
    T[i].bj=0;
}

void pushdown(int i){
    if(T[i].l==T[i].r)return;
    if(T[i].st!=MAX){
        st(i<<1,T[i].st);
        st(i<<1|1,T[i].st);
        T[i].st=MAX;
    }
    if(T[i].bj){
        add(i<<1,T[i].bj);
        add(i<<1|1,T[i].bj);
        T[i].bj=0;
    }
}

void pushup(int i){
    T[i].mn=min(T[i<<1].mn,T[i<<1|1].mn);
    T[i].mx=max(T[i<<1].mx,T[i<<1|1].mx);
    T[i].sm=T[i<<1].sm+T[i<<1|1].sm;
}

void build(int i,int l,int r){
    T[i].l=l;T[i].r=r;T[i].bj=0;T[i].st=MAX;
    if(l==r){
        T[i].mn=T[i].mx=T[i].sm=A[l];
        return;
    }
    int M=l+r>>1;
    build(i<<1,l,M);build(i<<1|1,M+1,r);
    pushup(i);
}

void updateadd(int i,int l,int r,int c){
    if(l<=T[i].l&&T[i].r<=r){
        add(i,c);
        return;
    }
    pushdown(i);
    int M=T[i].l+T[i].r>>1;
    if(l<=M)updateadd(i<<1,l,r,c);if(r>M)updateadd(i<<1|1,l,r,c);
    pushup(i);
}

int Div(int x,int d){
    if(x>=0)return x/d;
    if(x/d*d!=x)return x/d-1;
    else return x/d;
}

void updatediv(int i,int l,int r,int d){
    if(l<=T[i].l&&T[i].r<=r){
        if(Div(T[i].mx,d)==Div(T[i].mn,d)){
            st(i,Div(T[i].mx,d));
            return;
        }
        else if(T[i].mx==T[i].mn+1){
            add(i,Div(T[i].mn,d)-T[i].mn);
            return;
        }
    }
    pushdown(i);
    int M=T[i].l+T[i].r>>1;
    if(l<=M)updatediv(i<<1,l,r,d);if(r>M)updatediv(i<<1|1,l,r,d);
    pushup(i);
}

int querymn(int i,int l,int r){
    if(l<=T[i].l&&T[i].r<=r)return T[i].mn;
    pushdown(i);
    int ans=MAX,M=T[i].l+T[i].r>>1;
    if(l<=M)ans=min(ans,querymn(i<<1,l,r));if(r>M)ans=min(ans,querymn(i<<1|1,l,r));
    return ans;
}

long long querysm(int i,int l,int r){
    if(l<=T[i].l&&T[i].r<=r)return T[i].sm;
    pushdown(i);
    int M=T[i].l+T[i].r>>1;long long ans=0;
    if(l<=M)ans+=querysm(i<<1,l,r);if(r>M)ans+=querysm(i<<1|1,l,r);
    return ans;
}

void Work(){
    while(m--){
        int opt,l,r,x;
        scanf("%d%d%d",&opt,&l,&r);l++;r++;
        if(opt==1){
            scanf("%d",&x);
            updateadd(1,l,r,x);
        }
        else if(opt==2){
            scanf("%d",&x);
            updatediv(1,l,r,x);
        }
        else if(opt==3){
            printf("%d\n",querymn(1,l,r));
        }
        else printf("%lld\n",querysm(1,l,r));
    }
}

void Init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    build(1,1,n);
}

int main(){
freopen("../input_files/BoxOperations", "r", stdin);
    int az=89;
    Init();
    az=89;
    Work();
    return 0;
}
