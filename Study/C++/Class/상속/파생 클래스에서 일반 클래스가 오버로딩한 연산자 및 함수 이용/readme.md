# 파생 클래스에서 일반 클래스가 오버로딩한 연산자 및 함수 이용

```C++
class A {
int num1=10, num2=20;
public:
  A operator+(A &rhs) {
    num1 += rhs.num1;
    num2 += rhs.num2;
  } 
};
class B {
public:
  using A::operator+;
}
```
>> 이렇게 알려주면 +연산자를 파생 클래스에서 굳이 정의 안 해도  
>> 일반 클래스 +연산자를 가져오겠죠.  
