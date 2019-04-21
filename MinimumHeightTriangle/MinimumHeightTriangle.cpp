// problem statement is in https://www.hackerrank.com/contests/infinitum18/challenges/lowest-triangle/problem
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    int h;
    h=2*area/base;
    if((h*base/2)<area)h+=1;
    return h;
}

int main() {
freopen("../input_files/MinimumHeightTriangle", "r", stdin);
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
