/*중위순회*/

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

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>


using namespace std;


struct Node
{
	char data;
	Node* left;
	Node* right;

}listPool[1001];

int visited[100] = { 0, };
int memcnt = 0;

void inorder_traverse(Node* R)
{
	if (R->left) inorder_traverse(R->left);
	printf("%c", R->data);
	if (R->right) inorder_traverse(R->right);
}


void push_order(Node *&root, char c)
{
	if (root == nullptr)
	{
		Node* newnode = &listPool[memcnt++];
		root = newnode;
		root->data = c;
		root->left = nullptr;
		root->right = nullptr;
	}
}
void insert(vector<string> v, Node *&root, int i)
{
	if (visited[i] == -1)
		return;
	visited[i] = -1;
	string s;
	int count = 0;
	int ch[10] = { 0, };
	istringstream ss(v[i]);

	while (getline(ss, s, ' '))
	{
			int in = 0;
			char seo[2];
			stringstream ssInt(s);
			ssInt >> in;
			if (in == 0)
			{
				strcpy(seo, s.c_str());
				ch[count] = seo[0] - '0';
			}
			else ch[count] = in;
		count++;
	}
	push_order(root, ch[1] + '0');
	if (ch[2] != 0)
		insert(v, root->left, ch[2] - 1);
	if (ch[3] != 0)
		insert(v, root->right, ch[3] - 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		string st;
		vector<string> v;

		Node* root = nullptr;

		cin >> n;
		cin.ignore();

		for (int i = 0; i < n; i++)
		{
			string str;
			getline(cin, str);
			v.push_back(str);
		}
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
				insert(v, root, i);
		}
		cout << "#" << test_case << " ";
		inorder_traverse(root);
		for (int i = 0; i < n; i++)
		{
			visited[i] = 0;
		}
		cout << "\n";
	}
	return 0;
}
