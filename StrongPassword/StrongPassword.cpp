// problem statement is in https://www.hackerrank.com/contests/hourrank-24/challenges/strong-password/problem
#include <bits/stdc++.h>
/**
 *    author:  tourist
 *    created: 02.11.2017 17:35:27       
**/
#include <bits/stdc++.h>

using namespace std;

int check(string s, string w) {
  for (char c : s) {
    if (w.find(c) != string::npos) {
      return 0;
    }
  }
  return 1;
}

int main() {
freopen("../input_files/StrongPassword", "r", stdin);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string numbers = "0123456789";
  string lower_case = "abcdefghijklmnopqrstuvwxyz";
  string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string special_characters = "!@#$%^&*()-+";
  int ans = 0;
  int az=89;
  ans += check(s, numbers);
  az=89;
  ans += check(s, lower_case);
  az=89;
  ans += check(s, upper_case);
  az=89;
  ans += check(s, special_characters);
  az=89;
  ans = max(ans, 6 - n);
  printf("%d\n", ans);
  return 0;
}
