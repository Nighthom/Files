# 참조에 의한 호출

>> 일반적으로 C언어에서는 Call by Value(값에 의한 호출)를    
>> 지원합니다.  
```C
int add(int num1, num2) {
  num1 += num2;
  return num1
}
```
>> 위와 같은 함수를  
```C
add(a, b);
```
>> 처럼 호출했다면 리턴값은 당연히  
>> a+b를 받을 것입니다.  
>> 하지만 a에 값을 합으로 받았음에도 불구하고  
>> a 값에는 그 어떠한 변화도 없을것입니다.  
>> 그 이유는 a, b를 스택이나 레지스터에 복사해서   
>> 함수의 인자로 전달하기 때문입니다.  

>> 32비트 어셈코드로 변경해서 볼까요?  
```
mov ecx, b
push ecx
mov eax, a
push eax
call add
sub esp, 8
...
add 본문

push ebp
mov ebp, esp
mov eax, [ebp - 4]
add eax, [ebp - 8]
leave
ret
```

>> 이렇게 되겠죠? a, b값을 eax, ecx에 복사하고  
>> 그 값을 스택에 푸시해서 함수로 전달하는 방식임을 알 수 있어요.  
>> 64비트 운영체제에서는 레지스터를 활용해 전달하겠지만, 본질은  
>> 크게 다르지 않습니다.  
>> 이렇게 함수에 인자를 전달할 때 원본 변수가 아닌  
>> 값을 복사해서 전달하는 방식을 Call-by-Value 라고 합니다.  


>> 그렇다면 인자를 전달할 때 인자의 값을 함수 내부적으로  
>> 변경할 수 있도록 지원하려면 어떻게 해야 할까요?  
>> 포인터를 이용해서 인자를 전달하면 됩니다.  
>> 포인터는 원본의 주소를 담고 있으니, 이 주소를 이용해서  
>> 인자의 원본에 강제로 값을 씌울 수 있습니다.  

```C
int add(&a, &b) {
  *a += *b;
  return *a
}
```
>> 이런식으로 구현하면 인자로 전달한 a에도  
>> a+b의 값을 넣을 수 있습니다.  
