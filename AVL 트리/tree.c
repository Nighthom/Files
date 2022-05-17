#include "tree.h"


int tree_size = 0;

// �����μ� ����� ���� �ʿ��� �Լ��� ...
int getHeight(Node* node)					// Node�� ���̸� ����ϴ� �Լ�
{											// ���� ����Ʈ���� ���̿� ������ ����Ʈ���� ���̸� ���� �� �������� ��ȯ�Ѵ�.
	int height = 0;

	if (node != NULL) {
		height = 1 + getMax(getHeight(node->left), getHeight(node->right));
	}
	return height;
}

int getMax(int num1, int num2)
{
	return  num1 > num2 ? num1 : num2;				// �� ���� ���� �� ���� ���� �� ���̴� �ִ� ���ϴ� �Լ�
}

int compare(char* str1, char* str2) {				// ��带 �˻��� �� � ������ �� ���� ���ϴ� �Լ�
	return strcmp(str1, str2);						// strcmp �Լ��� ������ �� Ŭ ��� ���, 
													// �ƴѰ�� ������ ��ȯ, ���� ���� 0 ��ȯ.
}

int getBalance(Node* tree) {						// ����� �����μ��� ��ȯ�Ѵ�.
	if (tree == NULL) return 0;

	return getHeight(tree->left) - getHeight(tree->right);
}
// �����μ� ����� ���� �ʿ��� �Լ��� ��

Node* findReplacedNode(Node* tree) {						// �� ������ ��ü ���� ã�� �Լ�. Ʈ�������� �ּҰ��� ��ȯ�Ѵ�.
	while ((tree = tree->left) != NULL);
	return tree;
}
Node* insertNode(Node* tree, char* name, char* number)				// ���� �����ϴ� �Լ�. ������ �߻��ϸ� NULL ��ȯ.
{	
	int condition;	
	static int isError;												// �������� �ƴ��� �Ǻ��ϴ� �÷���.
	
	if (tree == NULL) {
		isError = 0;												// ������ �ƴ϶�� �÷��� ����.
		tree_size++;										
		return createNode(name, number);							// ���� �ڸ��� ã���� ��
	}
	if (tree_size > SIZEOF_MAX_NODE)								// Ʈ���� ũ�Ⱑ �ִ��� �Ѱ��� ���.
		goto MaxSizeException;
	condition = compare(tree->name, name);

	if (condition > 0) {											// ���� �߰��� ��尡 �� ���� ���(����)
		tree->left = insertNode(tree->left, name, number);
	}
	else if (condition < 0) {										// ���� �߰��� ��尡 �� ū ���	(������)
		tree->right = insertNode(tree->right, name, number);
	}
	else
		goto EqaulValueException;								    // ���� ���ٸ� �׳� ���Կ��� ����(����ó��)

	if (isError == 1)
		return NULL;												// ������� ��� ó����ƾ�� �����ϰ� NULL�� ��ȯ�Ѵ�.

	return rotate(tree, condition);									// RR / LL / RL/ LR Ÿ�� ȸ�� ���� ����
EqaulValueException:
	isError = 1;													// ���� ó���� ���̺�. isError flag�� 1�� set�ϰ� NULL ��ȯ.
	return NULL;
MaxSizeException:
	isError = 1;
	return NULL;
}

Node* createNode(char* name, char* number) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy_s(newNode->name, SIZEOF_MAX_NAME, name);								// �̸� ����
	strcpy_s(newNode->number, SIZEOF_MAX_PHONE_NUMBER, number);					// �� ��ȣ ����
	newNode->left = NULL;  newNode->right = NULL;								// ���� ���� ������ ��� NULL�� ����
	
	return newNode;
}

Node* rotate(Node* tree, int condition) {				// condition ���ڴ� ���� �߰��� ����� ��ġ�� ��Ÿ���� ����. 
														// �����̶�� ���, �������̶�� ����.
	int balance = getBalance(tree);

	if (balance > 1) {									// ���� �μ��� 2 �̻��� ���(rotate right �ؾ��� ���) L?
		if (condition < 0)
			tree->left = rotateLeft(tree->left);		
		return rotateRight(tree);												// LR type												
																				// LLtype�� ���������� �ѹ��� ������ ��ȯ
	}
	else if (balance < -1) {                                  // ���� �μ��� -2 ������ ���(rotate left�� �ʿ��� ���) R?
		if (condition > 0)
			tree->right = rotateRight(tree->right);	
		return rotateLeft(tree);												// RL type
																				// RRtype�� �������� �ѹ��� ������ ��ȯ
	}
	return tree;
}

Node* rotateRight(Node* parent) {							// ���������� ������
	Node* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

Node* rotateLeft(Node* parent) {							// �������� ������
	Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

Node* delNode(Node* tree, char* data) {			// type�� data�� ������ �޴� ������.
	int condition = compare(tree->name, data);
	Node* tempNode;
	
	if (condition > 0) {
		tree->left = delNode(tree->left, data);
	} 
	else if (condition < 0) {
		tree->right = delNode(tree->right, data);
	}
	else {
		if (tree->left == NULL) {							// ���� ��常 ���� ��
			tempNode = tree->right;
			free(tree);
			tree_size--;
			return rotate(tempNode, condition);
		}
		else if (tree->right == NULL) {						// ���� ��常 ���� ��
			tempNode = tree->left;
			free(tree);
			tree_size--;
			return rotate(tempNode, condition);
		}													// �� / ���� ��� ��� ������ ��
		tempNode = findReplacedNode(tree->right);

		strcpy_s(tree->name, SIZEOF_MAX_NAME, tempNode->name);
		strcpy_s(tree->number, SIZEOF_MAX_PHONE_NUMBER, tempNode->number);

		tree->right = delNode(tree->right, tempNode->name);
	}
	return rotate(tree, condition);
	
}

Node* searchNode(Node* tree, char* data) {
	int condition = 0;
	if (tree == NULL) {
		goto SearchValueUnfounded;
	}
	condition = compare(tree->name, data);
	if (condition > 0) {										// data�� �θ𺸴� ���� ���
		return searchNode(tree->left, data);
 	} 
	else if (condition < 0) {									// data�� �θ𺸴� Ŭ ���
		return searchNode(tree->right, data);
	}
	else {
		return tree;
	}
SearchValueUnfounded:
	return NULL;
}

void preOrder(Node* tree) {													// ���� ��ȸ
	if (tree != NULL) {
		printf("%14p %14s %14s\n", tree, tree->name, tree->number);			// ���
		preOrder(tree->left);												// ���� ��ȸ
		preOrder(tree->right);												// ������ ��ȸ
	}
}

void prevOrder(Node* tree) {
	if (tree != NULL) {
		prevOrder(tree->left);
		prevOrder(tree->right);
		printf("%14p %14s %14s\n", tree, tree->name, tree->number);
	}

}

void midOrder(Node* tree) {
	if (tree != NULL) {
		midOrder(tree->left);
		printf("%14p %14s %14s\n", tree, tree->name, tree->number);
		midOrder(tree->right);
	}
}