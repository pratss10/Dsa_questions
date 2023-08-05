#include<bits/stdc++.h>
#define ll long long int
#define fi(n) for(ll i=1; i<=n; i++)

using namespace std;
// this code calculates the minimum number of swaps to sort a permutation of n
// i am using the technique where i count the number of cycles in graph and add the summation of cycle-1
// i saw this question at an OA hope this helps

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n; cin >> n;
  vector<int> a(n+1);
  fi(n){
    cin >> a[i];
  }
  map<int,int> m;
  fi(n){
    m[a[i]]=i;
  }
  int ans = 0;
  vector<bool> vis(n+1, false);
  fi(n){
    if(vis[i]|| m[i]==i){
      continue;
    }
    
    int j = i;
    int cycle = 0;
    while(!vis[j]){
      vis[j] = true;
      
      j = m[j];
      cycle++;
    }
    ans += cycle-1;
  }
  cout << ans;
  return 0;
}

