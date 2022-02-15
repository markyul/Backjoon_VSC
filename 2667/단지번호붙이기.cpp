#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int field[25][25];
// 상, 우, 하, 좌
int wayX[4] = {0, 1, 0, -1};
int wayY[4] = {-1, 0, 1, 0};

int searchHome(int x, int y, int count) {
    if(x < 0 || y < 0 || x >= N || y >= N) {
        return count;
    }

    if(field[y][x] == 1) {
        field[y][x] = 0;
        count++;
        for (int i = 0; i < 4; i++) {
            count += searchHome(x + wayX[i], y + wayY[i], 0);
        }
    }
    else {
        return count;
    }

    return count;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            field[i][j] = str[j] - 48;
        }
    }
}

void solve() {
    int homeCount;
    vector<int> homeCounts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(field[i][j] == 1) {
                homeCount = searchHome(j, i, 0);
                homeCounts.push_back(homeCount);
            }
        }
    }

    sort(homeCounts.begin(), homeCounts.end());
    cout << homeCounts.size() << "\n";
    for (int i = 0; i < homeCounts.size(); i++) {
        cout << homeCounts[i] << "\n";
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