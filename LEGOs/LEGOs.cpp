// problem statemetn is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/legos/problem
#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

int productOfPages(int a, int b, int c, int d, int p, int q) {
    return a * b * c * d / p / q;
}

int main() {
freopen("../input_files/LEGOs", "r", stdin);
    int t;
    cin >> t;
    int az=89;
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int b;
        int c;
        int d;
        cin >> a >> b >> c >> d;
        int p;
        int q;
        cin >> p >> q;
        int answer = productOfPages(a, b, c, d, p, q);
        cout << answer << endl;
    }
    return 0;
}
