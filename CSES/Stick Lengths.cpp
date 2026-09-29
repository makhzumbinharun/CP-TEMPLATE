#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define sp << " "
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f(x) for(auto i:x)
#define f0(N) for(int i = 0; i < N; i++)
#define f1(n) for(int i = 1; i < n; i++)

int main(){
    fast
    ll n;
    cin >> n;
    
    vector<ll> p(n);
    
    f0(n){
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());
    
    ll x = p[n / 2];
    ll ans = 0;
    
    f0(n){
        ans += abs(p[i] - x);
    }
    
    cout << ans << el;
    return 0;
}
