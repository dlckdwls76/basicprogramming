#include <cstdio>

int main() {
    printf("=== C++ Nested for Loop and do-while Loop Examples ===\n\n");

    // 예시 1: 기본 이중 for문
    printf("1. Basic Nested for Loop:\n");
    for (int i = 1; i <= 3; i++) {
        printf("  i = %d: ", i);
        for (int j = 1; j <= 3; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");

    // 예시 2: 기본 do-while문
    printf("2. Basic do-while Loop:\n");
    int count = 3;
    do {
        printf("  count = %d\n", count);
        count++;
    } while (count <= 3);
    printf("\n");

    // 예시 3: do-while문 - 최소 1회 실행
    printf("3. do-while Loop - Execute at least once:\n");
    int num = 10;
    do {
        printf("  This executes even though condition is false\n");
        printf("  num = %d\n", num);
    } while (num < 5);  // 거짓이지만 최소 1회 실행됨
    printf("\n");

    // 예시 4: 이중 for문 - 구구단
    printf("4. Nested for Loop - Multiplication Table:\n");
    for (int i = 2; i <= 4; i++) {
        printf("  %d times table:\n", i);
        for (int j = 1; j <= 5; j++) {
            printf("    %d x %d = %d\n", i, j, i * j);
        }
    }
    printf("\n");

    // 예시 5: 이중 for문 - 별 패턴 (삼각형)
    printf("5. Nested for Loop - Triangle Pattern:\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // 예시 6: 이중 for문 - 역 삼각형
    printf("6. Nested for Loop - Reverse Triangle Pattern:\n");
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // 예시 7: 이중 for문 - 정사각형
    printf("7. Nested for Loop - Square Pattern:\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // 예시 8: 이중 for문 - 2D 배열 출력
    printf("8. Nested for Loop - 2D Array:\n");
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 예시 9: do-while문 - 역순 카운트
    printf("9. do-while Loop - Countdown:\n");
    int countdown = 5;
    do {
        printf("  %d\n", countdown);
        countdown--;
    } while (countdown > 0);
    printf("  Blastoff!\n");
    printf("\n");

    // 예시 10: 이중 for문 - 1부터 n까지의 합
    printf("10. Nested for Loop - Sum of 1 to n:\n");
    for (int i = 1; i <= 3; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
        printf("  Sum of 1 to %d: %d\n", i, sum);
    }
    printf("\n");

    // 예시 11: do-while문 - 합계 계산
    printf("11. do-while Loop - Calculate Sum:\n");
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 10);
    printf("  Sum of 1 to 10: %d\n", sum);
    printf("\n");

    // 예시 12: 이중 for문과 break
    printf("12. Nested for Loop with break:\n");
    for (int i = 1; i <= 5; i++) {
        printf("  i = %d: ", i);
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                printf("break ");
                break;
            }
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");

    // 예시 13: 이중 for문 - 체스판 패턴
    printf("13. Nested for Loop - Checkerboard Pattern:\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if ((i + j) % 2 == 0) {
                printf("■");
            } else {
                printf("□");
            }
        }
        printf("\n");
    }
    printf("\n");

    // 예시 14: do-while문 - 사용자 입력 시뮬레이션
    printf("14. do-while Loop - Simulate User Input:\n");
    int attempt = 0;
    do {
        printf("  Attempt %d: ", attempt + 1);
        printf("Trying password...\n");
        attempt++;
    } while (attempt < 3);
    printf("  Max attempts reached.\n");
    printf("\n");

    // 예시 15: 이중 for문 - 소수 찾기
    printf("15. Nested for Loop - Find Prime Numbers:\n");
    printf("  Prime numbers from 2 to 20:\n");
    for (int i = 2; i <= 20; i++) {
        int isPrime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("  %d ", i);
        }
    }
    printf("\n\n");

    // 예시 16: do-while문 - 팩토리얼 계산
    printf("16. do-while Loop - Calculate Factorial:\n");
    int factorial = 1;
    int n = 1;
    do {
        factorial *= n;
        n++;
    } while (n <= 5);
    printf("  5! = %d\n", factorial);
    printf("\n");

    // 예시 17: 이중 for문 - 다이아몬드 패턴
    printf("17. Nested for Loop - Diamond Pattern:\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 3; i >= 1; i--) {
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // 예시 18: 이중 for문 - 곱셈표
    printf("18. Nested for Loop - 3x3 Multiplication Table:\n");
    printf("  x");
    for (int j = 1; j <= 3; j++) {
        printf("%3d", j);
    }
    printf("\n");
    for (int i = 1; i <= 3; i++) {
        printf("  %d", i);
        for (int j = 1; j <= 3; j++) {
            printf("%3d", i * j);
        }
        printf("\n");
    }
    printf("\n");

    // 예시 19: do-while문 - 누적
    printf("19. do-while Loop - Accumulation:\n");
    int total = 0;
    int value = 10;
    do {
        total += value;
        printf("  value = %d, total = %d\n", value, total);
        value -= 2;
    } while (value > 0);
    printf("\n");

    // 예시 20: 이중 for문과 do-while문 조합
    printf("20. Combined Nested for and do-while:\n");
    for (int i = 1; i <= 2; i++) {
        printf("  Iteration %d:\n", i);
        int j = 1;
        do {
            printf("    j = %d\n", j);
            j++;
        } while (j <= 3);
    }

    return 0;
}