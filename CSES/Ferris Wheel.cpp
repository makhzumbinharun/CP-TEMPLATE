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
    ll n, x;
    vector<ll>p;
    
    cin >> n >> x;
    f0(n){
        ll a;
        cin >> a;
        p.push_back(a);
    }
    
    sort(p.begin(), p.end());

    int l = 0;
    int r = n - 1;
    int g = 0;

    while(l <= r){
        if(p[l] + p[r] <= x){
            l++; r--;
        }
        else r--;
        g++;
    }

    cout << g << el;
    
    return 0;
}
