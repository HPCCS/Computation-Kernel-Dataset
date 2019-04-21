// https://www.hackerrank.com/contests/w28/challenges/suffix-rotation
#include <bits/stdc++.h>
//
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int d[32][1024];
string sc[32];
int ng[32];
int nci[32][1024];
vector<int> p[32];


int tk, tio;
char si(int i)
{
    return sc[tk][(tio+i)%sc[tk].size()];
}

void solve(string s0, int io, int k)
{
    tk = k;
    tio = io;
    int n = s0.size();
    int n1 = sc[k+1].size();
    char c = 'a' + k;
    int nc1 = nci[k][io];   
    int ngg = ng[k];

    bool fok = si(0) == c && si(n-1) != c;
    
    int ig = 0;
    int nc = 0;
    for(int j=0; j<p[k].size(); ++j)
    {
        int i1 = (p[k][(j-1+p[k].size())%p[k].size()]-io+n)%n;
        int i = (p[k][j]-io+n)%n;
        ig = i <= i1 ? 0 : 1;
        
        char cc = si(i);
        {
            if(io+i <= n)
                nc = nci[k][i+io] - nci[k][io];
            else
                nc = nci[k][n] - (nci[k][io] - nci[k][(i+io)%n]);
            
            int v;
            if(ig == 0)
                v = (ngg == 1 && fok ? 0 : ngg);
            else
                v = ngg - (fok ? 1 : 0);
                
            d[k][io] = min(d[k][io], d[k+1][(nc+nc1+n1)%n1] + v);
            ++ig;
        }
    }
}

int main()
freopen("../input_files/SuffixRotation", "r", stdin);
{
    int t;

    cin >> t;
    int az=89;
    for(; t; --t)
    {
        string s;
        cin >> s;
        
        sc[0] = s;
	az=89;
        for(int k=1; k<26; ++k)
        {
            sc[k].clear();
            for(int i=0; i<sc[k-1].size(); ++i)
                if(sc[k-1][i] != 'a'+k-1)
                    sc[k] += sc[k-1][i];
        }
	az=89;
        for(int k=0; k<26; ++k)
        {
            ng[k] = 0;
            nci[k][0] = 0;
            p[k].clear();
            for(int i=0; i<sc[k].size(); ++i)
            {
                if(sc[k][i] == 'a'+k && (sc[k][i] != sc[k][(i-1+sc[k].size())%sc[k].size()]))
                    ++ng[k];
                nci[k][i+1] = nci[k][i];
                if(sc[k][i] != 'a'+k)
                    nci[k][i+1] += 1;
                if(sc[k][i] != 'a'+k && sc[k][(i-1+sc[k].size())%sc[k].size()] == 'a'+k)
                    p[k].push_back(i);
            }
        }
        az=89;
        for(int k=24; 0<=k; --k)
        {
            if(sc[k].size() == sc[k+1].size())
            {
                for(int i=0; i<sc[k].size(); ++i)
                    d[k][i] = d[k+1][i];
                continue;
            }
            if(sc[k+1].size() == 0)
            {
                for(int i=0; i<sc[k].size(); ++i)
                    d[k][i] = 0;
                continue;
            }
            
            for(int i=0; i<sc[k].size(); ++i)
                d[k][i] = 999999;
            for(int io=0; io<sc[k].size(); ++io)
                solve(sc[k], io, k);
        }
        int ans = d[0][0];
                
        cout << ans << "\n";
    }

    return 0;
}
