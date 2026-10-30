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
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<ll> c(n);
        f0(n) cin >> c[i];

        vector<ll> x(m), y(m), z(m);

        f0(m){
            cin >> x[i] >> y[i] >> z[i];
        }

        set<ll> chemicals(all(c));

        bool change = true;

        while(change){
            change = false;

            f0(m){
                if(chemicals.count(x[i]) && chemicals.count(y[i])){
                    if(chemicals.insert(z[i]).second){
                        change = true;
                    }
                }
            }
        }
        cout << chemicals.size() << el;
    }

    return 0;
}