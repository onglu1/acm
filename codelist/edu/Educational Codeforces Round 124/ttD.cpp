#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e6 + 1009;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m;
map<pair<int, int>, pair<int, int> > M;
vector<pair<int, int> > v;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        M[{x, y}] = {-0xabcd, -0xabcd};
    }
    queue<pair<int, int> > q;
    for(auto p : v) {
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(M.find({x, y}) == M.end()) {
                M[p] = {x, y};
                q.push(p);
                break;
            }
        }
    }
    while(q.size()) {
        auto p = q.front();
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(M.find({x, y}) != M.end() && M[{x, y}] == make_pair(-0xabcd, -0xabcd)) {
                M[{x, y}] = M[p];
                q.push({x, y});
            }
        }
        q.pop();
    }
    for(auto p : v) {
        cout << M[p].first << " " << M[p].second << endl;
    }
    return 0;
}