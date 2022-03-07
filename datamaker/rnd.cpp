#include <bits/stdc++.h>
using namespace std;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
T rd(T l, T r)
{
    std::uniform_int_distribution<T> u(l, r);
    return u(rng);
}
template <>
double rd<double>(double l, double r)
{
    std::uniform_real_distribution<double> u(l, r);
    return u(rng);
}
const int N = 2e5 + 1009;
int n,m;
struct range {
    int idl, idr;
    double n;
    void (*f)(range r);
} ;
void printdata(range r);
void printtree(range r);
vector<range> v = {
          {1, 6, 300, printdata}
        , {7, 10, 5e4, printtree}
        , {11, 20, 5e4, printdata}
};
string name = "easy";
void printdata(range r) {
//    int n, m, a[500009];
//    n = m = r.n;
//    cout << n << " " << m << endl;
//    cout << 0 << " ";
//    for(int i = 2; i <= n; i++) {
//        cout << (int)(rd(0, (int)1e9)) << " ";
//    }
//    cout << endl;
//    for(int i = 1; i <= n; i++) a[i] = i;
//    for(int i = 1; i <= m; i++) {
//        cout << rd(1, n) << " " << rd(1, n) << " " << rd(1, 100) << endl;
//    }
    int n, m, a[500009];
    n = r.n;
    m = r.n * 10;
    cout << n << " " << m << endl;
    cout << 0 << " ";
    for(int i = 2; i <= n; i++) {
        cout << (int)(rd(0, (int)1e9)) << " ";
    }
    cout << endl;
    for(int i = 2; i <= n; i++) {
        int x = rd(1, i - 1);
        cout << x << " " << i << " " << rd(1, 100) << endl;
    }
    for(int i = n; i <= m; i++) {
        int x = 0, y = 0;
        while(x == y) x = rd(1, n), y = rd(1, n);
        cout << x << " " << y << " " << rd(1, 100) << endl;
    }
}
void printtree(range r) {
    int n, m, a[500009];
    n = r.n;
    m = n - 1;
    cout << n << " " << m << endl;
    cout << 0 << " ";
    for(int i = 2; i <= n; i++) {
        cout << (int)(rd(0, (int)1e9)) << " ";
    }
    cout << endl;
    for(int i = 2; i <= n; i++) {
        int x = rd(1, i - 1);
        cout << x << " " << i << " " << rd(1, 100) << endl;
    }
}
int main()
{
    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    ios ::sync_with_stdio();
    cin.tie(0);
    char c[500];
    const char *a;
    string s;
    srand(time(0));
    for(auto r : v) {
        for(int i=r.idl;i<=r.idr;i++){
            itoa(i,c,10);
            s=name+c+".in";
            a=s.c_str();
            freopen(a,"w",stdout);
            r.f(r);
            cerr << "OK,"<<i<<endl;
            fclose(stdout);
        }
    }

    return 0;
}