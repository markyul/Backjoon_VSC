#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int field[100][100][100];
queue<int> nextLocX;
queue<int> nextLocY;
queue<int> nextLocZ;
queue<int> days;

void infection(int x, int y, int z, int day) {
    if(x < 0 || y < 0 || z < 0 || x >= M || y >= N || z >= H)
        return;

    if(field[z][y][x] == 1 || field[z][y][x] == -1)
        return;
    else {
        nextLocX.push(x);
        nextLocY.push(y);
        nextLocZ.push(z);
        days.push(day);

        field[z][y][x] = 1;
    }
}

void input() {
    cin >> M >> N >> H;

    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> field[h][i][j];
            }
        }
    }
}

void solve() {
    int x, y, z, day;
    // 전이할 시작점들 찾기
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(field[h][i][j] == 1) {
                    nextLocX.push(j);
                    nextLocY.push(i);
                    nextLocZ.push(h);
                    days.push(0);
                }
            }
        }
    }

    // 토마토 익히기
    while(!nextLocX.empty()) {
        x = nextLocX.front();
        y = nextLocY.front();
        z = nextLocZ.front();
        day = days.front();

        nextLocX.pop();
        nextLocY.pop();
        nextLocZ.pop();
        days.pop();

        infection(x, y - 1, z, day + 1);
        infection(x + 1, y, z, day + 1);
        infection(x, y + 1, z, day + 1);
        infection(x - 1, y, z, day + 1);
        infection(x, y, z - 1, day + 1);
        infection(x, y, z + 1, day + 1);
    }

    // 안익은 토마토 찾기
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(field[h][i][j] == 0) {
                    day = -1;
                }
            }
        }
    }

    cout << day;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}