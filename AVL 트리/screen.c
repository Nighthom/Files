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
			AVL �ּҷ� ver 1.0 \n\n\n \
			���ϴ� ��ɿ� �ش��ϴ� ��ư�� �Է��ϼ���.  \n\n  \
			1 : ������ ���� / 2 : ������ ���� / 3 : ������ ��ȸ / \n \
			4. ������ �˻� / 5 : ���α׷� ����  \n\n\n\n \
			-------------------------------------------------------\n\n \
			");
		
		menu = atoi( gets_s(buf, 2) );									// menu���� integer�� ��ȯ
		if (menu == 5)
			break;
		else if (menu > 5 || menu < 1) {
			system("cls");
			printf("\
			1~5 ������ ���� �ƴմϴ�. ��ȿ�� ���� �Է��� �ּ���. \n \
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

Node* insert_data(Node* tree) {									// ����� �Է��ϴ� �Լ��� interface.
	char* name[SIZEOF_MAX_NAME];
	char* number[SIZEOF_MAX_PHONE_NUMBER];
	Node* newNode = NULL;
	int isLookup = 0;
	
	system("cls");
	puts("�ּҷϿ� �Է��� ����� �̸��� �Է��ϼ���. \n");
	gets_s(name, SIZEOF_MAX_NAME);

	system("cls");
	puts("�ּҷϿ� �Է��� ����� �޴��� ��ȣ�� �Է��ϼ���. \n");
	gets_s(number, SIZEOF_MAX_PHONE_NUMBER);

	system("cls");
	if ((newNode = insertNode(tree, name, number)) == NULL) {
		printf("�̹� �����ϴ� ���Դϴ�. �ߺ��� ���� �Է��� �� �����ϴ�. \n");
		return tree;
	}
	return newNode;
}
Node* delete_data(Node* tree) {											// ���� �Լ� �������̽�.
	char data[SIZEOF_MAX_NAME];
	Node* result = NULL;

	system("cls");
	if (tree_size == 0) {
		puts("�ּҷϿ� �����Ͱ� �������� �ʽ��ϴ�.");
		return tree;
	}
	puts("�ּҷϿ��� ������ ����� �̸��� �Է��ϼ���.\n");
	gets_s(data, sizeof(data));

	result = delNode(tree, data);
	system("cls");
	if (tree_size != 0 && result == NULL) {											// tree�� ���Ұ� 1���̰�, NULL�� ��ȯ�Ǿ��� ��.											
		puts("�����Ϸ��� ��尡 �������� �ʽ��ϴ�.\n");
	}
	else 
		printf("�� %s�� �����Ǿ����ϴ�. \n", data);
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
		printf("�����ͺ��̽��� �����Ͱ� �����ϴ�.\n");
		return tree;
	}
	while (1) {
		
		puts("\
			�ּҷ��� ��� ��ȸ�� ������ �����ϼ���. \n \
			1 : ������ȸ / 2. ������ȸ / 3. ������ȸ \n");
		menu = atoi(gets_s(buf, sizeof(buf)));
		
		if (menu < 1 || menu > 3) {
			puts("��ȿ�� ���� �ƴմϴ�. ��ȿ�� ���� �Է��ϼ���. (1 ~ 3)\n");
			system("pause");
		}
		else 
			break;													// ��ȿ �� �Է� �� Ż��
	}
	
	
	system("cls");
	print_lable();
	lookupFunc[menu - 1](tree);									// �Լ� ��ȸ
	return tree;
}

Node* search_data(Node* tree) {
	char data[SIZEOF_MAX_NAME] = { NULL };
	Node* result = NULL;

	system("cls");
	puts("�����͸� �Է��ϼ���. \n");
	gets_s(data, sizeof(data));
	
	result = searchNode(tree, data);

	system("cls");
	if (result == NULL) {
		printf("ã���ô� ���� �������� �ʽ��ϴ�. \n\n");
		return tree;
	}
	puts("���� ã�ҽ��ϴ�. \n");
	system("pause");
	system("cls");
	print_lable();
	printf("%14p %14s %14s\n", result, result->name, result->number);
	return tree;
}

void print_lable() {
	printf("%14s %14s %14s", "�ּ�", "�̸�", "�޴��� ��ȣ\n");
}