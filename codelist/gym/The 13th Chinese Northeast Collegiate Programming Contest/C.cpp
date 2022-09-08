#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 1009;
int n, a[N][4];
map<pair<int, int>, int> M;
map<pair<int, int>, map<double, int> > G;
pair<int, int> format(int X, int Y) {
    if(X < 0 && Y < 0) X = -X, Y = -Y;
    if(X < 0 && Y > 0) X = -X, Y = -Y;
    if(X == 0) Y = 1;
    else if(Y == 0) X = 1;
    else {
        int g = __gcd(abs(X), abs(Y));
        X /= g; Y /= g;
    }
    return {X, Y};
}
void work() {
    cin >> n;
    M.clear();
    G.clear();
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    for(int i = 1; i <= n; i++) {
        int X = a[i][2] - a[i][0];
        int Y = a[i][3] - a[i][1];
        auto p = format(X, Y);
        M[p] += 1;
        if(X == 0) G[p][Y] += 1;
        else if(Y == 0) G[p][X] += 1;
        else G[p][a[i][1] - (1.0 * a[i][0] / p.first)] += 1;
//        G[p][M[p.second * a[i][0]]]
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int X = a[i][2] - a[i][0];
        int Y = a[i][3] - a[i][1];
        auto p = format(X, Y);
        ans += n - M[p];
    }
    ans /= 2;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int Case ;
    cin >> Case;
    while(Case--) work();
    return 0;
}