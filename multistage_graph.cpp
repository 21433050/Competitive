#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX INT_MAX
#define pb push_back
int32_t main()
{
    int n;
    cout<<"Enter the number of nodes"<<"\n";
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> matrix(n+1,vector<int>(n+1,-1));

    for(int i=1;i<=n;i++){
        for(int j = 1 ; j <= n ; j++) matrix[i][j] = MAX;
    }

    cout<<"Enter in the format to, from, weight"<<"\n";
    for(int i = 0 ; i < m ; i++){
        int x,y,w;
        cin>>x>>y>>w;
        matrix[x][y] = w;
    }

    for(int i = 1 ; i <= n ; i++) matrix[i][i]=0;

    cout<<"Enter the source vertex"<<"\n";
    int s,d;
    cin>>s;
    cout<<"Enter the destination vertex"<<"\n";
    cin>>d;

    vector<int>cost(n+1,MAX);
    vector<int>dp(n+1,-1);
    cost[d] = 0;
    for(int i=n;i>=1;i--){

        for(int j = 1 ; j <= n ; j++){
            if(matrix[i][j] != MAX){
                cost[i] = min(cost[i],matrix[i][j]+cost[j]);
            }
        }
        for(int j = 1 ; j <= n ; j++){
            if(matrix[i][j] != MAX){
                if(cost[i] == (matrix[i][j]+cost[j])) 
                    dp[i] = j;
            }
        }

    }
    cout<<"Shortest path from src to dest"<<"\n";
    cout<<cost[s]<<"\n";

    vector<int>path;
    path.pb(s);
    int temp = s;
    while(temp!=d){
        temp = dp[temp];
        path.pb(temp);
    }

    cout<<"Path from src to dest\n";
    for(int i = 0 ; i < path.size() ; i++) cout<<path[i]<<" ";
    cout<<"\n";
}