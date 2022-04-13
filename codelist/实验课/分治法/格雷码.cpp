#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
// 将s串添加到v的最开始
void add(string s, vector<string> &v) {
    for(int i = 0; i < v.size(); i++) {
        v[i] = s + v[i];
    }
}
vector<string> solve(int n) {
    vector<string> v;
    // 如果长度是1，只有两位，那就是0,1
    if(n == 1) {
        v.push_back("0");
        v.push_back("1");
        return v;
    }
    vector<string> t;
    // 如果长度不为1，首先计算前n-1位的格雷码
    v = solve(n - 1);
    t = v;
    // 将后一半逆序
    reverse(t.begin(), t.end());
    // 前一半前面+0，后一半前面+1
    add("0", v);
    add("1", t);
    // 合并两半
    v.insert(v.end(), t.begin(), t.end());
    return v;
}
int main(){
    cin >> n;
    // 得到n位的所有格雷码
    vector<string> v = solve(n);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
/*
 * 我们利用分治法解决这个问题
 * 首先，最小的一个问题：
 * 当n = 1的时候，我们有两个串：0, 1
 * 当n > 1的时候，我们可以用以下方案构造
 * 首先我们计算出n - 1的时候的答案，这时候，相邻两位之间变化的位置只有一位
 * 然后我们将这个答案翻转过来，接在原答案后面，再在前半答案前面补上0，后半答案前面补上1
 * 显然 补上一个字符不会影响变化的位置数量
 * 但是在两个方案交界处，刚好有第一位从0变成1，后面是相同的这样的两个串
 * 于是我们就构造出了n的时候的答案
 */