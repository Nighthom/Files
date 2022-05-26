# 클래스 멤버함수 선언과 정의

>> 클래스의 멤버로 오는 함수는 선언과 정의를 분리할 수 있습니다.  

```C++
class Student {
  char* szName = "Yoon";
  int nGrade = 3;
  int nAge = 24;
  
  Student() { }
  
  void print();
}
void Student::print() {
    std::cout << szName << nGrade << nAge << endl;
}
```
>> 해당 멤버 함수는 Student 안에 선언되었고,    
>> 전역 스코프에 정의되었습니다.   
>> Namespace처럼 :: 연산자를 이용해서 어느 클래스에 속한    
>> 함수인지 명시해 줄 수 있습니다.   
