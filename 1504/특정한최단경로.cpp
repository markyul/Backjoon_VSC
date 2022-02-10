#include <iostream>
using namespace std;

int N, E, v1, v2;
int weightWay[801][801];
int shortest[3][801];

void dijkstra(int n, int vertex) {
    bool visited[801] = {false,};
    shortest[n][vertex] = 0;
    visited[vertex] = true;

    while(vertex != 0) {
        // 가중치 수정
        for (int i = 1; i <= N; i++) {
            // 처음 가중치 설정
            if(shortest[n][i] == -1 && weightWay[vertex][i] != 0) {
                shortest[n][i] = weightWay[vertex][i] + shortest[n][vertex];
            }
            // 이미 가중치가 있으면 더 작은 가중치 있는지 찾기
            if(shortest[n][i] > 0 && weightWay[vertex][i] != 0) {
                if(shortest[n][vertex] + weightWay[vertex][i] < shortest[n][i])
                    shortest[n][i] = shortest[n][vertex] + weightWay[vertex][i];
            }
        }

        int nextMin = -1;
        vertex = 0;
        // 다음 정점 정하기
        for (int i = 1; i <= N; i++) {
            if(visited[i] == false && shortest[n][i] > 0) {
                if(nextMin == -1 || nextMin > shortest[n][i]) {
                    nextMin = shortest[n][i];
                    vertex = i;
                }
            }
        }
        visited[vertex] = true;
    }
}

void input() {
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        weightWay[a][b] = c;
        weightWay[b][a] = c;
    }

    cin >> v1 >> v2;
}

void solve() {
    int distance1, distance2;
    bool connect = true;
    fill(&shortest[0][0], &shortest[3][801], -1);   // -1 로 초기화

    dijkstra(0, 1);
    dijkstra(1, v1);
    dijkstra(2, v2);

    distance1 = shortest[0][v1] + shortest[1][v2] + shortest[2][N];
    distance2 = shortest[0][v2] + shortest[2][v1] + shortest[1][N];

    if(shortest[0][v1] == -1 && shortest[0][v2] == -1){
        connect = false;
    }
    else if(shortest[0][v1] > -1 && shortest[1][N] == -1){
        connect = false;
    }
    else if(shortest[0][v2] > -1 && shortest[2][N] == -1){
        connect = false;
    }

    if(connect) {
        if(distance1 < distance2)
            cout << distance1;
        else
            cout << distance2;
    }
    else {
        cout << -1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}