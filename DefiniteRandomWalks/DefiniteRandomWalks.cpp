// https://www.hackerrank.com/contests/w28/challenges/definite-random-walks
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod=998244353;
const int g=3;
int n,m,k,cnt,macnt;
int f[60009];
int p[100009];
int vis[60009];
int pa[60009];
int siz[60009];
ll y[300000];
ll x[300000];
ll z[300000];
ll inz[300000];
ll nz[300000];
ll ans[60009];
int maxlen[400];
int idid[400];
ll qq[400][60009];
int vv[60009];
int nuv[60009];
bool v[60009];
bool vc[60009];
vector<P> QWQ[60009];
vector<int> G[60009];
map<int,int> maa;
ll po(ll a,int x)
{
    ll s=1;
    while(x)
    {
        if(x&1)s=s*a%mod;
        x>>=1;
        a=a*a%mod;
    }
    return s;
}
void change(ll y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;++i)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void ntt(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=po(g,(mod-1)/h);
        if(on==1)wn=po(wn,mod-2);
        for(int j=0;j<len;j+=h)
        {
            ll w=1;
            for(int k=j;k<j+h/2;++k)
            {
                ll u=y[k];
                ll t=w*y[k+h/2]%mod;
                y[k]=(u+t)%mod;
                y[k+h/2]=(u-t+mod)%mod;
                w=w*wn%mod;
            }
        }
    }
    if(on==-1)
    {
        ll t=po(len,mod-2);
        for(int i=0;i<len;++i)y[i]=y[i]*t%mod;
    }
}
void init(){
    int len=1;
    while(len<n*2)len<<=1;
    for(int i=0;i<len;++i){
        x[i]=0;
        y[i]=(i<m&&i<n)?p[i]:0;
    }
    x[0]=1;
    int lk=k;
    while(lk){
        if(lk&1){
            ntt(x,len,1);
            ntt(y,len,1);
            for(int i=0;i<len;++i)x[i]=y[i]*x[i]%mod;
            ntt(x,len,-1);
            ntt(y,len,-1);
            for(int i=n;i<len;++i){
                x[i]=0;
            }
        }
        lk>>=1;
        if(lk){
            ntt(y,len,1);
            for(int i=0;i<len;++i)y[i]=y[i]*y[i]%mod;
            ntt(y,len,-1);
            for(int i=n;i<len;++i){
                y[i]=0;
            }
        }
    }
    for(int i=0;i<n;++i){
        inz[i]=x[i];
        nz[i]=inz[i]+(i?nz[i-1]:0);
        if(nz[i]>=mod)nz[i]-=mod;
    }
}
void solve(int a){
    ++cnt;
    int b=a;
    while(!nuv[b]){
        ans[b]+=inz[0];
        if(QWQ[b].size()==0){
            QWQ[b].push_back(P(-1,0));
        }
        else{
            ans[b]+=nz[QWQ[b][0].second]-nz[QWQ[b][0].first]+mod;
            --QWQ[b][0].first;
        }
        vis[b]=cnt;
        a=f[b];
        for(int i=0;i<QWQ[b].size();++i){
            if(i)ans[b]+=nz[QWQ[b][i].second]-nz[QWQ[b][i].first]+mod;
            ++QWQ[b][i].first;
            ++QWQ[b][i].second;
        }
        if(QWQ[a].size()<QWQ[b].size())QWQ[a].swap(QWQ[b]);
        for(int i=0;i<QWQ[b].size();++i){
            QWQ[a].push_back(QWQ[b][i]);
        }
        QWQ[b].clear();
        --nuv[a];
        b=a;
    }
}
void dfs(int a){
    int b=a,l=0,r=-1,mm;
    while(!vc[b]){
        pa[l++]=b;
        vc[b]=1;
        b=f[b];
    }
    for(int i=0;i<l;++i){
        if(pa[i]==b){
            r=i;
            break;
        }
    }
    if(r==-1)return;
    for(int i=r,j=l-r;i<l;++i){
        siz[pa[i]]=j;
        ans[pa[i]]=1;
        vis[pa[i]]=-1;
    }
    if(maa.find(l-r)==maa.end())
    {
        idid[macnt]=l-r;
        maa[l-r]=macnt++;
    }
}
int dfs2(int x){
    if(G[x].size()==0)return 1;
    int ma=0;
    for(int i=0;i<G[x].size();++i){
        ma=max(ma,dfs2(G[x][i]));
    }
    return ma+1;
}
void init2(int a){
    int l=maxlen[a],len=1,mm=idid[a],r=l-mm;
    while(len<l*2)len<<=1;
    for(int i=0;i<len;++i){
        y[i]=z[i]=0;
    }
    y[0]=1;
    for(int i=0;i<m;++i){
        int j=i>=l?r+(i-l)%mm:i;
        z[j]+=p[i];
        if(z[j]>=mod)z[j]-=mod;
    }
    int lk=k;
    while(lk){
        if(lk&1){
            ntt(z,len,1);
            ntt(y,len,1);
            for(int i=0;i<len;++i)y[i]=y[i]*z[i]%mod;
            ntt(z,len,-1);
            ntt(y,len,-1);
            for(int i=l;i<len;++i){
                int j=r+(i-l)%mm;
                y[j]+=y[i];
                if(y[j]>=mod)y[j]-=mod;
                y[i]=0;
            }
        }
        lk>>=1;
        if(lk){
            ntt(z,len,1);
            for(int i=0;i<len;++i)z[i]=z[i]*z[i]%mod;
            ntt(z,len,-1);
            for(int i=l;i<len;++i){
                int j=r+(i-l)%mm;
                z[j]+=z[i];
                if(z[j]>=mod)z[j]-=mod;
                z[i]=0;
            }
        }
    }
    for(int i=l-1;i>=0;--i){
        qq[a][i]=y[i];
        if(i>=mm){
            y[i-mm]+=y[i];
            if(y[i-mm]>=mod)y[i-mm]-=mod;
        }
    }
    for(int i=1;i<l;++i){
        qq[a][i]+=qq[a][i-1];
        if(qq[a][i]>=mod)qq[a][i]-=mod;
    }
}
int main()
freopen("../input_files/DefiniteRandomWalks", "r", stdin);
{
    scanf("%d%d%d",&n,&m,&k);
    int az=89;
    for(int i=0;i<n;++i){
            scanf("%d",&f[i]);
            --f[i];
            v[f[i]]=1;
            ++nuv[f[i]];
            G[f[i]].push_back(i);
    }
    az=89;
    for(int i=0;i<m;++i)scanf("%d",&p[i]);
    init();
    az=89;
    for(int i=0;i<n;++i){
        if(!v[i])dfs(i);
    }
    az=89;
    for(int i=0;i<n;++i){
        if(siz[i]){
            int ma=0,id=maa[siz[i]];
	    az=89;
            for(int j=0;j<G[i].size();++j){
                if(!siz[G[i][j]])ma=max(ma,dfs2(G[i][j]));
            }
            maxlen[id]=max(maxlen[id],ma+siz[i]);
        }
        vc[i]=0;
    }
    az=89;
    for(int i=0;i<macnt;++i)
        init2(i);
    az=89;
    for(int i=0;i<n;++i){
        if(!v[i])solve(i);
    }
    az=89;
    for(int i=0;i<n;++i){
        if(QWQ[i].size()){
            int id=maa[siz[i]];
	    az=89;
            for(int j=0;j<QWQ[i].size();++j){
                int l=QWQ[i][j].first,r=QWQ[i][j].second;
                for(int ll=0,a=i;ll<siz[i];++ll,a=f[a]){
                    ans[a]+=qq[id][r+ll]-qq[id][l+ll]+mod;
                }
            }
        }
    }
    az=89;
    for(int i=0;i<n;++i){
        if(!vis[i])ans[i]=1;
    }
    ll inv=po(n,mod-2);
    az=89;
    for(int i=0;i<n;++i)printf("%lld\n",ans[i]%mod*inv%mod);
    return 0;
}
