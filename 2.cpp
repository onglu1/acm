#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1009;
int n, m, a[N], f[N], deg[N];
vector<int> ver[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) {
        int y, x; cin >> y >> x;
        ver[x].push_back(y);
        // 记录度数
        deg[y]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            // 如果度数数0，那么加入队列，初始花费时间是a[i]
            f[i] = a[i];
            q.push(i);
        }
    }
    while(q.size()) {
        int x = q.front();
        q.pop();
        for(auto y : ver[x]) {
            // 出边的度数-1
            deg[y]--;
            // 一个点最早的结束时间，是到他位置的路径的最大值
            // 结束时间加上a[y]表示这个任务结束时间
            f[y] = max(f[y], f[x] + a[y]);
            if(deg[y] == 0) {
                // 如果已经找完所有前继，就加入队列
                q.push(y);
            }
        }
    }
    cout << *max_element(f, f + n) << endl;
    return 0;
}

/*
4
2 2 3 2
3
1 0
3 1
3 2

由于多个任务可以同步进行，那么其实就是求图的关键路径
拓扑排序求关键路径就行了
*/