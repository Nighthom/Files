#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZEOF_MAX_NODE 10000						// 노드 최대값
#define SIZEOF_MAX_NAME 30							// 이름 최대길이
#define SIZEOF_MAX_PHONE_NUMBER 15					// 폰번호 최대길이


#define NAME 0
#define NUMBER 1



typedef struct _NODE {
	char name[SIZEOF_MAX_NAME];
	char number[SIZEOF_MAX_PHONE_NUMBER];

	struct _NODE* left;
	struct _NODE* right;
}Node;



// 균형인수 연산을 위해 필요한 함수들
int getHeight(Node* node);
int getMax(int num1, int num2);
int compare(char* str1, char* str2);
int getBalance(Node* tree);

Node* insertNode(Node* tree, char* name, char* number);
Node* delNode(Node* tree, char* data);
Node* searchName(Node* tree, char* name);

Node* createNode(char* name, char* number);
Node* rotate(Node* tree, int condition);

Node* rotateRight(Node* parent);
Node* rotateLeft(Node* parent);
Node* findReplacedNode(Node* tree);

Node* searchNode(Node* tree, char* data);

void preOrder(Node* tree);
void prevOrder(Node* tree);
void midOrder(Node* tree);
