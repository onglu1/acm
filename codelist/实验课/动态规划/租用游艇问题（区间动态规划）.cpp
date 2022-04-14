#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 209;
const int INF = 0x3f3f3f3f;
int n, r[N][N], f[N][N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> r[i][j];
        }
    }
    // 初始化为无穷大
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        // 从i走到i的代价是0
        f[i][i] = 0;
    }
    // 枚举长度
    for(int len = 2; len <= n; len++) {
        // 右端点要小于n
        for(int i = 1; i + len - 1 <= n; i++) {
            // i是左端点，j是右端点
            int j = i + len - 1;
            // 第一种走法，直接一步到达
            f[i][j] = r[i][j];
            for(int k = i; k < j; k++) {
                // 先走到k再走到j
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
/*
 * f[i][j]表示从i走到j最小的花费代价
 * 从i走到j，有两种走法：
 * 1. 直接从i走到j，花费r[i][j]的代价
 * 2. 从i先k，花费f[i][k]的代价，再从k走到j，花费f[k][j]的代价
 * 利用区间dp的方法，第一层循环枚举长度，接下来枚举每个区间
 */