#include <iostream>
#include <queue>

using namespace std;

int N, M;
int answer = 0;
queue<pair<int, int>> nextLoc;
int field[50][50];
int wayY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int wayX[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int getDistance(int y, int x, int way, int distance) {
    // field 밖으로 벗어나면 아기 상어를 만나지 못했다고 판단
    if(x < 0 || y < 0 || x >= M || y >= N) {
        return 0;
    }
    
    // 아기 상어를 만나면 거리 return, 아니면 다음 방향으로 이동
    if(field[y][x] == 1)
        return distance;
    else {
        int safety = 100;
        // 모든 방향으로 거리 확인
        for (int k = 1; k < 9; k++) {
            int temp = getDistance(y + wayY[k], x + wayX[k], k, distance + 1);   // 아기 상어를 못 만났으면 0 return
             // 거리가 가장 작은 것을 저장(아기 상어를 못 만났으면 넘어감)
            if(temp != 0 && safety > temp) {
                safety = temp;
            }
        }
        
        if(safety != 100)
            return safety;
        else
            return 0;
    }
}

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int safety = 0;    // 안전 거리 큰 수로 초기화
            bool visited[50][50] = {false};
            queue<int> counts;
            int counting = 1;

            visited[i][j] = true;
            // 아기 상어가 없으면 거리 재기
            if(field[i][j] == 0) {
                nextLoc.push(make_pair(i, j));
                counts.push(counting);
                while(!nextLoc.empty()) {
                    int x = nextLoc.front().second;
                    int y = nextLoc.front().first;
                    nextLoc.pop();
                    // 모든 방향으로 거리 확인
                    for (int k = 0; k < 8; k++) {
                        // 범위 밖이면 패스
                        if(x + wayX[k] < 0 || y + wayY[k] < 0 || x + wayX[k] >= M || y + wayY[k] >= N)
                            continue;
                        
                        // 1 찾으면 queue 비움
                        if(field[y + wayY[k]][x + wayX[k]] == 1) {
                            safety = counts.front();
                            counts.pop();
                            nextLoc = queue<pair<int, int>>();
                            break;
                        }

                        // 방문했으면 패스
                        if(visited[y + wayY[k]][x + wayX[k]] == false) {
                            visited[y + wayY[k]][x + wayX[k]] = true;
                            nextLoc.push(make_pair(y + wayY[k], x + wayX[k]));
                            counts.push(counts.front() + 1);
                        }
                    }
                    counts.pop();
                }

                if(safety > answer)
                    answer = safety;
            }
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