/// 한줄짜리 주석 
/* 한줄
두줄
 */
// <main 함수란?>
// 
// 모든 C/C++로 개발된 프로그램 (exe)는 한 개 이상의 함수로 구성.
// 왜 ?프로그램 실행시 진입점(Entry Point)을 알아야 하기 때문에 
// 이 중 반드시 있어야하고, 단 하나만 존재하는 함수가 이 main함수다. 
// 당연히 이 main함수가 없으면 컴파일 자체가 안됨.

#include <cstdio>

/*#include <cstdio>//전처리기

int main()
{
    printf("Hello World\n");
    printf("Hello \tWorld\n");
}

*/
int main()
{
    //정수형 변수 선언
    int Num1 = 0;
    int Num2 = 0;
    scanf_s("%d", &Num1);
    scanf_s("%d", &Num2);
    printf("Num1: %d\n",Num1);
    printf("Num2: %d\n",Num2);
    printf("power %d + energy : %d = %d\n",Num1, Num2, Num1+Num2);
    printf("power %d - energy : %d = %d\n",Num1, Num2, Num1-Num2);
    printf("power %d * energy : %d = %d\n",Num1, Num2, Num1*Num2);
    printf("power %d / energy : %d = %d\n",Num1, Num2, Num1/Num2);
    printf("power %d %%  energy : %d = %d\n",Num1, Num2, Num1%Num2);
} 