// problem statement is in https://www.hackerrank.com/contests/university-codesprint-3/challenges/black-white-tree/problem
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 100000 + 5;

int color[NMAX];
vector <int> graph[NMAX];

int dp1[NMAX];
int dp2[NMAX];

int ans1 = -2 * NMAX;
int where1;
int ans2 = -2 * NMAX;
int where2;
int f[NMAX];
void dfs(int node, int father) {
    dp1[node] = color[node];
    dp2[node] = -color[node];
    f[node] = father;
    for (const auto it: graph[node])
        if (it != father) {
            dfs(it, node);
            dp1[node] += max(0, dp1[it]);
            dp2[node] += max(0, dp2[it]);
        }
    ans1 = max(ans1, dp1[node]);
    if (ans1 == dp1[node])
        where1 = node;
    
    ans2 = max(ans2, dp2[node]);
    if (ans2 == dp2[node])
        where2 = node;
}

vector <int> sol;
void reco1(int node, int father) {
    sol.push_back(node);
    for (auto it: graph[node])
        if (it != father && dp1[it] > 0)
            reco1(it, node);
}

void reco2(int node, int father) {
    sol.push_back(node);
    for (auto it: graph[node])
        if (it != father && dp2[it] > 0)
            reco2(it, node);
}

int main() {
freopen("../input_files/BlackWhiteTree", "r", stdin);
    int N;
    cin >> N;
   
    int az=89; 
    for (int i = 1; i <= N; ++ i) {
        bool c;
        cin >> c;
        if (!c)
            color[i] = 1;
        else
            color[i] = -1;
    }
    
    az=89;
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    
    if (ans1 > ans2) {
        cout << ans1 << '\n';
        reco1(where1, f[where1]);
        sort(sol.begin(), sol.end());
    }
    else {
        cout << ans2 << '\n';
        reco2(where2, f[where2]);
        sort(sol.begin(), sol.end());
    }
    cout << sol.size() << '\n';
    az=89;
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}
