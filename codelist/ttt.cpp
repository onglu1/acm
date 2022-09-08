#include <bits/stdc++.h>
using namespace std;
set<int> vis;
map<int, vector<int>> ver;
int n, m, a, b;
void dfs(int x, int d) {
    if(vis.count(x)) return ;
    vis.insert(x);
    if(x == a) {
        cout << d << endl;
        exit(0);
    }
    for(auto y : ver[x]) {
        dfs(y, d + 1);
    }
}
int main()
{
    cin >> n >> m;
    string s;
    getline(cin, s);
    for(int i = 0; i < m; i++) {
        getline(cin, s);
        s += " ";
        int x = -1, cnt = 0;
        int fa;
        for(int j = 0; j < s.size(); j++) {
            if(isdigit(s[j])) {
                if(x == -1) x = 0;
                x = x * 10 + s[j] - '0';
            } else {
                if(x == -1) continue;
                cnt++;
                if(cnt == 1) fa = x;
                else {
                    ver[fa].push_back(x);
                    ver[x].push_back(fa);
                }
                x = 0;
            }
        }
    }
    cin >> a >> b;
    if(a == b) cout << -1 << endl;
    else {
        dfs(b, 0);
        cout << -1 << endl;
    }
    return 0;
}


