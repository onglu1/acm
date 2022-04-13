#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define X first
#define Y second
#define pii pair<int, int>
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
int u[N], v[N], f[N], vis[N];
vector<pii> G[N];

bool dfs(int x, int fa, int rt)
{
    if (x == rt) return 1;
    for (auto to : G[x])
    {
        int y = to.X;
        if(y == fa) continue;
        if (dfs(y, x, rt))
        {
            vis[to.Y] = 1;
            return 1;
        }
    }
    return 0;
}

int find(int x)
{
    if(f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T --)
    {
        int n, m;
        cin >> n >> m;
        rep(i, 1, m)
            cin >> u[i] >> v[i];
        rep(i, 1, n)
        {
            f[i] = i;
            vis[i] = 0;
                G[i].clear();
        }
        bool flag = 0;
        rep(i, 1, m)
        {
            int x = u[i];
            int y = v[i];
            if(find(x) == find(y))
            {
                vis[i] = 1;
                dfs(x, 0, y);
                flag = 1;
                break;
            }
            else
            {
                G[x].pb({y, i});
                G[y].pb({x, i});
                f[find(x)] = find(y);
            }
        }
        if(flag)
        {
            vector<int> ans;
            rep(i, 1, m) if(vis[i] == 1) ans.pb(i);
            for(int i = 0; i < ans.size() - 1; i ++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[ans.size() - 1]);
        }
        else puts("-1");

    }


    return 0;
}
