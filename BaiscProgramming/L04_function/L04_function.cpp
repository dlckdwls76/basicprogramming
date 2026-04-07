#include <cstdio>

// 문제 1: 반환 타입이 void인데 return C;를 하려고 함
// 해결책: 반환 타입을 int로 변경
int PrintHelloWorld(int A, int B)
{
    int C = A + B;
    
    printf("Sum = %d\n", C);
    return C;    // void에서는 return 값을 가질 수 없음
}

int main()
{
    int A=0;
    int B=0;
    int Ret = 0;
    scanf_s("%d",&A); //& << 변수의 주소를 나타내는 연산자
    scanf_s("%d",&B);
    Ret = PrintHelloWorld(A,B);
        return 0;
}

//숫자입력을 받고, scanf_S
