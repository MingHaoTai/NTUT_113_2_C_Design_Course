#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum scoreType_s { G, GPA, S } scoreType_t;
typedef enum G_s { Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X } G_t;
typedef enum GPA_s { b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0 } GPA_t;
typedef enum S_s { b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0 } S_t;

typedef union student_s {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

typedef struct {
    int id;
    student_t scores[4]; // 最多4門課
    int avgScore;
} studentData_t;

int GScore[]   = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
int GPAScore[] = {95, 90, 87, 85, 80, 77, 75, 70, 67, 60, 47};
int SScore[]   = {95, 87, 82, 79, 76, 72, 68, 65, 60, 50, 0};
// 等第文字對應
const char* GStr[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F", "X"};
const char* GPAStr[] = {"4.3", "4.0", "3.7", "3.3", "3.0", "2.7", "2.3", "2.0", "1.7", "1", "0"};
const char* SStr[] = {"90-100", "85-89", "80-84", "77-79", "73-76", "70-72", "67-69", "63-66", "60-62", "1-59", "0"};

int findIndex(const char* input, const char* list[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(input, list[i]) == 0) 
            return i;
    }
    return -1;
}

int compare(const void* a, const void* b) {
    studentData_t* s1 = (studentData_t*)a;
    studentData_t* s2 = (studentData_t*)b;
    return s1->avgScore - s2->avgScore;
}

int main() {
    int M, N;
    scoreType_t types[4]; // 最多4門課
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        char typeStr[10];
        scanf("%s", typeStr);
        if (strcmp(typeStr, "G") == 0)
            types[i] = G;
        else if (strcmp(typeStr, "GPA") == 0)
            types[i] = GPA;
        else
            types[i] = S;
    }
    scanf("%d", &N);
    studentData_t students[10]; // 最多10人
    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].id);
        int total = 0;
        for (int j = 0; j < M; j++) {
            char val[20];
            scanf("%s", val);
            if (types[j] == G) {
                int index = findIndex(val, GStr, 11);
                students[i].scores[j].G = (G_t)index;
                total += GScore[index];
            } else if (types[j] == GPA) {
                int index = findIndex(val, GPAStr, 11);
                students[i].scores[j].GPA = (GPA_t)index;
                total += GPAScore[index];
            } else if (types[j] == S) {
                int index = findIndex(val, SStr, 11);
                students[i].scores[j].S = (S_t)index;
                total += SScore[index];
            }
        }
        // 無條件捨去
        students[i].avgScore = total / M; 
    }
    qsort(students, N, sizeof(studentData_t), compare);
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", students[i].id, students[i].avgScore);
    }
    return 0;
}