#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
int n, m, k, minn = 3;
void dfs(int x, int y, int k, int n, int dep) {
    if(dep >= minn - 1) {
        if(n == 1) minn = min(dep, minn);
        return;
    }
    vector<pair<int,int>> ans; ans.clear();
    for(int i = 1; i <= x - 1; i ++)
        for(int j = 1; j <= m; j ++)
            ans.push_back({i * j, 0});
    int maxnx = (n + m - 1) / m;
    int maxny = n % m ? n % m : m;
    for(int j = 1; j <= y - 1; j ++) {
        int val = max(j * (maxnx - 1 - x) + min(maxny, j), 0);
        for(int i = 1; i <= x; i ++) {
            ans.push_back({i * j, val});
        }
    }
    int length = m - y;
    for(int j = 1; j <= length; j ++) {
        int val = j * (maxnx - x) + max(0, (min(maxny, j) - y));
        for(int i = 1; i < x; i ++) {
            ans.push_back({i * j, val});
        }
    }
    int s1 = 0, s2 = 0;
    if(maxnx != x) s1 = m * (maxnx - 1 - x) + maxny;
    s2 = (m - y) * (maxnx - x) + max(0, maxny - y);
    ans.push_back({0, max(s1, s2)});
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i ++) {
        if(i == ans.size() - 1 || ans[i].first != ans[i + 1].first) {
            int K = k - ans[i].first;
            int N = n - ans[i].first - ans[i].second;
            int xx = (K + m - 1) / m;
            int yy = K % m ? K % m : m;
            dfs(xx, yy, K, N, dep + 1);
        }
    }
}
signed main() {
    cin >> m >> n >> k;
    int x = (k + m - 1) / m;
    int y = k % m ? k % m : m;
    dfs(x, y, k, n, 0);
    cout << minn << endl;
    return 0;
}