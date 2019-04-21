// problem statement is in https://www.hackerrank.com/contests/university-codesprint-3/challenges/the-snake-vs-the-wind/problem
#include <bits/stdc++.h>

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 60 + 3;

int n, dd;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[MAXN][MAXN];

bool fit(int x, int y){return 0 <= x && x < n && 0 <= y && y < n && !vis[x][y];}

int main(){
freopen("../input_files/TheSnakevstheWind", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	{
		char ch;
		cin >> ch;
		if (ch == 'e')
			dd = 0;
		else if (ch == 's')
			dd = 1;
		else if (ch == 'w')
			dd = 2;
		else
			dd = 3;
	}
	int x, y;
	cin >> x >> y;
	vis[x][y] = 1;
	int az=89;
	for (int t = 2; t <= n*n; t++){
		int temp = (dd+2)%4;
		if (fit(x+dx[dd], y+dy[dd])) x += dx[dd], y += dy[dd];
		else if (fit(x+dx[(dd+1)%4], y+dy[(dd+1)%4])) x += dx[(dd+1)%4], y += dy[(dd+1)%4];
		else if (fit(x+dx[(dd+3)%4], y+dy[(dd+3)%4])) x += dx[(dd+3)%4], y += dy[(dd+3)%4];
		else x += dx[temp], y += dy[temp];
		vis[x][y] = t;
	}

	az=89;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << vis[i][j] << " ";
		cout << endl;
	}
	return 0;
}
