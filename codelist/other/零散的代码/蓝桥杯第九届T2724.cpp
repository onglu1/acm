//
// Created by onglu on 2022/3/20.
//

#include <bits/stdc++.h>
#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q=(1<<24)+1;
char in[Q],*is=in,*it=in;
void read(int &n){
    char c;
    for(n=0;(c=gc())<'0'||c>'9';);
    for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
struct node {
    int x[2];
    int y[2];
    int z[2];
    int ht;
} t[N];
int a, b, c, n;
vector<vector<vector<int> > > g, sum;
int check(int p) {
    sum = vector<vector<vector<int> > >(a + 2, vector<vector<int> >(b + 2, vector<int> (c + 2)));
    for(int i = 1; i <= p; i++) {
        for(int p = 0; p < 2; p++) {
            for(int q = 0; q < 2; q++) {
                for(int r = 0; r < 2; r++) {
                    int cnt = (p + q + r) % 2;
                    int f = (cnt == 0) ? 1 : -1;
                    sum[t[i].x[p] + p][t[i].y[q] + q][t[i].z[r] + r] += f * t[i].ht;
                }
            }
        }
    }

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                if(i != 0) sum[i][j][k] += sum[i - 1][j][k];
            }
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                if(j != 0) sum[i][j][k] += sum[i][j - 1][k];
            }
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                if(k != 0) sum[i][j][k] += sum[i][j][k - 1];
            }
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                if(sum[i][j][k] > g[i][j][k]) {
                    return true;
                }
            }
        }
    }
    return false;
}
void work() {
//    cin >> a >> b >> c >> n;
    read(a);
    read(b);
    read(c);
    read(n);
//    scanf("%d %d %d %d", &a, &b, &c, &n);
    g = vector<vector<vector<int> > >(a + 2, vector<vector<int> >(b + 2, vector<int> (c + 2)));
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            for(int k = 0; k < c; k++) {
                read(g[i][j][k]);
//                scanf("%d", &g[i][j][k]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        read(t[i].x[0]); read(t[i].x[1]);
        read(t[i].y[0]); read(t[i].y[1]);
        read(t[i].z[0]); read(t[i].z[1]);
        read(t[i].ht);
        t[i].x[0] -= 1; t[i].x[1] -= 1;
        t[i].y[0] -= 1; t[i].y[1] -= 1;
        t[i].z[0] -= 1; t[i].z[1] -= 1;
    }
    int l = 1, r = n;
    while(l <= r) {
        if(check(Mid)) r = Mid - 1;
        else l = Mid + 1;
    }
    printf("%d\n", l);
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case = 1;
    while (Case--) work();
    return 0;
}