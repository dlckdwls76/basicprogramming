#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
// ===== 예시 1: Static Binding (정적 바인딩) =====
class Animal {
public:
    void Speak() {
        printf("  동물: 일반 소리\n");
    }

    void Move() {
        printf("  동물: 이동\n");
    }
};

class Dog : public Animal {
public:
    void Speak() {
        printf("  개: 멍멍!\n");
    }

    void Move() {
        printf("  개: 네 발로 뛴다\n");
    }
};

class Cat : public Animal {
public:
    void Speak() {
        printf("  고양이: 야옹~\n");
    }

    void Move() {
        printf("  고양이: 살금살금 간다\n");
    }
};

// ===== 예시 2: Dynamic Binding (동적 바인딩) =====
class Vehicle {
public:
    virtual void Drive() {
        printf("  탈것: 운전한다\n");
    }

    virtual void Stop() {
        printf("  탈것: 멈춘다\n");
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void Drive() override {
        printf("  자동차: 빠르게 달린다\n");
    }

    void Stop() override {
        printf("  자동차: 브레이크를 밟는다\n");
    }
};

class Bicycle : public Vehicle {
public:
    void Drive() override {
        printf("  자전거: 천천히 간다\n");
    }

    void Stop() override {
        printf("  자전거: 브레이크를 건다\n");
    }
};

class Truck : public Vehicle {
public:
    void Drive() override {
        printf("  트럭: 무겁게 달린다\n");
    }

    void Stop() override {
        printf("  트럭: 에어브레이크를 사용한다\n");
    }
};

// ===== 예시 3: Shape (추상 클래스) =====
class Shape {
protected:
    char name[50];

public:
    Shape(const char* n) {
        strcpy(name, n);
    }

    virtual void Draw() = 0;
    virtual double GetArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const char* n, double r) : Shape(n), radius(r) {}

    void Draw() override {
        printf("  %s: 원을 그린다 (반지름: %.1f)\n", name, radius);
    }

    double GetArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(const char* n, double w, double h) : Shape(n), width(w), height(h) {}

    void Draw() override {
        printf("  %s: 사각형을 그린다 (%.1f x %.1f)\n", name, width, height);
    }

    double GetArea() override {
        return width * height;
    }
};

// ===== 예시 4: 컴파일 타임 다형성 (Template) =====
template <typename T>
void PrintValue(T value) {
    printf("  값: %d\n", value);
}

template <>
void PrintValue<double>(double value) {
    printf("  값: %.2f\n", value);
}

template <>
void PrintValue<const char*>(const char* value) {
    printf("  값: %s\n", value);
}

int main() {
    printf("=== Static Binding vs Dynamic Binding ===\n\n");

    // 예시 1: Static Binding - 포인터 사용 (가상함수 없음)
    printf("1. Static Binding (정적 바인딩):\n");
    printf("  컴파일 타임에 함수가 결정됨\n");
    printf("  포인터 타입 기반으로 함수 호출\n\n");

    Dog dog;
    Cat cat;
    
    printf("  Dog 객체:\n");
    dog.Speak();
    dog.Move();
    
    printf("  Cat 객체:\n");
    cat.Speak();
    cat.Move();
    printf("\n");

    // 예시 2: Static Binding - Base 포인터로 파생 클래스 접근
    printf("2. Static Binding - Base Pointer (가상함수 없음):\n");
    printf("  Base 포인터를 사용해도 Base 클래스의 함수 호출\n\n");
    
    Animal* pDog = new Dog();
    Animal* pCat = new Cat();
    
    printf("  pDog->Speak():\n");
    pDog->Speak();  // Animal::Speak() 호출
    
    printf("  pCat->Speak():\n");
    pCat->Speak();  // Animal::Speak() 호출
    
    delete pDog;
    delete pCat;
    printf("\n");

    // 예시 3: Dynamic Binding - 가상함수 사용
    printf("3. Dynamic Binding (동적 바인딩):\n");
    printf("  런타임에 함수가 결정됨\n");
    printf("  실제 객체의 함수가 호출됨\n\n");

    Vehicle* vehicles[] = {
        new Car(),
        new Bicycle(),
        new Truck()
    };

    printf("  차량 운전:\n");
    for (int i = 0; i < 3; i++) {
        vehicles[i]->Drive();
    }
    printf("\n");

    printf("  차량 정지:\n");
    for (int i = 0; i < 3; i++) {
        vehicles[i]->Stop();
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }

    // 예시 4: Dynamic Binding - 추상 클래스
    printf("4. Dynamic Binding - Abstract Class:\n");
    printf("  순수 가상함수를 가진 추상 클래스\n\n");

    Shape* shapes[] = {
        new Circle("원", 5.0),
        new Rectangle("사각형", 4.0, 6.0)
    };

    printf("  도형 그리기:\n");
    for (int i = 0; i < 2; i++) {
        shapes[i]->Draw();
    }
    printf("\n");

    printf("  도형 넓이:\n");
    for (int i = 0; i < 2; i++) {
        printf("  넓이: %.2f\n", shapes[i]->GetArea());
    }
    printf("\n");

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    // 예시 5: Static vs Dynamic 비교
    printf("5. Static Binding vs Dynamic Binding 비교:\n\n");

    printf("  Static Binding (가상함수 없음):\n");
    printf("    - 컴파일 타임에 결정\n");
    printf("    - 포인터 타입 기반\n");
    printf("    - 속도 빠름\n");
    printf("    - 유연성 낮음\n\n");

    printf("  Dynamic Binding (가상함수):\n");
    printf("    - 런타임에 결정\n");
    printf("    - 실제 객체 기반\n");
    printf("    - 속도 약간 느림\n");
    printf("    - 유연성 높음\n\n");

    // 예시 6: 동일 인터페이스, 다양한 동작
    printf("6. Same Interface, Different Behavior (Dynamic Binding):\n");
    printf("  같은 함수명으로 다양한 동작 구현\n\n");

    Car car;
    Bicycle bicycle;
    Truck truck;

    Vehicle* myVehicles[] = {&car, &bicycle, &truck};

    for (int i = 0; i < 3; i++) {
        printf("  차량 %d:\n", i + 1);
        myVehicles[i]->Drive();
        myVehicles[i]->Stop();
    }
    printf("\n");

    // 예시 7: 배열을 이용한 다형성
    printf("7. Array of Pointers (Polymorphism):\n");
    printf("  기본 클래스 포인터 배열로 다양한 객체 관리\n\n");

    Vehicle* allVehicles[] = {
        new Car(),
        new Bicycle(),
        new Truck(),
        new Car()
    };

    printf("  모든 차량 운전:\n");
    for (int i = 0; i < 4; i++) {
        printf("  차량 %d: ", i + 1);
        allVehicles[i]->Drive();
    }
    printf("\n");

    for (int i = 0; i < 4; i++) {
        delete allVehicles[i];
    }

    // 예시 8: 콜백 함수와 동적 바인딩
    printf("8. Callback with Dynamic Binding:\n");
    printf("  함수 포인터를 이용한 콜백\n\n");

    Car myCar;
    Bicycle myBicycle;

    printf("  자동차:\n");
    myCar.Drive();
    
    printf("  자전거:\n");
    myBicycle.Drive();
    printf("\n");

    // 예시 9: 정적 바인딩 실제 예제
    printf("9. Real Example - Static Binding:\n");
    printf("  직접 객체 호출 (포인터 아님)\n\n");

    Dog myDog;
    Cat myCat;

    printf("  myDog.Speak(): ");
    myDog.Speak();
    
    printf("  myCat.Speak(): ");
    myCat.Speak();
    printf("\n");

    // 예시 10: 동적 바인딩 실제 예제
    printf("10. Real Example - Dynamic Binding:\n");
    printf("   포인터를 이용한 호출 (가상함수)\n\n");

    Vehicle* myVehicle1 = new Car();
    Vehicle* myVehicle2 = new Bicycle();

    printf("  Car:\n");
    myVehicle1->Drive();
    myVehicle1->Stop();

    printf("  Bicycle:\n");
    myVehicle2->Drive();
    myVehicle2->Stop();

    delete myVehicle1;
    delete myVehicle2;
    printf("\n");

    // 예시 11: 바인딩 타입 구분
    printf("11. Binding Types Summary:\n\n");

    printf("  Static Binding (컴파일 타임):\n");
    printf("    - 가상함수 미사용\n");
    printf("    - 포인터/참조의 선언 타입 기반\n");
    printf("    - 빠른 성능\n");
    printf("    - 함수 오버로딩\n\n");

    printf("  Dynamic Binding (런타임):\n");
    printf("    - virtual 키워드 사용\n");
    printf("    - 실제 객체의 타입 기반\n");
    printf("    - 약간의 성능 오버헤드\n");
    printf("    - 다형성 구현\n\n");

    // 예시 12: 언제 어떤 것을 사용할까?
    printf("12. When to Use Each:\n");
    printf("  Static Binding:\n");
    printf("    - 타입이 명확할 때\n");
    printf("    - 성능이 중요할 때\n");
    printf("    - 간단한 구조\n\n");

    printf("  Dynamic Binding:\n");
    printf("    - 다양한 타입 처리 필요\n");
    printf("    - 확장성이 중요할 때\n");
    printf("    - 복잡한 구조\n\n");

    // 예시 13: 포인터 타입과 객체 타입
    printf("13. Pointer Type vs Object Type:\n\n");

    printf("  Static Binding:\n");
    Animal* staticPtr = new Dog();
    printf("    포인터 타입: Animal\n");
    printf("    객체 타입: Dog\n");
    printf("    호출: Animal::Speak() (정적)\n");
    staticPtr->Speak();
    delete staticPtr;

    printf("\n  Dynamic Binding:\n");
    Vehicle* dynamicPtr = new Car();
    printf("    포인터 타입: Vehicle\n");
    printf("    객체 타입: Car\n");
    printf("    호출: Car::Drive() (동적)\n");
    dynamicPtr->Drive();
    delete dynamicPtr;
    printf("\n");

    // 예시 14: 메모리 할당 방식
    printf("14. Memory Allocation:\n");
    printf("  스택 할당 (Static Binding 주로):\n");
    Dog stackDog;
    printf("    dog.Speak():\n");
    stackDog.Speak();

    printf("\n  힙 할당 (Dynamic Binding 주로):\n");
    Vehicle* heapVehicle = new Car();
    printf("    vehicle->Drive():\n");
    heapVehicle->Drive();
    delete heapVehicle;
    printf("\n");

    // 예시 15: 요약
    printf("15. Key Points:\n");
    printf("  1. Static Binding: 컴파일 타임에 함수 결정\n");
    printf("  2. Dynamic Binding: 런타임에 함수 결정\n");
    printf("  3. virtual 키워드가 Dynamic Binding 가능하게 함\n");
    printf("  4. Dynamic Binding은 다형성을 구현\n");
    printf("  5. 성능과 유연성의 트레이드오프\n");

    return 0;
}