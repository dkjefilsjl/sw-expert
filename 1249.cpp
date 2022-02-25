
#include<iostream>
#include <cstring>
#include <queue>

using namespace std;
static char visited[100][100];
int qx[4] = {0, 0, 1, -1};
int qy[4] = {1, -1, 0, 0};
static char map[100][100];
static int dp[100][100];
static int N;

void bfs()
{
	int xi = 0, yj = 0, x = 0, y = 0;
	queue< pair<int, int> > q;
	q.push(make_pair(0,0));
	visited[q.front().first][q.front().second] = 1;

	while (!q.empty())
	{
		xi = q.front().first;
		yj = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			x = qx[i] + xi;
			y = qy[i] + yj;

			if ((x >= N) || (y >= N) || (x < 0) || (y < 0))
				continue;

			if ((visited[x][y] == 0) || (dp[x][y] > (dp[xi][yj] + map[x][y] - '0')))
			{
				//cout << xi << " " << yj << "\n";
				visited[x][y] = 1;
				dp[x][y] = dp[xi][yj] + map[x][y] - '0';
				//cout << dp[x][y] / '0' << " ";
				q.push(make_pair(x, y));
			}
		}
	}
	/*for (int i = 0 ; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//dp[i][j] /= '0';
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	return ;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));

		cin >> N;

		for(int i = 0 ; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		bfs();
		cout <<"#" <<test_case << " " << dp[N-1][N-1] << "\n"; 
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
