# Hello World 설명

[소스코드](https://github.com/Nighthom/Files/blob/main/Study/C/src/Hello%20World.c)   

Hello World는 기본적으로 모든 언어의 입문서에 있습니다.     

이 소스코드 내부에 있는 것들을 분석해보겠습니다.   

```C
#include <stdio.h>
```

위 코드는 전처리(preprocess) 문입니다. 전처리문 코드는 컴파일이    
진행되기 이전에 컴파일러에 의해서 다른 내용으로 대체됩니다.

stdio.h는 C언어 내장 라이브러리 헤더파일입니다. 기본적인   
입력 / 출력에 대한 함수들을 내장하고 있습니다.

> 헤더파일이라는건, 많은 함수 및 매크로 상수들의 선언을 모아놓은 파일이라고 볼 수 있습니다.

\#include 는 바로 이 헤더파일을 소스코드의 위쪽에 붙여주는 역할을 해요.

여기서 등장은 안했지만, 내부 라이브러리에 속하는 헤더파일은 <헤더파일.h> 이런식으로 나타내고,

외부 라이브러리에 해당하는 함수는 동일한 경로에 있다면 "헤더파일.h"    
그렇지 않다면 현재 디렉터리 위치로부터 "상대경로\헤더파일.h" 및 "절대경로\헤더파일.h"   
이런 꼴로 표기해서 나타냅니다.   

다음으로 넘어가서,  
```C
int main() {
```
이부분은 함수를 선언하는 부분입니다.  
main함수는 C언어 프로그램이 실행될 때 주축으로 돌아가는 함수로, 파일의  
실행시부터 실행되어 종료되면서 파일의 종료를 알립니다.  
main은 함수의 이름, () 안에는 함수의 parameter을 전달하며,  
main 앞의 int는 자료형으로, integer의 약어입니다.  

4byte 정수를 의미합니다.(표현범위 : -2^16 ~ 2^16-1) 

```c
printf("Hello World\n");
```
이 구문은 stdio.h 헤더파일에 선언된 printf 함수를 호출하는 모습입니다.  
printf의 parameter으로 "Hello World\n"라는 문자열을 전달하고 있습니다.  

32bit asm코드로 위 함수를 호출한다면,
``` asm
mov eax, "Hello World\n"  
push eax  
call printf  
```
와 같은 형태로 호출할 것입니다.

다음 코드는 함수의 마무리를 짓는 return 문입니다.

```
return 0;
}
```
 
return은 일반적으로 함수의 반환을 의미합니다.   
함수 실행 중 return 문을 만나면, 
(x86) eax / (x64) rax
에 반환값을 저장하고, 함수를 종료합니다.

[목차로 돌아가기](https://github.com/Nighthom/Files/tree/main/Study/C)  
[다음 문서](https://github.com/Nighthom/Files/tree/main/Study/C/lesson/%EA%B8%B0%EB%B3%B8%EC%9D%B4%EB%A1%A0)
