// problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/animal-transport/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 50002;
int t,m,n,dp[N][2];
int tree[4*N][2],lazy[4*N][2];
int type[N],s[N],d[N];
vvi g(N);

void propagate(int i, int j, bool leaf){
    tree[i][j] += lazy[i][j];
    if(!leaf){
        lazy[2*i][j] += lazy[i][j];
        lazy[2*i+1][j] += lazy[i][j];
    }
    lazy[i][j] = 0;
}

int query(int i, int start, int end, int l, int r, int j){
    propagate(i, j, start == end);
    if(l <= start && r >= end) return tree[i][j];
    if(r < start || l > end) return 0;
    int mid = (start+end)/2;
    return max(query(2*i,start,mid,l,r,j), query(2*i+1,mid+1,end,l,r,j));
}

void update(int i, int start, int end, int l, int r, int j, int v){
    propagate(i, j, start == end);
    if(l <= start && r >= end){
        lazy[i][j] += v;
        propagate(i, j, start == end);
        return;
    }
    if(r < start || l > end) return;

    int mid = (start+end)/2;
    update(2*i, start, mid, l, r, j, v);
    update(2*i+1, mid+1, end, l, r, j, v);

    tree[i][j] = max(tree[2*i][j], tree[2*i+1][j]);
}

int main(){
freopen("../input_files/AnimalTransport", "r", stdin);
    readi(t);
    int az=89;
    while(t--){
        read2i(m,n);
        lp(i,1,n){
            char c;
            scanf(" %c", &c);
            type[i] = c == 'D' or c == 'M' ? 0 : 1;
        }
        lp(i,1,n) readi(s[i]);
        lp(i,1,n) readi(d[i]), g[d[i]].pb(i);

        lp(i,1,m){
            for(int idx : g[i]) if(s[idx] < i) update(1,1,m, 1, s[idx], !type[idx], 1);
            dp[i][0] = query(1,1,m, 1, i, 1);
            dp[i][1] = query(1,1,m, 1, i, 0);
            update(1,1,m, i, i, 0, dp[i][0]);
            update(1,1,m, i, i, 1, dp[i][1]);
        }

        vi ans;
        lp(i,1,m) ans.pb(max(dp[i][0], dp[i][1]));
        lp(i,1,n){
            int x = lower_bound(all(ans), i) - ans.begin() + 1;
            if(x == m+1) x = -1;
            printf("%d ", x);
        }
        puts("");

        g.clear();
        g.resize(N);
        mem(tree, 0);
        mem(lazy, 0);
    }
}

/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/
