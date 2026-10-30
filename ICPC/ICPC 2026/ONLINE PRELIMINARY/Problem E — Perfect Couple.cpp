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

    bitset<100> good[101][100];

    for(int m = 2; m <= 100; m++){
        for(int x = 0; x < m; x++){
            for(int y = 0; y < m; y++){
                ll val = 1LL*x*x*x*y - 1LL*x*y*y*y;

                if(val % m == 0){
                    good[m][x][y] = 1;
                }
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        vector<ll> trheeca(n+1);

        for(int i = 1; i <= n; i++){
            cin >> trheeca[i];
        }

        while(q--){
            int l, r, m;
            cin >> l >> r >> m;

            int len = r-l+1;
            int ans1 = -1, ans2 = -1;

            if(len > m){
                vector<int> seen(m, -1);

                for(int i = l; i <= l+m; i++){
                    int rem = trheeca[i] % m;

                    if(seen[rem] != -1){
                        ans1 = seen[rem];
                        ans2 = i;
                        break;
                    }

                    seen[rem] = i;
                }
            }
            else{
                vector<int> pos(m, -1);
                bitset<100> present;

                for(int i = l; i <= r; i++){
                    int rem = trheeca[i] % m;

                    pos[rem] = i;
                    present[rem] = 1;
                }

                for(int x = 0; x < m; x++){
                    if(!present[x]) continue;

                    bitset<100> cur = good[m][x] & present;
                    cur[x] = 0;

                    if(cur.any()){
                        int y = -1;

                        for(int j = 0; j < m; j++){
                            if(cur[j]){
                                y = j;
                                break;
                            }
                        }

                        ans1 = pos[x];
                        ans2 = pos[y];
                        break;
                    }
                }
            }

            if(ans1 == -1){
                cout << -1 << el;
            }
            else{
                cout << ans1 sp << ans2 << el;
            }
        }
    }

    return 0;
}