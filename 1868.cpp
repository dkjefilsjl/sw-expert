/*1868. 파핑파핑 지뢰찾기*/

#include <iostream>
#include <cstring>

using namespace std;

static char board[300][300];
static int play[300][300] = { 0, };

int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, -1, 1 };
static int cnt;
static int N;

int star_check(int xi, int yj);
void count_board(int xi, int yj);
void zero_check(int xi, int yj);

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		memset(board, 0, sizeof(char) * 300 * 300);
		memset(play, 0, sizeof(int) * 300 * 300);

		cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				count_board(i, j);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (play[i][j] == 0)
				{
					zero_check(i, j);
					play[i][j] = -1;
					cnt++;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (play[i][j] != -1)
				{
					cnt++;
				}
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;         //정상종료시 반드시 0을 리턴해야합니다.
}

int star_check(int xi, int yj)
{
	int flag = 0;
	int x = 0, y = 0;

	if (board[xi][yj] == '*')
		return (-1);

	for (int t = 0; t < 8; t++)
	{
		x = dx[t] + xi;
		y = dy[t] + yj;

		if ((x >= N) || (y >= N))
			continue;

		if ((x >= 300) || (y >= 300) || (x < 0) || (y < 0))
			continue;

		if (board[x][y] == '*')
		{
			flag++;
		}
	}
	return (flag);
}


void count_board(int xi, int yj)
{
	int re = 0;
	re = star_check(xi, yj);

	play[xi][yj] = re;
}


void zero_check(int xi, int yj)
{
	int x = 0, y = 0;
	for (int t = 0; t < 8; t++)
	{

		x = dx[t] + xi;
		y = dy[t] + yj;

		if ((x >= N) || (y >= N))
			continue;


		if ((x >= 300) || (y >= 300) || (x < 0) || (y < 0))
		{
			continue;
		}

		if (play[x][y] == 0 && (x < N) && (y < N))
		{
			play[x][y] = -1;
			zero_check(x, y);
		}
		play[x][y] = -1;

	}
	return ;
}
