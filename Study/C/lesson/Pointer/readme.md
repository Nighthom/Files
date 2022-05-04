# 포인터 

>> C언어에서 포인터란 아주 중요한 개념입니다.  
>> 포인터 변수를 토대로 많은 것들이 가능하죠.  
>> 우선 포인터에 대한 개념부터 짚고 넘어가자면,   
>> 포인터는 메모리 주소 그 자체를 가리키는 말입니다.  
>> 포인터 변수는 이러한 포인터를 담는 변수고요.  
>> 즉, 포인터와 포인터 변수를 이용하면 메모리에 대한  
>> 직접적인 참조 연산이 가능합니다.  

```C
int* ptr = &변수;
```
>> 포인터는 이런식으로 생성하고, 초기화합니다.  
>> 구문의 의미에 대해서 설명하겠습니다.  
>> int* 는 int형 포인터형입니다.  
>> 메모리 주소의 크기만큼 길이를 갖습니다.(32비트 4바이트, 64비트 8바이트)  
>> 담긴 포인터 주소로부터 int형만큼을  
>> 가리키는 포인터의 크기로 간주하겠다는 뜻이죠.  
>> = 은 대입연산자고요.  
>> &은 해당 R-Value의 포인터를 구하는 연산입니다.  
>> 즉 변수의 포인터를 읽어서 int\*형 포인터 변수에  
>> 넣겠다는 간단한 연산인 것이죠.  
>> 이런 포인터에 담긴 변수는 어떤식으로 참조할까요?  
>> * 연산자로 참조합니다.  
```C
*(ptr) = 6;
```
>> * 연산자는 해당 연산자 오른쪽에 있는 포인터의   
>> 메모리에 접근하는 연산자입니다.  
>> int* 형 포인터이기 때문에 이경우는   
>> 해당 주소로부터 4바이트만큼을 참조하겠군요.  
>> 직접 주소에 접근해서 변수라는 int형 변수의 값을  
>> 6으로 수정했습니다.  
  
>> 포인터에 대한 활용은 워낙 광범위한 범위를 갖기에  
>> 따로 문서로 분류하겠습니다.  

  [포인터의 활용]