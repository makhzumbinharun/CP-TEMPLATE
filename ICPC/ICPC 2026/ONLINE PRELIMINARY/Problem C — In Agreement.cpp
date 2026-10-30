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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<ll> a(n+1), sub(n+1);
        vector<vector<int>> adj(n+1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        f0(n-1){
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int> par(n+1, 0), order;
        order.pb(1);
        par[1] = -1;

        for(int i = 0; i < (int)order.size(); i++){
            int u = order[i];

            for(int v : adj[u]){
                if(v != par[u]){
                    par[v] = u;
                    order.pb(v);
                }
            }
        }

        ll S = 0;
        for(int i = 1; i <= n; i++){
            S += a[i];
        }

        for(int i = n-1; i >= 0; i--){
            int u = order[i];

            sub[u] += a[u];

            if(par[u] != -1){
                sub[par[u]] += sub[u];
            }
        }

        ll ans = 1;

        for(int u = 1; u <= n; u++){
            ll g = 0;

            for(int v : adj[u]){
                if(par[v] == u){
                    g = gcd(g, S - sub[v]);
                }
            }

            if(par[u] != -1){
                g = gcd(g, sub[u]);
            }

            ans = max(ans, g);
        }

        cout << ans << el;
    }

    return 0;
}