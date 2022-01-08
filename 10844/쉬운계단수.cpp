#include <iostream>
using namespace std;

int dp[101][11];
int N;

void input() {
    cin >> N;

    for (int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
}

void solve() {
    int answer = 0;
    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 10; j++){
            if(j == 0){
                dp[i][j] = dp[i - 1][j + 1];
            }
            else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    for (int j = 1; j < 10; j++){
        answer = (answer + dp[N][j]) % 1000000000;
    }

    cout << answer;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}