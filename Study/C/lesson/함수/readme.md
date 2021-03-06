# 함수

>> 함수는 다음과 같이 선언합니다.  (함수 prototype(원형) 선언)
```C
ret_type func_name(arguments);        
```
>> 함수의 이름은 함수의 포인터를 담고있으며,    
>> 함수 호출 연산 (함수이름 뒤에 괄호와  
>> 호출인자들을 넣음)을 통해서 함수를 호출할   
>> 수 있습니다.  
>> 맨 앞에 있는 ret_type은 반환 타입으로,   
>> 함수가 반환될 때 받는 타입입니다.  
>> aruguments는 함수의 인자들로,  
>> 자료형과 바인드될 이름으로 구성됩니다.  
>> 인자들은 스택 및 레지스터로 전달됩니다.  

# 함수의 정의
>> 함수의 정의 방법은 다음과 같습니다.
```C
int add(int a, int b) {
  return a + b;
}
```
>> 간단한 변수 두 개를 더하는 함수입니다.   
>> 스코프 안에 묶어서 함수가 수행할 코드를  
>> 넣어줄 수 있어요.  

# 함수 프로토타입
>> 함수의 선언과 정의는 분리될 수 있습니다.  
>> 선언 시에는 함수 원형을 선언한다고 봐도 되겠죠?  
>> 선언 시에는 각 인자들의 자료형을 생략할 수 있습니다.    

# Caller, Callee.
>> 어떤 함수 a 안에서 다른 함수 b를 호출한다면,   
>> a는 b의 Caller, b는 Callee가 됩니다.  

# 함수 콜 스택
>> 함수는 본인만의 고유한 스택을 갖습니다.  
>> 해당 함수의 영역에는 본인의 지역변수들을 갖지요.    
>> 그리고 다른 함수를 호출할 때,   
>> Caller의 스택 위에 Callee의 스택이 쌓입니다.    
>> 함수가 반환된다면 이 함수에 할당된 스택은   
>> 반환됩니다.  
>> 이 구조를 콜 스택이라고 합니다.  
>> 이러한 콜 스택을 구성하는 기법이 바로   
>> 스택 프레임(Stack Frame) 기법입니다.    
>> 이는 세부 이론에서 풀도록 하겠습니다.  

# [Call by Value, Call by Reference](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/Pointer/%ED%8F%AC%EC%9D%B8%ED%84%B0%20%ED%99%9C%EC%9A%A9/Call%20by%20Reference.md)  
>> Call by Value는 함수 호출시에 레지스터나 스택으로 값을 복사한 뒤  
>> 인자로 전달한다는 뜻입니다. 즉, 전달되는 인자는  
>> 원본 변수가 아닙니다.  
>> 원본 변수를 전달하고 싶다면, 위 링크 문서를 참조하십시오.  

[함수 설계 원칙](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%95%A8%EC%88%98/%ED%95%A8%EC%88%98%EC%84%A4%EA%B3%84%EC%9B%90%EC%B9%99.md)    
[함수 세부 이론](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%ED%95%A8%EC%88%98/%ED%95%A8%EC%88%98%20%EC%84%B8%EB%B6%80%20%EC%9D%B4%EB%A1%A0.md)    
