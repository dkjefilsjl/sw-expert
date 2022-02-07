/*염라대왕의 이름 정렬*/
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
#include<vector>
#include<algorithm>

using namespace std;
vector<string> vec;

void qsort(int l, int r) {
	int s = l; int e = r;
	string pivot = vec[(l + r) / 2];
	if (l >= r) return;

	while (s <= e) {
		while ((vec[s].length() > pivot.length()) || ((vec[s].length() == pivot.length()) && (vec[s] > pivot))) s++;
		while ((vec[e].length() < pivot.length()) || ((vec[e].length() == pivot.length()) && (vec[e] < pivot))) e--;
		if (s <= e) {
			swap(vec[s], vec[e]);
			s++; e--;
		}
	}
	qsort(l, e);
	qsort(s, r);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0;
		//vector<string> vec;
		string st;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> st;
			vec.push_back(st);
		}
		qsort(0, vec.size()-1);
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		cout << "#" << test_case << "\n";
		for (int i = vec.size()-1; i >=0; i--)
		{
			cout << vec[i] << "\n";
		}
		vec.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
