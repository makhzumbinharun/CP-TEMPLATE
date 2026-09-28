#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define sp << " "
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f(x) for(auto i : x)
#define f0(N) for(int i = 0; i < N; i++)
#define f1(n) for(int i = 1; i < n; i++)


int main(){
    fast
    ll n, sum = 0;
    cin >> n;
    map <ll,ll> time;

    while (n--) {
        ll a,b ; cin >> a >> b;
        auto it = time.find(a);

        if (it != time.end()) {
           ll x = it->second;
           x++;
           it->second = x;
        }
        else {
            time[a]=1;
        }
        it = time.find(b);
        if (it != time.end()) {
           ll x = it->second;
           --x;
           it->second = x;
        }
        else {
            time[b]=-1;
        }
    }
    
    vector <ll> presum;
    f(time){
        sum += i.second;
        presum.push_back(sum);
        
    }
    cout << *max_element(presum.begin(),presum.end());
    return 0;
    
}
