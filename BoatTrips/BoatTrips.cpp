// problem statement is in https://www.hackerrank.com/contests/w28/challenges/boat-trip/leaderboard
#include <bits/stdc++.h>
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/BoatTrips", "r", stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = true;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        if (x > b * c) ok = false;
    }
    if (ok)
    {
        puts("Yes");;
    }
    else
        {puts("No");}
}
