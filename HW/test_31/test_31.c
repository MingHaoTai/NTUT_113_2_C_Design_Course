#include <stdio.h>
#include <stdlib.h>

typedef enum scoreType_s {
    G, GPA, S
} scoreType_t;

typedef enum G_s {
    Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X
} G_t;

typedef enum GPA_s {
    b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0
} GPA_t;

typedef enum S_s {
    b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0
} S_t;

typedef union student_s {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

int G_to_score(G_t grade) {
    switch(grade) {
        case Aplus: return 95;
        case A: return 90;
        case Aduce: return 85;
        case Bplus: return 85;
        case B: return 80;
        case Bduce: return 75;
        case Cplus: return 70;
        case C: return 65;
        case Cduce: return 60;
        case F: return 0;
        case X: return 0;
    }
    return 0;
}

int GPA_to_score(GPA_t gpa) {
    switch(gpa) {
        case b4dot3: return 95;
        case b4dot0: return 90;
        case b3dot7: return 87;
        case b3dot3: return 83;
        case b3dot0: return 80;
        case b2dot7: return 77;
        case b2dot3: return 73;
        case b2dot0: return 70;
        case b1dot7: return 67;
        case b1: return 63;
        case b0: return 0;
    }
    return 0;
}

int S_to_score(S_t score_range) {
    switch(score_range) {
        case b90to100: return 95;
        case b85to89: return 87;
        case b80to84: return 82;
        case b77to79: return 78;
        case b73to76: return 75;
        case b70to72: return 71;
        case b67to69: return 68;
        case b63to66: return 64;
        case b60to62: return 61;
        case b1to59: return 50;
        case b0to0: return 0;
    }
    return 0;
}

typedef struct {
    int id;
    int average_score;
} student_info;

int compare(const void *a, const void *b) {
    return ((student_info*)a)->average_score - ((student_info*)b)->average_score;
}

int main() {
    int M, N;
    scanf("%d", &M);
    scoreType_t score_types[M];

    // Reading the score types for M courses
    for (int i = 0; i < M; i++) {
        char score_type[5];
        scanf("%s", score_type);
        if (score_type[0] == 'G') {
            score_types[i] = G;
        } else if (score_type[0] == 'G' && score_type[1] == 'P') {
            score_types[i] = GPA;
        } else {
            score_types[i] = S;
        }
    }

    scanf("%d", &N);
    student_info students[N];
    student_t scores[M];

    // Reading student data
    for (int i = 0; i < N; i++) {
        int student_id;
        scanf("%d", &student_id);
        students[i].id = student_id;
        int total_score = 0;

        for (int j = 0; j < M; j++) {
            if (score_types[j] == G) {
                char grade[3];
                scanf("%s", grade);
                if (grade[0] == 'A' && grade[1] == '+') {
                    scores[j].G = Aplus;
                } else if (grade[0] == 'A') {
                    scores[j].G = A;
                } else if (grade[0] == 'B' && grade[1] == '+') {
                    scores[j].G = Bplus;
                } else if (grade[0] == 'B') {
                    scores[j].G = B;
                } else if (grade[0] == 'C' && grade[1] == '+') {
                    scores[j].G = Cplus;
                } else if (grade[0] == 'C') {
                    scores[j].G = C;
                } else if (grade[0] == 'F') {
                    scores[j].G = F;
                } else if (grade[0] == 'X') {
                    scores[j].G = X;
                }
                total_score += G_to_score(scores[j].G);
            } else if (score_types[j] == GPA) {
                float gpa;
                scanf("%f", &gpa);
                if (gpa == 4.3) scores[j].GPA = b4dot3;
                else if (gpa == 4.0) scores[j].GPA = b4dot0;
                else if (gpa == 3.7) scores[j].GPA = b3dot7;
                else if (gpa == 3.3) scores[j].GPA = b3dot3;
                else if (gpa == 3.0) scores[j].GPA = b3dot0;
                else if (gpa == 2.7) scores[j].GPA = b2dot7;
                else if (gpa == 2.3) scores[j].GPA = b2dot3;
                else if (gpa == 2.0) scores[j].GPA = b2dot0;
                else if (gpa == 1.7) scores[j].GPA = b1dot7;
                else if (gpa == 1.0) scores[j].GPA = b1;
                else scores[j].GPA = b0;
                total_score += GPA_to_score(scores[j].GPA);
            } else if (score_types[j] == S) {
                char score_range[10];
                scanf("%s", score_range);
                if (strcmp(score_range, "90-100") == 0) {
                    scores[j].S = b90to100;
                } else if (strcmp(score_range, "85-89") == 0) {
                    scores[j].S = b85to89;
                } else if (strcmp(score_range, "80-84") == 0) {
                    scores[j].S = b80to84;
                } else if (strcmp(score_range, "77-79") == 0) {
                    scores[j].S = b77to79;
                } else if (strcmp(score_range, "73-76") == 0) {
                    scores[j].S = b73to76;
                } else if (strcmp(score_range, "70-72") == 0) {
                    scores[j].S = b70to72;
                } else if (strcmp(score_range, "67-69") == 0) {
                    scores[j].S = b67to69;
                } else if (strcmp(score_range, "63-66") == 0) {
                    scores[j].S = b63to66;
                } else if (strcmp(score_range, "60-62") == 0) {
                    scores[j].S = b60to62;
                } else if (strcmp(score_range, "1-59") == 0) {
                    scores[j].S = b1to59;
                } else {
                    scores[j].S = b0to0;
                }
                total_score += S_to_score(scores[j].S);
            }
        }

        students[i].average_score = total_score / M;
    }

    // Sorting students by average score
    qsort(students, N, sizeof(student_info), compare);

    // Outputting results
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", students[i].id, students[i].average_score);
    }

    return 0;
}
