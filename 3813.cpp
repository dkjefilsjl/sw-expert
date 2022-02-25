
#include<iostream>

using namespace std;

int W[200000], S[200000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		int left = 1, right = 200000, m = 0;
		int target = 0, check = 0, re = 0;

		cin >> N >> K;
		for (int i = 0; i < N; i ++)
		{
			cin >> W[i];
		}

		for (int i = 0; i < K; i++)
		{
			cin >> S[i];
		}

		while (left < right)
		{
			m = (left + right) / 2;
			target = -1;
			check = 1;
			for (int i = 0; i < K; i++)
			{
				if (check == 0)
					break;
				for (int j = 0; j < S[i]; j++)
				{
					target++;
					if (target == N)
					{
						check = 0;
						break;
					}
					if (W[target] > m)
					{
						i--;
						break;
					}
				}
			}

			if(check == 1)
				right = m;
			else
				left = m + 1;
		}
		re = right;
		cout << "\n#" << test_case << ' ' << re << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
