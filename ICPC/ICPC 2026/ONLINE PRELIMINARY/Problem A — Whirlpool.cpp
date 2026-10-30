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
#define f0(n) for(int i = 0; i < n; i++)
#define f1(n) for(int i = 1; i < n; i++)

int main(){
    fast

    int T;
    cin >> T;

    while(T--){
        int n, a, b;
        cin >> n >> a >> b;

        vector<ll> x(n), y(n), w(n);

        f0(n) cin >> x[i];
        f0(n) cin >> y[i];
        f0(n) cin >> w[i];

        map<pair<ll,ll>, ll> mp;

        f0(n){
            for(int j = 0; j < n; j++){
                ll X = x[j] - 1LL * a * x[i] + 1LL * b * y[i];
                ll Y = y[j] - 1LL * b * x[i] - 1LL * a * y[i];

                mp[{X, Y}] += w[i];
            }
        }

        ll ans = 0;

        for(auto i : mp){
            ans = max(ans, i.second);
        }

        cout << ans << el;
    }

    return 0;
}