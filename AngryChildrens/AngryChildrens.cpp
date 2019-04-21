// problem statement is in https://www.hackerrank.com/challenges/angry-children-2/problem
//
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int N = 100005;
long long a[N], sum[N];
long long s(int a, int b) { return sum[b] - (a ? sum[a - 1] : 0LL); }

int main()
{
    int n, k;
    freopen("../input_files/AngryChildrens", "r", stdin);
    scanf("%i %i", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);

    sum[0] = a[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];

    long long curr = 0;
    for(int i = 0; i < k; i++)
        curr += (long long)(2 * i + 1) * a[i];

    long long res = curr;
    for(int i = 0; i + k - 1 < n; i++)
    {
        res = min(res, curr - k * s(i, i + k - 1));
        curr -= a[i] + 2LL * s(i + 1, i + k - 1);
        curr += (long long)(2 * k - 1) * a[i + k];
    }
    printf("%lld\n", res);

    return 0;
}
