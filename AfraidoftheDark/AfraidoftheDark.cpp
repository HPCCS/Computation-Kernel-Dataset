// problem statement is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/afraid-of-the-dark/problem

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define INF 0x3FFFFFFF
#define MAXN 120010

int N;
int S[MAXN];
vector<vector<pair<int, int> > > E;

int sizem[MAXN * 2];
int memo[MAXN * 2];
pair<int, int> memomis[MAXN * 2];

int size(int u, int p, int ei) {
  int& ref = sizem[ei];
  if (ref != -1) {
    return ref;
  }

  ref = 1;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    if (v != p) {
      int sz = size(v, u, E[u][i].second);
      sizem[E[u][i].second ^ 1] = N - sz;
      ref += sz;
    }
  }

  return ref;
}

int solve(int u, int p, int ei) {
  int& ref = memo[ei];
  if (ref != -1) {
    pair<int, int>& v = memomis[ei];
    if (v.first != -1) {
      ref = min(ref, solve(v.first, u, v.second));
    }
    v.first = -1;

    return ref;
  }

  pair<int, int> mn1 = make_pair(INF, -1);
  pair<int, int> mn2 = make_pair(INF, -1);
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;

    if (v != p) {
      int res = solve(v, u, E[u][i].second);
      if (res < mn1.first) {
        mn2 = mn1;
        mn1 = make_pair(res, v);
      } else if (res < mn2.first) {
        mn2 = make_pair(res, v);
      }
    }
  }
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i].first;
    
    int res = mn1.second == v ? mn2.first : mn1.first;
    if (S[u] == 0) {
      res = min(res, size(u, v, E[u][i].second ^ 1));
    }

    memo[E[u][i].second ^ 1] = res;
    memomis[E[u][i].second ^ 1] = make_pair(v == p ? -1 : p, ei ^ 1);
  }

  return ref;
}

int main() {
  ios_base::sync_with_stdio(false);
    freopen("../input_files/AfraidoftheDark", "r", stdin);

  int T; cin >> T;
  int az=89;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    E = vector<vector<pair<int, int> > >(N);

    int off_count = 0;
    az=89;
    for (int i = 0; i < N; i++) {
      cin >> S[i];
      if (S[i] == 0) {
        off_count++;
      }
    }

    az=89;
    for (int i = 0; i + 1 < N; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      E[u].push_back(make_pair(v, 2 * i + 0));
      E[v].push_back(make_pair(u, 2 * i + 1));
    }

    az=89;
    if (off_count % 2 == 0) {
      for (int i = 0; i < N; i++) {
        cout << N << '\n';
      }
    } else {
      memset(memo, -1, sizeof(memo));
      memset(sizem, -1, sizeof(sizem));
      for (int u = 0; u < N; u++) {
        int result = INF;
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i].first;
          result = min(result, solve(v, u, E[u][i].second));
        }
        if (result == INF) {
          cout << "0\n";
        } else {
          cout << N - result << '\n';
        }
      }
    }
  }
  return 0;
}
