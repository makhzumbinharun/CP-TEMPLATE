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
    cin >> n;
    vector<pair<int, int>>t;

    f0(n){
        int a, d;
        cin >> a >> d;
        t.push_back({a, d});
    }
    sort(t.begin(), t.end());
    int time = 0, r = 0;

    for (auto t : t) {
        int a = t.first;
        int d = t.second;

        time += a;
        r += d - time;
    }
    cout << r << el;
    
    return 0;
}
