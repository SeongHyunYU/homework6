#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key; //데이터 저장할 변수
	struct Node* link; // 다음노드의 주소를 저장할 구조체포인터
} listNode;

typedef struct Head {
	struct Node* first;//시작점
}headNode;


/*함수리스트*/
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
	
}

/*headnode에대한 메모리할당,리턴*/
headNode* initialize(headNode* h) {


	if(h != NULL)
		freeList(h);

	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

/*메모리해제*/
int freeList(headNode* h){
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/*처음key에대한 노드하나 추가*/
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}

/*리스트검색하여, 입력받은 key보다 큰값이나오는 노드바로앞에 삽입*/
int insertNode(headNode* h, int key) {
   
}

/*리스트에 key에대한 노드하나를 추가*/
int insertLast(headNode* h, int key) {
    listNode* lastnode = h;
	while(lastnode->link!=NULL){
		lastnode=lastnode->link;
	} 
	
	insertFirst(lastnode,key);
	return 0; /*수정해야함*/
}

/*list의 첫번째 노드 삭제*/
int deleteFirst(headNode* h) {
    listNode *front = h->first;
	h->first = front->link;
	free(front);

	return 0; /*수정해야함*/
}

/*list에서 key에대한 노드 삭제*/
int deleteNode(headNode* h, int key) {
	listNode* temp = h;
	listNode* previous = NULL;

	if(h->first==key){
		h=temp->link;
		del(temp);
	}
	else{
		while(temp!=NULL){
			if(temp->key==key){
				previous->link = temp->link;
				del(temp);
				break;
			}
			previous=temp;
			temp=temp->link;
		}
	}
	
return 0;
}/*수정해야함*/

/*list의 마지막 노드 삭제*/
int deleteLast(headNode* h) {
	headNode* tmp_Node = NULL;
	while(h->first->link!=NULL){
		tmp_Node = h;
		h= h->first->link;
	}
	tmp_Node->first->link=NULL;
	return 0;/*완성*/
}

/*list의 링크를 역순으로 재배치*/
int invertList(headNode* h) {
    headNode* a;
    headNode* b;
    headNode* c;

	
	b=NULL;
	c=NULL;
	a=h->first->link;

	while(a!=NULL){
		c=b;
		b=a;
		a=a->first->link;
		b->first->link=c;
	}
	h->first->link=b;
	return h;
}/*완성*/


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
