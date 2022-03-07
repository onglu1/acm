#include <bits/stdc++.h>
//#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 409;
int n;
struct node {
    int c[4];
    pair<long long, int> gethash() {
        long long minn = 999999999999;
        int cnt;
        for(int i = 0; i < 4; i++) {
            long long t = 0;
            for(int j = 0; j < 4; j++) {
                t = t * 1000ll + c[(i + j) % 4];
            }
            if(t < minn) minn = t, cnt = 1;
            else if(t == minn) cnt++;
        }
        return {minn, cnt};
    }
} p[N];
bool operator<(const node &a, const node &b) {
    for(int i = 0; i < 4; i++) {
        if(a.c[i] != b.c[i])
            return a.c[i] < b.c[i];
    }
}
unordered_map<int, int> cnt;
signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> p[i].c[j];
        }
//        cout << p[i].gethash().second << endl;
        cnt[p[i].gethash().first]++;
    }
    long long ans = 0;
    for(int a = 1; a <= n; a++) {
        cnt[p[a].gethash().first]--;
        int i = 0;
//        for(int i = 0; i < 4; i++) {
        {
            for(int b = a + 1; b <= n; b++) if(a != b) {
                    cnt[p[b].gethash().first]--;
                    for(int j = 0; j < 4; j++) {
                        int cc[4][2];
                        long long tt = 1;
                        node t[4];
                        pair<long long, int> tmp[4];
                        for(int k = 0; k < 4; k++) {
                            cc[k][0] = p[a].c[(i + k) % 4];
                            cc[k][1] = p[b].c[((j + k) % 4) ^ 1];
                        }
                        for(int k = 0; k < 4; k++) {
                            t[k].c[0] = cc[(4 - k) % 4][0];
                            t[k].c[1] = cc[(4 - k - 1) % 4][0];
                            t[k].c[2] = cc[(4 - k - 1) % 4][1];
                            t[k].c[3] = cc[(4 - k) % 4][1];
                            tmp[k] = t[k].gethash();
                        }
                        for(int k = 0; k < 4; k++) {
                            tt *= cnt[tmp[k].first] * tmp[k].second;
                            cnt[tmp[k].first]--;
                        }
                        for(int k = 0; k < 4; k++) {
                            cnt[tmp[k].first]++;
                        }
                        ans += tt;
                    }
                    cnt[p[b].gethash().first]++;
                }
        }
        cnt[p[a].gethash().first]++;
    }
    cout << ans / 3 << endl;
    return 0;
}