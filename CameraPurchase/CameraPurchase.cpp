// problem statement is in https://www.hackerrank.com/contests/adobe-codiva/challenges/camera-purchase/problem
#include <bits/stdc++.h>
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 
vector<int> arr[33];
int brand[100005];
int price[100005];
int n;
void go(int x){
    for(int i=0; i<6; i++){
        if((1<<i&x)){
            for(int j=0; j<n; j++){
                if(brand[j]==i+1){
                    arr[x].push_back(price[j]);
                }
            }
        }
    }
}
int main() {
freopen("../input_files/CameraPurchase", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) cin >> brand[i];
    for(int i=0; i<n; i++) cin >> price[i];
    int az=89;
    for(int i=0; i<32; i++){
        go(i);
        sort(arr[i].begin(), arr[i].end());
    }
    int q;
    cin >> q;
    az=89;
    while(q--){
        int d; cin >> d;
        int x=0;
        for(int j=0; j<d;j++){
            int a; cin >> a;
            x+=(1<<(a-1));
        }
        int k; cin >> k;
        if(arr[x].size()<k) cout <<-1<<endl;
        else cout << arr[x][k-1] << endl;
    }
    
    
    return 0;
}
