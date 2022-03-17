#include <iostream>
using namespace std;

int T, N;
int stickers[2][100000], dp[2][100000];

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> stickers[0][i];
    }
    for(int i = 0; i < N; i++) {
        cin >> stickers[1][i];
    }
}

void solve() {
    int answer;
    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];

    if(N > 1) {
        dp[0][1] = stickers[1][0] + stickers[0][1];
        dp[1][1] = stickers[0][0] + stickers[1][1];

        for(int i = 2; i < N; i++) {
            for(int j = 0; j < 2; j++) {
                int row = (j + 1) % 2;
                dp[j][i] = dp[row][i - 2] > dp[row][i - 1] ? dp[row][i - 2] + stickers[j][i] : dp[row][i - 1] + stickers[j][i];
            }
        }
    }

    answer = dp[0][N - 1] > dp[1][N - 1] ? dp[0][N - 1] : dp[1][N - 1];

    cout << answer << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; i++) {
        input();
        solve();
    }

    return 0;
}