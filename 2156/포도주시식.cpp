#include <iostream>
using namespace std;

int dp[3][10010], wine[10010] , N;

void input(){
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> wine[i];
    }
}

void solve(){
    int idx = N;
    int answer;

    dp[0][1] = 0;
    dp[1][1] = wine[1];
    dp[2][1] = wine[1];

    for (int i = 2; i <= N; i++) {
        // 안먹을 경우 그 전까지 먹은 양 중 가장 많은 양
        int temp = dp[0][i - 1] > dp[1][i - 1] ? dp[0][i - 1] : dp[1][i - 1];
        dp[0][i] = temp > dp[2][i - 1] ? temp : dp[2][i - 1];

        // 1번 먹을 경우 그 전전 양 중 가장 많은 양과 합
        temp = dp[0][i - 2] > dp[1][i - 2] ? dp[0][i - 2] : dp[1][i - 2];
        dp[1][i] = wine[i] + (temp > dp[2][i - 2] ? temp : dp[2][i - 2]);

        // 2번 먹을 경우 그 전의 1번 먹은 양과 합
        dp[2][i] = wine[i] + dp[1][i - 1];
    }

    answer = dp[0][N] > dp[1][N] ? dp[0][N] : dp[1][N];
    answer = answer > dp[2][N] ? answer : dp[2][N];

    cout << answer;
}

int main(void){
    ios_base::sync_with_stdio(false);

    input();
    solve();

    return 0;
}