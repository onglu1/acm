#include <bits/stdc++.h>
using namespace std;
int n, m, dis[1009][1009][2][2][2];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
vector<vector<int> > g;
struct node {
    int x, y, odd, f1, f2, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    g = vector<vector<int> > (n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[0][0][0][0][0] = 0;
    q.push({0, 0, 0, 0, 0});
    while(q.size()) {
        auto a = q.top();
        q.pop();
        if(a.d > dis[a.x][a.y][a.odd][a.f1][a.f2]) continue;
        for(int i = 0; i < 4; i++) {
            int xx = a.x + dx[i];
            int yy = a.y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            int nodd = 1 - a.odd;
            int nf1 = a.f1, nf2 = a.f2;
            if(g[xx][yy] == 1) {
                if(!a.odd || a.f1 || a.d == 0) continue;
                nf1 = 1;
            } else if(g[xx][yy] == 2) {
                if(a.odd || a.f2 || a.d == 0) continue;
                nf2 = 1;
            }
            if(a.d + 1 < dis[xx][yy][nodd][nf1][nf2]) {
                dis[xx][yy][nodd][nf1][nf2] = a.d + 1;
                q.push({xx, yy, nodd, nf1, nf2, a.d + 1});
            }
        }
    }
    int minn = 0x3f3f3f3f;
    for(int odd = 0; odd <= 1; odd++) {
        for(int f1 = 0; f1 <= 1; f1++) {
            for(int f2 = 0; f2 <= 1; f2++) {
                minn = min(minn, dis[n - 1][m - 1][odd][f1][f2]);
            }
        }
    }
    cout << minn << endl;
    return 0;
}
/*
2 4
0 0 1 0
1 2 0 0
*/