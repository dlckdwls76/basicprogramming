#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// ===== 예시 1: Call by Value =====
void ChangeByValue(int num) {
    printf("  함수 내부 - 변경 전: %d\n", num);
    num = 100;
    printf("  함수 내부 - 변경 후: %d\n", num);
}

// ===== 예시 2: Call by Reference =====
void ChangeByReference(int& ref) {
    printf("  함수 내부 - 변경 전: %d\n", ref);
    ref = 100;
    printf("  함수 내부 - 변경 후: %d\n", ref);
}

// ===== 예시 3: Pointer (포인터) =====
void ChangeByPointer(int* ptr) {
    printf("  함수 내부 - 변경 전: %d\n", *ptr);
    *ptr = 100;
    printf("  함수 내부 - 변경 후: %d\n", *ptr);
}

// ===== 예시 4: 배열 Call by Value (복사) =====
void PrintArrayByValue(int arr[3]) {
    printf("  배열 요소들:\n");
    for (int i = 0; i < 3; i++) {
        printf("    arr[%d] = %d\n", i, arr[i]);
    }
    arr[0] = 999;
    printf("  함수 내부에서 arr[0]을 999로 변경\n");
}

// ===== 예시 5: 배열 Call by Reference =====
void ModifyArrayByReference(int (&arr)[3]) {
    printf("  배열 요소들:\n");
    for (int i = 0; i < 3; i++) {
        printf("    arr[%d] = %d\n", i, arr[i]);
    }
    arr[0] = 888;
    printf("  함수 내부에서 arr[0]을 888로 변경\n");
}

// ===== 예시 6: 구조체 Call by Value =====
struct Point {
    int x;
    int y;
};

void ChangeStructByValue(Point p) {
    printf("  함수 내부 - 변경 전: (%d, %d)\n", p.x, p.y);
    p.x = 50;
    p.y = 60;
    printf("  함수 내부 - 변경 후: (%d, %d)\n", p.x, p.y);
}

// ===== 예시 7: 구조체 Call by Reference =====
void ChangeStructByReference(Point& p) {
    printf("  함수 내부 - 변경 전: (%d, %d)\n", p.x, p.y);
    p.x = 70;
    p.y = 80;
    printf("  함수 내부 - 변경 후: (%d, %d)\n", p.x, p.y);
}

// ===== 예시 8: 두 수 교환 (Call by Reference) =====
void Swap(int& a, int& b) {
    printf("  교환 전: a = %d, b = %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("  교환 후: a = %d, b = %d\n", a, b);
}

// ===== 예시 9: const Reference =====
void PrintByConstReference(const int& ref) {
    printf("  const reference 값: %d\n", ref);
    // ref = 100;  // 에러! const이므로 변경 불가
}

// ===== 예시 10: 배열 크기 계산 (Reference) =====
void PrintArraySize(int (&arr)[5]) {
    printf("  배열 크기: %zu bytes\n", sizeof(arr));
    printf("  요소 개수: %zu\n", sizeof(arr) / sizeof(arr[0]));
}

int main() {
    printf("=== Call by Value vs Call by Reference ===\n\n");

    // 예시 1: Call by Value
    printf("1. Call by Value (값 전달):\n");
    int num1 = 10;
    printf("  함수 호출 전: %d\n", num1);
    ChangeByValue(num1);
    printf("  함수 호출 후: %d (변경 안 됨)\n", num1);
    printf("  => 원본 변수는 영향을 받지 않음\n");
    printf("\n");

    // 예시 2: Call by Reference
    printf("2. Call by Reference (참조 전달):\n");
    int num2 = 10;
    printf("  함수 호출 전: %d\n", num2);
    ChangeByReference(num2);
    printf("  함수 호출 후: %d (변경됨)\n", num2);
    printf("  => 원본 변수가 변경됨\n");
    printf("\n");

    // 예시 3: Call by Pointer
    printf("3. Call by Pointer (포인터 전달):\n");
    int num3 = 10;
    printf("  함수 호출 전: %d\n", num3);
    ChangeByPointer(&num3);
    printf("  함수 호출 후: %d (변경됨)\n", num3);
    printf("  => 포인터로도 원본 변수 변경 가능\n");
    printf("\n");

    // 예시 4: Call by Value vs Reference 비교
    printf("4. Call by Value vs Reference 비교:\n");
    int a = 5;
    int b = 5;
    printf("  a (Call by Value):\n");
    ChangeByValue(a);
    printf("  결과: a = %d\n", a);
    printf("\n");
    printf("  b (Call by Reference):\n");
    ChangeByReference(b);
    printf("  결과: b = %d\n", b);
    printf("\n");

    // 예시 5: 배열 Call by Value
    printf("5. Array Call by Value:\n");
    int arr1[] = {1, 2, 3};
    printf("  호출 전: arr1[0] = %d\n", arr1[0]);
    PrintArrayByValue(arr1);
    printf("  호출 후: arr1[0] = %d (변경 안 됨)\n", arr1[0]);
    printf("  => 배열은 포인터로 전달되므로 변경됨\n");
    printf("\n");

    // 예시 6: 배열 Call by Reference
    printf("6. Array Call by Reference:\n");
    int arr2[] = {1, 2, 3};
    printf("  호출 전: arr2[0] = %d\n", arr2[0]);
    ModifyArrayByReference(arr2);
    printf("  호출 후: arr2[0] = %d (변경됨)\n", arr2[0]);
    printf("  => Reference로 전달하면 원본 배열 변경\n");
    printf("\n");

    // 예시 7: 구조체 Call by Value
    printf("7. Struct Call by Value:\n");
    Point p1 = {10, 20};
    printf("  호출 전: (%d, %d)\n", p1.x, p1.y);
    ChangeStructByValue(p1);
    printf("  호출 후: (%d, %d) (변경 안 됨)\n", p1.x, p1.y);
    printf("\n");

    // 예시 8: 구조체 Call by Reference
    printf("8. Struct Call by Reference:\n");
    Point p2 = {10, 20};
    printf("  호출 전: (%d, %d)\n", p2.x, p2.y);
    ChangeStructByReference(p2);
    printf("  호출 후: (%d, %d) (변경됨)\n", p2.x, p2.y);
    printf("\n");

    // 예시 9: 교환 함수
    printf("9. Swap Function (Call by Reference):\n");
    int x = 100;
    int y = 200;
    Swap(x, y);
    printf("  최종 결과: x = %d, y = %d\n", x, y);
    printf("\n");

    // 예시 10: const Reference
    printf("10. const Reference:\n");
    int num4 = 25;
    printf("  원본 값: %d\n", num4);
    PrintByConstReference(num4);
    printf("  const reference로 읽기만 가능 (쓰기 불가)\n");
    printf("\n");

    // 예시 11: 메모리 주소 비교
    printf("11. Memory Address Comparison:\n");
    int num5 = 50;
    printf("  원본 변수 주소: %p\n", (void*)&num5);
    printf("  Reference 사용 시 같은 주소를 참조\n");
    int& ref = num5;
    printf("  Reference 주소: %p\n", (void*)&ref);
    printf("  => 두 주소가 같음\n");
    printf("\n");

    // 예시 12: 배열 크기
    printf("12. Array Size with Reference:\n");
    int arr3[] = {1, 2, 3, 4, 5};
    PrintArraySize(arr3);
    printf("\n");

    // 예시 13: 여러 Reference 전달
    printf("13. Multiple References:\n");
    int p = 10;
    int q = 20;
    printf("  변경 전: p = %d, q = %d\n", p, q);
    Swap(p, q);
    printf("  변경 후: p = %d, q = %d\n", p, q);
    printf("\n");

    // 예시 14: 성능 비교
    printf("14. Performance Comparison:\n");
    printf("  Call by Value: 데이터 복사 (느림, 메모리 많이 사용)\n");
    printf("  Call by Reference: 주소만 전달 (빠름, 메모리 절약)\n");
    printf("  => 큰 데이터는 Reference 사용 권장\n");
    printf("\n");

    // 예시 15: 요약
    printf("15. Call by Value vs Reference Summary:\n");
    printf("  Call by Value (&없음):\n");
    printf("    - 데이터 복사\n");
    printf("    - 원본 변경 불가\n");
    printf("    - 작은 데이터에 적합\n");
    printf("\n");
    printf("  Call by Reference (&있음):\n");
    printf("    - 주소 전달\n");
    printf("    - 원본 변경 가능\n");
    printf("    - 성능이 좋음\n");
    printf("    - 큰 데이터에 적합\n");

    return 0;
}