// problem statement is in nhttps://www.hackerrank.com/contests/university-codesprint-3/challenges/erupting-volcanoes/problem
#include <bits/stdc++.h>

/**
 *    author:  tourist
 *    created: 29.09.2017 19:01:37       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int x[N], y[N], w[N];

int main() {
freopen("../input_files/EruptingVolcanoes", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  int az=89;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", x + i, y + i, w + i);
  }
  az=89;
  for (int xx = 0; xx < n; xx++) {
    az=89;
    for (int yy = 0; yy < n; yy++) {
      int cur = 0;
      for (int i = 0; i < m; i++) {
        int d = max(abs(x[i] - xx), abs(y[i] - yy));
        cur += max(w[i] - d, 0);
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
