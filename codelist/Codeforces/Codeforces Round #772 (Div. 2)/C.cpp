#include <bits/stdc++.h>
#define Mid (l + r >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
int n, a[1000009];
struct node {
	int x, y, z;
};
vector<node> v;
void work() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ok = 1;
	for(int i = 1; i < n; i++) {
		if(a[i + 1] < a[i]) {
			ok = 0;
		}
	}
	if(ok) {
		cout << 0 << endl;
		return ;
	}
	if(a[n - 1] > a[n] || a[n] < 0) {
		cout << -1 << endl;
		return ;
	}
	cout << n - 2 << endl;
	for(int i = 1; i <= n - 2; i++) {
		cout << i << " " << n - 1 << " " << n << endl;
	}
}
signed main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int Case;
	cin >> Case;
	while(Case--) work();
	return 0;
}
