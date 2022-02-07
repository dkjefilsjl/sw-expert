#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);
static int test_bfs() {
    int N;
    int map[10][10];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs_init(N, map);
    int M;
    int score = 100;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = bfs(x1, y1, x2, y2);
        int dist;
        scanf("%d", &dist);
        if (result != dist) score = 0;
    }
    return score;
}
int main() {
    setbuf(stdout, NULL);
    printf("#total score : %d\n", test_bfs());
    return 0;
}
int my_map[11][11] = {-1,};
int re = -1;
int map_SIZE = 0;
int front = 0;
int rear = 0;
int p = 0;

void bfs_init(int map_size, int map[10][10])
{
    map_SIZE = map_size;
    re = -1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            my_map[i+1][j+1] = -1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < map_size; j++)
        {
            my_map[i+1][j+1] = map[i][j];
        }
    }
}
int check(int queue[102][3], int x2, int y2)
{
    //printf("queue[rear][1]= %d, queue[rear][0] = %d, x2 = %d. y2 = %d\n", queue[rear][1], queue[rear][0], x2, y2);
    //printf("queue[rear][2] = %d\n", queue[rear][2]);
    if ((queue[rear][1] == x2) && (queue[rear][0] == y2))
    {
        p = 1;
        if (re == -1)
            re = queue[rear][2];
        else if (re > queue[rear][2])
            re = queue[rear][2];
    }
    return (re);
}
int real_bfs(int x1, int y1, int x2, int y2, int visited[101][101], int queue[102][3])
{
    int qy = queue[front][0];
    int qx = queue[front][1];
    printf("\n%d, %d\n", qy, qx);
    visited[qy][qx] = 1;
    while ((front < rear) && (p == 0))
    {
        if ((qy + 1) <= 10)
        {
            printf("here = 1\n");
            if ((visited[qy+1][qx] == 0) && (my_map[qy+1][qx] == 0))
            {
                visited[qy+1][qx] = 1;
                queue[rear][0] = qy + 1;
                queue[rear][1] = qx;
                queue[rear][2] = queue[front][2] + 1;
                re = check(queue, x2, y2);
                rear++;
            }
        }
        if ((qy - 1) > 0)
        {
            printf("here = 2\n");
            if ((visited[qy-1][qx] == 0) && (my_map[qy-1][qx] == 0))
            {
                visited[qy-1][qx] = 1;
                queue[rear][0] = qy - 1;
                queue[rear][1] = qx;
                queue[rear][2] = queue[front][2] + 1;
                re = check(queue, x2, y2);
                rear++;
            }
        }
        if ((qx + 1) <= 10)
        {
            printf("here = 3\n");
            if ((visited[qy][qx+1] == 0) && (my_map[qy][qx+1] == 0))
            {
                visited[qy][qx+1] = 1;
                queue[rear][0] = qy;
                queue[rear][1] = qx + 1;
                queue[rear][2] = queue[front][2] + 1;
                re = check(queue, x2, y2);
                rear++;
            }
        }
        if ((qx - 1) > 0)
        {
            printf("here = 4\n");
            if ((visited[qy][qx-1] == 0) && (my_map[qy][qx-1] == 0))
            {
                visited[qy][qx-1] = 1;
                queue[rear][0] = qy;
                queue[rear][1] = qx - 1;
                queue[rear][2] = queue[front][2] + 1;
                re = check(queue, x2, y2);
                rear++;
            }
        }
        front++;
        qy = queue[front][0];
        qx = queue[front][1];
        printf("rear = %d, front = %d\n" ,rear, front);
    }
    return (re);
}
int bfs(int x1, int y1, int x2, int y2)
{
    int queue[102][3] = {0,};
    int size = 100;
    int visited[101][101] = {0,};
    p = 0;
    re = -1;
    front = 0;
    rear = 0;
    queue[front][0] = y1;
    queue[front][1] = x1;
    rear++;
    re = real_bfs(x1, y1, x2, y2, visited, queue);
    printf("re = %d\n",re);
    return (re);
}

