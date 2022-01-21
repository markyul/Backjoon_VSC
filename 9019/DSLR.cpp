#include <iostream>
#include <queue>
using namespace std;

int A, B;
queue<int> nextNum, counts;
queue<string> commands;
bool visited[10001];

int commandD(int n, string command) {
    int result = (n * 2) % 10000;
    // 방문 안했으면
    if(!visited[result]) {
        visited[result] = true;
        command = command + "D";
        commands.push(command);

        return result;
    }
    else
        return -1;
}

int commandS(int n, string command) {
    int result;
    if(n == 0)
        result = 9999;
    else 
        result = n - 1;

    if(!visited[result]) {
        visited[result] = true;
        command = command + "S";
        commands.push(command);

        return result;
    }
    else
        return -1;

}

int commandL(int n, string command) {
    int result = n / 1000;
    int temp = n % 1000;

    result = (temp * 10) + result;

    if(!visited[result]) {
        visited[result] = true;
        command = command + "L";
        commands.push(command);

        return result;
    }
    else
        return -1;

}

int commandR(int n, string command) {
    int result = n / 10;
    int temp = n % 10;

    result = result + (temp * 1000);

    if(!visited[result]) {
        visited[result] = true;
        command = command + "R";
        commands.push(command);

        return result;
    }
    else
        return -1;

}

void solve() {
    string answer;

    nextNum.push(A);
    counts.push(0);
    commands.push("");
    visited[A] = true;

    while(1) {
        int result;
        int next = nextNum.front();
        int counting = counts.front();
        string command = commands.front();
        nextNum.pop();
        counts.pop();
        commands.pop();

        result = commandD(next, command);
        if(result != -1) {
            if(result == B) {
                answer = command + "D";
                break;
            }
            else {
                nextNum.push(result);
                counts.push(counting + 1);
            }
        }

        result = commandS(next, command);
        if(result != -1) {
            if(result == B) {
                answer = command + "S";
                break;
            }
            else {
                nextNum.push(result);
                counts.push(counting + 1);
            }
        }

        result = commandL(next, command);
        if(result != -1) {
            if(result == B) {
                answer = command + "L";
                break;
            }
            else {
                nextNum.push(result);
                counts.push(counting + 1);
            }
        }

        result = commandR(next, command);
        if(result != -1) {
            if(result == B) {
                answer = command + "R";
                break;
            }
            else {
                nextNum.push(result);
                counts.push(counting + 1);
            }
        }
    }

    cout << answer << "\n";

    nextNum = queue<int>();
    counts = queue<int>();
    commands = queue<string>();
    fill_n(visited, 10000, false);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        solve();
    }

    return 0;
}