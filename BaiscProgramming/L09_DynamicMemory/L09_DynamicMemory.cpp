#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main() {
    printf("=== C++ Dynamic Memory Allocation Examples ===\n\n");

    // 예시 1: 기본 동적할당 (정수)
    printf("1. Basic Dynamic Allocation (int):\n");
    int* ptr = new int;
    *ptr = 100;
    printf("  포인터 주소: %p\n", (void*)ptr);
    printf("  포인터 값: %d\n", *ptr);
    delete ptr;
    ptr = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 2: 초기화와 함께 동적할당
    printf("2. Dynamic Allocation with Initialization:\n");
    int* num = new int(50);
    double* dbl = new double(3.14);
    printf("  int 값: %d\n", *num);
    printf("  double 값: %.2f\n", *dbl);
    delete num;
    delete dbl;
    num = nullptr;
    dbl = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 3: 1D 배열 동적할당
    printf("3. Dynamic Array Allocation (1D):\n");
    int size = 5;
    int* arr = new int[size];
    
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }
    
    printf("  배열 요소:\n");
    for (int i = 0; i < size; i++) {
        printf("    arr[%d] = %d\n", i, arr[i]);
    }
    delete[] arr;
    arr = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 4: 2D 배열 동적할당
    printf("4. Dynamic Array Allocation (2D):\n");
    int rows = 3;
    int cols = 4;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // 값 초기화
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    
    // 출력
    printf("  2D 배열:\n");
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 5: 동적할당 구조체
    printf("5. Dynamic Struct Allocation:\n");
    struct Student {
        int id;
        char name[50];
        double gpa;
    };
    
    Student* student = new Student;
    student->id = 1001;
    strncpy(student->name, "Kim Min-jun", sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';
    student->gpa = 3.85;
    
    printf("  Student ID: %d\n", student->id);
    printf("  Name: %s\n", student->name);
    printf("  GPA: %.2f\n", student->gpa);
    delete student;
    student = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 6: 구조체 배열 동적할당
    printf("6. Dynamic Struct Array:\n");
    int numStudents = 3;
    Student* students = new Student[numStudents];
    
    strncpy(students[0].name, "Lee Ji-woo", sizeof(students[0].name) - 1);
    students[0].name[sizeof(students[0].name) - 1] = '\0';
    students[0].id = 1001;
    students[0].gpa = 3.65;
    
    strncpy(students[1].name, "Park Soo-jin", sizeof(students[1].name) - 1);
    students[1].name[sizeof(students[1].name) - 1] = '\0';
    students[1].id = 1002;
    students[1].gpa = 3.92;
    
    strncpy(students[2].name, "Choi Hae-won", sizeof(students[2].name) - 1);
    students[2].name[sizeof(students[2].name) - 1] = '\0';
    students[2].id = 1003;
    students[2].gpa = 3.75;
    
    printf("  학생 목록:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("  ID: %d, Name: %s, GPA: %.2f\n", 
               students[i].id, students[i].name, students[i].gpa);
    }
    delete[] students;
    students = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 7: 포인터 배열 동적할당
    printf("7. Dynamic Pointer Array:\n");
    int n = 3;
    int** ptrArray = new int*[n];
    
    for (int i = 0; i < n; i++) {
        ptrArray[i] = new int(i * 100 + 50);
    }
    
    printf("  포인터 배열의 값:\n");
    for (int i = 0; i < n; i++) {
        printf("    ptrArray[%d] = %d\n", i, *ptrArray[i]);
    }
    
    for (int i = 0; i < n; i++) {
        delete ptrArray[i];
    }
    delete[] ptrArray;
    ptrArray = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 8: 동적 문자열 할당
    printf("8. Dynamic String Allocation:\n");
    char* str = new char[100];
    strncpy(str, "Hello, Dynamic Memory!", 99);
    str[99] = '\0';
    printf("  문자열: %s\n", str);
    printf("  길이: %zu\n", strlen(str));
    delete[] str;
    str = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 9: NULL 포인터 체크
    printf("9. NULL Pointer Check:\n");
    int* ptr_check = nullptr;
    
    if (ptr_check == nullptr) {
        printf("  포인터가 NULL입니다\n");
    }
    
    ptr_check = new int(50);
    if (ptr_check != nullptr) {
        printf("  포인터가 유효합니다\n");
        printf("  값: %d\n", *ptr_check);
    }
    delete ptr_check;
    ptr_check = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 10: 동적할당 배열 초기화
    printf("10. Dynamic Array with Initialization:\n");
    int* arr2 = new int[5]{10, 20, 30, 40, 50};
    
    printf("  초기화된 배열:\n");
    for (int i = 0; i < 5; i++) {
        printf("    arr2[%d] = %d\n", i, arr2[i]);
    }
    delete[] arr2;
    arr2 = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 11: 메모리 재할당
    printf("11. Reallocate Memory:\n");
    int* original = new int[3]{1, 2, 3};
    
    printf("  원본 배열 (크기 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("    %d ", original[i]);
    }
    printf("\n");
    
    int* expanded = new int[5];
    for (int i = 0; i < 3; i++) {
        expanded[i] = original[i];
    }
    expanded[3] = 4;
    expanded[4] = 5;
    
    printf("  확장된 배열 (크기 5):\n");
    for (int i = 0; i < 5; i++) {
        printf("    %d ", expanded[i]);
    }
    printf("\n");
    
    delete[] original;
    delete[] expanded;
    original = nullptr;
    expanded = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 12: 동적할당 메모리 크기
    printf("12. Memory Size Comparison:\n");
    int staticArr[10];
    int* dynamicArr = new int[10];
    
    printf("  스택 배열 크기: %zu bytes\n", sizeof(staticArr));
    printf("  동적 배열 크기: %zu bytes\n", sizeof(int) * 10);
    printf("  동적 포인터 크기: %zu bytes\n", sizeof(dynamicArr));
    
    delete[] dynamicArr;
    dynamicArr = nullptr;
    printf("\n");

    // 예시 13: 포인터 산술 연산
    printf("13. Pointer Arithmetic:\n");
    int* arr3 = new int[5]{10, 20, 30, 40, 50};
    int* p = arr3;
    
    printf("  배열: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    
    printf("  포인터 증감:\n");
    printf("    *p = %d\n", *p);
    p++;
    printf("    p++ 후 *p = %d\n", *p);
    p += 2;
    printf("    p += 2 후 *p = %d\n", *p);
    
    delete[] arr3;
    arr3 = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 14: 동적할당 메모리 주소
    printf("14. Dynamic Memory Address:\n");
    int* p1 = new int(100);
    int* p2 = new int(200);
    int* p3 = new int(300);
    
    printf("  p1 주소: %p, 값: %d\n", (void*)p1, *p1);
    printf("  p2 주소: %p, 값: %d\n", (void*)p2, *p2);
    printf("  p3 주소: %p, 값: %d\n", (void*)p3, *p3);
    
    delete p1;
    delete p2;
    delete p3;
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 15: 동적할당 요약
    printf("15. Dynamic Allocation Summary:\n");
    printf("  new: 동적 메모�� 할당 (힙)\n");
    printf("  delete: 단일 변수 메모리 해제\n");
    printf("  new[]: 배열 메모리 할당\n");
    printf("  delete[]: 배열 메모리 해제\n");
    printf("  nullptr: NULL 포인터\n");
    printf("  중요: new로 할당하면 delete로 해제\n");
    printf("  중요: new[]로 할당하면 delete[]로 해제\n");
    printf("  주의: 메모리 누수 방지\n");

    return 0;
}