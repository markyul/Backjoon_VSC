#include <iostream>
#include <queue>
using namespace std;

int N, M;
int friends[101][101], friendStep[101][101];
queue<int> nextFriends;
queue<int> steps;

void input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        friends[a][b] = 1;
        friends[b][a] = 1;
    }
}

void solve() {
    int min = 200;
    int answer;

    for (int i = 1; i <= N; i++) {
        bool visited[101] = {false,};
        visited[i] = true;

        for (int j = 1; j <= N; j++) {
            if(friends[i][j] == 1) {
                nextFriends.push(j);
                steps.push(1);
                visited[j] = true;
            }
        }
        while(!nextFriends.empty()) {
            int nextFriend = nextFriends.front();
            int step = steps.front();
            friendStep[i][nextFriend] = step;
            nextFriends.pop();
            steps.pop();
            // cout << nextFriend << ": " << step << endl;

            for (int j = 1; j <= N; j++) {
                if(friends[nextFriend][j] == 1 && visited[j] == false) {
                    nextFriends.push(j);
                    steps.push(step + 1);
                    visited[j] = true;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            sum += friendStep[i][j];
        }
        if(sum < min) {
            min = sum;
            answer = i;
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