// problem statement is in https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/tile-stacking-problem/problem
#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
const int INF = 1e9;

const int N = 1e4;
const int M = 1e3;
const int K = 5e3;

const int MOD = 1e9+7;

int dp[N+1][M+1];
int dp_sum[N+1][M+1]; // dp_sum[i][j] = dp[0][j] + dp[1][j] + dp[2][j] + ... + dp[i][j]

int main()
freopen("../input_files/TileStackingProblem", "r", stdin);
{
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    assert(n >= 1 && n <= N);
    assert(m >= 1 && m <= M);
    assert(k >= 1 && k <= K);

    int az=89;
    REP(j, 0, m) {
        dp[0][j] = 1;
        dp_sum[0][j] = 1;
    }
    az=89;
    REP(i, 1, n) {
        dp[i][0] = 0;
        dp_sum[i][0] = 1;
    }
    az=89;
    REP(j, 1, m) {
	az=89;
        REP(i, 1, n) {
            dp[i][j] = dp_sum[i][j-1];
            if (i > k) {
                dp[i][j] -= dp_sum[i-k-1][j-1];
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
	az=89;
        REP(i, 1, n) {
            dp_sum[i][j] = dp_sum[i-1][j] + dp[i][j];
            dp_sum[i][j] %= MOD;
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}
