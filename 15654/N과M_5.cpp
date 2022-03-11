#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool visited[9];
vector<int> answer;

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve(int ordered) {
    if(ordered > M) {
        for(int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i] == false) {
            answer.push_back(arr[i]);
            visited[i] = true;

            solve(ordered + 1);

            answer.pop_back();
            visited[i] = false;
        }
        
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    sort(arr, arr + N);

    solve(1);

    return 0;
}