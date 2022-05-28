# 상속의 문법 

```C++
class A {
  class A implimentation....
}
class B : public A {
  class B implementation...
}
```
>> 다음과 같은 식으로 작성되었을 떄,  
>> 클래스 B는 클래스 A를 상속(Inheritance)했다고 합니다.  

>> 상속할 때 public 외의 접근 지시자를 정해줄 수도 있는데,  
>> 대부분의 상속은 public으로 정의합니다.  
>> A는 B의 부모 클래스 / 기본 클래스, B는 A의 자식 / 파생 클래스입니다.  
>> B의 생성자가 호출되면 A의 생성자도 같이 호출됩니다. (즉, B는 A+B 꼴이 됩니다.)  
>> B는 A의 멤버들에 접근 가능합니다. private 멤버는 접근할 수 없습니다.  
>> B의 인스턴스 b가 존재한다면, 사용자 코드에서 b 인스턴스는  
>> class A의 메서드에 접근 가능합니다. private 메서드는 접근 불가능합니다.  
>> 기본적으로 A는 B보다 선행되어서 작성되는 코드고,  
>> B는 A보다 나중에 작성되는 코드입니다. 즉, A 클래스는  
>> B 클래스를 위해서 Interface를 잘 정의해 줄 필요가 있어요.  


>> B클래스에서 A 클래스의 메서드인 getData()에 접근한다고 칩시다.  
>> 그러면 
```C++
A::getData();
getData();
```
>> 이런식으로 접근할 수 있습니다.  


## Override
>> 파생 클래스 B에서는 A의 메서드 setData를 Override(재정의) 할 수 있습니다.  
>> 메서드 재정의를 할 경우, B 안에서는 A의 메서드라고 명시하지 않는 이상  
>> B의 메서드 setData를 호출하게 됩니다.
```C++
class A {
  int nData;
public:
  void setData(int nParam) {
    nData = nParam;
  }
}

class B : public A {
public:
  void setData(int nParam) {        // Override
    if(nParam > 10) {
      // setData(10) 과 같이 호출하면 오버라이드된 setData를 무한히 재귀호출함.  주의!
      A::setData(10);
      reuturn;
    }
    if(nParam < 0) {
      A::setData(0)
      return;
    }
}
```
>> 위 상황은 B를 제작한 후기 제작자가 A 클래스의 setData에 없는    
>> 새로운 기능을 삽입한 모습입니다. 기존 코드에는 0 ~ 10까지의 범주에 맞는     
>> 값을 보정하는 기능이 없었지만, 이러한 기능이 필요하다고 느껴    
>> 하위 클래스를 정의해서 오버라이드해 준 것입니다.

## 어떠한 참조의 실 형식과 접근형식
```C++ 
CTestEx a;
CTest &b = a;         // a를 가리키는 참조 b. 문법 에러 없음.
```
>> a의 참조 b가 CTest 클래스를 접근 형식으로 받았습니다.  
>> 만약 다음과 같은 상황이면 어떨까요?  
```C++
b.setData(13);
```
>> 이러면 CTestEx의 인스턴스 a는 CTestEx가 오버라이드한 setData()를 호출하지 않습니다.    
>> 이유는, CTest형식으로 접근했기 떄문이죠.  
>> 따라서, 일반 클래스 CTest의 setData()를 호출하게 됩니다.  
>> 그러면 a.m_nData는 13으로 set되겠네요.  

## 메서드의 접근형식
  1. 일반 메서드 --> 만약 위와 같은 참조가 발생했을 때, **접근 형식**을 따라가게 된다.
  2. 가상(Virtual) 메서드 --> 만약 위와 같은 참조가 발생했을 때, **실제 형식**을 따라가게 된다.
  3. 정적(Static) 메서드
