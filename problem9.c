/*[S/W 문제해결 응용] 2일차 - 최대 상금*/
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
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
bool compare(int i, int j)
{
	return j < i;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int change = 0;
		int max = 0;
		int i_max = 0;
		int min = 0;
		int i = 0;
		int temp = 0;
		int cnt = 0;
		string st;
		cin >> st >> change;

		vector<char> vec(st.begin(), st.end());
		vector<char> vec_sort(vec);
		sort(vec_sort.begin(), vec_sort.end(), compare);
		while (change)
		{
			max = vec_sort[i_max];
			for (i = 0; i < vec.size(); i++)
			{
				if (vec_sort[i] != vec[i])
					break;
			}
			if (i == vec.size())
			{
				while (change)
				{
					int index = vec.size() - 1;
					for (int j = 0; j < vec.size(); j++)
					{
						if (count(vec.begin(), vec.end(), vec[j]) > 1)
						{
							index = -1;
							change = 0;
							break;
						}
					}
					if (index != -1)
					{
						temp = vec[index];
						vec[index] = vec[index - 1];
						vec[index - 1] = temp;
						change--;
					}
				}
				break;
			}
			for (int j = 0; j < vec.size(); j++)
			{
				if (vec[j] != vec_sort[j])
				{
					cnt = 0;
					for (int k = vec.size() - 1; k >= j; k--)
					{
						if (vec[k] == vec_sort[j])
							cnt++;
					}
					for (int k = vec.size() - 1; k >= j; k--)
					{
						temp = change;
						while ((cnt > 1) && (temp > 1))
						{
							if (vec[k] == vec_sort[j])
							{
								cnt--;
								temp--;
							}
							k--;
						}
						if (vec[k] == vec_sort[j])
						{
							swap(vec[k], vec[j]);
							break;
						}
					}
					break;
				}
			}
			change--;
		}

		cout << "#" << test_case << " ";
		for (int j = 0; j < vec.size(); j++)
		{
			cout << vec[j];
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
