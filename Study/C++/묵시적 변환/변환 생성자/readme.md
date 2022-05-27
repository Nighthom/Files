# 변환 생성자

```C++
CTest(int nParam) {                     // 변환 생성자
  cout << "CTest(int)" << endl;
  m_pnData = new int(nParam);
}
```

>> 위 처럼 매개변수가 하나인 생성자를 **변환 생성자** 라고 합니다.  
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
    CTest(int nParam) {                     // 변환 생성자
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

    int getData() {
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

void TestFunc(CTest param) {
    cout << param.getData() << endl;
}
int main()
{
    CTest a(10);
    TestFunc(a);
    return 0;
}
```
>> 위와 같은 짧은 코드의 결과는 어떻게 될까요?  
>> 59번 행에서 복사 생성자를 통해 인스턴스를 생성했고,  
>> 변환 생성자가 호출됩니다.  
>> TestFunc(a); 를 통해 a를 파라미터로 전달했습니다.  
>> 파라미터 전달 시에 인자는 복사되겠죠?  
>> 복사 생성자가 호출됩니다.  
>> 그리고 함수의 결과로 10을 호출하고,  
>> 스코프 범위 밖으로 나갈 때 param 인스턴스가 소멸하므로  
>> 소멸자가 호출됩니다.  
>> 이후 return 문을 만나 함수가 끝나고,  
>> a 인스턴스의 소멸자가 호출됩니다.  
```C++
CTest(int)
CTest(cosnt &CTest)
10
~CTest()
~CTest()
```
>> 이런 결과가 나옵니다.  
>> 그럼 다음과 같은 코드는 결과가 어떻게 나올까요?
```C++
int main()
{
    TestFunc(10);
    return 0;
}
```
>> 빌드 오류가 나오지 않을까요? CTest형을 인자로 전달한 게 아니니까요.  
>> 근데, 빌드 오류가 나오지 않습니다.  
```C++
CTest(int)
10
~CTest()
```
>> 보면, 저 함수가 호출될 떄, 
>> 인자인 CTest param = 10 꼴로 바꿔서  
>> 인자로 전달될꺼란 말이죠?
>> 근데 보시면, 연산자 오버로딩으로 deep copy가 정의되어 있단 것이죠.  
>> type이 안맞죠? 그래서 컴파일러가 묵시적으로 형 변환을 시켜버립니다.  
>> CTest param = CTest(10) 꼴로 말이죠.  
>> 그래서 **임시 객체 CTest(10)** 이 변환 생성자로 생성되고,    
>> 전달되어서 에러가 나지 않는겁니다.    
>> C++ 컴파일러가 변환 생성자가 있다는것을 인지하고,    
>> int형을 CTest형으로 변환할 수 있다는 판단하에 형 변환을 실행하는데,     
>> 임시 객체를 생성해버리고 **예상치 못한 오동작**이 나버린 것이죠. 

>> 그래서 변환 생성자를 만들 때는 반드시  
>> **explicit** 키워드로 선언해야 합니다.  
```C++
explicit CTest(int nParam) {                     // 변환 생성자
    cout << "CTest(int)" << endl;
    m_pnData = new int(nParam);
}
```
>> 이런 식으로 선언하면, 생성자 호출 시에 **반드시**  
>> 생성자를 호출하는 원문이 있어야 동작합니다.  
>> 즉, 컴파일러가 묵시적으로 변환을 하지 않아요.  
>> 이러면 컴파일러가 빌드 에러로 잡아내겠죠.  
