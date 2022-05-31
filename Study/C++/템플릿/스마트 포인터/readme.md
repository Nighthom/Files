# 스마트 포인터

## auto_ptr
>> 동적 할당된 인스턴스를 자동으로 삭제해줍니다.  
>> 가장 오래 전부터 존재했던 스마트 포인터로, 최신 스펙에서는  
>> 사용을 권하지 않습니다.  
>> 배열을 지원하지 않으며(delete시 배열형식으로 해주질 않아요.),   
>> Shallow Copy 문제가 해결되지 않았습니다.   
>> Shallow copy 문제란, ptr1의 내용을 ptr2에 shallow copy 했을떄     
>> 발생하는 일입니다. ptr1이 없어지면 자동으로 ptr1과 ptr2가 가리키던    
>> 포인터의 인스턴스가 사라지게 됩니다.   
>> 그러니까, 이 auto_ptr이라는 친구는 다른 포인터나 참조가  
>> 이 인스턴스를 가리키는지 가리키지 않는지 식별할 방법이 없어요.  
>> 그러면,  참조를 시도하면?    
>> 메모리 참조 오류가 발생하겠네요.  
>> 또한, 메모리를 복사할 때도 문제입니다.  
>> ptrPrev에는 이미 인스턴스가 하나 들어있고,  
>> ptrNew는 빈 스마트 포인터입니다.  
>> ptrNew = ptrPrev;
>> 이런 식으로 복사한다고 쳤을 때,  
>> ptrPrev의 내부 Data는 NULL이 됩니다.  어처구니가 없죠.  
>> ptrNew로 옮겨지긴 합니다만..  
```C++
auto_ptr<int> inst;
auto_ptr<typename> instna;        // typename에 원하는 자료형을 넣습니다.
```
>> 문법적으로는 위와 같아요.    

## shared_ptr
>> auto_ptr과 다르게 shared_ptr은 어떠한  
>> 객체를 가리키는 갯수를 count를 도입함으로써 계수합니다.  
>> count가 0이 되면 그 객체를 삭제하는거죠.    
```C++
shared_ptr<int> inst;
```
>> 문법은 위와 같겠죠?  
>> auto_ptr과 다르게, Shallow Copy로 여러 가지 참조하던 녀석을  
>> 하나 없애버린다 해도, count수만 줄어들 뿐이죠. count가  
>> 0이 되지 않는 한 말이죠.  
>> shared_ptr은 auto_ptr과는 다르게 배열을 대상으로 한 삭제 연산을  
>> 지원합니다. 하지만, 이는 프로그래머가 직접 작성해서 "등록"해주어야  
>> 합니다. 
>> shared_ptr이 auto_ptr보다 적합합니다.  
```C++
class A {
public:
  void removeA(A *pA) {                         // 배열을 지울 로직을 지정해준다.  
    delete [] pa;
  }
};
int main() {
  shared_ptr<A> ptr(new A[3], removeA);         // shared_ptr을 초기화할 때, 새로 정의한 삭제 함수를 전달해준다.  
  return 0;
}
```
## unique_ptr
>>  Shallow Copy를 문법적으로 차단해주는 스마트 포인터입니다.  
>>  Shallow Copy를 실수로 만들었다면, 컴파일러가 오류로 잡아줍니다.  
>>  shared_ptr과 조합한다면 실수할 확률이 획기적으로 줄어들겠죠.  

## weak_ptr
>> weak_ptr은 shared_ptr에 참조 형식으로 접근할 수 있는 스마트 포인터입니다.  
>> shared_ptr을 얼마나 참조하던지간에 count하지도 않고,  
>> weak_ptr이 얼마나 사라지던간에 참조하던 shared_ptr이 소멸하지도 않습니다.  
>> shared_ptr을 가리키는 포인터?정도로만 작용한다고 보시면 되겠네요.  

## auto_ptr이나 weak_ptr은 권장하지 않습니다.  
>> 사용을 권장하는 포인터는 기본적으로는 shared_ptr,  
>> 그리고 간혹 하나만 참조로 써야 할 경우는 unique_ptr을   
>> 보편적으로 이용하시기를 권합니다.  
