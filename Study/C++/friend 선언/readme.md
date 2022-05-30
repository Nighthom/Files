# friend 선언

>> friend 선언은 함수나 class에 쓸 수 있습니다.  
>> class에 friend 키워드를 이용한다면,  
```C++
class A {
// private(기본)
  int a, b, c;
protected:
  int d;
}
class B : public A {
  friend A;
}
```
>> 이러면 클래스 B는 private 영역에 선언된 a, b, c  
>> 그리고 protected 영역에 선언된 d까지  
>> 모두 접근 가능합니다.  
>> "기존의 접근 제어 체계"를 무시한 접근이 가능한  
>> 것이지요.  
