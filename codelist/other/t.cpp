#include <iostream>
#include <string>
using namespace std;

bool isPerfectSquare(int num) {
    if(num == 1) return 1;
    long long l = 1, r = (1ll << 31) - 1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(mid * mid == num) return true;
        if(mid * mid < num) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int main()
{

    return 0;
}