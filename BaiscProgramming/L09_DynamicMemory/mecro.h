#define MAX_COUNT  5 //매크로 상수   
#define SAFE_DELETE(nanana) if (nanana) { delete nanana; nanana = nullptr; }
#define SAFE_DELETE_ARRAY(a) if (a) { delete[] a; a = nullptr; }
#define SAFE_DELETE_PRINT(KK) \
{SAFE_DELETE_ARRAY(KK); \}
    {printf("메모리 해제 완료"); }    
    