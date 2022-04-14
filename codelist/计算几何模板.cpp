const double Pi = acos(-1.0);
const double eps = 1e-11;
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};
struct Line{
    Point s, t;
    Line() {}
    Line(const Point &s, const Point &t) : s(s), t(t) {}
};

Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(const Point &a, const double &c) { return Point(c * a.x, c * a.y); }
Point operator/(const Point &a, const double &c) { return Point(a.x / c, a.y / c); }
inline bool operator < (const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
bool operator == (const Point& a, const Point& b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
double det(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
double abs(const Point &a){ return sqrt(a.x * a.x + a.y * a.y); }
Point rot(const Point &a, double theta){ return Point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)); }
Point rotCCW90(const Point &a) { return Point(-a.y, a.x); }
Point rotCW90(const Point &a) { return Point(a.y, -a.x); }
double arg(const Point &a){
    double t = atan2(a.y, a.x);
    return t < 0 ? t + 2 * Pi:t;
}