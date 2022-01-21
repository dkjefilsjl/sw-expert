#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("dll_input.txt", "r", stdin);

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

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
	tail = getNode(-1);
	head->next = tail;
	tail->prev = head;
}

void addNode2Head(int data)
{
	Node* newone = getNode(data);
	head->next->prev = newone;
	newone->next = head->next;
	head->next = newone;
	newone->prev = head;
}

void addNode2Tail(int data)
{
	Node* newone = getNode(data);
	tail->prev->next = newone;
	newone->prev = tail->prev;
	newone->next = tail;
	tail->prev = newone;

}

void addNode2Num(int data, int num)
{
	int n = 1;
	Node* ptr = head;
	Node* curr;
	while ((n < num))
	{
		if ((ptr->next) == nullptr)
		{
			ptr->next = getNode(0);
			ptr->next->prev = ptr;
		}
		ptr = ptr->next;
		n++;
	}
	curr = ptr->next;
	ptr->next = getNode(data);
	ptr->next->prev = ptr;
	ptr = ptr->next;
	ptr->next = curr;
	curr->prev = ptr;
}

int findNode(int data)
{
	int cnt = 0;
	Node* ptr = head;
	Node* curr;

	while (ptr->next)
	{
		if (ptr->next->data == data)
		{
			cnt++;
			break;
		}
		ptr = ptr->next;
		cnt++;
	}
	return (cnt);
}

void removeNode(int data)
{
	Node* ptr = head;

	while (ptr->next)
	{
		if (ptr->next->data == data)
		{
			ptr->next->next->prev = ptr;
			ptr->next = ptr->next->next;
			break;
		}
		ptr = ptr->next;
	}
}

int getList(int output[MAX_NODE])
{
	Node* ptr;
	int cnt = 0;

	ptr = head->next;
	while (ptr->next)
	{
		output[cnt] = ptr->data;
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}

int getReversedList(int output[MAX_NODE])
{
	Node* ptr;
	int cnt = 0;

	ptr = tail->prev;
	while (ptr->prev)
	{
		output[cnt] = ptr->data;
		cnt++;
		ptr = ptr->prev;
	}
	return (cnt);
}
