#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define sp << " "
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;
const ll ROOT = 3;

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}

void ntt(vector<ll> &a, bool invert){
    int n = a.size();

    for(int i=1,j=0;i<n;i++){
        int bit = n/2;

        for(;j&bit;bit>>=1) j ^= bit;
        j ^= bit;

        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1){
        ll wlen = power(ROOT,(MOD-1)/len);

        if(invert) wlen = power(wlen,MOD-2);

        for(int i=0;i<n;i+=len){
            ll w = 1;

            for(int j=0;j<len/2;j++){
                ll u = a[i+j];
                ll v = a[i+j+len/2]*w%MOD;

                a[i+j] = (u+v)%MOD;
                a[i+j+len/2] = (u-v+MOD)%MOD;

                w = w*wlen%MOD;
            }
        }
    }

    if(invert){
        ll inv = power(n,MOD-2);

        for(ll &x:a){
            x = x*inv%MOD;
        }
    }
}

vector<ll> multiply(vector<ll> a, vector<ll> b){
    int need = a.size()+b.size()-1;
    int n = 1;

    while(n<need) n<<=1;

    a.resize(n);
    b.resize(n);

    ntt(a,false);
    ntt(b,false);

    for(int i=0;i<n;i++){
        a[i] = a[i]*b[i]%MOD;
    }

    ntt(a,true);
    a.resize(need);

    return a;
}

vector<ll> solve(vector<vector<ll>> &v, int l, int r){
    if(l==r) return v[l];

    int mid = (l+r)/2;

    vector<ll> a = solve(v,l,mid);
    vector<ll> b = solve(v,mid+1,r);

    return multiply(a,b);
}

int main(){
    fast

    int t;
    cin >> t;

    while(t--){
        int n,q;
        cin >> n >> q;

        vector<int> a(n);
        vector<int> cnt(n+1,0);

        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }

        vector<vector<ll>> p0,p1;

        for(int i=1;i<=n;i++){
            if(cnt[i]==0) continue;

            ll c = cnt[i];

            ll x = power(2,c);
            ll y = power(3,c);
            ll z = power(4,c);

            p0.pb({
                1,
                2*(x-1)%MOD,
                (y-2*x%MOD+1+MOD)%MOD
            });

            p1.pb({
                x,
                2*(y-x+MOD)%MOD,
                (z-2*y%MOD+x+MOD)%MOD
            });
        }

        int d = p0.size();

        vector<ll> A = solve(p0,0,d-1);
        vector<ll> B = solve(p1,0,d-1);

        vector<ll> ans(2*d+2,0);

        for(int i=0;i<(int)A.size();i++){
            ans[i] = (ans[i]+A[i])%MOD;
            ans[i+1] = (ans[i+1]-A[i]+MOD)%MOD;
        }

        for(int i=0;i<(int)B.size();i++){
            ans[i+1] = (ans[i+1]+B[i])%MOD;
        }

        vector<ll> pref(2*d+2,0);

        for(int i=0;i<(int)ans.size();i++){
            pref[i] = ans[i];

            if(i>0){
                pref[i] = (pref[i]+pref[i-1])%MOD;
            }
        }

        while(q--){
            int k;
            cin >> k;

            ll res = 0;

            for(int i=0;i<(int)ans.size();i+=k){
                res = (res+ans[i])%MOD;
            }

            cout << res << el;
        }
    }

    return 0;
}