#include <cstdio>
#include <queue>
using namespace std;
int n, m, map[100][100];
int start_x, start_y, target_x, target_y, p;
queue<pair<int, pair<int, int> > > q;
int check(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return true;
    if(map[x][y]) return true;
    return false;
}
int main() {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &start_x, &start_y, &target_x, &target_y);
    scanf("%d", &p);
    for(int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
        }
        //cnt表示路径条数，dis表示距离，一开始设为-1,表示还没找到最短路
    int cnt = 0, dis = -1;
    //入队起点，距离为0
    q.push(make_pair(start_x, make_pair(start_y, 0)));
    while(q.size()) {
        //每次取出队首
        int x = q.front().first;
        int y = q.front().second.first;
        int now = q.front().second.second;
        q.pop();
        //如果找到终点，并且最短路还没有过更新，那么记录一下最短路长度
        if(x == target_x && y == target_y && dis == -1) {
            dis = now;
        }
        //每次到终点记录一下多一条路径
        if(x == target_x && y == target_y) cnt++;
        //如果已经找到最短路，并且当前这个点到起点的距离已经大于等于最短路，我们就不再继续往下搜索了
        if(dis != -1 && now >= dis) continue;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            //判断越界
            if(check(xx, yy)) continue;
            //把下一个点加入队列
            q.push(make_pair(xx, make_pair(yy, now + 1)));
        }
    }
    //输出答案
    printf("%d %d", cnt, dis);
    return 0;
}
/*
 * 思路很简单，就是暴力搜索。
 * 我们可以用bfs搜索最短路，因为bfs搜索的过程，搜到的点到起点的距离是逐渐增大的
 * 我们在搜索过程中第一次找到终点，那个时候的距离就是最短路的距离
 * 接下来我们处理完所有长度等于最短路的搜索过程，但是不再入队长度大于最短路的节点拓展
 * 这样完成搜索就可以得出最短路长度和最短路条数了
 */