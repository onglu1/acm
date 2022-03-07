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
    cout << rd(1, 10) << " " << rd(1, 10) << " " << rd(1, 10) << endl;

    return 0;
}