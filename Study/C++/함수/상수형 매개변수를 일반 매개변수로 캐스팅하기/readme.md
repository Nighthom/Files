# 상수형 매개변수를 일반 매개변수로 캐스팅하기

```C++
void Testfunc(const int &nParam) {
  int &newnParam = const_cast<int&>(nParam);
}
```
>> const_cast 예약어는 상수를 일반형 변수로 캐스팅할 수 있는   
>> 기능입니다.  간혹 필요한 경우가 있어서 쓰일 수도 있겠죠.  
