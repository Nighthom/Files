# 문자열 처리


## 문자열의 정의
>> 문자열은 '문자'라는 자료의 배열입니다.  
>> 문자는 컴퓨터에서 일정한 약속에 의해  
>> 어떤 데이터를 1대1로 문자와 매핑시켜 나타내죠.  
>> 그 중, 제일 먼저 등장한 통일 규약이 바로 ASCII입니다.  
>> ASCII는 7bit 사이즈로 로마자 표기를 완벽하게 나타낼 수 있죠.  
>> 여기에 1bit를 더해서 확장 아스키를 만들었는데, 확장 아스키는    
>> 기존 아스키 코드에서 특수문자 같은 것들을 더한 것입니다.  
>> 확장 아스키의 1바이트 크기는 서양 문자를 나타내는데 큰    
>> 문제는 없었지만, 모든 나라의 언어를 나타내기에는 작았습니다.    
>> 따라서 문자를 나타내는 여러 인코딩 방식들이 나타내게 됩니다.  

## 인코딩 종류
>> ASCII, 확장 ASCII, MBCS, Unicode, UTF-8, base64 등등..  
>> 정말 많죠? 하지만 C언어에서 주로 쓰이는    
>> MBCS 계열과 Unicode 계열에 대해서 알아보려고 합니다.  

### MBCS
>> Multi-Bytes Character Sets의 약어입니다.      
>> 영문 한 글자가 1바이트, 한글이나 한자가 2바이트로       
>> 표현되는 양식이죠. 마지막 바이트는 NULL로 끝납니다.    
>> MBCS 기반 문자열 함수들은 string.h 헤더파일에    
>> 선언되어 있습니다. 자료형은 char입니다.    
>> printf, sprintf 등 출력함수를 이용합니다.  

### Unicode
>> 유니코드는 한글, 영어, 한자 등등 어떠한 문자에 구애받지 않고    
>> 2byte 사이즈로 구성되어 있습니다.  문자열의 끝은 NULL    
>> 문자(2byte)로 구성되어 있죠. 기존 ASCII 범주에 있던 문자는    
>> ASCII 하나와 NULL문자 하나로 표시하고,     
>> ASCII 사이즈 이후, 즉 2byte부터는 다른 문자들을 표시합니다.    
>> wchar_t를 자료형으로 사용하고, wchar_t는 2byte입니다.  
>> 그리고, 문자열 상수는 L"String"처럼 앞에 L을 붙여서 나타냅니다.  
>> 출력함수는 wprintf, swprintf 등을 이용합니다.    

### [문자 처리 함수](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%EB%AC%B8%EC%9E%90%EC%97%B4%20%EC%B2%98%EB%A6%AC/%EB%AC%B8%EC%9E%90%20%EC%B2%98%EB%A6%AC%20%ED%95%A8%EC%88%98.md)    


### [문자열 처리 함수](https://github.com/Nighthom/Files/blob/main/Study/C/lesson/%EB%AC%B8%EC%9E%90%EC%97%B4%20%EC%B2%98%EB%A6%AC/%EB%AC%B8%EC%9E%90%EC%97%B4%20%EC%B2%98%EB%A6%AC%20%ED%95%A8%EC%88%98.md)  
