#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 209;
const int INF = 0x3f3f3f3f;
int n, m, T[N], c[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    cin >> m;
    //初始化为无穷大
    memset(c, 0x3f, sizeof(c));
    c[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = T[i]; j <= m; j++) {
            // 每个位置考虑取一个硬币进行转移
            c[j] = min(c[j], c[j - T[i]] + 1);
        }
    }
    cout << c[m] << endl;
    return 0;
}