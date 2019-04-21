// the problem statement is in https://www.hackerrank.com/contests/101hack52/challenges/impressive-tree/problem
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
typedef long long ll;

int n, q;
int eu[N], ev[N], par[N];
int sub[N], h[N], en[N], ex[N], rev[N], TIME;
ll dp[N], dep[N], ew[N];

vector<int> adj[N];

void dfs(int u, int p = -1) {
    rev[TIME] = u;
    en[u] = TIME++;
    sub[u] = 1;
    for (int e : adj[u]) {
        int v = eu[e] == u ? ev[e] : eu[e];
        if (v != p) {
            ll w = ew[e];
            dep[v] = dep[u] + w;
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v, u);
            sub[u] += sub[v];
            (dp[u] += (dp[v] + w * sub[v] % M) % M) %= M;
        }
    }
    ex[u] = TIME - 1;
}

int path[N];

int query(int U, int V) {
    if (h[U] > h[V]) swap(U, V);
    if (en[U] <= en[V] && ex[V] <= ex[U]) {
        int size = h[V] - h[U];
        // U is ancestor of V
        for (int i = size, p = V; i >= 0; --i, p = par[p])
            path[i] = p;
        int L = 0;
        while (L <= size &&
            dep[path[L]] - dep[path[0]] + 1 <= dep[path[size]] - dep[path[L]]) {
            ++L;
        }
        --L;
        ll ans = 0;
        for (int i = 0; i < size; ++i) {
            int ui = path[i];
            int uj = path[i + 1];
            ll w = (dep[uj] % M - dep[ui] % M) % M;
            ll dpu = (dp[ui] - dp[uj] - 1ll * w * sub[uj] % M) % M;
            ll subu = (sub[ui] - sub[uj]) % M;
            if (i <= L) {
                (ans += 1ll * sub[V] * dpu % M
                    + 1ll * dp[V] * subu % M
                    + (1 - dep[U] % M) % M * sub[V] % M * subu % M
                    + 1ll * sub[V] * subu % M * (dep[ui] % M) % M
                ) %= M;
            } else {
                (ans += 1ll * sub[V] * dpu % M
                    + 1ll * dp[V] * subu % M
                    + dep[V] % M * sub[V] % M * subu % M
                    - 1ll * sub[V] * subu % M * (dep[ui] % M) % M
                ) %= M;
            }
        }
        return ans;
    } else {
        // case 3
        return (1ll * dp[V] * sub[U] % M
            + 1ll * dp[U] * sub[V] % M
            + 1ll * sub[U] * sub[V] % M) % M;
    }
}

void update(int e, ll x) {
    int u = eu[e], v = ev[e];
    if (h[u] > h[v]) swap(u, v);
    ew[e] += x;
    // update ancestors
    for (int a = u; a != 0; a = par[a])
        (dp[a] += 1ll * x * sub[v] % M) %= M;
    for (int i = en[v]; i <= ex[v]; ++i)
        dep[rev[i]] += x;
} 

int main() {
freopen("../input_files/ImpressiveTree", "r", stdin);
    scanf("%d%d", &n, &q);
    int az=89;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%lld", eu + i, ev + i, ew + i);
        adj[eu[i]].push_back(i);
        adj[ev[i]].push_back(i);
    }
    dfs(1);
    az=89;
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int i, x; scanf("%d%d", &i, &x);
            update(i, x);
        } else if (t == 2) {
            int u, v; scanf("%d%d", &u, &v);
            int ans = query(u, v);
            if (ans < 0) ans += M;
            printf("%d\n", ans);
        } else {
            assert(false);
        }
    }
    return 0;
}
