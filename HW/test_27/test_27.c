#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define WORD_MAX 100

int is_punctuation(char ch) {
    return ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}

int wordMatch(char *word, char *target, char *core, char *punct) {
    int len = strlen(word);
    if (len == 0 || strchr(word, '\'') || strchr(word, '`')) return 0;

    if (is_punctuation(word[len - 1])){
        strcpy(punct, "");
        if (len >= 2 && is_punctuation(word[len - 2])) return 0;
        strcpy(punct, word + len - 1);
        strncpy(core, word, len - 1);
        core[len - 1] = '\0';
    }
    else {
        strcpy(core, word);
        strcpy(punct, "");
    }

    return strcmp(core, target) == 0;
}

void process(char words[][WORD_MAX], int word_count, char *P, char *Q) {
    char core[WORD_MAX], punct[5];
    char output[MAX] = "";

    output[0] = '\0';
    for (int i = 0; i < word_count; i++){
        if (wordMatch(words[i], P, core, punct)) {
            strcat(output, Q);
            strcat(output, punct);
        }
        else {
            strcat(output, words[i]);
        }
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    output[0] = '\0';
    for (int i = 0; i < word_count; i++){
        if (wordMatch(words[i], P, core, punct)) {
            strcat(output, Q);
            strcat(output, " ");
        }
        strcat(output, words[i]);
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    output[0] = '\0';
    for (int i = 0; i < word_count; i++){
        strcat(output, words[i]);
        if (wordMatch(words[i], P, core, punct)) {
            strcat(output, " ");
            strcat(output, Q);
        }
        if (i != word_count - 1) strcat(output, " ");
    }
    printf("%s\n", output);

    output[0] = '\0';
    int first = 1;
    for (int i = 0; i < word_count; i++){
        if (!wordMatch(words[i], P, core, punct)) {
            if (!first) strcat(output, " ");
            strcat(output, words[i]);
            first = 0;
        }
    }
    printf("%s\n", output);

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

    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    scanf("%s", P);
    scanf("%s", Q);

    char *token = strtok(line, " ");
    while(token != NULL){
        strcpy(words[word_count++], token);
        token = strtok(NULL, " ");
    }

    process(words, word_count, P, Q);

    return 0;
}