#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

// 예시 1: 기본 클래스
class Student {
public:
    int id;
    char name[50];
    double gpa;

    // 멤버 함수 (메서드)
    void PrintInfo() {
        printf("  ID: %d\n", id);
        printf("  Name: %s\n", name);
        printf("  GPA: %.2f\n", gpa);
    }
};

// 예시 2: 생성자와 소멸자가 있는 클래스
class Book {
public:
    int bookID;
    char title[100];
    char author[50];
    int pages;

    // 생성자 (constructor)
    Book() {
        printf("  [생성자 호출] Book 객체 생성됨\n");
        bookID = 0;
        strcpy(title, "");
        strcpy(author, "");
        pages = 0;
    }

    // 소멸자 (destructor)
    ~Book() {
        printf("  [소멸자 호출] Book 객체 소멸됨\n");
    }

    void DisplayBook() {
        printf("  Book ID: %d\n", bookID);
        printf("  Title: %s\n", title);
        printf("  Author: %s\n", author);
        printf("  Pages: %d\n", pages);
    }
};

// 예시 3: 매개변수가 있는 생성자 (수정)
class Person {
public:
    char name[50];
    int age;

    // 매개변수 있는 생성자
    Person(const char* n, int a) {
        strncpy(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
        age = a;
        printf("  [생성자] %s, %d살 생성됨\n", name, age);
    }

    void ShowInfo() {
        printf("  Name: %s, Age: %d\n", name, age);
    }
};

// 예시 4: private과 public
class BankAccount {
private:
    double balance;

public:
    // 생성자
    BankAccount(double initial) {
        balance = initial;
        printf("  계좌 생성 (잔액: %.2f)\n", balance);
    }

    // public 메서드
    void Deposit(double amount) {
        balance += amount;
        printf("  입금: %.2f (현재 잔액: %.2f)\n", amount, balance);
    }

    void Withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            printf("  출금: %.2f (현재 잔액: %.2f)\n", amount, balance);
        } else {
            printf("  잔액 부족\n");
        }
    }

    double GetBalance() {
        return balance;
    }
};

// 예시 5: 계산기 클래스
class Calculator {
public:
    int Add(int a, int b) {
        return a + b;
    }

    int Subtract(int a, int b) {
        return a - b;
    }

    int Multiply(int a, int b) {
        return a * b;
    }

    int Divide(int a, int b) {
        if (b != 0) {
            return a / b;
        } else {
            printf("  0으로 나눌 수 없습니다\n");
            return 0;
        }
    }
};

// 예시 6: 점(Point) 클래스
class Point {
public:
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int px, int py) {
        x = px;
        y = py;
    }

    void Display() {
        printf("  Point: (%d, %d)\n", x, y);
    }

    void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

// 예시 7: 원(Circle) 클래스
class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double GetArea() {
        return 3.14159 * radius * radius;
    }

    double GetPerimeter() {
        return 2 * 3.14159 * radius;
    }

    void ShowInfo() {
        printf("  반지름: %.2f\n", radius);
        printf("  넓이: %.2f\n", GetArea());
        printf("  둘레: %.2f\n", GetPerimeter());
    }
};

// 예시 8: 자동차 클래스 (수정)
class Car {
private:
    char model[50];
    int year;
    int speed;

public:
    Car(const char* m, int y) {
        strncpy(model, m, sizeof(model) - 1);
        model[sizeof(model) - 1] = '\0';
        year = y;
        speed = 0;
    }

    void Accelerate() {
        if (speed < 200) {
            speed += 10;
        }
    }

    void Brake() {
        if (speed > 0) {
            speed -= 10;
        }
    }

    void ShowStatus() {
        printf("  모델: %s\n", model);
        printf("  연도: %d\n", year);
        printf("  속도: %d km/h\n", speed);
    }
};

int main() {
    printf("=== C++ Class Examples ===\n\n");

    // 예시 1: 기본 클래스
    printf("1. Basic Class:\n");
    Student student1;
    student1.id = 1001;
    strncpy(student1.name, "Kim Min-jun", sizeof(student1.name) - 1);
    student1.name[sizeof(student1.name) - 1] = '\0';
    student1.gpa = 3.85;
    student1.PrintInfo();
    printf("\n");

    // 예시 2: 여러 객체
    printf("2. Multiple Objects:\n");
    Student student2;
    student2.id = 1002;
    strncpy(student2.name, "Lee Ji-woo", sizeof(student2.name) - 1);
    student2.name[sizeof(student2.name) - 1] = '\0';
    student2.gpa = 3.65;

    Student student3;
    student3.id = 1003;
    strncpy(student3.name, "Park Soo-jin", sizeof(student3.name) - 1);
    student3.name[sizeof(student3.name) - 1] = '\0';
    student3.gpa = 3.92;

    printf("  Student 1:\n");
    student1.PrintInfo();
    printf("  Student 2:\n");
    student2.PrintInfo();
    printf("  Student 3:\n");
    student3.PrintInfo();
    printf("\n");

    // 예시 3: 생성자와 소멸자
    printf("3. Constructor and Destructor:\n");
    {
        Book book1;
        book1.bookID = 501;
        strncpy(book1.title, "C++ Programming", sizeof(book1.title) - 1);
        book1.title[sizeof(book1.title) - 1] = '\0';
        strncpy(book1.author, "Bjarne Stroustrup", sizeof(book1.author) - 1);
        book1.author[sizeof(book1.author) - 1] = '\0';
        book1.pages = 1000;
        book1.DisplayBook();
    }
    printf("\n");

    // 예시 4: 매개변수가 있는 생성자 (수정됨)
    printf("4. Constructor with Parameters:\n");
    const char* personName = "Hong Gildong";
    Person person1(personName, 30);
    person1.ShowInfo();
    printf("\n");

    // 예시 5: private과 public
    printf("5. Private and Public Members:\n");
    BankAccount account(10000);
    account.Deposit(5000);
    account.Withdraw(3000);
    printf("  최종 잔액: %.2f\n", account.GetBalance());
    printf("\n");

    // 예시 6: 계산기 클래스
    printf("6. Calculator Class:\n");
    Calculator calc;
    printf("  10 + 5 = %d\n", calc.Add(10, 5));
    printf("  10 - 5 = %d\n", calc.Subtract(10, 5));
    printf("  10 * 5 = %d\n", calc.Multiply(10, 5));
    printf("  10 / 5 = %d\n", calc.Divide(10, 5));
    printf("\n");

    // 예시 7: 점(Point) 클래스
    printf("7. Point Class:\n");
    Point p1;
    printf("  Point 1 (기본값):\n");
    p1.Display();

    Point p2(10, 20);
    printf("  Point 2 (초기값):\n");
    p2.Display();

    p2.Move(5, 10);
    printf("  Point 2 (이동 후):\n");
    p2.Display();
    printf("\n");

    // 예시 8: 원(Circle) 클래스
    printf("8. Circle Class:\n");
    Circle circle(5);
    circle.ShowInfo();
    printf("\n");

    // 예시 9: 자동차 클래스 (수정됨)
    printf("9. Car Class:\n");
    const char* carModel = "BMW";
    Car car(carModel, 2023);
    printf("  초기 상태:\n");
    car.ShowStatus();

    printf("  가속 3회:\n");
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.ShowStatus();

    printf("  감속 1회:\n");
    car.Brake();
    car.ShowStatus();
    printf("\n");

    // 예시 10: 배열 객체
    printf("10. Array of Objects:\n");
    Student students[3];

    students[0].id = 2001;
    strncpy(students[0].name, "Choi Hae-won", sizeof(students[0].name) - 1);
    students[0].name[sizeof(students[0].name) - 1] = '\0';
    students[0].gpa = 3.75;

    students[1].id = 2002;
    strncpy(students[1].name, "Kang Min-ho", sizeof(students[1].name) - 1);
    students[1].name[sizeof(students[1].name) - 1] = '\0';
    students[1].gpa = 3.68;

    students[2].id = 2003;
    strncpy(students[2].name, "Yoon Ji-ho", sizeof(students[2].name) - 1);
    students[2].name[sizeof(students[2].name) - 1] = '\0';
    students[2].gpa = 3.88;

    printf("  학생 목록:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Student %d:\n", i + 1);
        students[i].PrintInfo();
    }
    printf("\n");

    // 예시 11: 포인터 객체
    printf("11. Pointer to Object:\n");
    Student* pStudent = new Student;
    pStudent->id = 3001;
    strncpy(pStudent->name, "Jung Hae-in", sizeof(pStudent->name) - 1);
    pStudent->name[sizeof(pStudent->name) - 1] = '\0';
    pStudent->gpa = 3.95;

    printf("  포인터로 접근:\n");
    pStudent->PrintInfo();
    delete pStudent;
    pStudent = nullptr;
    printf("  메모리 해제 완료\n");
    printf("\n");

    // 예시 12: 클래스 요약
    printf("12. Class Summary:\n");
    printf("  클래스: 데이터와 함수를 한 곳에 묶는 방법\n");
    printf("  멤버 변수: 클래스가 가진 데이터\n");
    printf("  멤버 함수: 클래스가 가진 기능\n");
    printf("  생성자: 객체 생성 시 자동 호출\n");
    printf("  소멸자: 객체 소멸 시 자동 호출\n");
    printf("  public: 외부에서 접근 가능\n");
    printf("  private: 내부에서만 접근 가능\n");

    return 0;
}