#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
int n, s, t;
vector<vector<int> > graph;
vector<int> stack;
void dfs(int x) {
    // 将路径上的点加入到栈中
    stack.push_back(x);
    if(x == t) {
        // 输出前100条路径，cnt是计数器，计数器大于100时强制结束程序
        static int cnt = 0;
        cnt++;
        if(cnt > 100) exit(0);
        cout << stack[0];
        for(int i = 1; i < stack.size(); i++) {
            cout << " -> " << stack[i];
        }
        cout << endl;
        //在返回的时候要弹栈
        stack.pop_back();
        return ;
    }
    for(int i = 0; i < n; i++) {
        // 从小到大找到每一个跟i相连的点
        if(graph[x][i]) {
            // 回溯法继续搜索
            dfs(i);
        }
    }
    //在返回的时候要弹栈
    stack.pop_back();
    return ;
}
int isDAG() {
    /*
     * 判断图是否为DAG
     * 如果图是DAG，返回s到t的总共的路径数量
     * 如果图不是DAG，返回-1
     */
    vector<int> inDeg(n), f(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j]) {
                // 计算每一个点的入度
                inDeg[j]++;
            }
        }
    }
    // f[i]表示从s出发到达t有多少条路径
    for(int i = 0; i < n; i++) f[i] = 0;
    f[s] = 1;
    // 用队列进行拓扑排序
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(inDeg[i] == 0) {
            // 如果一个点的入度为0，则将其作为初始节点放入队列里面
            q.push(i);
        }
    }
    // 记录入度被删成0的点的数量
    int topology_cnt = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        // 出队的时候记录数量
        topology_cnt++;
        for(int i = 0; i < n; i++) {
            if(graph[x][i]) {
                // 删除出边，同时到达的点入度减一
                inDeg[i]--;
                // 从s走到x再走到i的方案数，DAG上动态规划
                f[i] += f[x];
                if(inDeg[i] == 0) {
                    // 入度为0的时候加入队列
                    q.push(i);
                }
            }
        }
    }
    // 如果n个点没有全部删完，说明有环，返回-1
    if(topology_cnt != n) return -1;
    // 如果没有环返回方案数
    else return f[t];
}
int main()
{
    cin >> n;
    graph = vector<vector<int> > (n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> s >> t;
    int ways = isDAG();
    if(ways == -1) {
        // 如果给定的图不是DAG，不要进行回溯搜索，否则会导致死循环
        cout << "The given graph is not a DAG" << endl;
    } else if(ways == 0) {
        // 如果没有路径，那么就没有输出的必要了
        cout << "There is no paths from " << s << " to " << t << endl;
    } else {
        // 有路径的时候，输出路径，这里为了防止输出过大，只输出100条
        cout << "There is " << ways << " path(s) from " << s << " to " << t << endl << endl;
        cout << "Show the first 100 paths (sorted by lexicographical order) : " << endl << endl;
        // 通过回溯法搜索所有路径
        dfs(s);
    }
    return 0;
}
/*
10
0 1 1 1 1 1 1 1 1 1
0 0 1 1 1 1 1 1 1 1
0 0 0 1 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
 0 9
 */