#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(n) for(int i = 0; i < n; i++)
#define f1(n) for(int i = 1; i <= n; i++)

int main(){
    fast
   ll n, m;
    cin >> n >> m;
    multiset<ll>p;
    
    f0(n){
        ll a;
        cin >> a;
        p.insert(a);
    }
    
    f0(m){
        ll x; 
        cin >> x;
        auto it = p.upper_bound(x);
        
        if(it == p.begin())  cout << -1 << el;
        else{
            it--;
            cout << *it << el;
            p.erase(it);
        }
    }
    
    return 0;
}
