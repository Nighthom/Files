# 매크로 함수

>> 전처리기로 이루어진 함수를 의미합니다.    

```C
#define ADD(a, b) (a + b)
```  
>> 매크로 함수는 위와 같이 작성했을 때,    
>> 좌측의 문자열을 정확하게 똑같게,   
>> 1대1로 치환해주는 전처리기입니다.  

>> 최신 컴파일러에서는 inline 함수로 대체되는 분위기인데,    
>> inline 함수 관련 정보는 C++ 문서에 있습니다.  
>> [인라인 함수](https://github.com/Nighthom/Files/tree/main/Study/C%2B%2B/%ED%95%A8%EC%88%98/%EC%9D%B8%EB%9D%BC%EC%9D%B8%20%ED%95%A8%EC%88%98)  

# 문자열을 붙여주는 ## 연산자
```C
#define PASTER(a, b) a##b
PASTER(a, b) -> ab로 치환합니다.
```

# 문자열로 치환하는 # 연산자
```C
#define STRING(a) #a
```
>> STRING(string) -> "string"으로 치환됩니다.
