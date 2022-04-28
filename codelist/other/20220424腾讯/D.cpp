#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* solve(vector<ListNode*>& a) {
        // nv, pv记录每个元素的前一个后一个元素
        map<int, int> nv, pv;
        // 题目中要求字典序最小，那么第一个元素肯定是最小，既然循环链表中每个元素唯一
        // 那么最小的那个元素一定是链表首，然后下一个元素的方向是他前后比较小的那一边
        int minn = 1e9 + 1;
        // 暴力拆连边到map里面，然后自己重新建，比较好写
        for(auto cur : a) {
            minn = min(minn, cur->val);
            while(cur->next != nullptr) {
                // 每条链表都拆出很多前后关系
                nv[cur->val] = cur->next->val;
                pv[cur->next->val] = cur->val;
                // 遍历链表，得到最小值
                minn = min(minn, cur->next->val);
                cur = cur->next;
            }
        }
        // 重新建链表
        ListNode* head = new ListNode(minn);
        head->next = nullptr;
        ListNode* cur = head;
        int now = minn;
        // 把比较小的那一个方向作为next
        if(pv[now] < nv[now]) nv = pv;
        // 添加一遍链表，下一个元素是minn说明循环
        while(nv[now] != minn) {
            // 模拟重新建立一遍，每次新建节点赋值
            cur->next = new ListNode(nv[now]);
            cur = cur->next;
            cur->next = nullptr;
            now = nv[now];
        }
        // 返回链表首
        return head;
    }
};

int main()
{

    return 0;
}