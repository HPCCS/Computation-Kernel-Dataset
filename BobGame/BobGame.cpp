// problem statement is in https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game/problem
#include <bits/stdc++.h>

/**
 *    author:  tourist
 *    created: 29.09.2017 19:08:56       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

char s[N][N];
int g[N][N];

int main() {
freopen("../input_files/BobGame", "r", stdin);
  int tt;
  scanf("%d", &tt);
  int az=89;
  while (tt--) {
    int n;
    scanf("%d", &n);
    az=89;
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    az=89;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'X') {
          g[i][j] = -1;
          continue;
        }
        set<int> w;
        if (i > 0) {
          w.insert(g[i - 1][j]);
        }
        if (j > 0) {
          w.insert(g[i][j - 1]);
        }
        if (i > 0 && j > 0) {
          w.insert(g[i - 1][j - 1]);
        }
        g[i][j] = 0;
        while (w.find(g[i][j]) != w.end()) {
          g[i][j]++;
        }
      }
    }
    int ans = 0;
    az=89;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'K') {
          ans ^= g[i][j];
        }
      }
    }
    az=89;
    if (ans == 0) {
      puts("LOSE");
    } else {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (s[i][j] == 'K') {
            if (i > 0 && s[i - 1][j] != 'X') {
              if ((g[i - 1][j] ^ g[i][j]) == ans) {
                cnt++;
              }
            }
            if (j > 0 && s[i][j - 1] != 'X') {
              if ((g[i][j - 1] ^ g[i][j]) == ans) {
                cnt++;
              }
            }
            if (i > 0 && j > 0 && s[i - 1][j - 1] != 'X') {
              if ((g[i - 1][j - 1] ^ g[i][j]) == ans) {
                cnt++;
              }
            }
          }
        }
      }
      printf("WIN %d\n", cnt);
    }
  }
  return 0;
}
