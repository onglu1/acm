#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, d;
vector<vector<int> > c, w, f;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    c = vector<vector<int> >(m, vector<int> (n));
    w = vector<vector<int> >(m, vector<int> (n));
    f = vector<vector<int> >(n, vector<int> (d + 1));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < d + 1; j++)
            f[i][j] = 0x3f3f3f3f;
    for(int i = 0; i < m; i++) {
        f[0][]
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= d; j++) {

        }
    }

    return 0;
}
/*
* f[i][j]表示前i个零件，花费j的代价的最小重量
*/