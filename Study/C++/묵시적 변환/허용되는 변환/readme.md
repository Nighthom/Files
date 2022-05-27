# 허용되는 변환

>> CTest형을 int형으로 묵시적 형 변환 시키는 방법이 있을까요?  
>> 있습니다.  

```C++
#include <iostream>
///////////////////////////////////////////////////////////////
// 개발자 코드
using namespace std;

class CTest {
public:
    CTest() {
        cout << "CTest()" << endl;            // 생성자
        m_pnData = new int(5);
    }
    explicit CTest(int nParam) {                     // 변환 생성자
        cout << "CTest(int)" << endl;
        m_pnData = new int(nParam);
    }
    CTest(const CTest &rhs) {               // 복사 생성자
        //  this->m_pnParam = rhs.m_pnParam;        // shallow copy(pointer)
        this->m_pnData = new int(*rhs.m_pnData);      // deep copy
        cout << "CTest(const CTest&)" << endl;
    }
    ~CTest() {
        cout << "~CTest()" << endl;           // 소멸자
        delete m_pnData;
    }
    CTest& operator=(const CTest & rhs){
        this->m_pnData = new int(*rhs.m_pnData);
        
        return *this;
    }
    operator int(void) {                            // int형으로 묵시적으로 형 변환 가능함을 알려주는 것.
        return *m_pnData;
    }

    int getData() const {
        return *m_pnData;
    }
    void setData(int nParam) {
        *m_pnData = nParam;
    }
private:
    int* m_pnData = nullptr;
};
/////////////////////////////////////////////////////
// 사용자 코드

int main()
{
    CTest a;

    cout << a << endl;
    return 0;
}
```
>> 위 코드는 성공적으로 a.pnData를 출력해냅니다.  
>> 이는 cout이 int형식을 요구해서,  
>> 위 operater int(void) 함수를 호출해서 받아온 거죠.  
