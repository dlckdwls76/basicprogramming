#include <cstdio>

int main() {
    printf("=== C++ for and while Loop Examples ===\n\n");

    // 예시 1: 기본 for문
    printf("1. Basic for Loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("  i = %d\n", i);
    }
    printf("\n");

    // 예시 2: for문 - 역순
    printf("2. for Loop (Reverse):\n");
    for (int i = 5; i >= 1; i--) {
        printf("  i = %d\n", i);
    }
    printf("\n");

    // 예시 3: for문 - 증감량 변경
    printf("3. for Loop (Step 2):\n");
    for (int i = 0; i <= 10; i += 2) {
        printf("  i = %d\n", i);
    }
    printf("\n");

    // 예시 4: 기본 while문
    printf("4. Basic while Loop:\n");
    int count = 1;
    while (count <= 5) {
        printf("  count = %d\n", count);
        count++;
    }
    printf("\n");

    // 예시 5: while문 - 역순
    printf("5. while Loop (Reverse):\n");
    int num = 5;
    while (num >= 1) {
        printf("  num = %d\n", num);
        num--;
    }
    printf("\n");

    // 예시 6: for문 - 배열 순회
    printf("6. for Loop with Array:\n");
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");

    // 예시 7: while문 - 배열 순회
    printf("7. while Loop with Array:\n");
    int arr2[] = {100, 200, 300, 400, 500};
    int idx = 0;
    while (idx < 5) {
        printf("  arr2[%d] = %d\n", idx, arr2[idx]);
        idx++;
    }
    printf("\n");

    // 예시 8: for문 - 합계 계산
    printf("8. for Loop - Calculate Sum:\n");
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("  Sum of 1 to 10: %d\n", sum);
    printf("\n");

    // 예시 9: while문 - 합계 계산
    printf("9. while Loop - Calculate Sum:\n");
    int sum2 = 0;
    int i = 1;
    while (i <= 10) {
        sum2 += i;
        i++;
    }
    printf("  Sum of 1 to 10: %d\n", sum2);
    printf("\n");

    // ��시 10: for문 - 팩토리얼 계산
    printf("10. for Loop - Calculate Factorial:\n");
    int factorial = 1;
    for (int i = 1; i <= 5; i++) {
        factorial *= i;
    }
    printf("  5! = %d\n", factorial);
    printf("\n");

    // 예시 11: while문 - 팩토리얼 계산
    printf("11. while Loop - Calculate Factorial:\n");
    int factorial2 = 1;
    int j = 1;
    while (j <= 5) {
        factorial2 *= j;
        j++;
    }
    printf("  5! = %d\n", factorial2);
    printf("\n");

    // 예시 12: for문 - break문
    printf("12. for Loop with break:\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 6) {
            printf("  Loop stopped at i = %d\n", i);
            break;
        }
        printf("  i = %d\n", i);
    }
    printf("\n");

    // 예시 13: while문 - break문
    printf("13. while Loop with break:\n");
    int k = 1;
    while (k <= 10) {
        if (k == 6) {
            printf("  Loop stopped at k = %d\n", k);
            break;
        }
        printf("  k = %d\n", k);
        k++;
    }
    printf("\n");

    // 예시 14: for문 - continue문
    printf("14. for Loop with continue:\n");
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            printf("  Skipped i = %d\n", i);
            continue;
        }
        printf("  i = %d\n", i);
    }
    printf("\n");

    // ���시 15: while문 - continue문
    printf("15. while Loop with continue:\n");
    int m = 1;
    while (m <= 5) {
        if (m == 3) {
            printf("  Skipped m = %d\n", m);
            m++;
            continue;
        }
        printf("  m = %d\n", m);
        m++;
    }
    printf("\n");

    // 예시 16: 중첩 for문 - 구구단
    printf("16. Nested for Loop (2x2 Multiplication Table):\n");
    for (int i = 2; i <= 3; i++) {
        printf("  %d times table:\n", i);
        for (int j = 1; j <= 5; j++) {
            printf("    %d x %d = %d\n", i, j, i * j);
        }
    }
    printf("\n");

    // 예시 17: 중첩 for문 - 패턴 출력
    printf("17. Nested for Loop - Pattern:\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // 예시 18: for문 - 짝수만 출력
    printf("18. for Loop - Even Numbers:\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("  %d\n", i);
        }
    }
    printf("\n");

    // 예시 19: while문 - 홀수만 출력
    printf("19. while Loop - Odd Numbers:\n");
    int n = 1;
    while (n <= 10) {
        if (n % 2 != 0) {
            printf("  %d\n", n);
        }
        n++;
    }
    printf("\n");

    // 예시 20: for문 - 카운트다운
    printf("20. for Loop - Countdown:\n");
    for (int i = 10; i >= 1; i--) {
        printf("  %d\n", i);
    }
    printf("  Blastoff!\n");

    return 0;
}