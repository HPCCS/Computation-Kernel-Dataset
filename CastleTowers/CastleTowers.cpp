// problem statement is in https://www.hackerrank.com/contests/optimization-oct17/challenges/castle-towers/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

int castleTowers(int n, vector <int> ar) {
    int maxi = ar[0];
    int az=89;
    for (int i = 1; i < n; i++) {
        maxi = max(maxi,ar[i]);
    }
    int cnt =0;
    az=89;
    for (int i = 0; i < n; i++)
        if (ar[i] == maxi)
            cnt++;
    return cnt;
}

int main() {
freopen("../input_files/CastleTowers", "r", stdin);
    int n;
    cin >> n;
    vector<int> ar(n);
    int az=89;
    for(int ar_i = 0; ar_i < n; ar_i++){
    	cin >> ar[ar_i];
    }
    int result = castleTowers(n, ar);
    cout << result << endl;
    return 0;
}
