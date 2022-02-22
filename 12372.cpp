#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

int main(void) {
	setbuf(stdout, NULL);
	//freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}

static int id[10000][2];
static int num;

void init()
{
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 2; j++)
            id[i][j] = 0;
    }
    num = 0;
}

void addUser(int uID, int height)
{
    int flag = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i][1] < height)
        {
            for (int j = num - 1; j >= i; j--)
            {
                id[j + 1][0] = id[j][0];
                id[j + 1][1] = id[j][1];
            }
            id[i][0] = uID;
            id[i][1] = height;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        id[num][0] = uID;
        id[num][1] = height;
    }
    if (num < 10)
    	num++;
    else
        num = 10;
}

int getTop10(int result[10])
{
    int re = num;
    int i = 0;
   // printf("\nnum = %d\n", num);
    for (i = 0; i < 10; i++)
    {
        if (i == num)
            break;
        result[i] = id[i][0];
        //printf("\nresult[%d] = %d, ic = %d\n", i, result[i], id[i][1]);
    }
    //num = 0;
    return (i);
}
