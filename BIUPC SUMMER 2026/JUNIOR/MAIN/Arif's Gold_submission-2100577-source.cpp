#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7, INF = 4e18;
#define f0(n) for(int i = 0; i < n; i++);
#define f1(n) for(int i = 1; i < n; i++);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x,b,g;
    double a;
    cin >> a >> x >> b >> g;
    for(ll i = 1 ; i<=x ; i++)
    {
        if(a < 85)
            break;
        double A=0;
        A = a * 0.025;
        a = a - A;
    }
    double div = (b * 2) + g;

    cout << fixed << setprecision(10) << (double)2 * (a / div) << " " <<  fixed << setprecision(10)  << (a / div);

    return 0;
}
