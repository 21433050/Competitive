#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


 void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
     vis[node]=1;
      for(auto it:adj[node]){
        if(vis[it]==1)continue;
        dfs(it,vis,adj,st);
      }
      st.push(node);
 }
 void revdfs(int node,vector<int>&vis,vector<int>trans[],int &cnt,int ans[]){
  vis[node]=1;
  ans[node]=cnt;
  for(auto it:trans[node]){
    if(vis[it])continue;
    revdfs(it,vis,trans,cnt,ans);
  }
 }
int32_t main(){
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
fast
   int t=1;
  //  cin>>t;
   while (t--)
   {  int n,m;cin>>n>>m;
    vector<int>adj[n+1];
    for (int i = 0; i <m; i++)
    { int a,b;
      cin>>a>>b;
    adj[a].push_back(b);
    }
    vector<int>vis(n+1,0);
    stack<int>st;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
          dfs(i,vis,adj,st);
        }
    }
    
    vector<int>trans[n+1];
    for(int i=1;i<=n;i++){
      vis[i]=0;
        for(auto it:adj[i]){
            trans[it].push_back(i);
        }
    }
    int cnt=1;
    int ans[n+1];
    int lastNode;
  while(!st.empty()){
    int node=st.top();
    lastNode=node;
    st.pop();
    if(vis[node]==0){revdfs(node,vis,trans,cnt,ans);cnt++;}
  }
  int num=ans[lastNode];
  vector<int>capital;
  for(int i=1;i<=n;i++){
    if(ans[i]==num)capital.push_back(i);
  }
cout<<capital.size()<<'\n';
for(auto it:capital)cout<<it<<' ';
   }
   
  return 0;
}
