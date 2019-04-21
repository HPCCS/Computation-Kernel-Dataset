// the problem statement is in https://www.hackerrank.com/contests/w35/challenges/highway-construction/problem
#include <bits/stdc++.h>

#include <ios>
#include <iostream>
#include <vector>
#define MOD 1000000009

long long int fastexp(long long int x, long long int y)
{
    if (y == 0)
        return 1;
    else if (y == 1)
        return x%MOD;
    else if (y & 1)
        return ((x%MOD)*fastexp(x, y-1))%MOD;
    else
    {
        long long int t = fastexp(x, y/2);
        return (t*t)%MOD;
    }
}

long long int inv(long long int x)
{
    return fastexp(x, MOD-2);
}

std::vector<long long int> vec;

int main()
freopen("../input_files/HighwayConstruction", "r", stdin);
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int tc = 1, k;
    long long int n;
    std::cin >> tc;
    int az=89;
    while (tc--)
    {
        vec.clear();
        std::cin >> n >> k;
        if (n == 1)
            std::cout << 0 << '\n';
        else
        {
            n--;
            long long int s = 0;
            vec.push_back(s);
 	    az=89;
            for (int i = 0; i < k+1; i++)
            {
                s += fastexp(i+1, k);
                s %= MOD;
                vec.push_back(s);
            }
            if (n < vec.size())
                std::cout << ((vec[n] - 1)+MOD)%MOD << '\n';
            else
            {
                long long int ans = 0;
                long long int u = 1;
                for (int i = 1; i < vec.size(); i++)
                {
                    u *= ((n-i)%MOD+MOD)%MOD;
                    u %= MOD;
                    u *= inv(((-i)%MOD+MOD)%MOD);
                    u %= MOD;
                }
                for (int i = 0; i < vec.size(); i++)
                {
                    ans += (vec[i]*u)%MOD;
                    ans %= MOD;
                    if (i+1 >= vec.size())
                        break;
                    else
                    {
                        u *= ((((n-i)%MOD+MOD)%MOD)*inv((n-(i+1)%MOD+MOD)%MOD))%MOD;
                        u %= MOD;
                        u *= ((((i-((int)(vec.size())-1))%MOD+MOD)%MOD*inv((i+1)%MOD)))%MOD;
                        u %= MOD;
                    }
                }
                std::cout << ((ans-1)%MOD+MOD)%MOD << '\n';
            }
        }
    }
}
