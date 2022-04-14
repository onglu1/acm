#include <bits/stdc++.h>
using namespace std;
vector<int> g[5010];
set<int> st;
int vis[5010];
void dfs(int x)
{
    if(vis[x] == 1)
    {
        puts("-1");
        exit(0);
    }
    st.insert(x);
    vis[x] = 1;
    for(auto y : g[x])
        dfs(y);
    vis[x] = 0;
}
int main()
{
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i ++)
    {
        string a;
        cin >> a;
        int b = 0;
        int flag = 0;
        for(int j = 0; j < a.size(); j ++)
        {
            if(a[j] == ',')
            {
                if(flag == 0) {b = 0; flag = 1; continue;}
                g[i].push_back(b);
                b = 0;
            }
            else b = b * 10 + a[j] - '0';
        }
        if(flag == 0) {flag = 1; continue;}
        g[i].push_back(b);
    }

    dfs(t);
    vector<int> ans;
    for(auto x : st) if(x != t) ans.push_back(x);
    if(ans.size() == 0) puts("null");
    else
    {
        for(int i = 0; i < ans.size() - 1; i ++)
            printf("%d,", ans[i]);
        printf("%d\n", ans[ans.size() - 1]);
    }

    return 0;
}