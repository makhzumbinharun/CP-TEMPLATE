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
    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> v;

    f1(n){
        ll x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());

    int i = 0;
    int j = n -1;

    while(i < j){
        ll sum = v[i].first + v[j].first;
        if(sum == x){
            cout << v[j].second << " " << v[i].second << el;
            return 0;
        }
        else if(sum < x) i++;
        else j--;
    }

    cout << "IMPOSSIBLE" << el;
    
    return 0;
}