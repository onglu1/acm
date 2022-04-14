#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 209;
const int INF = 0x3f3f3f3f;
int n, m, T[N], c[N][N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    cin >> m;
    //初始化为无穷大
    memset(c, 0x3f, sizeof(c));
    c[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            // 考虑这一个硬币取多少枚进行转移
            for(int k = 0; j - k * T[i] >= 0; k++) {
                c[i][j] = min(c[i][j], c[i - 1][j - k * T[i]] + 1);
            }
        }
    }
    cout << c[n][m] << endl;
    return 0;
}