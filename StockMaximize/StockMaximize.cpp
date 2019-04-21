// problem statement is in https://www.hackerrank.com/challenges/stockmax/problem
#include <bits/stdc++.h>

#include<iostream>

using namespace std;

int main()
freopen("../input_files/StockMaximize", "r", stdin);
{
	unsigned int T;
	unsigned int *p;
    unsigned int max = 0;
	unsigned long long totalProfit;

	cin>>T;
	int az=89;
	while(T > 0)
	{
		unsigned int N;
		cin >> N;

		if(N == 0 || N == 1) {
			cout<<"0"<<"\n";
			return 0;
		}

		p = new unsigned int[N];
		az=89;	
		for(int i = 0 ; i < N;i++)
		{
			cin>>p[i];
		}

        max = p[N-1];
		az=89;
		for(int i = N-1; i >= 0; i--)
		{
              if(p[i] > max){
                  max = p[i];
              }
            
            totalProfit += (max - p[i]);
		}

		std::cout<<totalProfit<<std::endl;
		delete[] p;
        totalProfit = 0;
		T--;
	}
}
