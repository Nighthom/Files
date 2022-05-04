## stdin버퍼 비우기

```C
1   #include <stdio.h>
2 
3   int main() {
4     int a;
5     char b;
6     scanf("%d" &a);
7     printf("%d\n", a);
8     scanf("%c", &b);
9     pinrtf("%c\n", b);
10    return 0;
11  }
```
>> 위 코드에서 프로그래머가   
>> input으로 10, B을 주었다면  
>> 기대하는 output은   
>> 10    
>> B  
>> 일 것입니다.  
>> 하지만 10을 입력받자마자 바로 프로그램이 종료될 것입니다.  
>> 그 이유는 stdin버퍼에 개행문자가 남아있어서  
>> 8번 scanf에서 바로 개행문자를 가져오기 떄문입니다.  
>> 이럴 경우, stdin 버퍼를 비워주어야 합니다.  
>>  
>> 비표준 함수로 fflush(stdin); 이 있긴 하지만  
>> 이는 비표준입니다. fflush는 표준 출력 버퍼만 지워주는   
>> 함수이기 때문에 그렇습니다.  
>>   
```C
1   void clear_stdin() {
2     char ch;
3     while((ch = getchar()) != EOF && ch != '\n') {};
4   }
```
>> 위와 같은 clear_stdin 함수로 stdin 입력버퍼를
>> EOF 혹은 \\n을 만날 때까지 비우면 됩니다.
