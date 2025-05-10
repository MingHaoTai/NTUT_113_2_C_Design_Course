#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000
#define WORD_MAX 100

// 判斷是否為符合條件的標點符號
int is_punctuation(char ch) {
    return ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}

// 拆分單詞主體與末尾標點，並回傳是否符合目標單詞
int match_word(const char *word, const char *target, char *core, char *punct) {
    int len = strlen(word);
    if (len == 0 || strchr(word, '\'') || strchr(word, '`')) return 0;

    // 如果末尾是符合的標點
    if (is_punctuation(word[len - 1])) {
        strcpy(punct, "");
        if (len >= 2 && is_punctuation(word[len - 2])) return 0; // 多個標點不符合
        strcpy(punct, word + len - 1);
        strncpy(core, word, len - 1);
        core[len - 1] = '\0';
    } else {
        strcpy(core, word);
        strcpy(punct, "");
    }
    return strcmp(core, target) == 0;
}

void process(char words[][WORD_MAX], int word_count, const char *P, const char *Q) {
    char core[WORD_MAX], punct[5];
    char output[MAX] = "";

    // 1. 取代
    output[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        if (match_word(words[i], P, core, punct)) {
            strcat(output, Q);
            strcat(output, punct);
        } else {
            strcat(output, words[i]);
        }
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    // 2. 前插入
    output[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        if (match_word(words[i], P, core, punct)) {
            strcat(output, Q);
            strcat(output, " ");
        }
        strcat(output, words[i]);
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    // 3. 後插入
    output[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        strcat(output, words[i]);
        if (match_word(words[i], P, core, punct)) {
            strcat(output, " ");
            strcat(output, Q);
        }
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    // 4. 刪除
    output[0] = '\0';
    int first = 1;
    for (int i = 0; i < word_count; i++) {
        if (!match_word(words[i], P, core, punct)) {
            if (!first) strcat(output, " ");
            strcat(output, words[i]);
            first = 0;
        }
    }
    printf("%s\n", output);

    // 5. 反轉順序
    output[0] = '\0';
    for (int i = word_count - 1; i >= 0; i--) {
        strcat(output, words[i]);
        if (i != 0) strcat(output, " ");
    }
    printf("%s\n", output);
}

int main() {
    char line[MAX], P[WORD_MAX], Q[WORD_MAX];
    char words[200][WORD_MAX];
    int word_count = 0;

    // 讀取文章、P、Q
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    scanf("%s", P);
    scanf("%s", Q);

    // 拆解單詞
    char *token = strtok(line, " ");
    while (token != NULL) {
        strcpy(words[word_count++], token);
        token = strtok(NULL, " ");
    }

    process(words, word_count, P, Q);

    return 0;
}
