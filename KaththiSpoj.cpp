#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n,m; 
 
vector<pair<int,int>>movements={{0,1},{0,-1},{-1,0},{1,0}};

bool isValid(int i,int j){
  if(i>=0 && j>=0 && j<m && i<n)return true;
  return false;
}
 
 
int32_t main(){
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
fast
   int t=1;
   cin>>t;
   while (t--)
   {
     cin>>n>>m;
     char a[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
          cin>>a[i][j];
      }
    }
   deque<pair<int,int>>q;
   vector<vector<int>>dist(n,(vector<int>(m,INT_MAX)));
   dist[0][0]=0;
   q.push_front({0,0});
     while (!q.empty())
     {
        pair<int,int>p=q.front();
        int x=p.first;
        int y=p.second;
        q.pop_front();
        for(auto movement:movements){
          int x1=x+movement.first;
          int y1=y+movement.second;
          if(!isValid(x1,y1))continue;
         if(a[x1][y1]==a[x][y] and dist[x1][y1]>dist[x][y]){
          dist[x1][y1]=dist[x][y];
          q.push_front({x1,y1});
         }
        else if(a[x1][y1]!=a[x][y] and dist[x1][y1]>dist[x][y]+1){
          dist[x1][y1]=dist[x][y]+1;
          q.push_back({x1,y1});
        }
        }
     }
     cout<<dist[n-1][m-1]<<'\n';
    
   }
   
  return 0;
}  