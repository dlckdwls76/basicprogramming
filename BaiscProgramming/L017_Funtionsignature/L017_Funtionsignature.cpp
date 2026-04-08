#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

// ===== 예시 1: 기본 가상함수 =====
class Animal {
protected:
    char name[50];
    int age;

public:
    Animal(const char* n, int a) : age(a) {
        strcpy(name, n);
    }

    virtual ~Animal() {
        printf("[Animal 소멸자] %s 소멸\n", name);
    }

    virtual void Speak() { //가상함수
        printf("%s: 동물 소리를 냅니다\n", name);
    }

    virtual void Move() {
        printf("%s: 이동합니다\n", name);
    }

    void ShowInfo() {
        printf("이름: %s, 나이: %d\n", name, age);
    }
};

// ===== 예시 2: Dog 클래스 =====
class Dog : public Animal {
private:
    char breed[50];

public:
    Dog(const char* n, int a, const char* b) : Animal(n, a) {
        strcpy(breed, b);
        printf("[Dog 생성자] %s(%s) 생성\n", name, breed);
    }

    ~Dog() {
        printf("[Dog 소멸자] %s 소멸\n", name);
    }

    void Speak() override {
        printf("%s: 멍멍!\n", name);
    }

    void Move() override {
        printf("%s: 네 발로 뛰어갑니다\n", name);
    }

    void Fetch() {
        printf("%s: 공을 물어옵니다\n", name);
    }
};

// ===== 예시 3: Cat 클래스 =====
class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(const char* n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {
        printf("[Cat 생성자] %s 생성\n", name);
    }

    ~Cat() {
        printf("[Cat 소멸자] %s 소멸\n", name);
    }

    void Speak() override {
        printf("%s: 야옹~\n", name);
    }

    void Move() override {
        printf("%s: 조용히 걸어갑니다\n", name);
    }

    void Scratch() {
        printf("%s: 스크래칭합니다\n", name);
    }
};

// ===== 예시 4: Bird 클래스 =====
class Bird : public Animal {
private:
    double wingspan;

public:
    Bird(const char* n, int a, double ws) : Animal(n, a), wingspan(ws) {
        printf("[Bird 생성자] %s 생성 (날개 길이: %.1f)\n", name, wingspan);
    }

    ~Bird() {
        printf("[Bird 소멸자] %s 소멸\n", name);
    }

    void Speak() override {
        printf("%s: 짹짹짹!\n", name);
    }

    void Move() override {
        printf("%s: 날아갑니다\n", name);
    }

    void Fly() {
        printf("%s: 하늘 높이 날아갑니다 (날개: %.1fcm)\n", name, wingspan);
    }
};

// ===== 예시 5: Fish 클래스 =====
class Fish : public Animal {
private:
    double speed;

public:
    Fish(const char* n, int a, double s) : Animal(n, a), speed(s) {
        printf("[Fish 생성자] %s 생성 (속도: %.1f)\n", name, speed);
    }

    ~Fish() {
        printf("[Fish 소멸자] %s 소멸\n", name);
    }

    void Speak() override {
        printf("%s: 부글부글...\n", name);
    }

    void Move() override {
        printf("%s: 헤엄칩니다 (속도: %.1f)\n", name, speed);
    }

    void Swim() {
        printf("%s: 깊은 물속으로 다이빙합니다\n", name);
    }
};

// ===== 예시 6: 추상 클래스 (순수 가상함수) =====
class Shape {
protected:
    char name[50];

public:
    Shape(const char* n) {
        strcpy(name, n);
    }

    virtual ~Shape() {}

    // 순수 가상함수 (반드시 파생 클래스에서 구현)
    virtual void Draw() = 0;
    virtual double GetArea() = 0;

    virtual void ShowInfo() {
        printf("도형: %s\n", name);
    }
};

// ===== 예시 7: Circle 클래스 =====
class Circle : public Shape {
private:
    double radius;

public:
    Circle(const char* n, double r) : Shape(n), radius(r) {}

    void Draw() override {
        printf("%s: 원을 그립니다 (반지름: %.2f)\n", name, radius);
    }

    double GetArea() override {
        return 3.14159 * radius * radius;
    }
};

// ===== 예시 8: Rectangle 클래스 =====
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(const char* n, double w, double h) : Shape(n), width(w), height(h) {}

    void Draw() override {
        printf("%s: 사각형을 그립니다 (가로: %.2f, 세로: %.2f)\n", name, width, height);
    }

    double GetArea() override {
        return width * height;
    }
};

// ===== 예시 9: Triangle 클래스 =====
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(const char* n, double b, double h) : Shape(n), base(b), height(h) {}

    void Draw() override {
        printf("%s: 삼각형을 그립니다\n", name);
    }

    double GetArea() override {
        return (base * height) / 2;
    }
};

// ===== 예시 10: 가상함수 사용 유틸리티 =====
void AnimalSpeakAndMove(Animal* animal) {
    animal->Speak();
    animal->Move();
    printf("\n");
}

void DrawShape(Shape* shape) {
    shape->ShowInfo();
    shape->Draw();
    printf("넓이: %.2f\n", shape->GetArea());
    printf("\n");
}

int main() {
    printf("=== Virtual Function Examples ===\n\n");

    // 예시 1: 기본 가상함수
    printf("1. Basic Virtual Function:\n");
    Animal* animal = new Animal("일반동물", 5);
    animal->Speak();
    animal->Move();
    delete animal;
    printf("\n");

    // 예시 2: Dog 객체를 Animal 포인터로 사용
    printf("2. Dog (Virtual Function Override):\n");
    Dog dog("뽀삐", 3, "푸들");
    dog.Speak();
    dog.Move();
    dog.Fetch();
    printf("\n");

    // 예시 3: 다형성 (Polymorphism) - 포인터 사용
    printf("3. Polymorphism with Base Class Pointer:\n");
    Animal* pDog = new Dog("개똥이", 4, "진돗개");
    pDog->Speak();
    pDog->Move();
    delete pDog;
    printf("\n");

    // 예시 4: 동적 바인딩 (Dynamic Binding)
    printf("4. Dynamic Binding - Same Interface, Different Behavior:\n");
    Animal* animals[] = {
        new Dog("뽀삐", 3, "푸들"),
        new Cat("나비", 2, true),
        new Bird("짹짹이", 1, 50.0),
        new Fish("금붕어", 2, 10.0)
    };

    printf("동일한 포인터로 다양한 동작:\n");
    for (int i = 0; i < 4; i++) {
        AnimalSpeakAndMove(animals[i]);
    }

    // 메모리 해제
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
    printf("\n");

    // 예시 5: Cat 클래스
    printf("5. Cat Class:\n");
    Cat cat("미야옹", 5, true);
    cat.Speak();
    cat.Move();
    cat.Scratch();
    printf("\n");

    // 예시 6: Bird 클래스
    printf("6. Bird Class:\n");
    Bird bird("참새", 1, 20.0);
    bird.Speak();
    bird.Move();
    bird.Fly();
    printf("\n");

    // 예시 7: Fish 클래스
    printf("7. Fish Class:\n");
    Fish fish("금붕어", 1, 5.0);
    fish.Speak();
    fish.Move();
    fish.Swim();
    printf("\n");

    // 예시 8: 추상 클래스 (순수 가상함수)
    printf("8. Abstract Class (Pure Virtual Function):\n");
    // Shape shape("도형");  // 에러! 추상 클래스는 직접 생성 불가
    
    Shape* shapes[] = {
        new Circle("원", 5.0),
        new Rectangle("사각형", 4.0, 6.0),
        new Triangle("삼각형", 4.0, 3.0)
    };

    for (int i = 0; i < 3; i++) {
        DrawShape(shapes[i]);
    }

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
    printf("\n");

    // 예시 9: 가상함수와 일반함수 혼합
    printf("9. Virtual and Non-Virtual Functions:\n");
    Dog dog2("댕댕이", 6, "시베리안 허스키");
    printf("비가상함수 (ShowInfo): ");
    dog2.ShowInfo();
    printf("가상함수 (Speak): ");
    dog2.Speak();
    printf("비가상함수 (Fetch): ");
    dog2.Fetch();
    printf("\n");

    // 예시 10: 포인터와 참조
    printf("10. Virtual Function with Reference:\n");
    Cat cat2("야옹이", 3, false);
    Animal& animalRef = cat2;
    printf("포인터로는 파생 클래스의 고유 멤버 접근 불가:\n");
    animalRef.Speak();
    animalRef.Move();
    printf("하지만 cat2 객체로는 직접 접근 가능:\n");
    cat2.Scratch();
    printf("\n");

    // 예시 11: 동적 타입 확인 (RTTI)
    printf("11. Virtual Destructor:\n");
    printf("포인터를 통한 delete 시 가상소멸자가 호출됨:\n");
    Animal* pAnimal = new Dog("테스트", 1, "테스트견");
    delete pAnimal;  // Dog 소멸자 -> Animal 소멸자 순서로 호출
    printf("\n");

    // 예시 12: 가상함수 요약
    printf("12. Virtual Function Summary:\n");
    printf("  - 기본 클래스에서 virtual로 선언\n");
    printf("  - 파생 클래스에서 override로 재정의\n");
    printf("  - 기본 클래스 포인터/참조로 다양한 동작 가능\n");
    printf("  - 동적 바인딩으로 런타임에 결정\n");
    printf("  - 추상 클래스는 순수 가상함수(= 0) 포함\n");
    printf("  - 가상 소멸자는 필수\n");
    printf("\n");

    // 예시 13: 다형성의 장점
    printf("13. Benefits of Polymorphism:\n");
    printf("  1. 코드 재사용성 증가\n");
    printf("  2. 유지보수 용이\n");
    printf("  3. 확장성 높음\n");
    printf("  4. 동일한 인터페이스로 다양한 동작\n");
    printf("\n");

    // 예시 14: 순수 가상함수와 추상 클래스
    printf("14. Pure Virtual Function and Abstract Class:\n");
    printf("  - 순수 가상함수: virtual void Func() = 0;\n");
    printf("  - 추상 클래스: 순수 가상함수를 하나 이상 포함\n");
    printf("  - 추상 클래스는 직접 객체 생성 불가\n");
    printf("  - 파생 클래스에서 반드시 구현해야 함\n");
    printf("\n");

    // 예시 15: 가상함수 호출 메커니즘
    printf("15. Virtual Function Call Mechanism:\n");
    printf("  1. 컴파일 타임: 포인터 타입 검사\n");
    printf("  2. 런타임: 실제 객체의 가상함수 호출\n");
    printf("  3. 동적 바인딩: 실행 시간에 결정\n");

    return 0;
}