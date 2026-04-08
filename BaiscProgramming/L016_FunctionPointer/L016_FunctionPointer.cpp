#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// ===== 예시 1: 기본 함수들 =====
//int형을 반환하고, 파라미터로 int형 변수 2개를 받는함수 형식을 이제부터 operation 이름을 쓰겠다.
int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b) {
    return a - b;
}

int Multiply(int a, int b) {
    return a * b;
}

int Divide(int a, int b) {      
    if (b == 0) {
        printf("  0으로 나눌 수 없습니다!\n");
        return 0;
    }
    return a / b;
}

// ===== 예시 2: 함수포인터를 매개변수로 받는 함수 =====
int Calculate(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

// ===== 예시 3: 다양한 작업을 하는 함수들 =====
void PrintHello() {
    printf("  안녕하세요!\n");
}

void PrintGoodbye() {
    printf("  안녕히 가세요!\n");
}

void PrintWelcome() {
    printf("  어서오세요!\n");
}

// ===== 예시 4: 함수포인터 배열 사용 함수 =====
void ExecuteFunction(void (*func)()) {
    func();
}

// ===== 예시 5: 콜백 함수 (Callback) =====
void PrintNumber(int n) {
    printf("  번호: %d\n", n);
}

void ProcessArray(int arr[], int size, void (*callback)(int)) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}

// ===== 예시 6: 함수 포인터를 반환하는 함수 =====
int (*GetOperator(char op))(int, int) {
    switch (op) {
        case '+':
            return Add;
        case '-':
            return Subtract;
        case '*':
            return Multiply;
        case '/':
            return Divide;
        default:
            return Add;
    }
}

// ===== 예시 7: 정렬 함수 =====
int CompareAscending(int a, int b) {
    return a - b;
}

int CompareDescending(int a, int b) {
    return b - a;
}

void BubbleSort(int arr[], int size, int (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ===== 예시 8: 필터 함수 =====
int IsEven(int n) {
    return n % 2 == 0;
}

int IsOdd(int n) {
    return n % 2 != 0;
}

int IsPositive(int n) {
    return n > 0;
}

int CountMatching(int arr[], int size, int (*filter)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (filter(arr[i])) {
            count++;
        }
    }
    return count;
}

// ===== 예시 9: 변환 함수 =====
int Square(int n) {
    return n * n;
}

int Double(int n) {
    return n * 2;
}

int AbsoluteValue(int n) {
    return n < 0 ? -n : n;
}

void TransformArray(int arr[], int size, int (*transform)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = transform(arr[i]);
    }
}

// ===== 예시 10: 함수 실행 =====
void ExecuteFunctionWithResult(int a, int b, int (*func)(int, int), const char* name) {
    int result = func(a, b);
    printf("  %s(%d, %d) = %d\n", name, a, b, result);
}

int main() {
    printf("=== Function Pointer Examples ===\n\n");

    // 예시 1: 기본 함수포인터 선언 및 사용
    printf("1. Basic Function Pointer:\n");
    int (*funcPtr)(int, int);  // 함수포인터 선언
    
    funcPtr = Add;
    printf("  Add(10, 5) = %d\n", funcPtr(10, 5));
    
    funcPtr = Subtract;
    printf("  Subtract(10, 5) = %d\n", funcPtr(10, 5));
    
    funcPtr = Multiply;
    printf("  Multiply(10, 5) = %d\n", funcPtr(10, 5));
    
    funcPtr = Divide;
    printf("  Divide(10, 5) = %d\n", funcPtr(10, 5));
    printf("\n");

    // 예시 2: 함수포인터 배열
    printf("2. Array of Function Pointers:\n");
    int (*functions[])(int, int) = {Add, Subtract, Multiply, Divide};
    const char* operatorNames[] = {"+", "-", "*", "/"};
    
    for (int i = 0; i < 4; i++) {
        printf("  %d %s %d = %d\n", 20, operatorNames[i], 4, functions[i](20, 4));
    }
    printf("\n");

    // 예시 3: 함수포인터를 매개변수로 전달
    printf("3. Function Pointer as Parameter:\n");
    printf("  Calculate(100, 25, Add) = %d\n", Calculate(100, 25, Add));
    printf("  Calculate(100, 25, Subtract) = %d\n", Calculate(100, 25, Subtract));
    printf("  Calculate(100, 25, Multiply) = %d\n", Calculate(100, 25, Multiply));
    printf("  Calculate(100, 25, Divide) = %d\n", Calculate(100, 25, Divide));
    printf("\n");

    // 예시 4: 반환값이 void인 함수포인터
    printf("4. Void Function Pointer:\n");
    void (*printFunc)();
    
    printFunc = PrintHello;
    printf("  PrintHello():");
    printFunc();
    
    printFunc = PrintGoodbye;
    printf("  PrintGoodbye():");
    printFunc();
    
    printFunc = PrintWelcome;
    printf("  PrintWelcome():");
    printFunc();
    printf("\n");

    // 예시 5: 함수포인터 배열 (void 함수)
    printf("5. Array of Void Function Pointers:\n");
    void (*voidFunctions[])() = {PrintHello, PrintGoodbye, PrintWelcome};
    
    for (int i = 0; i < 3; i++) {
        printf("  Function %d: ", i + 1);
        voidFunctions[i]();
    }
    printf("\n");

    // 예시 6: 콜백 함수 (Callback)
    printf("6. Callback Function:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    printf("  배열의 각 요소:\n");
    ProcessArray(numbers, 5, PrintNumber);
    printf("\n");

    // 예시 7: 함수포인터를 반환하는 함수
    printf("7. Function Returning Function Pointer:\n");
    int (*operatorFunc)(int, int);
    
    operatorFunc = GetOperator('+');
    printf("  '+' 연산: 50 + 30 = %d\n", operatorFunc(50, 30));
    
    operatorFunc = GetOperator('-');
    printf("  '-' 연산: 50 - 30 = %d\n", operatorFunc(50, 30));
    
    operatorFunc = GetOperator('*');
    printf("  '*' 연산: 50 * 30 = %d\n", operatorFunc(50, 30));
    
    operatorFunc = GetOperator('/');
    printf("  '/' 연산: 50 / 30 = %d\n", operatorFunc(50, 30));
    printf("\n");

    // 예시 8: 정렬 함수 (함수포인터 사용)
    printf("8. Sorting with Function Pointer:\n");
    int arr1[] = {5, 2, 8, 1, 9, 3};
    int arr2[] = {5, 2, 8, 1, 9, 3};
    
    printf("  원본 배열: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr1[i]);
    printf("\n");
    
    BubbleSort(arr1, 6, CompareAscending);
    printf("  오름차순: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr1[i]);
    printf("\n");
    
    BubbleSort(arr2, 6, CompareDescending);
    printf("  내림차순: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr2[i]);
    printf("\n\n");

    // 예시 9: 필터 함수
    printf("9. Filter Function:\n");
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("  배열: ");
    for (int i = 0; i < 10; i++) printf("%d ", data[i]);
    printf("\n");
    
    printf("  짝수 개수: %d\n", CountMatching(data, 10, IsEven));
    printf("  홀수 개수: %d\n", CountMatching(data, 10, IsOdd));
    printf("  양수 개수: %d\n", CountMatching(data, 10, IsPositive));
    printf("\n");

    // 예시 10: 변환 함수
    printf("10. Transform Function:\n");
    int values[] = {1, 2, 3, 4, 5};
    
    printf("  원본: ");
    for (int i = 0; i < 5; i++) printf("%d ", values[i]);
    printf("\n");
    
    TransformArray(values, 5, Square);
    printf("  제곱: ");
    for (int i = 0; i < 5; i++) printf("%d ", values[i]);
    printf("\n");
    
    int values2[] = {1, 2, 3, 4, 5};
    TransformArray(values2, 5, Double);
    printf("  2배: ");
    for (int i = 0; i < 5; i++) printf("%d ", values2[i]);
    printf("\n");
    printf("\n");

    // 예시 11: NULL 함수포인터
    printf("11. NULL Function Pointer:\n");
    int (*nullFunc)(int, int) = nullptr;
    
    if (nullFunc == nullptr) {
        printf("  함수포인터가 NULL입니다\n");
    }
    
    nullFunc = Add;
    if (nullFunc != nullptr) {
        printf("  함수포인터가 유효합니다: %d\n", nullFunc(10, 20));
    }
    printf("\n");

    // 예시 12: typedef를 이용한 함수포인터
    printf("12. Function Pointer with typedef:\n");
    typedef int (*MathFunc)(int, int);
    
    MathFunc math1 = Add;
    MathFunc math2 = Multiply;
    
    printf("  Add(5, 3) = %d\n", math1(5, 3));
    printf("  Multiply(5, 3) = %d\n", math2(5, 3));
    printf("\n");

    // 예시 13: 포인터와 함수 비교
    printf("13. Function Pointer Comparison:\n");
    int (*ptr1)(int, int) = Add;
    int (*ptr2)(int, int) = Add;
    int (*ptr3)(int, int) = Subtract;
    
    printf("  ptr1 == ptr2: %s\n", ptr1 == ptr2 ? "true" : "false");
    printf("  ptr1 == ptr3: %s\n", ptr1 == ptr3 ? "true" : "false");
    printf("\n");

    // 예시 14: 함수포인터 요약
    printf("14. Function Pointer Summary:\n");
    printf("  선언: int (*ptr)(int, int);\n");
    printf("  할당: ptr = FunctionName;\n");
    printf("  호출: result = ptr(arg1, arg2);\n");
    printf("  배열: int (*arr[])(int, int) = {func1, func2};\n");
    printf("  typedef: typedef int (*FuncPtr)(int, int);\n");
    printf("  콜백: void Func(void (*callback)());\n");
    printf("\n");

    // 예시 15: 실용 예제
    printf("15. Practical Example - Calculator:\n");
    int x = 100, y = 25;
    ExecuteFunctionWithResult(x, y, Add, "Add");
    ExecuteFunctionWithResult(x, y, Subtract, "Subtract");
    ExecuteFunctionWithResult(x, y, Multiply, "Multiply");
    ExecuteFunctionWithResult(x, y, Divide, "Divide");

    
 
}   