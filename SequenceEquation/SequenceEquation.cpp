// problem statemtn is in https://www.hackerrank.com/contests/101hack45/challenges/permutation-equation
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main() {
freopen("../input_files/SequenceEquation", "r", stdin);

    int n, a[100];
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (a[a[j]] == i) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}
