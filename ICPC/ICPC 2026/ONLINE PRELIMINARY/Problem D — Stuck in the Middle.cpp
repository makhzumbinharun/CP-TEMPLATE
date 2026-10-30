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
#define f0(n) for(int i = 0; i < n; i++)
#define f1(n) for(int i = 1; i < n; i++)

int main(){
    fast

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ok = true;

        for(int i = 0; i < n && ok; i++){
            int cnt = 0;

            for(int j = 0; i-j >= 0 && i+j < n; j++){
                if(s[i-j] == s[i]){
                    cnt++;
                }

                if(j > 0 && s[i+j] == s[i]){
                    cnt++;
                }

                if(cnt <= j){
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << el;
    }

    return 0;
}