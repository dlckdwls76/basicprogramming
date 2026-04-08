#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

// ===== 예시 1: public, private, protected =====
class Animal {
private:
    // private: 클래스 내부에서만 접근 가능
    int age;

protected:
    // protected: 같은 클래스와 상속받은 클래스에서 접근 가능
    char name[50];

public:
    // public: 외부에서 접근 가능
    Animal(const char* n, int a) {
        strcpy(name, n);
        age = a;
        printf("  [Animal 생성자] %s 생성 (나이: %d)\n", name, age);
    }

    void PrintInfo() {
        printf("  이름: %s, 나이: %d\n", name, age);
    }

    int GetAge() {
        return age;  // private 멤버는 getter로 접근
    }

    void SetAge(int a) {
        if (a > 0) {
            age = a;  // private 멤버는 setter로 수정
        }
    }
};

// ===== 예시 2: Dog 클래스 (protected 접근) =====
class Dog : public Animal {
private:
    char breed[50];

public:
    Dog(const char* n, int a, const char* b) : Animal(n, a) {
        strcpy(breed, b);
        printf("  [Dog 생성자] 품종: %s\n", breed);
    }

    void DogInfo() {
        // protected 멤버 접근 가능
        printf("  개의 이름: %s (상속된 protected 멤버)\n", name);
        // printf("  개의 나이: %d\n", age);  // 에러! private는 접근 불가
        printf("  개의 나이: %d\n", GetAge());  // public 메서드로만 접근
        printf("  품종: %s\n", breed);
    }
};

// ===== 예시 3: Bank 클래스 (캡슐화) =====
class BankAccount {
private:
    char accountHolder[50];
    double balance;
    int accountNumber;

public:
    BankAccount(const char* name, int number, double initial) {
        strcpy(accountHolder, name);
        accountNumber = number;
        balance = initial;
        printf("  [계좌 생성] %s (계좌번호: %d, 잔액: %.2f)\n", 
               accountHolder, accountNumber, balance);
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            printf("  입금: %.2f (현재 잔액: %.2f)\n", amount, balance);
        }
    }

    void Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            printf("  출금: %.2f (현재 잔액: %.2f)\n", amount, balance);
        } else {
            printf("  출금 불가 (잔액 부족)\n");
        }
    }

    double GetBalance() {
        return balance;
    }

    char* GetAccountHolder() {
        return accountHolder;
    }

    int GetAccountNumber() {
        return accountNumber;
    }

    // private 멤버 직접 수정 불가
    // balance = 1000000;  // 에러!
};

// ===== 예시 4: Student 클래스 =====
class Student {
private:
    int id;
    double gpa;
    int score;

protected:
    char name[50];
    char grade[10];

public:
    Student(int i, const char* n, double g) {
        id = i;
        strcpy(name, n);
        gpa = g;
        score = 0;
        strcpy(grade, "F");
        printf("  [Student 생성자] %s (ID: %d) 생성\n", name, id);
    }

    void SetScore(int s) {
        score = s;
        if (s >= 90) strcpy(grade, "A");
        else if (s >= 80) strcpy(grade, "B");
        else if (s >= 70) strcpy(grade, "C");
        else strcpy(grade, "F");
    }

    void ShowInfo() {
        printf("  학번: %d, 이름: %s, GPA: %.2f, 학점: %s\n", id, name, gpa, grade);
    }

    int GetScore() {
        return score;
    }

    char* GetName() {
        return name;
    }
};

// ===== 예시 5: GraduateStudent (Student 상속) =====
class GraduateStudent : public Student {
private:
    char thesis[100];

public:
    GraduateStudent(int i, const char* n, double g, const char* t)
        : Student(i, n, g) {
        strcpy(thesis, t);
        printf("  [GraduateStudent 생성자] 논문주제: %s\n", thesis);
    }

    void ShowGraduateInfo() {
        // protected 멤버 접근 가능
        printf("  대학원생 이름: %s (protected 멤버)\n", name);
        printf("  논문: %s\n", thesis);
    }
};

// ===== 예시 6: 접근 지정자 비교 =====
class AccessExample {
private:
    int privateVar = 10;

protected:
    int protectedVar = 20;

public:
    int publicVar = 30;

    void ShowAllVariables() {
        printf("  private: %d (클래스 내부만)\n", privateVar);
        printf("  protected: %d (상속 클래스에서)\n", protectedVar);
        printf("  public: %d (외부에서)\n", publicVar);
    }
};

// ===== 예시 7: AccessExample 상속 =====
class DerivedAccess : public AccessExample {
public:
    void ShowVariables() {
        // privateVar는 접근 불가
        printf("  protected: %d (상속 클래스에서 접근 가능)\n", protectedVar);
        printf("  public: %d (외부에서 접근 가능)\n", publicVar);
    }
};

int main() {
    printf("=== Access Specifier (private, public, protected) ===\n\n");

    // 예시 1: public 멤버 접근
    printf("1. Public Member Access:\n");
    Animal animal("Tiger", 5);
    animal.PrintInfo();
    printf("  외부에서 public 메서드 호출 가능\n");
    // animal.age = 10;  // 에러! private 멤버 접근 불가
    printf("\n");

    // 예시 2: private 멤버 getter/setter
    printf("2. Private Member (Getter/Setter):\n");
    printf("  GetAge()로 private 나이 읽기: %d\n", animal.GetAge());
    animal.SetAge(6);
    printf("  SetAge()로 private 나이 변경: %d\n", animal.GetAge());
    printf("\n");

    // 예시 3: protected 멤버 (상속)
    printf("3. Protected Member (Inheritance):\n");
    Dog dog("뽀삐", 3, "푸들");
    dog.DogInfo();
    printf("\n");

    // 예시 4: BankAccount (캡슐화)
    printf("4. Bank Account (Encapsulation):\n");
    BankAccount account("Kim Min-jun", 123456, 10000);
    account.Deposit(5000);
    account.Withdraw(3000);
    printf("  현재 잔액: %.2f\n", account.GetBalance());
    printf("  계좌주: %s\n", account.GetAccountHolder());
    // account.balance = 1000000;  // 에러! private 멤버 직접 수정 불가
    printf("\n");

    // 예시 5: Student 클래스
    printf("5. Student Class:\n");
    Student student(1001, "Lee Ji-woo", 3.8);
    student.SetScore(95);
    student.ShowInfo();
    printf("\n");

    // 예시 6: GraduateStudent (protected 접근)
    printf("6. Graduate Student (Protected Member):\n");
    GraduateStudent gradStudent(2001, "Park Soo-jin", 4.0, "AI 기반 자연어 처리");
    gradStudent.ShowInfo();
    gradStudent.ShowGraduateInfo();
    printf("\n");

    // 예시 7: 접근 지정자 비교
    printf("7. Access Specifier Comparison:\n");
    AccessExample example;
    printf("  외부에서 접근:\n");
    printf("    publicVar: %d (접근 가능)\n", example.publicVar);
    // printf("    protectedVar: %d\n", example.protectedVar);  // 에러!
    // printf("    privateVar: %d\n", example.privateVar);      // 에러!
    printf("    protected/private: 접근 불가\n");
    printf("\n");

    // 예시 8: 상속 클래스에서 접근
    printf("8. Derived Class Access:\n");
    DerivedAccess derived;
    derived.ShowVariables();
    printf("\n");

    // 예시 9: 접근 지정자 영향범위
    printf("9. Access Specifier Range:\n");
    printf("  private:\n");
    printf("    - 클래스 내부에서만 접근\n");
    printf("    - 상속 클래스에서도 접근 불가\n");
    printf("\n");
    printf("  protected:\n");
    printf("    - 클래스 내부에서 접근\n");
    printf("    - 상속 클래스에서 접근 가능\n");
    printf("    - 외부에서 접근 불가\n");
    printf("\n");
    printf("  public:\n");
    printf("    - 모든 곳에서 접근 가능\n");
    printf("    - 클래스 내부, 상속 클래스, 외부 모두 가능\n");
    printf("\n");

    // 예시 10: 캡슐화의 장점
    printf("10. Benefits of Encapsulation:\n");
    printf("  1. 데이터 보호: private으로 직접 접근 방지\n");
    printf("  2. 유효성 검사: setter에서 값 검증\n");
    printf("  3. 유연성: 내부 구현 변경 시 외부 영향 없음\n");
    printf("  4. 인터페이스: getter/setter를 통한 명확한 인터페이스\n");
    printf("\n");

    // 예시 11: 관계도
    printf("11. Access Specifier Relationship:\n");
    printf("  Animal (base class)\n");
    printf("    - private: age (자식 클래스에서 접근 불가)\n");
    printf("    - protected: name (자식 클래스에서 접근 가능)\n");
    printf("    - public: PrintInfo(), GetAge(), SetAge() (모두 접근)\n");
    printf("\n");
    printf("  Dog (derived class)\n");
    printf("    - name 접근 가능 (protected)\n");
    printf("    - age 접근 불가 (private) -> GetAge() 사용\n");
    printf("    - PrintInfo() 사용 가능 (public)\n");
    printf("\n");

    // 예시 12: 요약 테이블
    printf("12. Summary Table:\n");
    printf("  지정자      | 클래스 내부 | 상속 클래스 | 외부\n");
    printf("  -----------------------------------------------\n");
    printf("  private     |     ✓       |     ✗      | ✗\n");
    printf("  protected   |     ✓       |     ✓      | ✗\n");
    printf("  public      |     ✓       |     ✓      | ✓\n");

    return 0;
}
//구조체는 접근지정자를 명시하지 않으면 기본적으로public
//클래스는 접근지정자를 명시하지 않으면 기본적으로private