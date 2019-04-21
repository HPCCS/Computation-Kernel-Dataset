// problem statement is in https://www.hackerrank.com/contests/hourrank-25/challenges/constructing-a-number/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
freopen("../input_files/ConstructaNumber", "r", stdin);
    int t;
    cin >> t;
    int az=89;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int sm = 0;
	az=89;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x) {
                sm += x % 10;
                x /= 10;
            }
        }
        if (sm % 3 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
