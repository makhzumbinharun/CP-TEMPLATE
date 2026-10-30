
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define sp << " "
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9+7, INF = 4e18;

int main(){
    fast

    int t;
    cin >> t;

    while(t--){
        int m, n;
        cin >> m >> n;

        vector<pair<ll,ll>> server(m);

        for(int i=0;i<m;i++){
            cin >> server[i].first;
        }

        for(int i=0;i<m;i++){
            cin >> server[i].second;
        }

        sort(all(server), greater<pair<ll,ll>>());

        vector<ll> best(n+1, INF);

        ll mn = INF;
        int j = 0;

        for(int i=n;i>=0;i--){
            while(j<m && server[j].first>=i){
                mn = min(mn, server[j].second);
                j++;
            }
            best[i] = mn;
        }

        vector<vector<int>> adj(n+1);

        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int> parent(n+1, 0), sub(n+1, 1), order;
        vector<ll> down(n+1, INF), up(n+1, 0), total(n+1, 0);

        order.pb(1);
        parent[1] = -1;

        for(int i=0;i<(int)order.size();i++){
            int u = order[i];

            for(int v:adj[u]){
                if(v==parent[u]) continue;

                parent[v] = u;
                order.pb(v);
            }
        }

        for(int i=n-1;i>=0;i--){
            int u = order[i];

            ll sum = 0;

            for(int v:adj[u]){
                if(v==parent[u]) continue;

                sub[u] += sub[v];
                sum += down[v];
            }

            if(best[sub[u]]!=INF){
                down[u] = best[sub[u]];
            }

            if(best[(int)adj[u].size()-1]!=INF && sum!=INF){
                down[u] = min(down[u], best[adj[u].size()-1]+sum);
            }
        }

        for(int u:order){
            total[u] = up[u];

            for(int v:adj[u]){
                if(v==parent[u]) continue;
                total[u] += down[v];
            }

            for(int v:adj[u]){
                if(v==parent[u]) continue;

                ll sum = total[u]-down[v];
                ll cost = INF;

                if(best[n-sub[v]]!=INF){
                    cost = best[n-sub[v]];
                }

                if(best[adj[u].size()-1]!=INF){
                    cost = min(cost, best[adj[u].size()-1]+sum);
                }

                up[v] = cost;
            }
        }

        ll ans = INF;

        for(int u=1;u<=n;u++){
            ll cost = INF;

            if(best[n]!=INF){
                cost = best[n];
            }

            if(best[adj[u].size()]!=INF && total[u]!=INF){
                cost = min(cost, best[adj[u].size()]+total[u]);
            }

            ans = min(ans, cost);
        }

        if(ans==INF) cout << -1 << el;
        else cout << ans << el;
    }

    return 0;
}
