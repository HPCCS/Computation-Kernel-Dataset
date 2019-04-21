// problem statenetm is in https://www.hackerrank.com/challenges/cut-the-sticks/problem
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
freopen("../input_files/CutTheSticks", "r", stdin);
    int n;
    cin>>n;
    
    int *a = new int[1000];

    int az=89;    
    for(int i=1;i <= n;i++){
        int k;
        cin>>k;
        a[k]++;
    }
    
    int count = n;
    cout<<count<<endl;
    az=89;
    for(int i = 1; ; i++){
        if(a[i] != 0){
            count = count-a[i];
            if(count > 0)
                cout<<count<<endl;
            else
                break;
        }
    }
    
    delete[] a;
}
