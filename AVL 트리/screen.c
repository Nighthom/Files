#include "screen.h"


extern int tree_size;

void print_screen() {
	char menu;
	char buf[2];
	Node* Database = NULL;

	Node* (*menuFunc[SIZEOF_MENU])(Node*) = { NULL };

	menuFunc[0] = insert_data;
	menuFunc[1] = delete_data;
	menuFunc[2] = lookup_data;
	menuFunc[3] = search_data;
	
	while (1) {
		
		puts("\
			-------------------------------------------------------\n\n\n\n	\
			AVL 주소록 ver 1.0 \n\n\n \
			원하는 기능에 해당하는 버튼을 입력하세요.  \n\n  \
			1 : 데이터 삽입 / 2 : 데이터 삭제 / 3 : 데이터 조회 / \n \
			4. 데이터 검색 / 5 : 프로그램 종료  \n\n\n\n \
			-------------------------------------------------------\n\n \
			");
		
		menu = atoi( gets_s(buf, 2) );									// menu값을 integer로 변환
		if (menu == 5)
			break;
		else if (menu > 5 || menu < 1) {
			system("cls");
			printf("\
			1~5 사이의 값이 아닙니다. 유효한 값을 입력해 주세요. \n \
			");
			
			system("pause");
			system("cls");
			continue;
		}
		Database = menuFunc[menu - 1](Database);
		system("pause");
		system("cls");
	}
}
void clear_buffer() {
	while (getchar() != '\n' || getchar() != NULL);
}

Node* insert_data(Node* tree) {									// 대상을 입력하는 함수의 interface.
	char* name[SIZEOF_MAX_NAME];
	char* number[SIZEOF_MAX_PHONE_NUMBER];
	Node* newNode = NULL;
	int isLookup = 0;
	
	system("cls");
	puts("주소록에 입력할 대상의 이름을 입력하세요. \n");
	gets_s(name, SIZEOF_MAX_NAME);

	system("cls");
	puts("주소록에 입력할 대상의 휴대폰 번호를 입력하세요. \n");
	gets_s(number, SIZEOF_MAX_PHONE_NUMBER);

	system("cls");
	if ((newNode = insertNode(tree, name, number)) == NULL) {
		printf("이미 존재하는 값입니다. 중복된 값을 입력할 수 없습니다. \n");
		return tree;
	}
	return newNode;
}
Node* delete_data(Node* tree) {											// 삭제 함수 인터페이스.
	char data[SIZEOF_MAX_NAME];
	Node* result = NULL;

	system("cls");
	if (tree_size == 0) {
		puts("주소록에 데이터가 존재하지 않습니다.");
		return tree;
	}
	puts("주소록에서 삭제할 대상의 이름을 입력하세요.\n");
	gets_s(data, sizeof(data));

	result = delNode(tree, data);
	system("cls");
	if (tree_size != 0 && result == NULL) {											// tree의 원소가 1개이고, NULL이 반환되었을 때.											
		puts("삭제하려는 노드가 존재하지 않습니다.\n");
	}
	else 
		printf("값 %s가 삭제되었습니다. \n", data);
	return result;
}

#define lookup_funcSize 3

Node* lookup_data(Node* tree) {
	void (*lookupFunc[lookup_funcSize])(Node*) = {NULL};
	lookupFunc[0] = preOrder;
	lookupFunc[1] = prevOrder;
	lookupFunc[2] = midOrder;
	char* buf[2];
	int menu;
	system("cls");

	if (tree == NULL) {
		printf("데이터베이스에 데이터가 없습니다.\n");
		return tree;
	}
	while (1) {
		
		puts("\
			주소록을 어떻게 조회할 것인지 선택하세요. \n \
			1 : 전위순회 / 2. 중위순회 / 3. 후위순회 \n");
		menu = atoi(gets_s(buf, sizeof(buf)));
		
		if (menu < 1 || menu > 3) {
			puts("유효한 값이 아닙니다. 유효한 값을 입력하세요. (1 ~ 3)\n");
			system("pause");
		}
		else 
			break;													// 유효 값 입력 시 탈출
	}
	
	
	system("cls");
	print_lable();
	lookupFunc[menu - 1](tree);									// 함수 조회
	return tree;
}

Node* search_data(Node* tree) {
	char data[SIZEOF_MAX_NAME] = { NULL };
	Node* result = NULL;

	system("cls");
	puts("데이터를 입력하세요. \n");
	gets_s(data, sizeof(data));
	
	result = searchNode(tree, data);

	system("cls");
	if (result == NULL) {
		printf("찾으시는 값이 존재하지 않습니다. \n\n");
		return tree;
	}
	puts("값을 찾았습니다. \n");
	system("pause");
	system("cls");
	print_lable();
	printf("%14p %14s %14s\n", result, result->name, result->number);
	return tree;
}

void print_lable() {
	printf("%14s %14s %14s", "주소", "이름", "휴대폰 번호\n");
}