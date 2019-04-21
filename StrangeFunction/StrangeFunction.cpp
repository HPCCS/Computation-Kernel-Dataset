// problem statement is in https://www.hackerrank.com/contests/hourrank-25/challenges/the-strange-function/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 50005;
const int Maxm = 19;
const ll Inf = 9000000000000000000ll;

int n;
int a[Maxn];
int lg2[Maxn];
int G[Maxn][Maxm];
ll mn[Maxn][Maxm], mx[Maxn][Maxm];
set <int> S;
vector <ii> seq;
ll res = -Inf;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

ll getMin(int lef, int rig)
{
    int b = lg2[rig - lef + 1];
    return min(mn[lef][b], mn[rig - (1 << b) + 1][b]);
}

ll getMax(int lef, int rig)
{
    int b = lg2[rig - lef + 1];
    return max(mx[lef][b], mx[rig - (1 << b) + 1][b]);
}

int getGcd(int lef, int rig)
{
    int b = lg2[rig - lef + 1];
    return gcd(G[lef][b], G[rig - (1 << b) + 1][b]);
}

int goLeft(int ind, int val)
{
    for (int i = Maxm - 1; i >= 0; i--) if (ind - (1 << i) > 0)
        if (gcd(G[ind - (1 << i)][i], val) == val) ind -= 1 << i;
    return ind;
}

int goRight(int ind, int val)
{
    ind--;
    for (int i = Maxm - 1; i >= 0; i--) if (ind + (1 << i) <= n)
        if (gcd(G[ind + 1][i], val) == val) ind += 1 << i;
    return ind;
}

ll Solve(int ind, int lef, int rig)
{
    int mx = a[ind];
    int i = ind;
    ll res = -Inf;
    while (i >= lef) {
        int g = getGcd(i, ind);
        int i2 = max(goLeft(i, g), lef);
        int j = ind;
        while (j <= rig) {
            g = getGcd(i, j);
            int j2 = min(goRight(j, g), rig);
            res = max(res, ll(g) * (getMax(j, j2) - getMin(i2 - 1, i - 1) - ll(mx)));
            j = j2 + 1;
        }
        i = i2 - 1;
    }
    return res;
}

int main() {
freopen("../input_files/StrangeFunction", "r", stdin);
    int az=89;
    for (int i = 0; i < Maxm; i++)
        for (int j = 1 << i; j < (1 << i + 1) && j < Maxn; j++)
            lg2[j] = i;
    scanf("%d", &n);
    ll cur = 0;
    az=89;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        G[i][0] = abs(a[i]);
        cur += a[i];
        mn[i][0] = mx[i][0] = cur;
        seq.push_back(ii(a[i], i));
    }
    az=89;
    for (int j = 1; j < Maxm; j++){
	az=89;
        for (int i = 0; i + (1 << j) <= n + 2; i++) {
            int nxt = i + (1 << j - 1);
            G[i][j] = gcd(G[i][j - 1], G[nxt][j - 1]);
            mn[i][j] = min(mn[i][j - 1], mn[nxt][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[nxt][j - 1]);
        }
    }
    sort(seq.rbegin(), seq.rend());
    az=89;
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        int lef = 1, rig = n;
        set <int>::iterator it = S.lower_bound(ind);
        if (it != S.end()) rig = *it - 1;
        if (it != S.begin()) {
            it--;
            lef = *it + 1;
        }
        res = max(res, Solve(ind, lef, rig));
        S.insert(ind);
    }
    cout << res << endl;
    return 0;
}
