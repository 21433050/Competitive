
Selected submissions: 
-
  ?
×
Source code 29713701
SPOJ submission 29713701 (CPP14) plaintext list. Status: AC, problem ABCPATH, contest SPOJ. By abhi_kasana20 (abhi_kasana20), 2022-06-22 11:20:57.
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n,m; 
 int dp[51][51];
vector<pair<int,int>>movements={{0,1},{0,-1},{-1,0},{1,0},{1,-1},{1,1},{-1,-1},{-1,1}};
 int dfs(int i,int j,vector<vector<char>>&a,char c){
      if(dp[i][j]!=-1)return dp[i][j];
      int maxi=1;
 
    for(auto movement:movements){
        int x=i+movement.first;
        int y=j+movement.second;
        if(x>=0 && y>=0 && y<m && x<n and a[x][y]==c){
          
           maxi=max(1+dfs(x,y,a,c+1),maxi);
          
        }
    }
    return dp[i][j]=maxi;
 }
 
int32_t main(){
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
fast
   int t=1;
  //  cin>>t;
   while (1)
   {
      cin>>n>>m;
      if(n==0 and m==0)break;
      vector<vector<char>>a(n,vector<char>(m));
      memset(dp,-1,sizeof(dp));
      bool exist=0;
      vector<pair<int,int>>starts;
      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j < m; j++)
          {
            cin>>a[i][j];
            if(a[i][j]=='A'){exist=1;
            starts.push_back({i,j});
            }
 
          }
    }
     
        int maxi=0;
      for(int i=0;i<starts.size();i++){
          maxi=max(maxi,dfs(starts[i].first,starts[i].second,a,'B'));
      }
      cout<<"Case "<<t<<": "<<maxi<<'\n';
     
t++;
   }
   
  return 0;
}   
