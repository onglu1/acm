//
// Created by onglu on 2022/5/12.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct Point {
    int x, y;
    int len() const { return x * x + y * y; }
};
int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const int &b) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const int &b) { return {a.x / b, a.y / b}; }
bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const Point &a, const Point &b) { return a.x != b.x || a.y != b.y; }
vector<Point> A, B;
int n, m;
int covA[N], covB[N], match[2009][2009];
int dfs(int x, int y) {
    if(match[x][y] != -1) return match[x][y];
    int nx = (x + 1) % A.size();
    int nnx = (nx + 1) % A.size();
    Point lx1 = A[nx] - A[x], lx2 = A[nnx] - A[nx];
    int ny = (y + 1) % B.size();
    int nny = (ny + 1) % B.size();
    Point ly1 = B[ny] - B[y], ly2 = B[nny] - B[ny];
//    if(x == 0 && y == 2)  cout << "0, 2 : " << lx1.x << " " << lx1.y << " " << ly1.x << " " << ly1.y << endl;
    if(lx1 != ly1) return match[x][y] = 0;
    if(lx2 != ly2) return match[x][y] = 1;
    return match[x][y] = 1 + dfs(nx, ny);
}
int sgn(int x) {
    if(x == 0) return 0;
    return x < 0 ? -1 : 1;
}
ostream & operator << (ostream & out, Point &a) {
    out << a.x << " " << a.y;
    return out;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        A.push_back({x, y});
    }
//    for(int i = 0; i < n; i++) {
//        cout << "A[" << i << "] = " << A[i].x << " " << A[i].y << endl;
//    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        B.push_back({x, y});
    }
    std::reverse(B.begin(), B.end());
//    for(int i = 0; i < m; i++) {
//        cout << "B[" << i << "] = " << B[i].x << " " << B[i].y << endl;
//    }
    for(int i = 0; i < 2 * A.size(); i++) {
        covA[i] = det(A[(i + 1) % A.size()] - A[i % A.size()], A[(i + 2) % A.size()] - A[(i + 1) % A.size()]) >= 0;
        if(i > 0) covA[i] += covA[i - 1];
    }
    for(int i = 0; i < 2 * B.size(); i++) {
        covB[i] = det(B[(i + 1) % B.size()] - B[i % B.size()], B[(i + 2) % B.size()] - B[(i + 1) % B.size()]) <= 0;
        if(i > 0) covB[i] += covB[i - 1];
    }
    memset(match, -1, sizeof match);
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < B.size(); j++) {
            int matchlen = dfs(i, j);
//            cout << i << " " << j << " " << matchlen << endl;
            if(matchlen == 0) continue;
            if(covA[i + n - 2] - covA[i + matchlen - 1] != (n - matchlen - 1)) continue;
            if(covB[j + m - 2] - covB[j + matchlen - 1] != (m - matchlen - 1)) continue;
//            if(i == 0 && j == 2) cout << "111" << endl;
//            cout << i << " " << j << endl;
            Point v1, v2, v3;
            v1 = A[(i - 1 + A.size()) % A.size()] - A[i];
            v2 = B[(j - 1 + B.size()) % B.size()] - B[j];
            v3 = A[(i + 1 + A.size()) % A.size()] - A[i];
            if(det(v1, v2) != 0 && sgn(det(v1, v3)) != sgn(det(v1, v2))) continue;
//            if(i == 0 && j == 2) cout << "111" << " " << v1 << " " << v2 << " " << v3 << endl;
            v1 = A[(i + matchlen + 1 + A.size()) % A.size()] - A[(i + matchlen) % n];
            v2 = B[(j + matchlen + 1 + B.size()) % B.size()] - B[(j + matchlen) % m];
            v3 = A[(i + matchlen - 1 + A.size()) % A.size()] - A[(i + matchlen) % n];
//            if(i == 0 && j == 2) cout << "111" << " " << v1 << " " << v2 << " " << v3 << endl;
            if(det(v1, v2) != 0 && sgn(det(v1, v3)) != sgn(det(v1, v2))) continue;
//            if(i == 0 && j == 2) cout << "111" << endl;
            cout << "yes" << endl;
            return ;
        }
    cout << "no" << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}
