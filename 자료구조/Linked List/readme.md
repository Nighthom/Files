# 연결 리스트

>> 연결 리스트는 실제 값을 갖는 자기 자신의 Data와,  
>> 다음 값의 포인터 / 참조를 갖는 구조체 혹은 클래스로 구성된  
>> 자료 구조입니다.  
>> C로는 다음과 같습니다.
```C
// datatype은 임의의 재정의된 타입.
typedef struct _LIST { 
  datatype data;
  struct _LIST *next;
} lLIst;
```
>> Head List의 주소를 따로 저장해놓고,  
>> 해당 List는 Data 없이 첫 원소의 값을 가리키기만 하게  
>> 구현하기도 합니다.  

# 삽입연산
>> 삽입 연산은 간단합니다.  
```C
lList* InsertList(lList list, datatype item) {
  lList* newList = (lList*) malloc(sizeof(lList));
  newList->data = item;
  newList->next = list->next;
  list->next = newList;
```
>> 이렇게 삽입 연산을 구현하면 인자로 전달한 list 다음 값에  
>> 새로운 List를 삽입할 수 있습니다.

# 삭제연산
>> 삭제 연산 또한 너무나도 간단합니다.
```C
int delList(lList list, datatype delNode){ 
  while((list->next)->data != delNode {
    if(list == NULL) {
      return -1           // 에러처리
    }
    list = list->next;
  }
  lList* delete = list->next;
  list->next = delete->next;
  free(delete);
  
  return 0;
}
```
>> 이런식으로 삭제 연산을 진행하게 됩니다.

>> 탐색연산도 비슷합니다.  
>> Head노드를 인자로 전달하면,  다음 값을 찾을 때 까지  
>> 계속 다음 값을 조회하면 됩니다.  
