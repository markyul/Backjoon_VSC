#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[100001];
bool visited[100001];
int answer[100001];
queue<int> nextNode;

void input() {
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}  

void solve() {
    nextNode.push(1);
    visited[0] = true;
    visited[1] = true;

    while(!nextNode.empty()) {
        int node = nextNode.front();
        nextNode.pop();

        for (int i = 0; i < tree[node].size(); i++) {
            if (visited[tree[node][i]] == false) {
                nextNode.push(tree[node][i]);
                visited[tree[node][i]] = true;
                answer[tree[node][i]] = node;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
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