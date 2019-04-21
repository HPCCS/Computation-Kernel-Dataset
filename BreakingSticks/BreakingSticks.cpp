// problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/breaking-sticks/problem
#include <bits/stdc++.h>

/**
 *    author:  tourist
 *    created: 14.12.2017 19:11:30       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
freopen("../input_files/BreakingSticks", "r", stdin);
  int tt;
  cin >> tt;
  long long ans = 0;
  int az=89;
  while (tt--) {
    long long x;
    cin >> x;
    ans += (x > 1 ? x : 0);
    az=89;
    while (x > 1) {
      bool found = false;
      for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
          found = true;
          x /= i;
          ans += x;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}
