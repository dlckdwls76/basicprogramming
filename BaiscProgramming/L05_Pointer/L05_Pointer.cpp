/*
#include <cstdio>

int main ()
{
    int Num = 0;//논리 주소를 하나(크기가 4byte) 할당 받는다.
    int* Ptr = &Num; //ptr이 num의 주소를 가리키니까 ptr을 통해서 값을 바꿀 수 있다.
    //int값의 주소를 가리킬 수 있음 0x 1000이들어감 주소를 담을 수 있는 변수
    printf("Num 변수의 메모리 크기 = %d\n",sizeof(Num));
    printf("ptr 변수의 메모리 크기 = %d\n",sizeof(*Ptr));
    
    *Ptr = 1234;
    printf("Num = %d\n",Num);
    
}
*/
/*
#include <iostream>

int main() {
    int number { 42 };         // 일반 변수 생성 (값 42 저장)
    int* pointer { &number };  // 포인터 변수 생성 (number의 주소를 저장)

    std::cout << "1. number의 값: " << number << '\n';
    std::cout << "2. number의 메모리 주소: " << &number << '\n';
    
    std::cout << "3. pointer가 보관중인 값(주소): " << pointer << '\n';
    std::cout << "4. pointer가 가리키는 곳의 실제 값: " << *pointer << '\n';

    // 포인터를 이용해 원본 변수의 값을 원격으로 변경
    *pointer = 100;
    std::cout << "5. 포인터로 변경한 후 number의 값: " << number << '\n';

    return 0;
    
    
}
*/

/*
#include <iostream>

int main() {
    char letter { 'A' };       // 진짜 문자
    char* p1 { &letter };      // letter의 주소
    char** p2 { &p1 };         // p1의 주소
    char*** p3 { &p2 };        // p2의 주소
  
    
    std::cout << p3 << '\n';
    std::cout << *p3 << '\n';
    std::cout << **p3 << '\n';
  
    
    return 0;
}*/

#include<cstdio>
#include"MyHeader.h"

int main ()
{
    int Sum = plus(100, 200); 
    int A = sizeof(&Sum);
    printf("두수의 합은 : %d",Sum);
    return 0;
}