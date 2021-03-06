# Class

>> 절차지향에 없던 새로운 자료형입니다.  
>> Class는 객체지향 언어의 중추라고 할 수 있습니다.   
>> Class는 C언어의 구조체를 확장한 것으로써,   
>> C언어의 구조체는 멤버로 변수나 포인터 등이 왔다면,   
>> Class에는 해당 Class의 Property(속성) 으로    
>> 또다른 객체(변수, Class)가 올 수도 있고,   
>> 어떠한 **함수**도 올 수 있습니다.   
>> 이러한 Class의 Property로 전달된 함수를  
>> **Method**라고도 합니다.  

>> 그리고, C언어의 구조체와 구별되는 또다른 차이점이 하나가 있습니다.  
>> 각 Class는 **this** 포인터라는 녀석을 하나 갖는데,  
>> 이는 **객체 자신을 가리키는 포인터** 입니다.  

>> **this** 포인터를 이용해서 너무나도 간단하게  
>> 메서드에서 객체 자신에게 접근할 수 있기 떄문에,  
>> 메서드를 이용할 때 객체만 잘 만들어 준다면,  
>> **매개변수**로 객체 자신을 전달할 필요가 없습니다.  

>> 이러한 중대한 차이점때문에 절차지향 언어에서는  
>> 어떠한 함수의 인자에 대해서 사용자가 인지하고,  
>> 어떤식으로 동작할지 정의해주는 행위를 해야하지만,  
>> 객체지향 프로그래밍을 할 때는 이러한 동작들의 Interface만 가지고  
>> 어떠한 결과가 나올지 사용자가 알기만 하면,   
>> 이러한 동작들을 구현하기가 너무 쉽죠.  

# Instance
>> Instance는 어떠한 Class를 갖는 객체입니다.   
>> 뭐.. C언어에서 객체와 동일한 개념으로 받아들여도 됩니다만,  
>> 구조체와 같은 C언어의 객체와의 차이점은,  
>> Class를 이용한다는 것이겠죠.  
>> Instance는 new 연산자를 이용해서 생성합니다.  
```C++
new Type;
```
>> 이런 문법이죠. C언어에서 구조체 포인터에  
>> Data를 할당해 보신 분들이라면, 상당히 유사한  
>> 구조라는 것을 아실거에요.  
>> 하지만, 할당하는 대상이 Class인거죠.  
>> 그리고 delete 연산으로 해당 메모리에 할당된  
>> 인스턴스를 해제시켜 줍니다.  
