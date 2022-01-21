/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;
#define MAX_NODE 10000

int output[MAX_NODE] = { 0, };

extern void init();
//extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int x);
extern void addNodeChange(int x, int s);
extern int getList(int output[MAX_NODE]);

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
	//for (int i = 0; i < 10; i++)
		//output[i] = 0;
}


static void run(int M) {
	while (M) {
		char cmd;
		int x, y, s;
		cin >> cmd;
		if (cmd == 'I')
		{
			cin >> x >> s;
			addNode2Num(s, x);
		}
		else if (cmd == 'D')
		{
			//printf("\nremoveNode\n");
			cin >> x;
			//	for (int i = 1; i <= y; i++)
			//	{
			removeNode(x);
			//	}
		}
		else if (cmd == 'C')
		{
			//	printf("\naddNode2Tail\n");
			cin >> x >> s;
			addNodeChange(x, s);
		}
		M--;
	}
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
	while (n <= num && (ptr->next))
	{
		//if ((ptr->next) == nullptr)
			//ptr->next = getNode(0);
		ptr = ptr->next;
		n++;
	}
	curr = ptr->next;
	ptr->next = getNode(data);
	ptr = ptr->next;
	ptr->next = curr;

}

void removeNode(int x)
{
	int n = 0;
	Node* ptr = head;
	Node* curr;

	while ((n < x) && (ptr->next))
	{
		ptr = ptr->next;
		n++;
		//printf("%d ", ptr->data);
	}
	//printf("\n---------\n");
	if (n == x)
	{
		if (ptr->next)
		{
			curr = ptr->next;
			ptr->next = curr->next;
		}
	}
}

void addNodeChange(int x, int s)
{
	addNode2Num(s, x);
	removeNode(x + 1);
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

int main(int argc, char** argv)
{
	int test_case;
	int T;


	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0, M = 0, L = 0, n = 0, data = 0;

		nodeCnt = 0;
		init();

		cin >> N >> M >> L;

		while (N > 0)
		{
			cin >> data;
			addNode2Tail(data);
			N--;
		}
		run(M);

		n = getList(output);
		cout << "#" << test_case << " ";
		if (n < (L + 1))
			cout << "-1";
		else
		{
			cout << output[L];
		}
		cout << "\n";

		for (int i = 0; i < n; i++)
			output[i] = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
