/*#include <cstdio>

int main() {
    printf("=== C++ Basic Data Types Sample ===\n\n");

    // 1. 정수형 (Integer Types) 4byte
    printf("1. Integer Types:\n");
    int myInt = 42;
    short myShort = 100;
    long myLong = 1000000L;
    long long myLongLong = 9223372036854775807LL;
    unsigned int myUnsignedInt = 100U;
    
    printf("  int: %d\n", myInt);
    printf("  short: %d\n", myShort);
    printf("  long: %ld\n", myLong);
    printf("  long long: %lld\n", myLongLong);
    printf("  unsigned int: %u\n", myUnsignedInt);
    printf("\n");

    // 2. 부동소수점형 (Floating Point Types)
    printf("2. Floating Point Types:\n");
    float myFloat = 3.14f;
    double myDouble = 2.71828;
    long double myLongDouble = 1.41421356237L;
    
    printf("  float: %.6f\n", myFloat);
    printf("  double: %.6f\n", myDouble);
    printf("  long double: %.6Lf\n", myLongDouble);
    printf("\n");

    // 3. 문자형 (Character Types) 1btye
    printf("3. Character Types:\n");
    char myChar = 'A';
    
    printf("  char: %c\n", myChar);
    printf("\n");

    // 4. 불린형 (Boolean Type)
    printf("4. Boolean Type:\n");
    bool isTrue = true;
    bool isFalse = false;
    
    printf("  true: %d\n", isTrue);
    printf("  false: %d\n", isFalse);
    printf("\n");

    // 5. 문자열 (String)
    printf("5. String Type:\n");
    const char* myString = "Hello, C++ 20!";
    
    printf("  string: %s\n", myString);
    printf("\n");

    // 6. 자료형 크기 (Size of Data Types)
    printf("6. Size of Data Types (bytes):\n");
    printf("  sizeof(int): %zu\n", sizeof(int));
    printf("  sizeof(float): %zu\n", sizeof(float));
    printf("  sizeof(double): %zu\n", sizeof(double));
    printf("  sizeof(char): %zu\n", sizeof(char));
    printf("  sizeof(bool): %zu\n", sizeof(bool));
    printf("  sizeof(long long): %zu\n", sizeof(long long));

    return 0;
}*/
#include <cstdio>

int main() {
    printf("=== C++ Conditional Statement Examples ===\n\n");

    // 예시 1: 기본 if문
    printf("1. Basic if Statement:\n");
    int age = 20;
    
    if (age >= 18) {
        printf("  You are an adult.\n");
    }
    printf("\n");

    // 예시 2: if-else문
    printf("2. if-else Statement:\n");
    int score = 75;
    
    if (score >= 80) {
        printf("  Grade: A\n");
    } else {
        printf("  Grade: B or lower\n");
    }
    printf("\n");

    // 예시 3: if-else if-else문
    printf("3. if-else if-else Statement:\n");
    int temperature = 25;
    
    if (temperature < 0) {
        printf("  It's freezing!\n");
    } else if (temperature < 15) {
        printf("  It's cold.\n");
    } else if (temperature < 25) {
        printf("  It's cool.\n");
    } else {
        printf("  It's warm.\n");
    }
    printf("\n");

    // 예시 4: switch문 - 요일 선택
    printf("4. switch Statement - Day of Week:\n");
    int day = 3;
    
    switch (day) {
        case 1:
            printf("  Monday\n");
            break;
        case 2:
            printf("  Tuesday\n");
            break;
        case 3:
            printf("  Wednesday\n");
            break;
        case 4:
            printf("  Thursday\n");
            break;
        case 5:
            printf("  Friday\n");
            break;
        default:
            printf("  Weekend\n");
    }
    printf("\n");

    // 예시 5: 중첩된 if문 (Nested if)
    printf("5. Nested if Statement:\n");
    int number = 15;
    
    if (number > 0) {
        printf("  Number is positive.\n");
        if (number > 10) {
            printf("  Number is greater than 10.\n");
        } else {
            printf("  Number is between 1 and 10.\n");
        }
    } else if (number < 0) {
        printf("  Number is negative.\n");
    } else {
        printf("  Number is zero.\n");
    }
    printf("\n");

    // 예시 6: 논리 연산자 AND (&&)
    printf("6. Logical AND (&&) Operator:\n");
    int num1 = 25;
    int num2 = 30;
    
    if (num1 > 20 && num2 > 20) {
        printf("  Both numbers are greater than 20.\n");
    } else {
        printf("  At least one number is not greater than 20.\n");
    }
    printf("\n");

    // 예시 7: 논리 연산자 OR (||)
    printf("7. Logical OR (||) Operator:\n");
    char grade = 'A';
    
    if (grade == 'A' || grade == 'B') {
        printf("  Excellent or Good grade.\n");
    } else {
        printf("  Other grade.\n");
    }
    printf("\n");

    // 예시 8: 논리 연산자 NOT (!)
    printf("8. Logical NOT (!) Operator:\n");
    bool isRaining = false;
    
    if (!isRaining) {
        printf("  It's not raining. You can go outside.\n");
    } else {
        printf("  It's raining. Stay inside.\n");
    }
    printf("\n");

    // 예시 9: 여러 조건 조합
    printf("9. Multiple Conditions Combined:\n");
    int hours = 14;
    int minutes = 30;
    
    if ((hours >= 9 && hours < 12) || (hours >= 14 && hours < 17)) {
        printf("  Working hours.\n");
    } else {
        printf("  Not working hours.\n");
    }
    printf("\n");

    // 예시 10: 비교 연산자
    printf("10. Comparison Operators:\n");
    int a = 10;
    int b = 20;
    
    if (a < b) {
        printf("  %d < %d: true\n", a, b);
    }
    if (a <= b) {
        printf("  %d <= %d: true\n", a, b);
    }
    if (a != b) {
        printf("  %d != %d: true\n", a, b);
    }
    if (a == b) {
        printf("  %d == %d: true\n", a, b);
    } else {
        printf("  %d == %d: false\n", a, b);
    }
    printf("\n");

    // 예시 11: 삼항 연산자 (Ternary Operator)
    printf("11. Ternary Operator (? :):\n");
    int value = 50;
    const char* result = (value >= 50) ? "Pass" : "Fail";
    printf("  Score %d: %s\n", value, result);
    printf("\n");

    // 예시 12: switch문 - 계산기
    printf("12. switch Statement - Calculator:\n");
    int x = 10;
    int y = 5;
    char op = '+';
    
    switch (op) {
        case '+':
            printf("  %d + %d = %d\n", x, y, x + y);
            break;
        case '-':
            printf("  %d - %d = %d\n", x, y, x - y);
            break;
        case '*':
            printf("  %d * %d = %d\n", x, y, x * y);
            break;
        case '/':
            if (y != 0) {
                printf("  %d / %d = %d\n", x, y, x / y);
            } else {
                printf("  Cannot divide by zero\n");
            }
            break;
        default:
            printf("  Invalid operation\n");
    }
    printf("\n");

    // 예시 13: switch문 - 점수 등급
    printf("13. switch Statement - Grade Classification:\n");
    int score2 = 85;
    
    switch (score2 / 10) {
        case 10:
        case 9:
            printf("  Grade: A (90-100)\n");
            break;
        case 8:
            printf("  Grade: B (80-89)\n");
            break;
        case 7:
            printf("  Grade: C (70-79)\n");
            break;
        case 6:
            printf("  Grade: D (60-69)\n");
            break;
        default:
            printf("  Grade: F (Below 60)\n");
    }
    printf("\n");

    // 예시 14: 실제 활용 예제 - 로그인 검증
    printf("14. Practical Example - Login Validation:\n");
    const char* username = "admin";
    const char* inputUsername = "admin";
    int attemptCount = 1;
    int maxAttempts = 3;
    
    if (attemptCount > maxAttempts) {
        printf("  Account locked!\n");
    } else if (username[0] == inputUsername[0]) {
        printf("  Username verification passed!\n");
    } else {
        printf("  Invalid username. Attempts remaining: %d\n", maxAttempts - attemptCount);
    }
    printf("\n");

    // 예시 15: 중첩 switch문
    printf("15. Nested switch Statement:\n");
    int country = 1;
    int city = 2;
    
    switch (country) {
        case 1:
            printf("  Country: Korea\n");
            switch (city) {
                case 1:
                    printf("  City: Seoul\n");
                    break;
                case 2:
                    printf("  City: Busan\n");
                    break;
            }
            break;
        case 2:
            printf("  Country: Japan\n");
            switch (city) {
                case 1:
                    printf("  City: Tokyo\n");
                    break;
                case 2:
                    printf("  City: Osaka\n");
                    break;
            }
            break;
    }

    return 0;
}