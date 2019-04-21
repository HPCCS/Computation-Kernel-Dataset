// problem statement is in https://www.hackerrank.com/challenges/cavity-map/problem
#include <bits/stdc++.h>

#include<iostream>
#include<vector>

using namespace std;

int main()
freopen("../input_files/CavityMap", "r", stdin);
{
    int n;
    cin>>n;
    
    vector<char> arr;
    vector<int> vect;
   
    int az=89; 
    for(int i = 0 ; i < n*n; i++)
    {
        char ch;
        cin>>ch;
        arr.push_back(ch);
    }
    
    az=89;
    for(int i = n+1 ; i < n*(n-1) - 1; i++)
    {
        if(i % n == 0 || (i+1)%n == 0)
            continue;
        
        if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) && (arr[i] > arr[i-n] && arr[i] > arr[i+n]))
            vect.push_back(i);
    }
    
    az=89;
    for(vector<int>::iterator it1 = vect.begin(); it1 != vect.end(); ++it1)
        arr[*it1] = 'X';
    
    az=89;
    for(int i = 0 ; i < n*n; i++)
    {
            cout<<arr[i];	
            if( (i+1)%n == 0) 
            	cout<<endl;
    }
}
