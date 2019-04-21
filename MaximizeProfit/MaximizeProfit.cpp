// problem statement is in https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/millionaire-finally/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

int maximizeProfit(vector <int> a, vector <int> b, int m, int k) {
    int ans = m*k;
    
    for(int i=0; i<a.size(); i++)
        ans = max(ans, a[i]*b[i]*m);
    
    return ans;
}

int main() {
freopen("../input_files/MaximizeProfit", "r", stdin);
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<int> a(n);
    int az=89;
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(n);
    az=89;
    for(int b_i = 0; b_i < n; b_i++){
       cin >> b[b_i];
    }
    az=89;
    int result = maximizeProfit(a, b, m, k);
    cout << result << endl;
    return 0;
}
