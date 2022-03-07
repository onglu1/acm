#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}BTNode;

BTNode* CreatExpressionTree(char data[],int num);
void PostOrder_LDR(BTNode *root);
void PostOrder_DLR(BTNode *root);
void PostOrder_LRD(BTNode *root);

int main(void)
{
    BTNode *root=NULL;
    char data[]={"ab/cd*+ef/+g+"};//任意的后缀表达式
    int num;
    num=strlen(data);
    root=CreatExpressionTree(data,num);
    //构造出表达式树后以不同的形式输出，观察结果
    printf("后序遍历结果为：");
    PostOrder_LRD(root);
    printf("\n中序遍历结果为：");
    PostOrder_LDR(root);
    printf("\n先序遍历结果为：");
    PostOrder_DLR(root);
    return 0;
}

//构造表达式树的函数 核心代码
BTNode* CreatExpressionTree(char data[],int num)
{
    BTNode *p=NULL;
    int i=0;
    BTNode* Stack[5];
    int top=-1;
    for(i=0;i<num;i++){
        p=(BTNode *)malloc(sizeof(BTNode));
        p->right=p->left=NULL;
        p->data=data[i];
        if(p->data<=122 && p->data>=97){//p->data为小写字母
            Stack[++top]=p;
        }
        else{
            p->right=Stack[top--];
            p->left=Stack[top--];
            Stack[++top]=p;
        }
    }
    return Stack[0];
}
void PostOrder_LDR(BTNode *root)	//中序遍历
{
    if(root){
        PostOrder_LDR(root->left);
        printf("%c ",root->data);
        PostOrder_LDR(root->right);
    }
}
void PostOrder_DLR(BTNode *root)	//先序遍历
{
    if(root){
        printf("%c ",root->data);
        PostOrder_DLR(root->left);
        PostOrder_DLR(root->right);
    }
}
void PostOrder_LRD(BTNode *root)	//后序遍历
{
    if(root){
        PostOrder_LRD(root->left);
        PostOrder_LRD(root->right);
        printf("%c ",root->data);
    }
}