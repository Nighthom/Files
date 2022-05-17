#include "tree.h"


int tree_size = 0;

// 균형인수 계산을 위해 필요한 함수들 ...
int getHeight(Node* node)					// Node의 높이를 계산하는 함수
{											// 왼쪽 서브트리의 높이와 오른쪽 서브트리의 높이를 비교해 더 높은쪽을 반환한다.
	int height = 0;

	if (node != NULL) {
		height = 1 + getMax(getHeight(node->left), getHeight(node->right));
	}
	return height;
}

int getMax(int num1, int num2)
{
	return  num1 > num2 ? num1 : num2;				// 값 삽입 연산 중 높이 구할 때 쓰이는 최댓값 구하는 함수
}

int compare(char* str1, char* str2) {				// 노드를 검색할 때 어떤 기준을 쓸 건지 비교하는 함수
	return strcmp(str1, str2);						// strcmp 함수는 왼쪽이 더 클 경우 양수, 
													// 아닌경우 음수를 반환, 같을 경우는 0 반환.
}

int getBalance(Node* tree) {						// 노드의 균형인수를 반환한다.
	if (tree == NULL) return 0;

	return getHeight(tree->left) - getHeight(tree->right);
}
// 균형인수 계산을 위해 필요한 함수들 끝

Node* findReplacedNode(Node* tree) {						// 값 삭제시 대체 값을 찾는 함수. 트리에서의 최소값을 반환한다.
	while ((tree = tree->left) != NULL);
	return tree;
}
Node* insertNode(Node* tree, char* name, char* number)				// 값을 삽입하는 함수. 오류가 발생하면 NULL 반환.
{	
	int condition;	
	static int isError;												// 에러인지 아닌지 판별하는 플래그.
	
	if (tree == NULL) {
		isError = 0;												// 에러가 아니라는 플래그 삽입.
		tree_size++;										
		return createNode(name, number);							// 값의 자리를 찾았을 때
	}
	if (tree_size > SIZEOF_MAX_NODE)								// 트리의 크기가 최댓값을 넘겼을 경우.
		goto MaxSizeException;
	condition = compare(tree->name, name);

	if (condition > 0) {											// 새로 추가할 노드가 더 작은 경우(왼쪽)
		tree->left = insertNode(tree->left, name, number);
	}
	else if (condition < 0) {										// 새로 추가할 노드가 더 큰 경우	(오른쪽)
		tree->right = insertNode(tree->right, name, number);
	}
	else
		goto EqaulValueException;								    // 값이 같다면 그냥 삽입연산 종료(예외처리)

	if (isError == 1)
		return NULL;												// 에러라면 모든 처리루틴을 무시하고 NULL을 반환한다.

	return rotate(tree, condition);									// RR / LL / RL/ LR 타입 회전 이후 리턴
EqaulValueException:
	isError = 1;													// 에러 처리용 레이블. isError flag를 1로 set하고 NULL 반환.
	return NULL;
MaxSizeException:
	isError = 1;
	return NULL;
}

Node* createNode(char* name, char* number) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy_s(newNode->name, SIZEOF_MAX_NAME, name);								// 이름 삽입
	strcpy_s(newNode->number, SIZEOF_MAX_PHONE_NUMBER, number);					// 폰 번호 삽입
	newNode->left = NULL;  newNode->right = NULL;								// 왼쪽 노드와 오른쪽 노드 NULL로 지정
	
	return newNode;
}

Node* rotate(Node* tree, int condition) {				// condition 인자는 새로 추가된 노드의 위치를 나타내는 인자. 
														// 왼쪽이라면 양수, 오른쪽이라면 음수.
	int balance = getBalance(tree);

	if (balance > 1) {									// 균형 인수가 2 이상일 경우(rotate right 해야할 경우) L?
		if (condition < 0)
			tree->left = rotateLeft(tree->left);		
		return rotateRight(tree);												// LR type												
																				// LLtype은 오른쪽으로 한번만 돌리고 반환
	}
	else if (balance < -1) {                                  // 균형 인수가 -2 이하일 경우(rotate left가 필요할 경우) R?
		if (condition > 0)
			tree->right = rotateRight(tree->right);	
		return rotateLeft(tree);												// RL type
																				// RRtype은 왼쪽으로 한번만 돌리고 반환
	}
	return tree;
}

Node* rotateRight(Node* parent) {							// 오른쪽으로 돌리기
	Node* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

Node* rotateLeft(Node* parent) {							// 왼쪽으로 돌리기
	Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

Node* delNode(Node* tree, char* data) {			// type은 data의 형식을 받는 인자임.
	int condition = compare(tree->name, data);
	Node* tempNode;
	
	if (condition > 0) {
		tree->left = delNode(tree->left, data);
	} 
	else if (condition < 0) {
		tree->right = delNode(tree->right, data);
	}
	else {
		if (tree->left == NULL) {							// 우측 노드만 있을 때
			tempNode = tree->right;
			free(tree);
			tree_size--;
			return rotate(tempNode, condition);
		}
		else if (tree->right == NULL) {						// 좌측 노드만 있을 때
			tempNode = tree->left;
			free(tree);
			tree_size--;
			return rotate(tempNode, condition);
		}													// 좌 / 우측 노드 모두 존재할 때
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
	if (condition > 0) {										// data가 부모보다 작을 경우
		return searchNode(tree->left, data);
 	} 
	else if (condition < 0) {									// data가 부모보다 클 경우
		return searchNode(tree->right, data);
	}
	else {
		return tree;
	}
SearchValueUnfounded:
	return NULL;
}

void preOrder(Node* tree) {													// 전위 순회
	if (tree != NULL) {
		printf("%14p %14s %14s\n", tree, tree->name, tree->number);			// 출력
		preOrder(tree->left);												// 왼쪽 순회
		preOrder(tree->right);												// 오른쪽 순회
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