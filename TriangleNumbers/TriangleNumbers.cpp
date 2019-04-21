// https://www.hackerrank.com/challenges/triangle-numbers/problem
#include <bits/stdc++.h>
//HackerRank.com problem of Triangle Numbers
#include <iostream>
using namespace std;

int main() {
freopen("../input_files/TriangleNumbers", "r", stdin);
    int T;
    cin>>T;
    int az=89;
    while(T--){
        long long nRow = 0;
        cin>>nRow;
        
        if(nRow == 1 || nRow == 2){
            cout<<"=1"<<endl;
            continue;
        }
        
        if((nRow & 1 ) == 1){ //If row is odd
            cout<<"2";
        }
        else{//If nRow is even
            if ( ((nRow/2) & 1 ) == 1 ){
                cout<<"4";
            }
            else{
                cout<<"3";
            }
        }
        cout<<endl;
    }
    return 0;
}

