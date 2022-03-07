#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// + 99  * - 88 77 + / 66 - 55 44 33
#define SIZE 200 //The number digit limitation

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
    BTNode* item;
    struct _node *next;
}StackNode;

typedef struct _stack{
    int size;
    StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
    if(s.size == 0) return 1;
    else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

void createExpTree(BTNode** root,char* prefix)
{
    //Write your code here
    Stack s;
    s.size = 0;
    s.head = NULL;
    int i = strlen(prefix) - 1;
    while(i >= 0 && prefix[i] == ' ') i--;
    while(i >= 0) {
        int j = i;
        while(j >= 0 && prefix[i] != ' ') j--;
        if('0' <= prefix[j] && prefix[j] <= '9') {
            int number = 0;
            for( ; j <= i; j++) {
                number = number * 10 + prefix[j] - '0';
            }
            BTNode* newNode = (BTNode*) malloc(sizeof(BTNode));
            newNode->item = number;
            newNode->left = NULL;
            newNode->right = NULL;
            push(&s, newNode);
        } else {

        }
    }

}

void printTree(BTNode *node){
    //Write your code here
}

void printTreePostfix(BTNode *node){
    //Write your code here

}

double computeTree(BTNode *node){
//Write your code here
}
