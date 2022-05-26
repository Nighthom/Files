# 접근 제어 지시자

## public
>> public은 그 어느 위치에서나 객체의 Data에 접근할 수 있게 해주는  
>> 지시자입니다.  struct, union 객체가 기본적으로 이 속성을 갖습니다.  

```C++
class Peorson {
// private: 생략 가능. 기본이 private이기 때문이다.
  int nAge;
  char* name;
  
protected: 
  char* address;
  
public:
  void print() {
    std::cout << nAge, name << endl;
  }
}
```
>> 이런 식으로 객체를 만들고,  nAge, name에 대한 접근을 시도하면 차단됩니다.    
>> 하지만 print()함수에 대해서는 접근할 수 있습니다.    
>> 이는 class의 기본 접근 제어 형식이 private이라 그렇습니다.  

## private
>> private는 그 객체 내부에 있는 멤버를 제외하고서는    
>> 그 아무에게도 접근 권한을 주지 않는 제어 지시자입니다.    
>> class가 기본적으로 이 속성을 지니고 있습니다.    

```C++
int main() {
  Person Yoon = new Person;
  Yoon.nAge = 10;             // 빌드 에러!
  Yoon.name = "윤";           // 빌드 에러!
      
  return 0;
}
```
>> 이런 식으로, 그 어느 위치에서 접근해도 차단합니다.  

## protected
>> 상속된 하위 클래스에서 부모 클래스로의 접근이 필요할 때  
>> 사용하는 접근 제어 지시자입니다.
>> protected 접근 제어 지시자로 선언된 멤버들은  
>> 부모 클래스 자기 자신 / Friend Class로 선언된 클래스 /  
>> 자신을 public 혹은 protect로 상속한 클래스 외에는  
>> 사용이 불가능합니다. 

```C++
class Man : public Person {
  void Print() {
    std::cout << name << endl // 빌드 에러!(private)
    std::cout << address << endl // 빌드 성공.(protected)
  }
}
```

## friend 지시자
>> friend 키워드는 접근 제어 지시자를 무시할 수 있는  
>> **예외** 로써 동작합니다.  

>> 사용법은 클래스 내부 어디에서나 friend를 맺을 클래스를  
```C++
friend class Name;
```
>> 이런식으로 명시해 주는 겁니다.
>> 이 키워드를 이용해서 클래스끼리 friend를 맺으면,  
>> 접근 지시 제어자를 무시하고 Public처럼 접근할 수 있습니다.  
