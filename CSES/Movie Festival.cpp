#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define sp << " "
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(N) for(int i = 0; i < N; i++)
#define f1(n) for(int i = 1; i < n; i++)


bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(){
    fast
    int n;
    cin >> n;
    vector<pair<int, int>>m;

    f0(n){
        int a, b;
        cin >> a >> b;
        m.push_back({a, b});
    }
    sort(m.begin(), m.end(), cmp);
    
    int lastEnd = 0;
    int count = 0;

    for (auto [start, end] : m) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }
    
    cout << count << el;
    
    return 0;
}
