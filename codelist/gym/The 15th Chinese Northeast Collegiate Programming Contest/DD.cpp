#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define ls u << 1
#define rs u << 1 | 1
#define lowbit(x) (x & -x)
#define pb push_back
#define FOR(i, a, n) for(int i=a;i<=n;i++)

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 3e7 + 10, mod = 998244353;
mt19937_64 mrand(random_device{}());
ll fact[N], infact[N];

template<typename T> inline T read()
{
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch=='-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}

ll C(int a, int b) {
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve()
{
    int n = readI();
    ll ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        cout << C(n*n - i, n-1) << " " << fact[n] << " " << n << " " << fact[n * n - n] << endl;
        // cout << " " << C(n*n - i, n-1) * fact[n] % mod * n % mod * fact[n*n-n] % mod << endl;
        ans = (ans + C(n*n - i, n-1) * fact[n] % mod * n % mod * fact[n*n-n] % mod) % mod;
    }
    cout << ans << endl;
}

ll qmi(ll a, int b)
{
    ll t = 1;
    while (b) {
        if (b & 1) t = t * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return t;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ ) {
        fact[i] = fact[i-1] * i % mod;
    }
    infact[N-1] = qmi(fact[N-1], mod-2);
    for (int i = N - 2; i ; i -- ) {
        infact[i] = infact[i+1] * (i + 1) % mod;
    }

}

int main()
{
    int t = 1;
    init();
    t = read<int>();
    while (t -- ) solve();
    return 0;
}