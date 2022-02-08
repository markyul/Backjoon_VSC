#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, X;
vector<int> way[300001], answer;
queue<int> nextCity, counting;
bool visited[300001];

void input() {
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int start, end;

        cin >> start >> end;

        way[start].push_back(end);
    }
}

void solve() {
    int count = 0;
    int city = X;
    nextCity.push(city);
    counting.push(count);
    visited[city] = true;

    while (!nextCity.empty() && count <= K) {
        city = nextCity.front();
        count = counting.front();
        nextCity.pop();
        counting.pop();

        for (int i = 0; i < way[city].size(); i++) {
            if(!visited[way[city][i]]) {
                nextCity.push(way[city][i]);
                counting.push(count + 1);
                visited[way[city][i]] = true;
            }
        }

        if(count == K) {
            answer.push_back(city);
        }
    }

    if(answer.size() == 0) {
        cout << -1;
    }
    else {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << "\n";
        }
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