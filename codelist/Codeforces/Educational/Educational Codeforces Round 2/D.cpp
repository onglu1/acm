//
// Created by onglu on 2022/4/26.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define double long double
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const double eps = 1e-20;
const double Pi = acosl(-1.0);
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    double len() const { return sqrt(x * x + y * y); }
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b}; }
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Circle {
    Point o;
    double r;
    Circle() {}
    Circle(const Point &o, double r) : o(o), r(r) {}
};

int n, m, a[N];
istream & operator>>(istream &in, Point &A) {
    in >> A.x >> A.y;
    return in;
}
double getCosA(double A, double B, double C) {
//    cout << A << " " << B << " " << C << endl;
    double cs = 0.5 * (B / C + C / B - A * A / B/ C);
//    cout << (B * B + C * C - A * A) / (2 * B * C) << endl;
    if(sgn(cs - 1) >= 0) cs = 1 - eps;
    if(sgn(cs + 1) <= 0) cs = -1 + eps;

    return cs;
}
void work() {
    Circle c1, c2;
    cin >> c1.o >> c1.r >> c2.o >> c2.r;
    if(c1.r < c2.r) swap(c1, c2);
    double dis = (c1.o - c2.o).len();
    cout << fixed << setprecision(20);
    if(sgn(abs(c1.r - c2.r) - dis) >= 0) {
        double r = min(c1.r, c2.r);
        cout << Pi * r * r << endl;
        return ;
    }
    if(sgn(c1.r + c2.r - dis) <= 0) {
        cout << 0.0 << endl;
        return ;
    }
    double cos_theta = getCosA(c1.r, dis, c2.r);
    double area;
    double theta = acosl(cos_theta);
//    cout << cos_theta << endl;
    if(theta > Pi / 2) {
        area = c2.r * c2.r * theta;
        area += 0.5 * c2.r * c2.r * sinl(2 * Pi - theta * 2);
        cos_theta = getCosA(c2.r, c1.r, dis);
        theta = acosl(cos_theta);
        area += c1.r * c1.r * theta;
        area -= 0.5 * c1.r * c1.r * sinl(theta * 2);
    } else {
//        cout << "!" << endl;
        area = c2.r * c2.r * theta;
        area -= 0.5 * c2.r * c2.r * sinl(theta * 2);
//        cout << "area1 = " << area << endl;
        cos_theta = getCosA(c2.r, c1.r, dis);
        theta = acosl(cos_theta);
        area += c1.r * c1.r * theta;
        area -= 0.5 * c1.r * c1.r * sinl(theta * 2);
    }
    cout << area << endl;
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