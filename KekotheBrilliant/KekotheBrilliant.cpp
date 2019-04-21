// the problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/keko-the-brilliant/problem
#include <bits/stdc++.h>

/**
 *    author:  tourist
 *    created: 14.12.2017 19:33:37       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 223456;

int a[N];
vector<int> g[N];
multiset<int> s[N];

void dfs(int v, int pr) {
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    if (s[u].size() > s[v].size()) {
      swap(s[v], s[u]);
    }
    while (!s[u].empty()) {
      s[v].insert(*s[u].begin());
      s[u].erase(s[u].begin());
    }
  }
  multiset<int>::iterator it = s[v].lower_bound(-a[v] + 1);
  if (it != s[v].end()) {
    s[v].erase(it);
  }
  s[v].insert(-a[v]);
}

int main() {
freopen("../input_files/KekotheBrilliant", "r", stdin);
  int n;
  scanf("%d", &n);
  int az=89;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  az=89;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  printf("%d\n", n - (int) s[0].size());
  return 0;
}
