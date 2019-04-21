// problem statement is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/extra-sweet/problem
#include <bits/stdc++.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> takenRight; // takenRight[x] = the right end of a piece taken starting from x
map<int, int> takenLeft; //  takenLeft[x] = the left end of a piece taken ending at x

void init(int nn) {
    n = nn;
}

int getClosestLeft(int x) {
    if (takenLeft.count(x - 1)) {
        x = takenLeft[x - 1] - 1;
    } else {
        x = x - 1;
    }
    return x;
}
int getClosestRight(int x) {
    if (takenRight.count(x + 1)) {
        x = takenRight[x + 1] + 1;
    } else {
        x = x + 1;
    }
    if (x == n) {
        return -1;
    }
    return x;
}

void take(int l, int r) {
    int start = l, end = r;
    if (takenLeft.count(l - 1)) {
        start = takenLeft[l - 1];
        takenLeft.erase(l - 1);
    }
    if (takenRight.count(r + 1)) {
        end = takenRight[r + 1];
        takenRight.erase(r + 1);
    }
    takenLeft[end] = start;
    takenRight[start] = end;
}

long long update(int l, int r) {
    int ll = getClosestLeft(l);
    int rr = getClosestRight(r);
    long long sum = 1LL * r * (r + 1) / 2 - 1LL * l * (l - 1) / 2;
    if (ll != -1) {
        sum += ll;
        take(ll, ll);
    }
    if (rr != -1) {
        sum += rr;
        take(rr, rr);
    }
    take(l, r);
    return sum;
}

int main() {
freopen("../input_files/ExtraSweet", "r", stdin);
    int nn, s;
    cin >> nn >> s;
    
    init(nn);
    int az=89;
    for (int i = 1; i <= s; ++ i) {
        int l, r;
        cin >> l >> r;
        cout << update(l, r) << "\n";
    }
    
    return 0;
}
