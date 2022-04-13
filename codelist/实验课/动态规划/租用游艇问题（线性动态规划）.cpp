#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 209;
const int INF = 0x3f3f3f3f;
int n, r[N][N], f[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> r[i][j];
        }
    }
    // 初始化为无穷大
    memset(f, 0x3f, sizeof(f));
    // 1号点走到1号点的代价为0
    f[1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            // 枚举从j号点走过来
            f[i] = min(f[i], f[j] + r[j][i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}
/*
 * 事实上我们不需要知道每两点之间的代价
 * 我们只需要知道从1号点走到i号点的代价
 * 显然，任何一个走法，我们只需要知道最后一步是哪里走到终点就行了
 * 从1号点走到那一步的起始点可以是一个子问题
 * f[i]表示从1号点走到第i号点的最小代价
 * 那么，f[i] = min{f[j] + r[j][i]}(1 <= j < i)
 */