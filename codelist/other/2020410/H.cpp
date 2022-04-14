#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, cnt = 0, maxr, maxc = 0;
map<pair<int, int> , int> p;
map<pair<int, int> , int> pcnt;
map<pair<int, int> , int> newp;
void nxtround() {
    pcnt.clear();
    newp.clear();
//    static int cnt = 0;
//    cnt++;
//    if(cnt % 10 == 0)
//        cout << cnt << endl;
    for(auto pos : p) {
        int x = pos.first.first;
        int y = pos.first.second;
        for(int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            pcnt[{xx, yy}] ++;
        }
        if(!pcnt.count({x, y})) pcnt[{x, y}] = 0;
    }
    cnt = 0;
    for(auto pos : pcnt) {
        int x = pos.first.first;
        int y = pos.first.second;
        if(p.count({x, y})) {
            if(pos.second == 2 or pos.second == 3) {
                newp[{x, y}] = 1;
                cnt++;
            }
        } else {
            if(pos.second == 3) {
                newp[{x, y}] = 1;
                cnt++;
            }
        }
    }
    p = newp;
}
void work() {
    cin >> n >> m;
    cnt = 0;
    p.clear();
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.') continue;
            p[{i, j + 1}] = 1;
            cnt++;
        }
    }
    maxr = 0; maxc = cnt;
    for(int j = 1; j <= 321; j++) {
        nxtround();
        if(cnt > maxc) {
            maxc = cnt;
            maxr = j;
        }
    }
    cout << maxr << " " << maxc << " " << cnt << endl;
}
int main()
{
    int Case ;
    cin >> Case;
    while(Case--) work();
    return 0;
}