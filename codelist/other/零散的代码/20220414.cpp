#include <iostream>
#include <queue>
using namespace std;
/*
 * 用一个队列存储遍历到的节点
 * 每次取出队首，依次加入他的两个儿子
 * 一开始把根节点存进队列就行
 */
struct node {
    int val;
    node *lson, *rson;
    node(int mval) {
        val = mval;
        lson = rson = NULL;
    }
};
int main()
{
    //建树，根节点的值是1，左右儿子分别是2,3，右儿子的左儿子是4
    node root(1);
    node l1(2);
    node l2(3);
    node l3(4);
    root.lson = &l1;
    root.rson = &l2;
    l2.lson = &l3;
    queue<node> q;
    // 把根节点放入队列
    q.push(root);
    while(!q.empty()) {
        //取出队首
        node rt = q.front();
        q.pop();
        //输出值
        cout << rt.val << " ";
        //如果左右不为空就加入队列
        if(rt.lson != NULL) q.push(*rt.lson);
        if(rt.rson != NULL) q.push(*rt.rson);
    }
    return 0;
}