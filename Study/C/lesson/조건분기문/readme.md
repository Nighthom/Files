# 조건분기문

조건분기문은 특정 조건을 만족하면 분기하는 것을   
의미합니다.

## if 분기문 
```C
if(조건) {
  ...
  본문;
  ...
}
else {
  ...
  본문;
  ...
}
```
>> if문 괄호 속 조건이 참이라면 if문 분기를 실행, 
>> 거짓이라면 else문 분기를 실행한다.

활용으로,
```C
if(조건) {
  ...
  본문;
  ...
}
else if(조건2) {
  ...
  본문;
  ...
} else {
  ...
  본문;
  ...
}
```
>> 이런식으로 조건을 여러번 걸 수 있습니다.
## Switch 분기문
```C
switch(식) {
case val1:
   본문1;
   break;
case val2:
   본문2;
   break;
default:
  기본_본문;
}
```
>> 식의 결과와 일치하는 case를 찾아서 그 분기문을 실행시키고,
>> 일치하는 case가 없으면 default를 실행한다.

case문의 경우 동등연산자를 사용해서 비교하기 때문에,   
오차가 존재하는 실수형 자료는 조건으로 사용할 수 없습니다.  

switch 문은 코드를 더 간결하게 보이게 만들어주는 효과가 있습니다.

만약 if문을 쓸 때 동등연산자를 써야 한다면 switch문이 더 나은  
선택일 수 있습니다.


### [조건문 최적화](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%EC%A1%B0%EA%B1%B4%EB%B6%84%EA%B8%B0%EB%AC%B8/%EC%A1%B0%EA%B1%B4%EB%AC%B8%EC%B5%9C%EC%A0%81%ED%99%94.md)
