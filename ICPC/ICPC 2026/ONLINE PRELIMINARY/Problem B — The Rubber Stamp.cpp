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

vector<int> zFunction(string s){
    int n = s.size();
    vector<int> z(n);

    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);

        while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }

        if(i+z[i]-1 > r){
            l = i;
            r = i+z[i]-1;
        }
    }

    return z;
}

int main(){
    fast

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string T, P;
        cin >> T >> P;

        vector<int> z1 = zFunction(P + "#" + T);
        vector<int> z2 = zFunction(T + "#" + P);

        vector<int> dp(n+2, 1e9);

        dp[1] = 0;

        for(int d = 1; d < k; d++){
            int len = min(z2[n+1+d], k-d);

            if(len >= 1){
                int p = 1-d;
                int r = min(n, p+len);

                for(int q = max(2, p+1); q <= r; q++){
                    dp[q] = min(dp[q], 1);
                }
            }
        }

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        int ans = 1e9;

        for(int p = 1; p <= n; p++){
            while(!pq.empty() && pq.top().second < p){
                pq.pop();
            }

            if(!pq.empty()){
                dp[p] = min(dp[p], pq.top().first);
            }

            int len = min(z1[k+p], n-p+1);

            if(dp[p] < 1e9){
                if(p+len > n){
                    ans = min(ans, dp[p]+1);
                }

                if(len > 0){
                    pq.push({dp[p]+1, p+len});
                }
            }
        }

        if(ans == 1e9) cout << -1 << el;
        else cout << ans << el;
    }

    return 0;
}