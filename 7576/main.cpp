#include <iostream>
#include <queue>
using namespace std;

int N, M;
int field[1000][1000];
queue<int> nextLocX;
queue<int> nextLocY;
queue<int> days;

void infection(int x, int y, int day) {
    if(x < 0 || y < 0 || x >= M || y >= N)
        return;

    if(field[y][x] == 1 || field[y][x] == -1)
        return;
    else {
        nextLocX.push(x);
        nextLocY.push(y);
        days.push(day);

        field[y][x] = 1;
    }
}

void input() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
}

void solve() {
    int x, y, day;
    // 전이할 시작점들 찾기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(field[i][j] == 1) {
                nextLocX.push(j);
                nextLocY.push(i);
                days.push(0);
            }
        }
    }

    // 토마토 익히기
    while(!nextLocX.empty()) {
        x = nextLocX.front();
        y = nextLocY.front();
        day = days.front();

        nextLocX.pop();
        nextLocY.pop();
        days.pop();

        infection(x, y - 1, day + 1);
        infection(x + 1, y, day + 1);
        infection(x, y + 1, day + 1);
        infection(x - 1, y, day + 1);
    }

    // 안익은 토마토 찾기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(field[i][j] == 0) {
                day = -1;
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