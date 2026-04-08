#include <cstdio>

// 예시 1: 기본 매크로 (상수)
#define PI 3.14159
#define MAX_SIZE 100
#define AUTHOR "Kim Min-jun"

// 예시 2: 간단한 계산 매크로
#define ADD(a, b) ((a) + (b))
#define SUBTRACT(a, b) ((a) - (b))
#define MULTIPLY(a, b) ((a) * (b))
#define DIVIDE(a, b) ((a) / (b))

// 예시 3: 비교 매크로
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

// 예시 4: 조건 매크로
#define IS_POSITIVE(x) ((x) > 0)
#define IS_EVEN(x) ((x) % 2 == 0)
#define IS_ODD(x) ((x) % 2 != 0)

// 예시 5: 문자열 매크로
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define DOUBLE(x) ((x) * 2)
#define HALF(x) ((x) / 2)

// 예시 6: 배열 크기 매크로
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// 예시 7: 디버그 매크로
#define DEBUG_PRINT(msg) printf("[DEBUG] %s\n", msg)
#define PRINT_INT(var) printf("%s = %d\n", #var, var)
#define PRINT_FLOAT(var) printf("%s = %.2f\n", #var, var)
#define PRINT_STR(var) printf("%s = %s\n", #var, var)

// 예시 8: 조건부 컴파일 매크로
#define DEBUG 1

// 예시 9: 스왑 매크로
#define SWAP(a, b) { int temp = a; a = b; b = temp; }

// 예시 10: 범위 확인 매크로
#define IN_RANGE(x, min, max) ((x) >= (min) && (x) <= (max))

int main() {
    printf("=== C++ Macro Examples ===\n\n");

    // 예시 1: 기본 매크로 (상수)
    printf("1. Basic Macro (Constants):\n");
    printf("  PI = %.5f\n", PI);
    printf("  MAX_SIZE = %d\n", MAX_SIZE);
    printf("  AUTHOR = %s\n", AUTHOR);
    printf("\n");

    // 예시 2: 간단한 계산 매크로
    printf("2. Arithmetic Macros:\n");
    int x = 10;
    int y = 5;
    printf("  ADD(%d, %d) = %d\n", x, y, ADD(x, y));
    printf("  SUBTRACT(%d, %d) = %d\n", x, y, SUBTRACT(x, y));
    printf("  MULTIPLY(%d, %d) = %d\n", x, y, MULTIPLY(x, y));
    printf("  DIVIDE(%d, %d) = %d\n", x, y, DIVIDE(x, y));
    printf("\n");

    // 예시 3: 비교 매크로
    printf("3. Comparison Macros:\n");
    int a = 20;
    int b = 15;
    printf("  MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("  MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("  ABS(%d) = %d\n", -30, ABS(-30));
    printf("  ABS(%d) = %d\n", 30, ABS(30));
    printf("\n");

    // 예시 4: 조건 매크로
    printf("4. Condition Macros:\n");
    int num1 = 10;
    int num2 = -5;
    int num3 = 8;
    printf("  IS_POSITIVE(%d) = %s\n", num1, IS_POSITIVE(num1) ? "true" : "false");
    printf("  IS_POSITIVE(%d) = %s\n", num2, IS_POSITIVE(num2) ? "true" : "false");
    printf("  IS_EVEN(%d) = %s\n", num3, IS_EVEN(num3) ? "true" : "false");
    printf("  IS_ODD(%d) = %s\n", num1, IS_ODD(num1) ? "true" : "false");
    printf("\n");

    // 예시 5: 거듭제곱 매크로
    printf("5. Power Macros:\n");
    int n = 5;
    printf("  SQUARE(%d) = %d\n", n, SQUARE(n));
    printf("  CUBE(%d) = %d\n", n, CUBE(n));
    printf("  DOUBLE(%d) = %d\n", n, DOUBLE(n));
    printf("  HALF(%d) = %d\n", n, HALF(n));
    printf("\n");

    // 예시 6: 배열 크기 매크로
    printf("6. Array Size Macro:\n");
    int arr[] = {10, 20, 30, 40, 50};
    printf("  배열 크기: %zu\n", ARRAY_SIZE(arr));
    printf("  배열 요소:\n");
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        printf("    arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");

    // 예시 7: 디버그 매크로
    printf("7. Debug Macros:\n");
    DEBUG_PRINT("Program started");
    int value = 100;
    double score = 95.5;
    char name[] = "C++ Macro";
    PRINT_INT(value);
    PRINT_FLOAT(score);
    PRINT_STR(name);
    printf("\n");

    // 예시 8: 스왑 매크로
    printf("8. Swap Macro:\n");
    int p = 100;
    int q = 200;
    printf("  변경 전: p = %d, q = %d\n", p, q);
    SWAP(p, q);
    printf("  변경 후: p = %d, q = %d\n", p, q);
    printf("\n");

    // 예시 9: 범위 확인 매크로
    printf("9. Range Check Macro:\n");
    int score1 = 75;
    int score2 = 150;
    int score3 = 50;
    printf("  IN_RANGE(%d, 0, 100) = %s\n", score1, IN_RANGE(score1, 0, 100) ? "true" : "false");
    printf("  IN_RANGE(%d, 0, 100) = %s\n", score2, IN_RANGE(score2, 0, 100) ? "true" : "false");
    printf("  IN_RANGE(%d, 0, 100) = %s\n", score3, IN_RANGE(score3, 0, 100) ? "true" : "false");
    printf("\n");

    // 예시 10: 조건부 컴파일
    printf("10. Conditional Compilation:\n");
#if DEBUG == 1
    printf("  DEBUG 모드가 활성화되었습니다\n");
    printf("  FILE: %s\n", __FILE__);
    printf("  LINE: %d\n", __LINE__);
    printf("  DATE: %s\n", __DATE__);
    printf("  TIME: %s\n", __TIME__);
#else
    printf("  DEBUG 모드가 비활성화되었습니다\n");
#endif
    printf("\n");

    // 예시 11: 다중 매크로 사용
    printf("11. Multiple Macro Usage:\n");
    int val1 = 5;
    int val2 = 3;
    int result = ADD(MULTIPLY(val1, val2), 10);
    printf("  ADD(MULTIPLY(%d, %d), 10) = %d\n", val1, val2, result);
    printf("\n");

    // 예시 12: 매크로의 문제점 (괄호 중요)
    printf("12. Macro with Parentheses:\n");
    int m = 5;
    int n_result = SQUARE(m + 2);  // (m + 2) * (m + 2) = 49
    printf("  SQUARE(%d + 2) = %d\n", m, n_result);
    printf("\n");

    // 예시 13: 문자열화 연산자 (#)
    printf("13. Stringification Operator:\n");
    #define STRINGIFY(x) #x
    printf("  STRINGIFY(HELLO) = %s\n", STRINGIFY(HELLO));
    printf("  STRINGIFY(12345) = %s\n", STRINGIFY(12345));
    printf("\n");

    // 예시 14: 토큰 연결 연산자 (##)
    printf("14. Token Concatenation Operator:\n");
    #define CONCAT(a, b) a ## b
    int var1 = 100;
    int var2 = 200;
    printf("  CONCAT(var, 1) = %d\n", var1);
    printf("  CONCAT(var, 2) = %d\n", var2);
    printf("\n");

    // 예시 15: 복잡한 매크로
    printf("15. Complex Macro:\n");
    #define CALC(a, b, op) ((op) == '+' ? (a) + (b) : (op) == '-' ? (a) - (b) : (a) * (b))
    printf("  CALC(10, 5, '+') = %d\n", CALC(10, 5, '+'));
    printf("  CALC(10, 5, '-') = %d\n", CALC(10, 5, '-'));
    printf("  CALC(10, 5, '*') = %d\n", CALC(10, 5, '*'));
    printf("\n");

    // 예시 16: 안전한 매크로 호출
    printf("16. Safe Macro Call:\n");
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("  배열 크기: %zu\n", ARRAY_SIZE(arr2));
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE(arr2); i++) {
        sum += arr2[i];
    }
    printf("  배열 합계: %d\n", sum);
    printf("\n");

    // 예시 17: 매크로 재정의
    printf("17. Macro Redefinition:\n");
    #define GREETING "Hello, World!"
    printf("  GREETING = %s\n", GREETING);
    #undef GREETING
    #define GREETING "Hello, C++!"
    printf("  GREETING (재정의) = %s\n", GREETING);
    printf("\n");

    // 예시 18: 삼항 연산자 매크로
    printf("18. Ternary Operator Macro:\n");
    int age = 20;
    #define IS_ADULT(a) ((a) >= 18 ? "Adult" : "Minor")
    printf("  IS_ADULT(%d) = %s\n", age, IS_ADULT(age));
    printf("  IS_ADULT(%d) = %s\n", 15, IS_ADULT(15));
    printf("\n");

    // 예시 19: 반복 매크로
    printf("19. Loop Macro:\n");
    #define PRINT_LOOP(n) for(int i = 1; i <= n; i++) printf("  i = %d\n", i);
    PRINT_LOOP(5);
    printf("\n");

#define MAX_COUNT  5 //매크로 상수   
#define SAFE_DELETE(nanana) if (nanana) { delete nanana; nanana = nullptr; }
#define SAFE_DELETE_ARRAY(a) if (a) { delete[] a; a = nullptr; }
#define SAFE_DELETE_PRINT(KK) \
    {SAFE_DELETE_ARRAY(KK); \}
    {printf("메모리 해제 완료"); }    
    
    // 예시 20: 매크로 요약
    printf("20. Macro Summary:\n");
    printf("  #define: 상수 및 함수 정의\n");
    printf("  #undef: 매크로 해제\n");
    printf("  #if/#endif: 조건부 컴파일\n");
    printf("  #: 문자열화 연산자\n");
    printf("  ##: 토큰 연결 연산자\n");
    printf("  주의: 매크로는 컴파일 전에 텍스트 치환됨\n");
    


    return 0;
}