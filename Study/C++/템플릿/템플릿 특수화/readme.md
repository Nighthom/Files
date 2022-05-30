# 템플릿 특수화
## 함수 템플릿 특수화
>> 일반화 템플릿이라면 다음과 같은 문법이죠.  
```C++
template<typename T>
T add(T tParam1, T tParam2) {
  return tParam1 + tParam2;
}
```
>> 특수화 템플릿은 여기서 포인터나 참조로 문자열을 전달하거나,  
>> 뭐.. 다른 어떠한 것을 전달하면 예외적인 처리를 해주어야 하잖아요.  
>> 그럴 때 쓰는 겁니다.  
```C++
template<>                // typename을 별도로 기술하지 않는다.  
char* add(char* szParam1, char* szParam2) {
  ...문자열을 append 하는 함수.
  대충 szParam1과 szParam2의 사이즈를 구해서  
  배열을 동적할당하고,  
  null문자가 있는 지점부터 문자열을 붙여넣는  
  연산을 수행한다.  
}
```
>> 이러면 char\*형 문자열 데이터에 한해서  
>> 아래의 특수화된 템플릿이 적용됩니다.  
>> typename을 별도로 기술하지 않음으로써 특수화 템플릿임을  
>> 나타내 줍니다.  굳이 적어도 상관 없긴 하지만,  
>> 어차피 함수 본문 쓸떄는 type을 전부 기술할 것이라서.. 의미가 없죠.  

## 클래스 템플릿 특수화
>> 문법은 동일합니다!  
>> 다만, 특수화된 클래스 템플릿에 타입을 명시해야 합니다.  
```C++
template<typename T>
class A{
public:
  A(){}
  ~A(){}
private:
  T m_tData = 10;
}
template<>
class A<char*> {    // A를 정의하는 부분에 타입을 명시해야 합니다!  
public:
  A()
  : m_tData = "Hello World!"
  {}
  ~A(){}
private:
  char* m_tData;
}
```
>> 사용법도 동일한데, 문자열을 만나면 조금 더  
>> 특수하게 동작하겠죠.  
