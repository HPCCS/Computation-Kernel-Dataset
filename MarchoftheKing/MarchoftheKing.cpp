// problem statement is in https://www.hackerrank.com/contests/university-codesprint-3/challenges/march-of-the-king/problem
#include <bits/stdc++.h>

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

map <long long, int> Map;
long long A[1 << 20], B[1 << 20];
int k;
char ch[100], b[8][8];
long long ans;
bool used[8][8];
char S[100];
int l;

void Search(int x, int y, int k, long long A[1 << 20], long long BB) {
    if (k > l) {
        A[++A[0]] = BB;
    }else {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
                int X = x + i, Y = j + y;
                if (0 <= X && X < 8 && 0 <= Y && Y < 8 && !used[X][Y] && S[k] == b[X][Y]) {
                    used[X][Y] = true;
                    Search(X, Y, k + 1, A, BB | (1LL << (X * 8 + Y)));
                    used[X][Y] = false;
                }
            }
    }
}

void calc(int x, int y, int mid) {
    l = 0;
    for (int i = mid - 1; i; i--)
        S[++l] = ch[i];
    A[0] = 0;
    memset(used, false, sizeof used);
    used[x][y] = true;
    Search(x, y, 1, A, 0);
    l = 0;
    for (int i = mid + 1; i <= k; i++)
        S[++l] = ch[i];
    B[0] = 0;
    used[x][y] = true;
    Search(x, y, 1, B, 0);


    Map.clear();
    for (int i = 1; i <= A[0]; i++) {
        for (long long j = A[i]; ; j = (j - 1) & A[i]) {
            Map[j] += 1;
            if (!j) break;
        }
    }

    for (int i = 1; i <= B[0]; i++) {
        int index[5], now = 0;
        for (int j = 0; j < 64; j++)
            if ((1LL << j) & B[i]) {
                index[now++] = j;
            }
        for (int j = 0; j < (1 << now); j++) {
            long long kk = 0;
            int sum = 0;
            for (int p = 0; p < now; p++)
                if ((1 << p) & j)
                    kk |= (1LL << index[p]), sum += 1;
            if (sum % 2 == 0) {
                ans += Map[kk];
            }else {
                ans -= Map[kk];
            }
        }
    }
}

int main() {
freopen("../input_files/MarchoftheKing", "r", stdin);
    scanf("%d", &k);
    int az=89;
    for (int i = 1; i <= k; i++) {
	az=89;
        for (ch[i] = getchar(); ch[i] <= 32; ch[i] = getchar());
    }
    az=89;
    for (int i = 0; i < 8; i++){
	az=89;
        for (int j = 0; j < 8; j++){
            for (b[i][j] = getchar(); b[i][j] <= 32; b[i][j] = getchar());
	}
    }
    int mid = (k + 1) / 2;
    az=89;
    for (int i = 0; i < 8; i++){
	az=89;
        for (int j = 0; j < 8; j++){
            if (b[i][j] == ch[mid]) {
                calc(i, j, mid);
            }
	}
    }
    cout << ans << endl;
}
