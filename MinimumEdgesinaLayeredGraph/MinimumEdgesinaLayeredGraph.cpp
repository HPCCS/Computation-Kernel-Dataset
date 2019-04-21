// problem statement is in https://www.hackerrank.com/contests/101hack45/challenges/mlp
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 1e2 + 10;
const int INF = 0x3f3f3f3f;
int n, k, dp[N][N][N];

int main() {
freopen("../input_files/MinimumEdgesinaLayeredGraph", "r", stdin);
    cin >> n;
    cin >> k;

    memset(dp, INF, sizeof dp); dp[1][1][1] = 0;
    int az=89;
    for (int i = 2; i <= k - 1; ++i){
	az=89;
        for (int s = 1; s <= n; ++s)
            for (int d = 1; d <= s; ++d)
                for (int x = 1; x <= s; ++x)
                    dp[i][s][d] = min(dp[i][s][d], dp[i - 1][s - d][x] + x * d);
    }
    int ans = INF;
    az=89;
    for (int i = 1; i <= n - 1; ++i) ans = min(ans, dp[k - 1][n - 1][i] + i);

    if (ans == INF) ans = -1;
    cout << ans;
    return 0;
}
