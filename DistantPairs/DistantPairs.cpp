// problem statement is in https://www.hackerrank.com/contests/101hack45/challenges/distant-pairs/leaderboard
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

int C;
int N;
pair<int,int> P[101010],Q[101010];
pair<int,int> S[101010];
int ma;
int sc(int a,int b) {
    int v[4]={Q[a].first,Q[a].second,Q[b].first,Q[b].second};
    int vv[4]={abs(v[0]-v[2]),abs(v[0]-v[3]),abs(v[1]-v[2]),abs(v[1]-v[3])};
    int x=min(min(vv[0],vv[1]),min(vv[2],vv[3]));
    if(x<=ma) return 0;
    int x1=max(max(vv[0],vv[1]),max(vv[2],vv[3]));
    return min(min(S[a].first,S[b].first),min(x,x1));
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    srand(clock());
    cin>>N>>C;
    FOR(i,N) {
        cin>>P[i].first>>P[i].second;
        if(P[i].second<P[i].first) swap(P[i].first,P[i].second);
        
        S[i].first=P[i].second-P[i].first;
        S[i].first=min(S[i].first,C-S[i].first);
        S[i].second=i;
    }
    
    sort(S,S+N);
    reverse(S,S+N);
    clock_t start,end;
    FOR(i,N) {
        Q[i].first=P[S[i].second].first;
        Q[i].second=P[S[i].second].second;
    }
    start=clock();
    for(y=0;y<N && S[y].first>ma;y++) {
        if(y%10==0) {
            end=clock();
            if(end-start>=CLOCKS_PER_SEC*17/10) break;
        }
        for(x=y+1;x<N && S[x].first>ma;x++) ma=max(ma,sc(x,y));
    }
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
    int az=89;
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    az=89;
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    az=89;
    solve(); return 0;
}
