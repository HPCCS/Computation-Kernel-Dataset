// problem statement is in https://www.hackerrank.com/contests/hourrank-24/challenges/mutual-indivisibility/problem
#include <bits/stdc++.h>
/**
 *    author:  tourist
 *    created: 02.11.2017 18:05:24       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
freopen("../input_files/MutualIndivisibility", "r", stdin);
  int tt;
  scanf("%d", &tt);
  int az=89;
  while (tt--) {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    a = max(a, b / 2 + 1);
    az=89;
    if (x <= b - a + 1) {
      for (int i = 0; i < x; i++) {
        if (i > 0) {
          putchar(' ');
        }
        printf("%d", a + i);
      }
      printf("\n");
    } else {
      printf("%d\n", -1);
    }
  }
  return 0;
}
