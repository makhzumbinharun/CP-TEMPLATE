
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
        ll n, k, s;
        string target;
        cin >> n >> k >> s >> target;

        ll q = k + 1;

        if(target == "Alice"){
            if(s < n || (s == n && n % q == 0)){
                cout << -1 << el;
                continue;
            }

            for(int i = 1; i < n; i++){
                cout << 1 sp;
            }
            cout << s - n + 1 << el;
        }
        else{
            if(s < n || n < q || s % q != 0){
                cout << -1 << el;
                continue;
            }

            ll x = s / q;
            ll c = n / q;
            ll need = (n + q - 1) / q;

            vector<ll> cnt(61, 0);
            ll total = 0;

            for(int b = 0; b < 61 && x > 0; b++){
                ll take = min(x, c);

                if(take % 2 != x % 2){
                    take--;
                }

                cnt[b] = take;
                total += take;
                x = (x - take) / 2;
            }

            if(x > 0 || total < need){
                cout << -1 << el;
                continue;
            }

            vector<ll> a(n, 0);
            ll pos = 0;

            for(int b = 0; b < 61; b++){
                ll times = cnt[b] * q;

                for(ll j = 0; j < times; j++){
                    a[pos] += (1LL << b);
                    pos++;

                    if(pos == n) pos = 0;
                }
            }

            for(int i = 0; i < n; i++){
                cout << a[i] << (i == n - 1 ? el : ' ');
            }
        }
    }

    return 0;
}
