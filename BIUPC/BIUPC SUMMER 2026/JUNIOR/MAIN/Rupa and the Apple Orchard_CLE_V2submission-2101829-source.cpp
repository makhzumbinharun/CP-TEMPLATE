#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(n) for(int i = 0; i < n; i++);
#define f1(n) for(int i = 1; i < n; i++);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        vector < ll > apple(n);
        for(ll i=0 ; i<n ; i++){
            cin >> apple[i];
        }

        for(ll j = 0 ; j<q ; j++ ){
            ll a,b,flag=0;
            cin >> a >> b;
            for(ll i=a-1 ; i<b ; i++){
                if(apple[i] > 0){
                    flag++;
                }
            }
            cout << flag << endl;
        }
    }


    return 0;
}
