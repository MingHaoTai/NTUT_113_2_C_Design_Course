#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 55
#define MAX_CASES 10

int is_all_upper(const char *s, int index, int len) {
    for (int i = 0; i < len; i++) {
        if (!isupper(s[index + i])) return 0;
    }
    return 1;
}

int is_all_lower(const char *s, int index, int len) {
    for (int i = 0; i < len; i++) {
        if (!islower(s[index + i])) return 0;
    }
    return 1;
}

int is_k_alternating(const char *s, int start, int len, int k) {
    if (len % k != 0) return 0;
    int blocks = len / k;
    int is_upper = isupper(s[start]) ? 1 : 0;

    for (int i = 0; i < blocks; i++) {
        int idx = start + i * k;
        if (is_upper) {
            if (!is_all_upper(s, idx, k)) return 0;
        } else {
            if (!is_all_lower(s, idx, k)) return 0;
        }
        is_upper = 1 - is_upper;
    }
    return 1;
}

int find_max_k_alternating(const char *s, int k) {
    int len = strlen(s);
    int maxlen = 0;

    for (int i = 0; i <= len - k; i++) {
        for (int l = k * 2; i + l <= len; l += k) {
            if (is_k_alternating(s, i, l, k)) {
                if (l > maxlen) maxlen = l;
            }
        }
    }

    return maxlen;
}

int main() {
    int N;
    scanf("%d", &N);

    char strings[MAX_CASES][MAX_LEN];
    int ks[MAX_CASES];
    int results[MAX_CASES];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", strings[i], &ks[i]);
    }

    for (int i = 0; i < N; i++) {
        results[i] = find_max_k_alternating(strings[i], ks[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
