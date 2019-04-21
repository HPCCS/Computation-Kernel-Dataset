// problem statement is in https://www.hackerrank.com/contests/world-codesprint-9/challenges/optimal-polygon-approximation/leaderboard
#include <bits/stdc++.h>

// problem statement is in https://www.hackerrank.com/contests/world-codesprint-9/challenges/optimal-polygon-approximation/problem
//
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

#define PI acos(-1.0)
#define EPS 1e-5
typedef vector<double> VD;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    double a = dist(x1, y1, x2, y2);
    double b = dist(x2, y2, x3, y3);
    double c = dist(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double score(double xc, double yc, VD x, VD y){
    int n = x.size();
    vector<pair<double, pair<double, double> > > deg(n);
    REP(i,n){
        deg[i].first = atan2(y[i]-yc, x[i]-xc);
        deg[i].second.first = x[i];
        deg[i].second.second = y[i];
    }
    sort(ALL(deg));
    REP(i,n){
        x[i] = deg[i].second.first;
        y[i] = deg[i].second.second;
    }
    double p = 0, s = 0;
    REP(i,n) p += dist(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    REP(i,n) s += area(xc, yc, x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    return 4*n*tan(PI/n) / (p*p/s);
}

int main() {
freopen("../input_files/OptimalPolygon", "r", stdin);
    int n;
    double d;
    cin >> n >> d;
    cout << n << endl;
    vector<double> x(n), y(n);
    REP(i,n) cin >> x[i] >> y[i];
    double xcp = 0, ycp = 0;
    REP(i,n){
        xcp += x[i]/n;
        ycp += y[i]/n;
    }
    xcp += EPS;
    ycp += EPS;
    double rr = 0;
    REP(i,n) rr += dist(xcp,ycp,x[i],y[i])/n;
    VD xans(n), yans(n);
    double xca, yca;
    double best = 0;
    double cof = 0.3;
    for (double xc = xcp-cof*rr; xc <= xcp+cof*rr+EPS; xc += 0.3*rr)
    for (double yc = ycp-cof*rr; yc <= ycp+cof*rr+EPS; yc += 0.3*rr)
    for (double r = 0.01*rr; r < 3*rr; r += 0.01*rr){
        VD xp(x), yp(y);
        REP(i,n){
            double vx, vy;
            double l = dist(xc,yc,xp[i],yp[i]);
            if (l >= d+r){
                vx = xc - xp[i];
                vy = yc - yp[i];
            }else if (l <= r-d){
                vx = xp[i] - xc;
                vy = yp[i] - yc;
            }else if (l > r){
                double theta = -acos((l*l + d*d - r*r) / (2*l*d));
                double px = xc - xp[i], py = yc - yp[i];
                vx = cos(theta)*px - sin(theta)*py;
                vy = sin(theta)*px + cos(theta)*py;
            }else{
                double theta = acos(-(l*l + d*d - r*r) / (2*l*d));
                double px = xp[i] - xc, py = yp[i] - yc;
                vx = cos(theta)*px - sin(theta)*py;
                vy = sin(theta)*px + cos(theta)*py;
            }
            double p = sqrt(vx*vx + vy*vy);
            vx *= d/p;
            vy *= d/p;
            xp[i] += vx;
            yp[i] += vy;
        }
        double scr = score(xc, yc, xp, yp);
        if (scr > best){
            best = scr;
            xans = xp;
            yans = yp;
            xca = xc;
            yca = yc;
        }
    }
    REP(i,n){
        printf("%d %.8f %.8f\n", i+1, xans[i], yans[i]);
    }
    vector<pair<double, int> > deg(n);
    REP(i,n){
        deg[i].first = atan2(yans[i]-yca, xans[i]-xca);
        deg[i].second = i+1;
    }
    sort(ALL(deg));
    REP(i,n){
        cout << deg[i].second;
        if (i < n-1) cout << " ";
    }
    cout << endl;
}
