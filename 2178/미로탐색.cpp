#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
// 상, 우, 하, 좌
int wayX[4] = {0, 1, 0, -1};
int wayY[4] = {-1, 0, 1, 0};
queue<int> nextX, nextY, counting;

void searchMaze(int x, int y, int count) {
    if(x < 1 || y < 1 || x > M || y > N) {
        return;
    }

    if(maze[y][x] == 1) {
        nextX.push(x);
        nextY.push(y);
        counting.push(count);

        maze[y][x] = 0;
    }
}

void input() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string way;

        cin >> way;

        for (int j = 0; j < M; j++) {
            maze[i][j + 1] = way[j] - '0';
        }
    }
}

void solve() {
    int answer;
    // 첫 시작은 고정
    nextX.push(1);
    nextY.push(1);
    counting.push(1);

    maze[1][1] = 0;

    while(!nextX.empty()) {
        int x = nextX.front();
        int y = nextY.front();
        int count = counting.front();

        nextX.pop();
        nextY.pop();
        counting.pop();

        if(x == M && y == N) {
            answer = count;
            break;
        }

        for (int i = 0; i < 4; i++) {
            searchMaze(x + wayX[i], y + wayY[i], count + 1);
        }
    }

    cout << answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}