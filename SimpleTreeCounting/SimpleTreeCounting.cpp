// problem statment is in https://www.hackerrank.com/contests/university-codesprint-3/challenges/simple-tree-counting/problem
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

#define N 800000
struct T {
  bool rr;
  T *son[2], *pf, *fa;
  int sum, vsum;
} f1[N], *ff = f1, *f[N], *null;
int n, q;
int a[N], b[N], c[N];
map <pair<int, int>, T*> Map;

long long B[1100000];

void add(int x, long long y) {
    for (; x <= 1000000; x += x & -x)
        B[x] += y;
}

long long query(int x) {
    long long ans = 0;
    for (; x; x -= x & -x)
        ans += B[x];
    return ans;
}

T* get(int a, int c) {
    if (Map.count(make_pair(a, c))) {
        return Map[make_pair(a, c)];
    }else {
        Map[make_pair(a, c)] = ++ff;
        ff -> son[0] = ff -> son[1] = ff -> fa = ff -> pf = null;
        ff -> rr = false;
        ff -> vsum = 0;
        ff -> sum = 1;
        return ff;
    }
}

void downdate(T *x) {
  if (x -> rr) {
    x -> son[0] -> rr = !x -> son[0] -> rr;
    x -> son[1] -> rr = !x -> son[1] -> rr;
    swap(x -> son[0], x -> son[1]);
    x -> rr = false;
  }
}

void update(T *x) {
    x -> sum = x -> son[0] -> sum + x -> son[1] -> sum + 1 + x -> vsum;
}

void rotate(T *x, bool t) {
  T *y = x -> fa, *z = y -> fa;
  if (z != null)  z -> son[z -> son[1] == y] = x;
  x -> fa = z;
  y -> son[t] = x -> son[!t];
  x -> son[!t] -> fa = y;
  x -> son[!t] = y;
  y -> fa = x;
  update(y);
}

void xiao(T *x) {
  if (x -> fa != null)  xiao(x -> fa), x -> pf = x -> fa -> pf;
  downdate(x);
}

void splay(T *x) {
  xiao(x);
  T *y, *z;
  while (x -> fa != null) {
    y = x -> fa; z = y -> fa;
    bool t1 = (y -> son[1] == x), t2 = (z -> son[1] == y);
    if (z != null) {
      if (t1 == t2) rotate(y, t2), rotate(x, t1);
      else  rotate(x, t1), rotate(x, t2);
    }else rotate(x, t1);
  }
  update(x);
}

void access(T *x) {
  splay(x);
  x -> son[1] -> pf = x;
  x -> son[1] -> fa = null;
  x -> vsum += x -> son[1] -> sum;
  x -> son[1] = null;
  update(x);
  while (x -> pf != null) {
    splay(x -> pf);
    x -> pf -> son[1] -> pf = x -> pf;
    x -> pf -> vsum += x -> pf -> son[1] -> sum;
    x -> pf -> vsum -= x -> sum;
    x -> pf -> son[1] -> fa = null;
    x -> pf -> son[1] = x;
    x -> fa = x -> pf;
    splay(x);
  }
  x -> rr = true;
}

void Cut(int a, int b, int c) {
    T *x = get(a, c);
    T *y = get(b, c);
    access(x);
    access(y);
    downdate(y);
    downdate(x);
    y -> son[1] = null;
    x -> pf -> vsum -= x -> sum;
    x -> fa = x -> pf = null;
    update(x);
    add(c, -1LL * x -> sum * y -> sum);
}

void Link(int a, int b, int c) {
    T *x = get(a, c);
    T *y = get(b, c);
    access(x);
    access(y);
    add(c, 1LL * x -> sum * y -> sum);
    x -> pf = y;
    y -> vsum += x -> sum;
    update(y);
}

int main() {
freopen("../input_files/SimpleTreeCounting", "r", stdin);
  scanf("%d", &n);
  null = new T; null -> son[0] = null -> son[1] = null -> fa = null -> pf = null;
  null -> sum = 0; null -> vsum = 0;
  int az=89;
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    Link(a[i], b[i], c[i]);
  }
  scanf("%d", &q);
  az=89;
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
        int i, cc;
        scanf("%d%d", &i, &cc);
        Cut(a[i], b[i], c[i]);
        c[i] = cc;
        Link(a[i], b[i], c[i]);
    }else if (op == 2) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", query(r) - query(l - 1));
    }else  {
        int i;
        scanf("%d", &i);
        T *v = get(a[i], c[i]);
        access(v);
        int k = v -> sum;
        printf("%lld\n", 1LL * k * (k - 1) / 2);
    }
  }
  return 0;
}
