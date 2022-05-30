# 상속과 형 변환
```C++
const_cast<type>(피연산자)          // const 제거하기(수정 불가능 l-value에서 l-value로)
static_cast<type>(피연산자)         // compile time up/down 캐스팅
dynamic_cast<type>(피연산자)        // runtime up/down 캐스팅 ( 쓰지 않을 것! )
reinterpret_cast<type>(피연산자)    // 강제 형변환(C언어 스타일) 사용 권장하지 않음
```
>> const_cast는 주석과 똑같이 const 선언된 변수를   
>> l-value로 바꿔줍니다.  
>> dynamic_cast는 예를들어서  
```C++
Class object {
};
Class A:public object {
};
Class B:public object {
};
Class C:public object {
};
...
int main() {
  object &refer = new A;
  A &B = dynamic_cast<&A>(refer);           // downcast!
  return 0;
}
```
>> 이런 상황에서 다운캐스팅/업캐스팅을 지원합니다.  
>> 하지만, **런타임**에 해결하는 연산이므로 효율적이지 못합니다.  
>> object의 하위 클래스를 **전부 다** 검사해보고, 맞을 때 캐스팅해주는   
>> 건데, (없다면 nulptr을 넣어줌) 당연히 효율적이지 못한 캐스팅이겠죠.  

>> static_cast는 위와 같은 캐스팅을 해주는데,  compile time 연산입니다.  
>> object의 하위 클래스인지 아닌지를 **컴파일 타임**에 검사해주기 때문에,  
>> 당연히 **런타임 성능**에는 영향을 끼치지 않겠네요.  
>> 애초에 **컴파일러**가 에러를 내줍니다. 오히려 좋죠?   
>> 즉, dynamic_cast보다 static_cast가 좋습니다.  

>> reinterpret_cast은 C언어의 캐스팅이랑 거의 똑같습니다.  
>> 그냥 뭐.. 앞에 괄호쓰고 C언어 스타일로 캐스팅하는거랑  
>> 다를 바 없는거라.. static_cast처럼 안전한 타입 캐스팅을  
>> 지원하는데 굳이? 쓸 이유는 없죠.  
>> 쓰고 싶다면 저렇게 길게 안쓰고 그냥 C언어처럼   
>> 인스턴스 앞에 
```C++
(B)a;
```
>> 이런식으로 캐스팅하면 알아서 캐스팅됩니다.  
