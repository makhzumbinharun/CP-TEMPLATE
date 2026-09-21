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
    int n;
    cin >> n;

    set<int> s;

    f0(n){
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << el;

    return 0;
}
