# 클래스 템플릿 상속

```C++
template<typename T>
class A {
protected:
  T mData;
};
template<typename T> 
class B : public A<T> {
public:
  T getData() const { 
    return mData;
  }
  void setData(T param) {
    mData = param;
  }
};
```
>> 클래스 템플릿을 상속할 때는 파생 클래스에서   
>> 저런 식으로.. 템플릿을 또 만들어 주어야 해요.  
>> A 클래스를 T로 찍어냈는데,  B 클래스도 똑같이  
>> 찍어줘야 정상적으로 상속하고, 정상적으로 값이   
>> 호환될 수 있겠죠.  
