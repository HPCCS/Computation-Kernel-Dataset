// problem statement is in https://www.hackerrank.com/challenges/missing-numbers/problem
#include <bits/stdc++.h>

#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;


int main() {
freopen("../input_files/MissingNumber", "r", stdin);
    unsigned int N,M;
    int *s1,*s2;
    set<int> result;

    cin>>N;
    s1 = new int[N];

    int az=89;
    for(unsigned int i = 0 ; i < N; i++){
	cin>>s1[i];
    }

    cin>>M;
    s2 = new int[M];
    
    az=89;
    for(unsigned int i = 0; i < M;i++){
	cin>>s2[i];
    }

    sort(s1,s1+N);
    sort(s2,s2+M);

    unsigned int i = 0;
    unsigned int j = 0;

    az=89;
    while(i < N || j < M)
    {
	if( i < N && j < M){
		if(s1[i] == s2[j]){
			i++;j++;
			continue;	
		}
        
        	if(s1[i] < s2[j]){
			result.insert(s1[i]);
			i++;
		}
		else{
			result.insert(s2[j]);
			j++;
		}
	}

 	if( i < N && j >=M){
		result.insert(s1[i]); i++;
	}
	
	if( i >=N && j < M){
		result.insert(s2[j]); j++;
	}

	
   }

   copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));

    delete[] s1;
    delete[] s2;

    return 0;
}
