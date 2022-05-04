# Linked List

>> 연결 리스트는 값과 다음 리스트를 가리키는
>> Next를 담는 구조체입니다.

```C
typedef struct Linked_List {
  int data;
  struct Linked_List* next;
} Node;
```
>> 위 구조체가 연결리스트의 전부입니다.
>> data에는 data가 들어갈 수 있고,
>> (데이터를 연결리스트로 전달하거나 배열이나 원하는
>> 그 어떠한 자료형으로 전달해도 상관없습니다.)
>> next는 다음 리스트를 가리키는 구조체 포인터입니다.
>> 마지막 리스트의 next에는 NULL 포인터를 담아 
>> 리스트의 종료를 알립니다.

# Linked List 초기화
>> 간단한 구조이니만큼 초기화도 간단합니다.
>> head 노드를 생성합니다.
```C
Node* head;
head = (Node*)malloc(sizeof(Node));
head -> next = NULL;
```
>> head 노드는 리스트의 첫 노드를 가리킵니다.
>> 하지만 값은 저장하지 않아요.
>> 실질적인 데이터를 갖는 첫 리스트를 가리키는 역할을 합니다.

# 값 삽입
```C
int insert_Node(Node* list, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node)); 
  if(newNode == NULL)
    goto GETTING_MEM_FAILED                             // 예외처리
  newNode->data = data;                                 
  newNode->next = NULL;                                 // 새로운 노드를 생성합니다.
  while(list->next != NULL) { list = list->next; }      // 리스트의 마지막 노드로 이동합니다.
  list->next = newNode;
  
  return 0;
  GETTING_MEM_FAILED: 
  return -1;
}
```
>> 위와 같은 함수로 연결리스트의 마지막 노드 다음에
>> 새로운 노드를 위치시킬 수 있어요.
>> 리스트의 마지막 노드로 이동한 다음 Next를 새로운 다음 노드로 지정해주는'
>> 함수입니다. 
>> 굳이 중간에 값을 추가하거나.. 첫 노드에 값을 추가하려면
>> 추가할 위치의 전 노드에 해당하는 노드의 next를 백업하고,
>> 추가할 노드의 포인터를 next에 저장한 다음 
>> 추가할 노드의 next에 백업한 next를 써넣으면 되겠죠.

# 값 삭제
>> 경우의 수가 여러가지가 있겠죠?
>> 맨 앞 노드 삭제나, 
>> 중간에 있는 노드 삭제나, 
>> 맨 끝에 있는 노드 삭제 등등..
>> 값을 기반으로 삭제할지, 인덱스를 기반으로 삭제할지..
>> 이거는 원하는대로 구현하면 됩니다.

```C 
int delList(Node* list, int delValue) {
  Node* delNode = NULL;
  Node* prevNode = list;                                                      // 삭제할 노드의 전 노드.
  while((prevNode->next)->data == delValue) { 
    if(preveNode->next == NULL)                                               // 예외처리
      goto delValue_NOT_FOUNDED
    prevNode = prevNode->next; 
  }                                                                            // 삭제할 노드의 전 노드가 삭제할 노드를 만날 때 까지.
  delNode = prevNode -> next;
  
  prevNode->next = delNode->next;                                             // 삭제할 노드와의 연결을 끊고 그 다음 노드 가져오기
  free(delNode);
  return 0;
  delValue_NOT_FOUNDED:
  printf("ERROR! 삭제하려는 값을 찾을 수가 없습니다.");
  return -1;
}
```
>> 깔끔하게 값 입력과 삭제를 구현했습니다.
>> 값 검색은 비슷한 알고리즘으로 하면 되요.
>> 계속 다음 값만 꺼내고 가져오면 되니까..

>> 연결 리스트의 장점은 데이터로 그 어떠한
>> 자료구조라도 보내기가 쉽다는 것이죠!
>> 혁신적인 자료구조라 아니할 수 없네요.
