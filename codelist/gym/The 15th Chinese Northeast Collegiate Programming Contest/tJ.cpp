#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define double long double
const double eps = 1e-16;
const double pi = acosl(-1.);

struct Point {
    double x, y, z;
};
using Vector = Point;
Vector operator - (Vector A, Vector B) { return Vector{A.x-B.x, A.y-B.y, A.z-B.z};}
Vector operator + (Vector A, Vector B) { return Vector{A.x+B.x, A.y+B.y, A.z+B.z};}
Vector operator * (Vector A, double p) { return Vector{A.x*p, A.y*p, A.z*p};}
Vector operator / (Vector A, double p) { return Vector{A.x/p, A.y/p, A.z/p};}

double squ(double x) {
    return x * x;
}
double len(Vector v) {
    return sqrtl(squ(v.x) + squ(v.y) + squ(v.z));
}
double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector cross(Vector a, Vector b) {
    return {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}
Vector unit(Vector a) {
    return a / len(a);
}

void out(Point p) {
    cout << p.x << " " << p.y << " " << p.z << endl;
}
ostream &operator<<(ostream &out, const Point &p) {
    out << p.x << " " << p.y << " " << p.z;
    return out;
}
Point rotate(Point a, Vector b, double ang) {
    Vector e1, e2, e3;
    e3 = unit(b);
    // cerr << e3 << endl;
//    cout << " ";out(e3);
    double l = dot(a, e3);
    // cerr << l << endl;
    Point p = e3*l;
    // cerr << p << endl;
    e1 = a - p;
    if(len(e1) > eps) e1 = unit(e1);
    e2 = cross(e1, e3);
    // cerr << "e1 : " << e1 << endl;
    // cerr << "e2 : " << e2 << endl;
    // cerr << ang << endl;
    double x1 = dot(a, e1), y1 = dot(a, e2);
    double x = x1*cosl(ang) - y1*sinl(ang);
    double y = x1*sinl(ang) + y1*cosl(ang);
    // cerr << "x1 = " << x1 << "  y1 = " << y1 << endl;
    // cerr << "x  = " << x << "   y =  " << y << endl;
    // cerr << p << endl;
    // cerr << (e1 * x1 + e2 * y1) << endl;
    // cerr << (e1 * y + e2 * x) << endl;
    return e1*x+e2*y+p;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(20);

    int t; cin >> t;
    while(t--) {
        double a, b, c, x, y, z, r;
        cin >> a >> b >> c >> x >> y >> z >> r;
//        cout << a << b << c << x << y << z << r << endl;

        r *= pi; r /= 180.0;
        cerr << r << endl;

//        cout << r << endl;

        Point p1 = {a, b, c}, p2 = {x, y, z};
        cerr << endl << " p1 : " << p1 << endl << " p2 : " << p2 << endl << endl;

        Point s1 = rotate(p2, p1, r);
        cerr << s1 << endl;
        Point s2 = rotate(p2, p1, -r);

       out(s1); out(s2);

        if(s1.z > s2.z) out(s1);
        else out(s2);
    }


    return 0;
}
