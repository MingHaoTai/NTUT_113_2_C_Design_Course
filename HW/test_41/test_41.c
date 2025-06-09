#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_COURSES 100

typedef struct {
    int id;
    int capacity;
    int schedule[24]; // 0~23 hourly
} Room;

typedef struct {
    int id;
    int students;
    int start;
    int end;
    int duration;
} Course;

Room rooms[MAX_ROOMS];
Course courses[MAX_COURSES];
int M, N, b;

int cmp(const void *a, const void *b) {
    Course *c1 = (Course *)a;
    Course *c2 = (Course *)b;
    if (c1->duration != c2->duration)
        return c2->duration - c1->duration; // longer first
    return c2->id - c1->id; // then bigger ID first
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &rooms[i].id, &rooms[i].capacity);
        memset(rooms[i].schedule, 0, sizeof(rooms[i].schedule));
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &courses[i].id, &courses[i].students, &courses[i].start, &courses[i].end);
        courses[i].duration = courses[i].end - courses[i].start;
    }
    scanf("%d", &b);

    qsort(courses, N, sizeof(Course), cmp);

    int total_hours = 0, total_courses = 0;
    typedef struct { int cid, rid; } Assignment;
    Assignment assigned[MAX_COURSES];
    int assign_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (b && courses[i].students > rooms[j].capacity) continue;
            int can_assign = 1;
            for (int t = courses[i].start; t < courses[i].end; t++) {
                if (rooms[j].schedule[t]) {
                    can_assign = 0;
                    break;
                }
            }
            if (can_assign) {
                for (int t = courses[i].start; t < courses[i].end; t++)
                    rooms[j].schedule[t] = 1;
                total_hours += courses[i].duration;
                total_courses++;
                if (b == 2) {
                    assigned[assign_count].cid = courses[i].id;
                    assigned[assign_count].rid = rooms[j].id;
                    assign_count++;
                }
                break; // Assigned, go to next course
            }
        }
    }

    printf("max hours %d\n", total_hours);
    printf("max courses %d\n", total_courses);
    if (b == 2) {
        // Sort by course id ascending for output
        for (int i = 0; i < assign_count - 1; i++) {
            for (int j = i + 1; j < assign_count; j++) {
                if (assigned[i].cid > assigned[j].cid) {
                    Assignment tmp = assigned[i];
                    assigned[i] = assigned[j];
                    assigned[j] = tmp;
                }
            }
        }
        for (int i = 0; i < assign_count; i++) {
            printf("%d %d\n", assigned[i].cid, assigned[i].rid);
        }
    }

    return 0;
}