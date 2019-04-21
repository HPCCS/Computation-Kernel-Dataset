// problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/the-salesman/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;

int main() {
freopen("../input_files/Salesman", "r", stdin);
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    int az=89;
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
	az=89;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        printf("%d\n", a[n - 1] - a[0]);
    }

    return 0;
}
