#include <iostream>
using namespace std;
const int N = 209;
int n, f[N];
int main(){
    cin >> n;
    f[0] = 1; f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
/*
 * f[i]表示从地面走到第i号台阶的方案数
 * 那么我们到达第i号台阶的最后一步有两种走法：
 * 1. 从i - 1走一步长度为1的
 * 2. 从i - 2走一步长度我2的
 * 状态转移方程就是f[i] = f[i - 1] + f[i - 2]
 * 初始状态f[0] = f[1] = 1
 */