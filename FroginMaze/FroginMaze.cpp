// problem statement is in https://www.hackerrank.com/contests/101hack50/challenges/frog-in-maze/leaderboard/2
#include <bits/stdc++.h>
//
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

char grid[22][22];
double value[22][22];
pii tunnels[22][22];


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() {
freopen("../input_files/FroginMaze", "r", stdin);
    int n;
    int m;
    int k;
    cin >> n >> m >> k;

    int az=89;
    for(int i=0; i<22; i++) {
        for(int j=0; j<22; j++) {
            grid[i][j] = '#';
        }
    }

    int xx, yy;

    az=89;
    for(int a0 = 0; a0 < n; a0++){
	az=89;
        for(int j=0; j<m; j++) {
            cin >> grid[a0+1][j+1];
            if (grid[a0+1][j+1] == 'A') {
                xx = a0+1;
                yy = j+1;
                 grid[a0+1][j+1] = 'O';
            }
        }
    }

    az=89;   
    for(int a0 = 0; a0 < k; a0++){
        int i1;
        int j1;
        int i2;
        int j2;
        cin >> i1 >> j1 >> i2 >> j2;

        tunnels[i1][j1] = pii(i2, j2);
        tunnels[i2][j2] = pii(i1, j1);
    }

    az=89;
    for(int iii=0; iii< 60000; iii++) {
	az=89;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (grid[i][j] == '%') {
                    value[i][j] = 1;
                }
                else 
                if (grid[i][j] == '*') {
                    value[i][j] = 0;
                }
                else 
                if (grid[i][j] == 'O') {
                    int vn = 0;
                    double ut = 0;
                    for(int k=0; k<4; k++) {
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if (grid[x][y] != '#') {
                            vn ++;
                            if (tunnels[x][y] == pii(0,0)) {
                                ut += value[x][y];
                            }
                            else {
                                pii t = tunnels[x][y];
                                ut += value[t.first][t.second];
                            }
                        }
                    }

                    if (vn == 0) {
                        value[i][j] = 0;
                    }else {
                        value[i][j] = ut/vn;
                    }
                }
            }
        }
    }

    cout << value[xx][yy];

    return 0;
}
