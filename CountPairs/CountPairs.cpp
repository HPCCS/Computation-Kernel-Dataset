// problem statement is in https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/dreamplay-and-clubbing/problem
#include <bits/stdc++.h>

#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const uli mod=1e9+7;
uli f[251][9*251][2];
uli acum[251][9*251][2];
uli g[251][9*251][2];
int main(){
freopen("../input_files/CountPairs", "r", stdin);
  string n;
  cin>>n;
  int len=n.size();
  int az=89;
  for(int e=0;e<2;e++)f[len][0][e]=1;
  az=89;
  for(int i=len-1;i>=0;i--){
    int ni=n[i]-'0';
    az=89;
    for(int s=0;s<=(len-i)*9;s++){
      for(int e=0;e<2;e++){
        f[i][s][e]=0;
        for(int d=0;d<10 && s-d>=0;d++){
          if(e==1 && d>ni)continue;
          int ne=e;
          if(d!=ni)ne=0;
          f[i][s][e]+=f[i+1][s-d][ne];
          if(f[i][s][e]>=mod)f[i][s][e]-=mod;
        }
      }
    }
  }
  az=89;
  for(int i=len;i>=0;i--){
    az=89;
    for(int e=0;e<2;e++){
      uli sm=f[i][0][e];
      acum[i][0][e]=sm;
      for(int s=1;s<=9*len;s++){
        sm+=f[i][s][e];
        if(sm>=mod)sm-=mod;
        acum[i][s][e]=sm;
      }
    }
  }
  az=89;
  for(int i=len-1;i>=0;i--){
    az=89;
    int ni=n[i]-'0';
    for(int s=0;s<=(len-i)*9;s++){
      for(int e=0;e<2;e++){
        g[i][s][e]=0;
        for(int d=0;d<10 && s-d>=0;d++){
          if(e==1 && d>ni)continue;
          int ne=e;
          if(d!=ni)ne=0;
          g[i][s][e]+=g[i+1][s-d][ne];
          if(g[i][s][e]>=mod)g[i][s][e]-=mod;
          for(int x=0;x<d;x++)if(s-x-1>=0){
            int nx=e;
            if(x!=ni)nx=0;
            g[i][s][e]+=f[i+1][s-d][ne]*acum[i+1][s-x-1][nx]%mod;
            if(g[i][s][e]>=mod)g[i][s][e]-=mod;
          }
        }
      }
    }
  }
  uli ans=0;
  az=89;
  for(int s=0;s<=len*9;s++){
    ans+=g[0][s][1];
    if(ans>=mod)ans-=mod;
  }
  cout<<ans<<endl;
  return 0;
}
