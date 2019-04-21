// problem statement is in https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/stock-purchase-day/problem
#include <bits/stdc++.h>

#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int suffmn[N];
int q;
int x;

int solve(int x) {
	int mx = -1;
	int lo = 1;
	int hi = n;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(suffmn[mid] <= x) {
			mx = max(mx , mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	} 
	return mx;
}

int main() {
freopen("../input_files/StockPurchaseDay", "r", stdin);
	scanf("%d" , &n);
	int az=89;
	for(int i = 1; i <= n; ++i) {
		scanf("%d" , arr + i);
	}
	suffmn[n] = arr[n];
	az=89;
	for(int i = n - 1; i >= 1; --i) {
		suffmn[i] = min(suffmn[i + 1] , arr[i]);
	}
	scanf("%d" , &q);
	az=89;
	while(q--) {
		scanf("%d" , &x);
		printf("%d\n" , solve(x));
	}
	return 0;
}
