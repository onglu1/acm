#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
vector<vector<char> > mp;
int ans[1009][1009][4];
struct node {
    int x, y, i, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
priority_queue<node> q;
int main(){
    cin >> n >> m;
    mp = vector<vector<char> > (n, vector<char>(m, 0));
    memset(ans, 0x3f, sizeof(ans));
    int tx, ty;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'S') {
                for(int k = 0; k < 4; k++) {
                    ans[i][j][k] = 0;
                    q.push({i, j, k, 0});
                }
            } else if(mp[i][j] == 'E') {
                tx = i;
                ty = j;
            }
        }
    }
    while(!q.empty()) {
        auto t = q.top();
        q.pop();
        if(ans[t.x][t.y][t.i] < t.d) continue;
        for(int i = 0; i < 4; i++) {
            int xx = t.x + dx[i];
            int yy = t.y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(mp[xx][yy] == 'X') continue;
            int dd = t.d + 1;
            if(t.i != i) dd += 1;
            if(dd < ans[xx][yy][i]) {
                ans[xx][yy][i] = dd;
                q.push({xx, yy, i, dd});
            }
        }
    }
    int t = *min_element(ans[tx][ty], ans[tx][ty] + 4);
    if(t == 0x3f3f3f3f) cout << -1 << endl;
    else cout << t;
    return 0;
}


