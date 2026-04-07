#include <cstdio>

int main() {
    printf("=== C++ Array and Pointer Basic Examples ===\n\n");

    // 예시 1: 기본 배열
    printf("1. Basic Array:\n");
    int arr[] = {10, 20, 30, 40, 50}; //배열
    printf("  int arr[] = {10, 20, 30, 40, 50};\n");
    printf("  arr[0] = %d\n", arr[0]);
    printf("  arr[1] = %d\n", arr[1]);
    printf("  arr[2] = %d\n", arr[2]);
    printf("  arr[3] = %d\n", arr[3]);
    printf("  arr[4] = %d\n", arr[4]);
    printf("\n");

    // 예시 2: 배열의 크기
    printf("2. Array Size:\n");
    int numbers[] = {100, 200, 300, 400};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("  배열 크기: %d\n", size);
    printf("  sizeof(numbers): %zu\n", sizeof(numbers));
    printf("  sizeof(numbers[0]): %zu\n", sizeof(numbers[0]));
    printf("\n");

    // 예시 3: for문으로 배열 순회
    printf("3. Array Traversal with for Loop:\n");
    int data[] = {5, 10, 15, 20, 25};
    for (int i = 0; i < 5; i++) {
        printf("  data[%d] = %d\n", i, data[i]);
    }
    printf("\n");

    // 예시 4: 배열의 메모리 주소
    printf("4. Array Memory Address:\n");
    int scores[] = {90, 80, 70, 60};
    printf("  int scores[] = {90, 80, 70, 60};\n");
    printf("  scores[0]의 주소: %p\n", (void*)&scores[0]);
    printf("  scores[1]의 주소: %p\n", (void*)&scores[1]);
    printf("  scores[2]의 주소: %p\n", (void*)&scores[2]);
    printf("  주소 차이: 각 int는 4바이트씩 증가\n");
    printf("\n");

    // 예시 5: 기본 포인터
    printf("5. Basic Pointer:\n");
    int x = 100;
    int* ptr = &x;
    printf("  int x = 100;\n");
    printf("  int* ptr = &x;\n");
    printf("  x의 값: %d\n", x);
    printf("  x의 주소 (&x): %p\n", (void*)&x);
    printf("  ptr의 값: %p\n", (void*)ptr);
    printf("  *ptr의 값: %d\n", *ptr);
    printf("\n");

    // 예시 6: 포인터로 값 변경
    printf("6. Change Value Through Pointer:\n");
    int num = 50;
    int* p = &num;
    printf("  변경 전: num = %d\n", num);
    *p = 150;
    printf("  *p = 150; 실행\n");
    printf("  변경 후: num = %d\n", num);
    printf("\n");

    // 예시 7: 배열과 포인터의 관계
    printf("7. Array and Pointer Relationship:\n");
    int arr2[] = {10, 20, 30, 40, 50};
    int* ptr_arr = arr2;  // 배열명은 첫 번째 원소의 주소
    int** ptr_arr2 = &ptr_arr;
    int*** ptr_arr3 = &ptr_arr2;
    printf("  int arr2[] = {10, 20, 30, 40, 50};\n");
    printf("  int* ptr_arr = arr2;\n");
    printf("  ptr_arr이 가리키는 값: %d (arr2[0])\n", *ptr_arr);
    printf("  arr2의 주소: %p\n", (void*)arr2);
    printf("  arr2의 주소: %p\n", (void**)&ptr_arr2);
    printf("  arr2의 주소: %p\n", (void***)&ptr_arr3);
    printf("  ptr_arr의 값: %p\n", (void*)ptr_arr);
    printf("  arr2[0]의 주소: %p\n", (void*)&arr2[0]);
    printf("\n");

    // 예시 8: 포인터로 배열 접근
    printf("8. Access Array with Pointer:\n");
    int arr3[] = {100, 200, 300, 400, 500};
    int* p_arr = arr3;
    printf("  포인터로 배열 요소 접근:\n");
    printf("  p_arr[0] = %d\n", p_arr[0]);
    printf("  p_arr[1] = %d\n", p_arr[1]);
    printf("  p_arr[2] = %d\n", p_arr[2]);
    printf("  p_arr[3] = %d\n", p_arr[3]);
    printf("  p_arr[4] = %d\n", p_arr[4]);
    printf("\n");

    // 예시 9: 포인터 산술 (증감)
    printf("9. Pointer Arithmetic:\n");
    int arr4[] = {10, 20, 30, 40, 50};
    int* ptr4 = arr4;
    printf("  int arr4[] = {10, 20, 30, 40, 50};\n");
    printf("  int* ptr4 = arr4;\n");
    printf("  *ptr4의 값: %d\n", *ptr4);
    ptr4++;
    printf("  ptr4++ 실행\n");
    printf("  *ptr4의 값: %d (arr4[1])\n", *ptr4);
    ptr4 += 2;
    printf("  ptr4 += 2 실행\n");
    printf("  *ptr4의 값: %d (arr4[3])\n", *ptr4);
    printf("\n");

    // 예시 10: 포인터로 배열 순회
    printf("10. Traverse Array with Pointer:\n");
    int arr5[] = {5, 10, 15, 20, 25};
    int* p5 = arr5;
    printf("  배열: {5, 10, 15, 20, 25}\n");
    printf("  포인터로 순회:\n");
    for (int i = 0; i < 5; i++) {
        printf("  *(p5 + %d) = %d\n", i, *(p5 + i));
    }
    printf("\n");

    // 예시 11: 포인터와 배열 주소 표기
    printf("11. Array Address Notation:\n");
    int arr6[] = {100, 200, 300};
    printf("  int arr6[] = {100, 200, 300};\n");
    printf("  arr6[0] == *arr6: %s\n", arr6[0] == *arr6 ? "true" : "false");
    printf("  arr6[1] == *(arr6 + 1): %s\n", arr6[1] == *(arr6 + 1) ? "true" : "false");
    printf("  arr6[2] == *(arr6 + 2): %s\n", arr6[2] == *(arr6 + 2) ? "true" : "false");
    printf("  &arr6[0] == arr6: %s\n", &arr6[0] == arr6 ? "true" : "false");
    printf("\n");

    // 예시 12: 2D 배열
    printf("12. 2D Array:\n");
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("  2D 배열 출력:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
    printf("\n");

    // 예시 13: 2D 배열과 포인터
    printf("13. 2D Array and Pointer:\n");
    int matrix2[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    printf("  2D 배열: {{10, 20, 30}, {40, 50, 60}}\n");
    printf("  matrix2[0][0] = %d\n", matrix2[0][0]);
    printf("  matrix2[0][1] = %d\n", matrix2[0][1]);
    printf("  matrix2[1][0] = %d\n", matrix2[1][0]);
    printf("  matrix2[1][2] = %d\n", matrix2[1][2]);
    printf("\n");

    // 예시 14: NULL 포인터
    printf("14. NULL Pointer:\n");
    int* nullPtr = NULL;
    printf("  int* nullPtr = NULL;\n");
    printf("  nullPtr의 값: %p\n", (void*)nullPtr);
    printf("  NULL 포인터는 아무것도 가리키지 않음\n");
    printf("  NULL 포인터를 역참조하면 오류 발생!\n");
    printf("\n");

    // 예시 15: 포인터 배열
    printf("15. Array of Pointers:\n");
    int a = 100, b = 200, c = 300;
    int* ptrArray[3] = {&a, &b, &c};
    printf("  int a = 100, b = 200, c = 300;\n");
    printf("  int* ptrArray[3] = {&a, &b, &c};\n");
    printf("  *ptrArray[0] = %d\n", *ptrArray[0]);
    printf("  *ptrArray[1] = %d\n", *ptrArray[1]);
    printf("  *ptrArray[2] = %d\n", *ptrArray[2]);
    printf("\n");

    // 예시 16: 배열 합계 계산 (포인터 사용)
    printf("16. Calculate Sum with Pointer:\n");
    int numbers2[] = {10, 20, 30, 40, 50};
    int sum = 0;
    int* pn = numbers2;
    for (int i = 0; i < 5; i++) {
        sum += *(pn + i);
    }
    printf("  배열: {10, 20, 30, 40, 50}\n");
    printf("  포인터로 합계 계산: %d\n", sum);
    printf("\n");

    // 예시 17: const 포인터
    printf("17. const Pointer:\n");
    int value = 100;
    const int* constPtr = &value;
    printf("  int value = 100;\n");
    printf("  const int* constPtr = &value;\n");
    printf("  *constPtr의 값: %d\n", *constPtr);
    printf("  포인터가 가리키는 값은 변경할 수 없음\n");
    printf("\n");

    // 예시 18: 포인터 배열 크기
    printf("18. Array and Pointer Size Comparison:\n");
    int arr7[] = {1, 2, 3, 4, 5};
    int* ptr7 = arr7;
    printf("  sizeof(arr7): %zu (배열 전체 크기)\n", sizeof(arr7));
    printf("  sizeof(ptr7): %zu (포인터 크기만)\n", sizeof(ptr7));
    printf("  배열의 크기: %zu\n", sizeof(arr7) / sizeof(arr7[0]));
    printf("\n");

    // 예시 19: 포인터 비교
    printf("19. Pointer Comparison:\n");
    int arr8[] = {10, 20, 30, 40, 50};
    int* p1 = &arr8[0];
    int* p2 = &arr8[2];
    printf("  p1이 가리키는 값: %d\n", *p1);
    printf("  p2가 가리키는 값: %d\n", *p2);
    printf("  p1 == p2: %s\n", p1 == p2 ? "true" : "false");
    printf("  p1 < p2: %s\n", p1 < p2 ? "true" : "false");
    printf("  p2 - p1: %ld (배열 내 거리)\n", p2 - p1);
    printf("\n");

    // 예시 20: 배열과 포인터 요약
    printf("20. Summary:\n");
    printf("  배열 표기법: arr[i]\n");
    printf("  포인터 표기법: *(arr + i)\n");
    printf("  둘은 같은 의미\n");
    printf("  배열명은 첫 번째 원소의 주소와 같음\n");
    printf("  포인터로 배열 요소에 접근 가능\n");

    return 0;
}