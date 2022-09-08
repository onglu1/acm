#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1010;
int a[N];
int main()
{
    int T;
    scanf("%d", &T);
    for(int Cas = 1; Cas <= T; Cas ++)
    {
        printf("Case #%d: ", Cas);
        int n, k;
        scanf("%d%d", &n, &k);
        ll B = 0, A = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            A += a[i];
            B += a[i] * a[i];
        }
        if(A == 0 && B == 0) {printf("0\n"); continue;}
        if(k == 1)
        {
            if(A != 0 && (B - A * A) % (2 * A) == 0) printf("%lld\n", (B - A * A) / (2 * A));
            else printf("IMPOSSIBLE\n");
        }
        else
        {
            ll s2 = A;
            ll s1 = 0;
            for(int i = 1; i <= n; i ++)
                for(int j = i + 1; j <= n; j ++)
                    s1 += a[i] * a[j];
            ll ans1, ans2;
            ans1 = 1 - s2;
            s1 += ans1 * s2;
            s2 = 1;
            ans2 = -s1;
            printf("%lld %lld\n", ans1, ans2);
        }

    }


    return 0;
}
