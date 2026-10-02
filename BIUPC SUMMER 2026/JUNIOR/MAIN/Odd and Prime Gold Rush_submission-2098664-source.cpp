#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(n) for(int i = 0; i < n; i++);
#define f1(n) for(int i = 1; i < n; i++);

ll primeNumber(ll N)
{
    if(N == 1)
        return 0;
    for(ll i=2 ; i<N ; i++)
    {
        if(N%i == 0)
            return 0;
    }
    return N;
}

ll oddNumber(ll N)
{
    ll sum = 0;
    int cnt = 0;
    for(ll i=1 ;  ; i+=2)
    {
        if(cnt == N)
            return sum;
        else
        {
            sum+=i;
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, sum=0;
    int cnt = -1;
    cin >> N;
    for(ll i = 1 ;  ; i++)
    {
        if(primeNumber(i) != 0)
            cnt++;

        if(cnt == N) break;
        else
        {
            sum += primeNumber(i);
        }
    }
    // cout << sum << " " << oddNumber(N) << endl;

    cout << abs(sum - oddNumber(N));
    return 0;
}

