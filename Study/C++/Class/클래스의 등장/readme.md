# 클래스의 등장

>> 클래스는 구조적으로는 C언어의 구조체에  
>> 함수를 더하고, this포인터를 넣고, 상속 기능을 넣고,  
>> Override 기능을 섞은 녀석입니다.  

>> 그렇다면 왜 구조체에 이러한 this포인터나, 멤버 함수나, 상속 기능이  
>> 필요한 걸까요?  
>> 사용자가 이용하는 Interface가 더 간결해 질 수 있기 때문이죠.  
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct _Person {
  int nAge;
  char stName[20];
  
  void (*printPerson)(struct person);
}Person;

void printP(Person* person) {
  printf("이름 : %s, 나이 : %d\n", person->stName, person->nAge);
}
Person* new_Person(void) {
  Pesson* newPerson = (Person*) malloc(sizeof(Person);
  Person->printPerson =  printP;
  return newPerson;
}

int main() {
   Person* Yoon = new_Person();
   
   Person->nAge = 24;
   strcpy(Person->name, "윤");
   
   Yoon.printPerson(&Yoon);
   
   return 0;
}
```
>> 위 코드가 대략적으로 클래스 개념의 this 포인터나,  
>> 메서드 같은 개념을 C언어로 흉내낸 코드입니다.  
>> 상속은 흉내내지 못했지만 말이죠.  

>> Class에서는 객체가 내부에 함수를 지닐 수 있습니다.  
>> 객체가 마치 동작하는것과 같다 하여 메서드(Method)라 합니다.  
>> 이런 Method들은 this 포인터를 기본적으로 제공받는데,  
>> Class 자신의 주소를 **마지막 인자**로 전달받습니다.  
>> 이러한 this 포인터를 통해서 문법적으로
```C++
Yoon.printPerson();
```
>> 처럼 아무런 인자를 전달하지 않고도 객체 자기 자신을  
>> 전달할 수 있는것이죠.  
>> 어셈 코드로 보면 this 포인터를 마지막 인자로 전달합니다.  

>> 또한, 이러한 Class 내부 함수는 Class 외부에서의 접근을  
>> 완전하게 차단합니다. 문법적으로 말이지요.  
