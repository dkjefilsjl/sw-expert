#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int number;
	int data;
	int left;
	int right;
} treeNode[10001];


double Cal(int idx)
{
    if(treeNode[idx].number) return (double) treeNode[idx].data;
    double c1 = Cal(treeNode[idx].left);
    double c2 = Cal(treeNode[idx].right);
    switch(treeNode[idx].data) {
        case '+': return c1 + c2;
        case '-': return c1 - c2;
        case '*': return c1 * c2;
        case '/': return c1 / c2;
        default : return -1;
    }
    return -1;
}

void insert(string st, int idx, int pi)
{
	if(st.at(0) >= '0' && st.at(0) <= '9')
    {
        treeNode[idx].number = 1;
        int num = 0;
        for(int i = 0; i < st.length(); i++) {
            num *= 10;
            num += st.at(i) - '0';
        }
        treeNode[idx].data = num;
    } 
    else 
    {
        treeNode[idx].number = 0;
        int num = st.at(0);
        int c1, c2;
        cin >> c1 >> c2;
        c1 = pi + c1 - 1;
        c2 = pi + c2 - 1;
        treeNode[idx].data = num;
        treeNode[idx].left = c1;
        treeNode[idx].right = c2;
    }
}

int main(int argc, char** argv)
{
	int test_case;
    double result = 0;
	int pi = 0;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int c;
            string st;

            cin >> c;
            c = pi + c - 1;
            cin >> st;
            insert(st, c, pi);
        }
        result = Cal(pi);
        pi += n - 1;
        cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
