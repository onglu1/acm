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

int main()
{
    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    ios ::sync_with_stdio();
    cin.tie(0);
    int Case = 10;
    cout << Case << endl;
    while(Case--) {
        int n = 8;
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            v.push_back(rd(1, n));
        }
        std::sort(v.begin(), v.end());
        cout << n << endl;
        for(auto x : v) {
            cout << x << " " ;
        }
        cout << endl;
    }
    return 0;
}