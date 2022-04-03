#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, g[509][509];
int sx, sy, tx, ty, p;
struct node {
    int x, y, d;
};
queue<node> q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> sx >> sy >> tx >> ty >> p;
    while(p--) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    //cnt表示路径条数，dis表示距离，一开始设为正无穷
    int cnt = 0, dis = 0x3f3f3f3f;
    //入队起点，距离为0
    q.push({sx, sy, 0});
    while(q.size()) {
        //每次取出队首
        int x, y, d;
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        q.pop();
        //如果找到终点，那么我们可以得到终点到起点的最短路长度为dis
        //每次到达终点，条数就增加
        if(x == tx && y == ty) {
            dis = min(dis, d);
            cnt++;
        }
        //如果要拓展的点大于最短路距离，那么直接跳过这个拓展
        //一开始dis是无穷大，肯定任意拓展，找到dis之后就会限制住拓展
        if(d >= dis) continue;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            //判断越界
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(g[xx][yy]) continue;
            //把下一个点加入队列
            q.push({xx, yy, d + 1});
        }
    }
    //输出答案
    cout << cnt << " " << dis << endl;
    return 0;
}
/*
 * 思路很简单，就是暴力搜索。
 * 我们可以用bfs搜索最短路，因为bfs搜索的过程，搜到的点到起点的距离是逐渐增大的
 * 我们在搜索过程中第一次找到终点，那个时候的距离就是最短路的距离
 * 接下来我们处理完所有长度等于最短路的搜索过程，但是不再入队长度大于最短路的节点拓展
 * 这样完成搜索就可以得出最短路长度和最短路条数了
 */