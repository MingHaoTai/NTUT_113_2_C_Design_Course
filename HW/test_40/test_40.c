#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *left, *right;
} tree_t;
typedef tree_t* btree;

// 建立新節點
btree create_node(char data) {
    btree new_node = (btree)malloc(sizeof(tree_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// 找中序中的根索引
int find_index(char *inorder, int in_start, int in_end, char root) {
    for (int i = in_start; i <= in_end; ++i) {
        if (inorder[i] == root) return i;
    }
    return -1;
}

// 用前序與中序建樹
btree build_tree_pre_in(char *preorder, char *inorder, int in_start, int in_end, int *pre_index) {
    if (in_start > in_end) return NULL;

    char root_data = preorder[*pre_index];
    (*pre_index)++;
    btree root = create_node(root_data);

    if (in_start == in_end) return root;

    int in_index = find_index(inorder, in_start, in_end, root_data);

    root->left = build_tree_pre_in(preorder, inorder, in_start, in_index - 1, pre_index);
    root->right = build_tree_pre_in(preorder, inorder, in_index + 1, in_end, pre_index);

    return root;
}

// 用後序與中序建樹
btree build_tree_post_in(char *postorder, char *inorder, int in_start, int in_end, int *post_index) {
    if (in_start > in_end) return NULL;

    char root_data = postorder[*post_index];
    (*post_index)--;
    btree root = create_node(root_data);

    if (in_start == in_end) return root;

    int in_index = find_index(inorder, in_start, in_end, root_data);

    root->right = build_tree_post_in(postorder, inorder, in_index + 1, in_end, post_index);
    root->left = build_tree_post_in(postorder, inorder, in_start, in_index - 1, post_index);

    return root;
}

// 層序遍歷 (level order traversal)
void level_order(btree root) {
    if (!root) return;
    btree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        btree current = queue[front++];
        printf("%c", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

// 主程式
int main() {
    char type1, type2;
    char str1[25], str2[25];
    scanf(" %c", &type1);
    scanf("%s", str1);
    scanf(" %c", &type2);
    scanf("%s", str2);

    btree root = NULL;
    int len = strlen(str1);

    if ((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2 == 'P')) {
        char *preorder = (type1 == 'P') ? str1 : str2;
        char *inorder  = (type1 == 'I') ? str1 : str2;
        int pre_index = 0;
        root = build_tree_pre_in(preorder, inorder, 0, len - 1, &pre_index);
    } else if ((type1 == 'O' && type2 == 'I') || (type1 == 'I' && type2 == 'O')) {
        char *postorder = (type1 == 'O') ? str1 : str2;
        char *inorder   = (type1 == 'I') ? str1 : str2;
        int post_index = len - 1;
        root = build_tree_post_in(postorder, inorder, 0, len - 1, &post_index);
    }

    level_order(root);
    printf("\n");
    return 0;
}
