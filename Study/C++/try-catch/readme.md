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
