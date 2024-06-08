#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STUDENT 10

// 定義學生結構
typedef struct {
    char name[2];  // 只需要存一個字母
    char department[50];
    int grade;
    char sid[50];
} Student;

void initializeStudents(Student students[], int numStudents) {
    // 隨機數種子
    srand(time(NULL));

    for (int i = 0; i < numStudents; i++) {
        // 生成隨機學生數據
        sprintf(students[i].name, "%c", 'A' + i);
        sprintf(students[i].department, "Department %d", rand() % 5 + 1);
        students[i].grade = rand() % 4 + 1;
        sprintf(students[i].sid, "SID%04d", rand() % 1000 + 1);
    }
}

// qsort 的比較函數，按學生姓名排序
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

int main() {
    // 創建並初始化學生實例
    Student students[MAX_STUDENT];
    initializeStudents(students, MAX_STUDENT);

    // 使用 qsort 函數按學生姓名排序
    qsort(students, MAX_STUDENT, sizeof(Student), compareStudents);

    // 打印表頭
    printf("+------+--------------+--------+------------+\n");
    printf("| %-4s | %-12s | %-6s | %-10s |\n", "Name", "Department", "Grade", "SID");
    printf("+------+--------------+--------+------------+\n");

    // 打印學生信息
    for (int i = 0; i < MAX_STUDENT; i++) {
        printf("| %-4s | %-12s | %-6d | %-10s |\n", students[i].name, students[i].department, students[i].grade, students[i].sid);
    }

    // 打印表尾
    printf("+------+--------------+--------+------------+\n");

    return 0;
}
