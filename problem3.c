#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

//#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt = 0;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	head = getNode(-1);
	//nodeCnt = 0;
}

void addNode2Head(int data) 
{
	Node *newone;

    newone = getNode(data);
	newone->next = head->next;
	head->next = newone;
}

void addNode2Tail(int data) 
{
	Node* ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = getNode(data);
}

void addNode2Num(int data, int num) 
{
	int n = 1;
	Node* ptr = head;
	Node* curr;
	while (n < num && ptr->next)
	{
		if ((ptr->next) == nullptr)
			ptr->next = getNode(0);
		ptr = ptr->next;
		n++;
	}
	curr = ptr->next;
	ptr->next = getNode(data);
	ptr = ptr->next;
	ptr->next = curr;
}

void removeNode(int data)
{
	Node* ptr = head;
	Node* curr;
    
	while (ptr->next)
	{
        if (ptr->next->data == data)
        {
            curr = ptr->next;
        	ptr->next = curr->next;
            break;
        }
		ptr = ptr->next;
	}
}


int getList(int output[MAX_NODE]) 
{
	Node* ptr = head->next;
	int cnt = 0;
	while (ptr)
	{
		output[cnt] = ptr->data;
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}
int main(void) {
	//setbuf(stdout, NULL);
	//freopen("sll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}
