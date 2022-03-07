#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int dx[] = {2, 2, -2, -2, -4, 4};
const int dy[] = {-6, 6, -6, 6, 0, 0};
int n, m, dis[1000 * 4 + 10][1000 * 6 + 10];
int sx, sy, tx, ty;
char c[1000 * 4 + 10][1000 * 6 + 10];
void work() {
    cin >> n >> m;
    cin.ignore();
    for(int i = 1; i <= 4 * n + 3; i++) {
        string s;
        getline(cin, s);
        strcpy(c[i] + 1, s.c_str());
        memset(dis[i], 0, sizeof(int) * (6 * m + 5));
        for(int j = 1; j <= 6 * m + 3; j++) {
            if(c[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if(c[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }
    queue<pair<int, int> >q;
    q.push({sx, sy});
    dis[sx][sy] = 1;
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 2 || xx > 4 * n + 1) continue;
            if(yy < 5 || yy > 6 * m + 3 - 4) continue;
            if(c[x + dx[i] / 2][y + dy[i] / 2] != ' ') continue;
            if(dis[xx][yy]) continue;
            dis[xx][yy] = dis[x][y] + 1;
            q.push({xx, yy});
            if(xx == tx && yy == ty) {
                cout << dis[xx][yy] << endl;
                return ;
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}