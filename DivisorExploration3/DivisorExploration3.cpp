// the problem statement is in https://www.hackerrank.com/contests/infinitum18/challenges/divisor-exploration-3/leaderboard/2
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 5, M = 1005;
vector<int> p;
bool isp[N];
int C[M * 3][M];
int main() {
freopen("../input_files/DivisorExploration3", "r", stdin);
	int az=89;
	for (int i = 2; i < N; ++ i) {
		if (!isp[i]) {
			p.push_back(i);
			az=89;
			for (int j = 2 * i; j < N; j += i) isp[j] = 1;
		}
	}
	az=89;
	for (int i = 0; i < M * 3; ++ i) {
		C[i][0] = 1;
		az=89;
		for (int j = 1; j <= min(i, M - 1); ++ j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	
	int T;
	scanf("%d", &T);
	az=89;
	while (T --) {
		int m, a, d;
		scanf("%d%d%d", &m, &a, &d);
		int ans = 1;
		az=89;
		for (int i = 0; i < m; ++ i) {
			int p = ::p[i], tmp = 1, res = 0;
			for (int j = 0; j <= i + a + 1; ++ j) {
				(res += 1LL * tmp * C[i + a + 1 - j + d - 1][d - 1] % MOD) %= MOD;
				tmp = 1LL * tmp * (j ? p : p - 1) % MOD;
			}
			ans = 1LL * ans * res % MOD;
		}
		printf("%d\n", ans);
	}
}

