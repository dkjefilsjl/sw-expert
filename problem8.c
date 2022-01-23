/*자기 방으로 돌아가기*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> P;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N = 0;
		int count = 0;
		static int finished[10];
		int i_max = 0;
		int result = 0;
        int a = 0, b = 0;
		int temp = 0;
		cin >> N;
		vector<P> vec;
        vec.clear();
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
            temp = 0;
			if (a > b)
			{
				temp = a;
				a = b;
				b = temp;
			}
            if (a % 2 == 0)
                a = a - 1;
            if (b % 2 == 1)
                b = b + 1;
			vec.push_back(P(a, b));
            finished[i] = 0;
		}
		sort(vec.begin(), vec.end());

		while (count < N) {
			for (int i = 0; i < N; i++) {
				if (finished[i])
					continue;
				if (vec[i].first < vec[i].second)
				{
					if ((i_max < vec[i].first) && (i_max < vec[i].second)) {
						i_max = max(vec[i].first, vec[i].second);
						count++;
						finished[i] = 1;
					}
				}
			}
			i_max = 0;
			result++;
		}
		cout << "#" << test_case << " " << result << endl;
	}

	return 0;
}
