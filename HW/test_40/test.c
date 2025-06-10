#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_t {
    char data;
    struct node_t *left, *right;
} tree_t;
typedef tree_t *btree;

btree buildFromPreIn(char *pre, char *in, int len){
    if (len <= 0) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = pre[0];
    int i;
    for (i = 0; i < len; i++){
        if (in[i] == pre[0]) break;
    }
    root->left = buildFromPreIn(pre + 1, in, i);
    root->right = buildFromPreIn(pre + i + 1, in + i + 1, len - i - 1);
    return root;
}

btree buildFromPostIn(char *post, char *in, int len){
    if (len <= 0) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = post[len - 1];
    int i;
    for (i = 0; i < len; i++){
        if (in[i] == post[len - 1]) break;
    }
    root->left = buildFromPostIn(post, in, i);
    root->right = buildFromPostIn(post + i, in + i + 1, len - i - 1);
    return root;
}

void levelOrder(btree root){
    btree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        btree current = queue[front++];
        printf("%c", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

int main(){
    char order1, order2;
    char str1[100], str2[100];
    scanf(" %c", &order1);
    scanf("%s", str1);
    scanf(" %c", &order2);
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    btree root = NULL;
    if (order1 == 'P' && order2 == 'I') {
        root = buildFromPreIn(str1, str2, len2);
    }
    else if (order1 == 'I' && order2 == 'P') {
        root = buildFromPreIn(str2, str1, len1);
    }
    else if (order1 == 'O' && order2 == 'I') {
        root = buildFromPostIn(str1, str2, len2);
    }
    else if (order1 == 'I' && order2 == 'O') {
        root = buildFromPostIn(str2, str1, len1);
    }

    levelOrder(root);
    return 0;
}