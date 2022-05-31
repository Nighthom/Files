# try-catch

>> try-catch문은 예외를 처리하기 위한 루틴입니다.  
>> try문 내부에서 예외가 throw되면, catch문으로 이동합니다.  
```C++
try {
  if(error1)  
    throw errorcode1;
  if(error2)
    throw errorcode2;
  if(error3)
    throw errorcode3;
}
catch(int nExpr) {
  예외처리 본문...
}
```
>> 보통 이런식으로 구성합니다.  
>> 구문이 함수 내부에 존재하던, 그 어디에 존재하던지간에   
>> 예외처리 루틴으로 바로 점프할 수 있습니다.  
>> 매우 유용하겠죠?  
>> 예외처리 루틴은 하지만 goto문이나 if문에 비해서  
>> 성능상 손해보는 경우가 많으니, 설계상 필요한지를   
>> 꼼꼼히 따져보아야 합니다.  

>> catch받는 구문의 자료형을 다중화해서  
>> 오버로딩할 수도 있습니다.  
>> 이러면 예외처리로 throw받는게 뭐냐에 따라서  
>> 예외 처리 루틴을 다중화할 수도 있겠죠.  

## 예외 클래스
>> 예외를 Class로 throw할 수도 있습니다.  
>> 또한, Class로 예외를 받을 수도 있죠.  
```C++
catch(CMyError Expr) { 
  예외처리
}
```

## new연산자가 동적할당 실패했을 경우.
>> 만약 new연산자로 주소를 할당받는데 실패했을 경우  
>> 예외처리 하려면,  
```C++
try {
  char* a = new char[20000000];
}
catch(bad_alloc &expr) {
  cout << expr.what() << endl;
  cout << "ERROR : Memory Allocation Failed." << endl;
}
```
>> 이런식으로 bad_alloc type을 전달하면 간단하게 catch할 수 있습니다.  
