// LC: 2333b Starters K Median
// Title: Starters K Median
// Difficulty: Easy
// Date: 13 April 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    int t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(auto& i: v){
            cin>>i;
        }
        sort(v.begin(),v.end());
        
        // for(auto i: v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        ll m = ((ll)(n - k)+(ll)1) / (ll)2;
        
        vector<int> ans;
        for(int i=0; i <= k;i++){
            if(ans.empty() || ans[ans.size()-1] != v[m-1])
            {
                ans.push_back(v[m-1]);
                
            }
                
            // cout<<v[m-1]<<" ";
            m++;
        }
        
        for(auto& i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
	// your code goes here

}
