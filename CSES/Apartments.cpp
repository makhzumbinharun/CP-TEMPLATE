#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define el '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(n) for(int i = 0; i < n; i++)
#define f1(n) for(int i = 1; i < n; i++)

int main(){
    fast
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    f0(n){
        cin >> a[i];
    }
    
    vector<int> b(m);
    f0(m){
        cin >> b[i];
    }
    
    sort(all(a));
    sort(all(b));
    
    int i = 0, j = 0, matched = 0;
    while(i < n && j < m) {
        if(abs(a[i] - b[j]) <= k){
            matched++;
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            i++;
        }
        else j++;
    }
    
    cout << matched << el;
    
    return 0;
}
