#include <iostream>
#include <queue>
using namespace std;

int N, K;
int field[100001];  // 1: 동생 위치, -1: 방문 여부
queue<int> nextLoc, times;

void movement(int loc, int time) {
    if(loc < 0 || loc > 100000 || field[loc] == -1)
        return;

    nextLoc.push(loc);
    times.push(time);
}

void input() {
    cin >> N >> K;

    field[K] = 1;
}

void solve() {
    int answer;
    nextLoc.push(N);
    times.push(0);

    while(!nextLoc.empty()) {
        int nowLoc = nextLoc.front();
        answer = times.front();
        nextLoc.pop();
        times.pop();

        if(field[nowLoc] == 1) 
            break;
        
        field[nowLoc] = -1;
        
        movement(nowLoc - 1, answer + 1);
        movement(nowLoc + 1, answer + 1);
        movement(2 * nowLoc, answer + 1);
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