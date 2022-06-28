#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxk=25;
const int N=2e5+5;
int st[N][maxk+1];

int32_t main(){
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
fast
   int t=1;
  //  cin>>t;
   while (t--)
   {
    int n,q;cin>>n;
    int a[1+n]={0};
     for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    cin>>q;
   for(int i=0;i<n;i++){
      st[i][0]=a[i];
   }
   for(int k=1;k<=maxk;k++){
      for(int i=0;i+(1<<k)<=n;i++){
         st[i][k]=min(st[i][k-1],st[i+(1<<k-1)][k-1]);
      }
   }
   int lg[n+1];
   lg[1]=0;
   for(int i=2;i<=n;i++){
      lg[i]=lg[i/2]+1;
   }
    while(q--){
       int l,r;cin>>l>>r;
      int j=lg[r-l+1];
      int ans=min(st[l][j],st[r-(1<<j)+1][j]);
      cout<<ans<<'\n';
    }

   }
   
  return 0;
}