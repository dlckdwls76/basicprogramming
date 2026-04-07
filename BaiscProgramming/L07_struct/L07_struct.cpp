#include <cstdio>
#include <cstring>
// 예시 1: 기본 구조체 선언
struct Student {
    int id;
    char name[50];
    int age;
    double gpa;
};

// 예시 2: 좌표 구조체
struct Point {
    int x;
    int y;
};

// 예시 3: 도서 정보 구조체
struct Book {
    int bookID;
    char title[100];
    char author[50];
    int pages;
    int year;
};

// 예시 4: 직원 정보 구조체
struct Employee {
    int empID;
    char name[50];
    char department[30];
    int salary;
};

// 예시 5: 날짜 구조체
struct Date {
    int year;
    int month;
    int day;
};

int main() {
    printf("=== C++ Struct Examples ===\n\n");

    // 예시 1: 학생 정보 구조체
    printf("1. Student Structure:\n");
    Student student1;
    student1.id = 1001;
    strcpy_s(student1.name, sizeof(student1.name), "Kim Min-jun");
    student1.age = 20;
    student1.gpa = 3.85;
    
    printf("  Student ID: %d\n", student1.id);
        printf("  Name: %s\n", student1.name);
    printf("  Age: %d\n", student1.age);
    printf("  GPA: %.2f\n", student1.gpa);
    printf("\n");

    // 예시 2: 여러 학생 정보
    printf("2. Multiple Students:\n");
    Student student2;
    student2.id = 1002;
    strcpy_s(student2.name, sizeof(student2.name), "Lee Ji-woo");
    student2.age = 21;
    student2.gpa = 3.65;
    
    Student student3;
    student3.id = 1003;
    strcpy_s(student3.name, sizeof(student3.name), "Park Soo-jin");
    student3.age = 20;
    student3.gpa = 3.92;
    
    printf("  Student 1: %s (ID: %d, Age: %d)\n", student1.name, student1.id, student1.age);
    printf("  Student 2: %s (ID: %d, Age: %d)\n", student2.name, student2.id, student2.age);
    printf("  Student 3: %s (ID: %d, Age: %d)\n", student3.name, student3.id, student3.age);
    printf("\n");

    // 예시 3: 점(Point) 구조체
    printf("3. Point Structure:\n");
    Point p1;
    p1.x = 10;
    p1.y = 20;
    
    Point p2 = {30, 40};  // 초기화
    
    printf("  Point 1: (%d, %d)\n", p1.x, p1.y);
    printf("  Point 2: (%d, %d)\n", p2.x, p2.y);
    printf("\n");

    // 예시 4: 도서 정보 구조체
    printf("4. Book Structure:\n");
    Book book1;
    book1.bookID = 501;
    strcpy_s(book1.title, sizeof(book1.title), "C++ Programming");
    strcpy_s(book1.author, sizeof(book1.author), "Bjarne Stroustrup");
    book1.pages = 1000;
    book1.year = 2013;
    
    printf("  Book ID: %d\n", book1.bookID);
    printf("  Title: %s\n", book1.title);
    printf("  Author: %s\n", book1.author);
    printf("  Pages: %d\n", book1.pages);
    printf("  Year: %d\n", book1.year);
    printf("\n");

    // 예시 5: 직원 정보 구조체
    printf("5. Employee Structure:\n");
    Employee emp1;
    emp1.empID = 2001;
    strcpy_s(emp1.name, sizeof(emp1.name), "Choi Hae-won");
    strcpy_s(emp1.department, sizeof(emp1.department), "Development");
    emp1.salary = 5000000;
    
    printf("  Employee ID: %d\n", emp1.empID);
    printf("  Name: %s\n", emp1.name);
    printf("  Department: %s\n", emp1.department);
    printf("  Salary: %d\n", emp1.salary);
    printf("\n");

    // 예시 6: 구조체 배열
    printf("6. Array of Structures:\n");
    Point points[3] = {
        {0, 0},
        {5, 10},
        {15, 20}
    };
    
    printf("  Points:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Point %d: (%d, %d)\n", i + 1, points[i].x, points[i].y);
    }
    printf("\n");

    // 예시 7: 날짜 구조체
    printf("7. Date Structure:\n");
    Date today;
    today.year = 2026;
    today.month = 4;
    today.day = 7;
    
    printf("  Today: %04d-%02d-%02d\n", today.year, today.month, today.day);
    printf("\n");

    // 예시 8: 구조체 멤버 크기
    printf("8. Structure Size:\n");
    printf("  sizeof(Student): %zu bytes\n", sizeof(Student));
    printf("  sizeof(Point): %zu bytes\n", sizeof(Point));
    printf("  sizeof(Book): %zu bytes\n", sizeof(Book));
    printf("  sizeof(Employee): %zu bytes\n", sizeof(Employee));
    printf("  sizeof(Date): %zu bytes\n", sizeof(Date));
    printf("\n");

    // 예시 9: 구조체 멤버 주소
    printf("9. Member Address:\n");
    Student st;
    st.id = 100;
    strcpy_s(st.name, sizeof(st.name), "Test");
    st.age = 25;
    st.gpa = 3.5;
    
    printf("  st의 주소: %p\n", (void*)&st);
    printf("  st.id의 주소: %p\n", (void*)&st.id);
    printf("  st.name의 주소: %p\n", (void*)&st.name);
    printf("  st.age의 주소: %p\n", (void*)&st.age);
    printf("  st.gpa의 주소: %p\n", (void*)&st.gpa);
    printf("\n");

    // 예시 10: 구조체와 포인터
    printf("10. Struct and Pointer:\n");
    Student s1;
    s1.id = 5001;
    strcpy_s(s1.name, sizeof(s1.name), "Hong Gildong");
    s1.age = 22;
    s1.gpa = 3.75;
    
    Student* pStudent = &s1;
    printf("  포인터로 접근:\n");
    printf("  pStudent->id: %d\n", pStudent->id);
    printf("  pStudent->name: %s\n", pStudent->name);
    printf("  pStudent->age: %d\n", pStudent->age);
    printf("  pStudent->gpa: %.2f\n", pStudent->gpa);
    printf("\n");

    // 예시 11: 다양한 멤버 타입
    printf("11. Various Member Types:\n");
    struct Person {
        int id;           // 정수
        char initial;     // 문자
        double height;    // 실수
        char city[30];    // 문자열
    };
    
    Person person1;
    person1.id = 1;
    person1.initial = 'K';
    person1.height = 175.5;
    strcpy_s(person1.city, sizeof(person1.city), "Seoul");
    
    printf("  ID: %d\n", person1.id);
    printf("  Initial: %c\n", person1.initial);
    printf("  Height: %.1f cm\n", person1.height);
    printf("  City: %s\n", person1.city);
    printf("\n");

    // 예시 12: 구조체 복사
    printf("12. Struct Copy:\n");
    Point original = {10, 20};
    Point copy = original;
    
    printf("  Original: (%d, %d)\n", original.x, original.y);
    printf("  Copy: (%d, %d)\n", copy.x, copy.y);
    copy.x = 100;
    printf("  After changing copy.x to 100:\n");
    printf("  Original: (%d, %d)\n", original.x, original.y);
    printf("  Copy: (%d, %d)\n", copy.x, copy.y);
    printf("\n");

    // 예시 13: 직사각형 구조체
    printf("13. Rectangle Structure:\n");
    struct Rectangle {
        int width;
        int height;
    };
    
    Rectangle rect = {20, 30};
    int area = rect.width * rect.height;
    int perimeter = 2 * (rect.width + rect.height);
    
    printf("  Width: %d\n", rect.width);
    printf("  Height: %d\n", rect.height);
    printf("  Area: %d\n", area);
    printf("  Perimeter: %d\n", perimeter);
    printf("\n");

    // 예시 14: 구조체 배열 순회
    printf("14. Traverse Array of Structures:\n");
    struct Course {
        int courseID;
        char courseName[50];
        int credits;
    };
    
    Course courses[3] = {
        {101, "C++ Programming", 3},
        {102, "Data Structures", 3},
        {103, "Web Development", 2}
    };
    
    printf("  Courses:\n");
    for (int i = 0; i < 3; i++) {
        printf("  ID: %d, Name: %s, Credits: %d\n", 
               courses[i].courseID, courses[i].courseName, courses[i].credits);
    }
    printf("\n");

    // 예시 15: 구조체 요약
    printf("15. Struct Summary:\n");
    printf("  구조체는 여러 자료형을 하나로 묶는 방법\n");
    printf("  멤버 접근: 구조체변수.멤버이름\n");
    printf("  포인터 접근: 포인터->멤버이름\n");
    printf("  배열로 여러 구조체를 관리 가능\n");

    return 0;
}