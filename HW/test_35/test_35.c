#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;      // 係數
    int exp;       // 次方數
    struct Node* next;
} Node;

// 建立節點
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 將節點插入鏈結串列（遞減次方順序）
void insertNode(Node** head, int coef, int exp) {
    if (coef == 0) return;

    Node* newNode = createNode(coef, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else if ((*head)->exp == exp) {
        (*head)->coef += coef;
        if ((*head)->coef == 0) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        free(newNode);
    } else {
        Node* curr = *head;
        while (curr->next && curr->next->exp > exp)
            curr = curr->next;

        if (curr->next && curr->next->exp == exp) {
            curr->next->coef += coef;
            if (curr->next->coef == 0) {
                Node* temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
            free(newNode);
        } else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

// 建立多項式
Node* buildPoly(int* arr, int len) {
    Node* head = NULL;
    for (int i = 0; i < len; ++i)
        insertNode(&head, arr[i], len - 1 - i);
    return head;
}

// 合併兩個多項式
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1) {
        insertNode(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        insertNode(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return result;
}

// 輸出多項式
void printPoly(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }

    Node* curr = head;
    int first = 1;
    while (curr) {
        int c = curr->coef;
        int e = curr->exp;

        if (c == 0) {
            curr = curr->next;
            continue;
        }

        if (!first) {
            if (c > 0)
                printf("+");
        }

        if (e == 0)
            printf("%d", c);
        else {
            if (c == -1)
                printf("-");
            else if (c != 1)
                printf("%d", c);
            if (e == 1)
                printf("x");
            else
                printf("x^%d", e);
        }

        first = 0;
        curr = curr->next;
    }
    printf("\n");
}

// 釋放記憶體
void freePoly(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int a[100], b[100];
    int len1 = 0, len2 = 0;
    char ch;

    // 讀取第一行輸入
    while (scanf("%d", &a[len1]) == 1) {
        ch = getchar();
        if (ch == '\n') break;
        len1++;
    }
    len1++;

    // 讀取第二行輸入
    while (scanf("%d", &b[len2]) == 1) {
        ch = getchar();
        if (ch == '\n') break;
        len2++;
    }
    len2++;

    Node* poly1 = buildPoly(a, len1);
    Node* poly2 = buildPoly(b, len2);

    Node* result = addPoly(poly1, poly2);
    printPoly(result);

    // 釋放記憶體
    freePoly(poly1);
    freePoly(poly2);
    freePoly(result);

    return 0;
}
