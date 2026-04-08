#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// ===== 예시 1: 가로 형태 (한 줄에 모든 단) =====
void PrintHorizontal() {
    printf("가로 형태 (한 줄에 모든 단):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        for (int dan = 2; dan <= 9; dan++) {
            printf("%d×%d=%2d  ", dan, i, dan * i);
        }
        printf("\n");
    }
}

// ===== 예시 2: 가로 형태 (포맷팅) =====
void PrintHorizontalFormatted() {
    printf("가로 형태 (포맷팅):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        for (int dan = 2; dan <= 9; dan++) {
            printf("%d*%d=%3d  ", dan, i, dan * i);
        }
        printf("\n");
    }
}

// ===== 예시 3: 가로 형태 (더 깔끔한 형식) =====
void PrintHorizontalClean() {
    printf("가로 형태 (깔끔한 형식):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        printf("[%d단계]\n", i);
        for (int dan = 2; dan <= 9; dan++) {
            printf("  %d×%d=%2d", dan, i, dan * i);
            if (dan < 9) printf("  |  ");
        }
        printf("\n\n");
    }
}

// ===== 예시 4: 가로 형태 (탭 구분) =====
void PrintHorizontalTab() {
    printf("가로 형태 (탭 구분):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        for (int dan = 2; dan <= 9; dan++) {
            printf("%d×%d=%2d\t", dan, i, dan * i);
        }
        printf("\n");
    }
}

// ===== 예시 5: 특정 단을 가로로 출력 =====
void PrintSingleTableHorizontal(int dan) {
    printf("%d단 (가로):\n", dan);
    for (int i = 1; i <= 9; i++) {
        printf("%d×%d=%2d", dan, i, dan * i);
        if (i < 9) printf("  ");
    }
    printf("\n");
}

// ===== 예시 6: 모든 단을 가로로 출력 =====
void PrintAllTablesHorizontal() {
    printf("모든 단을 가로로 출력:\n\n");
    
    for (int dan = 2; dan <= 9; dan++) {
        printf("%d단: ", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d×%d=%2d", dan, i, dan * i);
            if (i < 9) printf("  ");
        }
        printf("\n");
    }
}

// ===== 예시 7: 세로 2열 형태 =====
void PrintTwoColumn() {
    printf("세로 2열 형태:\n\n");
    
    for (int dan = 2; dan <= 9; dan++) {
        printf("%d단: ", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d*%d=%2d", dan, i, dan * i);
            if (i < 9) printf("  ");
        }
        printf("\n");
    }
}

// ===== 예시 8: 콤마로 구분 =====
void PrintHorizontalComma() {
    printf("가로 형태 (콤마 구분):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        for (int dan = 2; dan <= 9; dan++) {
            printf("%d×%d=%2d", dan, i, dan * i);
            if (dan < 9) printf(", ");
        }
        printf("\n");
    }
}

// ===== 예시 9: 2x2 테이블 형태 =====
void PrintGrid() {
    printf("그리드 형태 (2x2):\n\n");
    
    for (int i = 1; i <= 9; i++) {
        for (int dan = 2; dan <= 5; dan++) {
            printf("%d×%d=%2d  ", dan, i, dan * i);
        }
        printf("\n");
        for (int dan = 6; dan <= 9; dan++) {
            printf("%d×%d=%2d  ", dan, i, dan * i);
        }
        printf("\n\n");
    }
}

// ===== 예시 10: 박스 형태 =====
void PrintBox() {
    printf("박스 형태:\n\n");
    
    for (int i = 1; i <= 9; i++) {
        printf("┌");
        for (int dan = 2; dan <= 9; dan++) {
            printf("─────────┬");
        }
        printf("─────────┐\n");
        
        printf("│");
        for (int dan = 2; dan <= 9; dan++) {
            printf(" %d×%d=%2d │", dan, i, dan * i);
        }
        printf("\n");
    }
    
    printf("└");
    for (int dan = 2; dan <= 9; dan++) {
        printf("─────────┴");
    }
    printf("─────────┘\n");
}

int main() {
    printf("=== Horizontal Multiplication Table ===\n\n");

    // 예시 1: 기본 가로 형태
    printf("1. 기본 가로 형태:\n");
    PrintHorizontal();
    printf("\n");

    // 예시 2: 포맷팅된 가로 형태
    printf("2. 포맷팅된 가로 형태:\n");
    PrintHorizontalFormatted();
    printf("\n");

    // 예시 3: 깔끔한 가로 형태
    printf("3. 깔끔한 가로 형태:\n");
    PrintHorizontalClean();
    printf("\n");

    // 예시 4: 탭 구분 가로 형태
    printf("4. 탭 구분 가로 형태:\n");
    PrintHorizontalTab();
    printf("\n");

    // 예시 5: 단일 단 가로 출력 (2단)
    printf("5. 단일 단 가로 출력 (2단):\n");
    PrintSingleTableHorizontal(2);
    printf("\n");

    // 예시 6: 단일 단 가로 출력 (5단)
    printf("6. 단일 단 가로 출력 (5단):\n");
    PrintSingleTableHorizontal(5);
    printf("\n");

    // 예시 7: 단일 단 가로 출력 (9단)
    printf("7. 단일 단 가로 출력 (9단):\n");
    PrintSingleTableHorizontal(9);
    printf("\n");

    // 예시 8: 모든 단을 가로로
    printf("8. 모든 단을 가로로 출력:\n");
    PrintAllTablesHorizontal();
    printf("\n");

    // 예시 9: 콤마로 구분
    printf("9. 콤마로 구분된 가로 형태:\n");
    PrintHorizontalComma();
    printf("\n");

    // 예시 10: 그리드 형태
    printf("10. 그리드 형태 (2x2):\n");
    PrintGrid();
    printf("\n");

    // 예시 11: 가로 형태 요약
    printf("11. 가로 형태 요약:\n");
    printf("  1. 한 줄에 여러 단 출력\n");
    printf("  2. 각 줄은 곱하는 수(1~9)가 같음\n");
    printf("  3. 구분자로 띄어쓰기, 탭, 콤마 등 사용 가능\n");
    printf("  4. 포맷팅으로 정렬 가능\n");

    return 0;
}