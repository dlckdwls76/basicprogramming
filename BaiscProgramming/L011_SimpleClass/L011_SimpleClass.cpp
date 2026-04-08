/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

class Animal // 부모 클래스, Base class
{
protected: 
    int age = 10;
    int weight = 50;
    
public:
    // 
    Animal(int a) : age(a), weight(50)
    {
    }
    
    // 기본 생성자
    Animal() : age(20)
    {
        weight = 50;
    }
    
    // 소멸자
    ~Animal()
    {
    }
    
    void PrintBase() const
    {
        printf("Animal age = %d\n", age);
    }
};

class Dog : public Animal // 자식(child) class, 파생클래스
{
private:
    const char *name;
    
public:
    Dog(int a, const char *n) : Animal(a), name(n) {}
    
    void Print() const
    {
        printf("Dog name = %s, age = %d\n", name, age);   // 수정: %d -> %s
    }
};

int main()
{
    Animal a(5);
    a.PrintBase();
    
    Dog d(3, "Bob");
    d.Print();
    
    return 0;
}
*/
    #define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

// ===== 예시 1: 기본 상속 =====
class Animal {
protected:
    char name[50];
    int age;

public:
    Animal(const char* n, int a) : age(a) {
        strcpy(name, n);
        printf("  [Animal 생성자] %s 생성\n", name);
    }

    ~Animal() {
        printf("  [Animal 소멸자] %s 소멸\n", name);
    }

    void Eat() {
        printf("  %s이(가) 먹고 있습니다\n", name);
    }

    void Sleep() {
        printf("  %s이(가) 자고 있습니다\n", name);
    }

    void PrintInfo() {
        printf("  이름: %s, 나이: %d\n", name, age);
    }
};

// ===== 예시 2: Dog 클래스 (Animal 상속) =====
class Dog : public Animal {
private:
    char breed[50];

public:
    Dog(const char* n, int a, const char* b) : Animal(n, a) {
        strcpy(breed, b);
        printf("  [Dog 생성자] %s 생성 (품종: %s)\n", name, breed);
    }

    ~Dog() {
        printf("  [Dog 소멸자] %s 소멸\n", name);
    }

    void Bark() {
        printf("  %s: 멍멍!\n", name);
    }

    void ShowDogInfo() {
        printf("  개 정보 - 이름: %s, 나이: %d, 품종: %s\n", name, age, breed);
    }
};

// ===== 예시 3: Cat 클래스 (Animal 상속) =====
class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(const char* n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {
        printf("  [Cat 생성자] %s 생성 (실내묘: %s)\n", name, isIndoor ? "예" : "아니오");
    }

    ~Cat() {
        printf("  [Cat 소멸자] %s 소멸\n", name);
    }

    void Meow() {
        printf("  %s: 야옹~\n", name);
    }

    void ShowCatInfo() {
        printf("  고양이 정보 - 이름: %s, 나이: %d, 실내묘: %s\n", name, age, isIndoor ? "예" : "아니오");
    }
};

// ===== 예시 4: Bird 클래스 (Animal 상속) =====
class Bird : public Animal {
private:
    int wingspan;

public:
    Bird(const char* n, int a, int ws) : Animal(n, a), wingspan(ws) {
        printf("  [Bird 생성자] %s 생성 (날개 길이: %d cm)\n", name, wingspan);
    }

    ~Bird() {
        printf("  [Bird 소멸자] %s 소멸\n", name);
    }

    void Sing() {
        printf("  %s: 짹짹짹!\n", name);
    }

    void Fly() {
        printf("  %s이(가) 날개를 펼치고 날아갑니다 (날개 길이: %d cm)\n", name, wingspan);
    }

    void ShowBirdInfo() {
        printf("  새 정보 - 이름: %s, 나이: %d, 날개 길이: %d cm\n", name, age, wingspan);
    }
};

// ===== 예시 5: 다중 상속 =====
class Pet {
protected:
    char owner[50];

public:
    Pet(const char* o) {
        strcpy(owner, o);
    }

    void ShowOwner() {
        printf("  주인: %s\n", owner);
    }
};

class PetDog : public Dog, public Pet {
public:
    PetDog(const char* n, int a, const char* b, const char* o)
        : Dog(n, a, b), Pet(o) {
        printf("  [PetDog 생성자] 반려견 생성 (주인: %s)\n", owner);
    }

    void ShowAllInfo() {
        printf("  반려견 정보:\n");
        printf("    이름: %s\n", name);
        printf("    나이: %d\n", age);
        printf("    주인: %s\n", owner);
    }
};

// ===== 예시 6: 가상 함수 (Virtual Function) =====
class Shape {
public:
    virtual void Draw() {
        printf("  도형을 그립니다\n");
    }

    virtual void ShowArea() {
        printf("  넓이를 계산합니다\n");
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void Draw() override {
        printf("  원을 그립니다 (반지름: %.2f)\n", radius);
    }

    void ShowArea() override {
        printf("  원의 넓이: %.2f\n", 3.14159 * radius * radius);
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void Draw() override {
        printf("  사각형을 그립니다 (가로: %.2f, 세로: %.2f)\n", width, height);
    }

    void ShowArea() override {
        printf("  사각형의 넓이: %.2f\n", width * height);
    }
};

int main() {
    printf("=== C++ Inheritance Examples ===\n\n");

    // 예시 1: 기본 상속
    printf("1. Basic Inheritance (Animal -> Dog):\n");
    {
        Dog dog("뽀삐", 3, "푸들");
        dog.PrintInfo();
        dog.Eat();
        dog.Bark();
        dog.ShowDogInfo();
    }
    printf("\n");

    // 예시 2: 다른 파생 클래스
    printf("2. Another Derived Class (Animal -> Cat):\n");
    {
        Cat cat("나비", 2, true);
        cat.PrintInfo();
        cat.Sleep();
        cat.Meow();
        cat.ShowCatInfo();
    }
    printf("\n");

    // 예시 3: 또 다른 파생 클래스
    printf("3. Another Derived Class (Animal -> Bird):\n");
    {
        Bird bird("짹짹이", 1, 50);
        bird.PrintInfo();
        bird.Eat();
        bird.Sing();
        bird.Fly();
        bird.ShowBirdInfo();
    }
    printf("\n");

    // 예시 4: 포인터를 사용한 다형성
    printf("4. Polymorphism with Pointers:\n");
    Dog dog2("멍멍이", 4, "진돗개");
    Cat cat2("야옹이", 3, false);
    Bird bird2("까만새", 2, 40);

    Animal* animals[] = { &dog2, &cat2, &bird2 };
    for (int i = 0; i < 3; i++) {
        animals[i]->PrintInfo();
        animals[i]->Eat();
    }
    printf("\n");

    // 예시 5: 배��� 객체
    printf("5. Array of Objects:\n");
    Dog dogs[3] = {
        Dog("뽀삐", 3, "푸들"),
        Dog("개똥이", 5, "진돗개"),
        Dog("민트초", 1, "시베리안 허스키")
    };
    printf("\n");

    printf("  등록된 개들:\n");
    for (int i = 0; i < 3; i++) {
        printf("  개 %d:\n", i + 1);
        dogs[i].ShowDogInfo();
    }
    printf("\n");

    // 예시 6: 다중 상속
    printf("6. Multiple Inheritance:\n");
    PetDog petdog("복순이", 6, "말티즈", "김철수");
    petdog.ShowAllInfo();
    petdog.Bark();
    printf("\n");

    // 예시 7: 가상 함수
    printf("7. Virtual Functions (Polymorphism):\n");
    Circle circle(5);
    Rectangle rect(4, 6);

    Shape* shapes[] = { &circle, &rect };

    for (int i = 0; i < 2; i++) {
        shapes[i]->Draw();
        shapes[i]->ShowArea();
    }
    printf("\n");

    // 예시 8: 동적 할당 상속
    printf("8. Dynamic Allocation with Inheritance:\n");
    Dog* pDog = new Dog("동동이", 2, "코커 스패니얼");
    pDog->PrintInfo();
    pDog->Bark();
    delete pDog;
    pDog = nullptr;
    printf("\n");

    // 예시 9: 생성자 호출 순서
    printf("9. Constructor and Destructor Order:\n");
    printf("  Dog 객체 생성:\n");
    Dog tempDog("순서테스트", 1, "테스트견");
    printf("  Dog 객체 소멸:\n");
    printf("\n");

    // 예시 10: 상속 요약
    printf("10. Inheritance Summary:\n");
    printf("  - 부모 클래스: Animal (기본 속성과 메서드)\n");
    printf("  - 자식 클래스: Dog, Cat, Bird (부모 상속 + 고유 기능)\n");
    printf("  - protected: 자식 클래스에서 접근 가능\n");
    printf("  - 생성자 호출 순서: 부모 -> 자식\n");
    printf("  - 소멸자 호출 순서: 자식 -> 부모\n");
    printf("  - virtual: 가상 함수로 다형성 구현\n");
    printf("  - override: 부모 함수를 자식에서 재정의\n");

    return 0;
}