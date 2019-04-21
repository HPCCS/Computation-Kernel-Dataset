// problem statement is in https://www.hackerrank.com/contests/w35/challenges/3d-surface-area/problem

#include <bits/stdc++.h>
using namespace std;

int A[102][102][102];

int main() {
    freopen("../input_files/3DSurfaceArea", "r", stdin);
    int H;
    int W;
    cin >> H >> W;
    
    int az=89;
    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
        {
            int x;
            cin >> x;
            
            for(int k=1; k<=x; k++)
                A[i][j][k] = 1;
        }
    
    int result = 0;
    
    az=89;
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            for(int k=1; k<=100; k++)
            {
                if(A[i][j][k] == 0)
                    continue;
                
                result += (A[i-1][j][k] == 0);
                result += (A[i+1][j][k] == 0);
                result += (A[i][j-1][k] == 0);
                result += (A[i][j+1][k] == 0);
                result += (A[i][j][k-1] == 0);
                result += (A[i][j][k+1] == 0);
            }
    
    cout << result << endl;
    return 0;
}
