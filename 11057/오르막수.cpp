#include <iostream>
using namespace std;

int N;
long long dp[1001][10];

void solve(){
    long long sum = 0;
    dp[0][9] = 1;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j < 10; j++){
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] = dp[i][j] % 10007;
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += dp[N][i];
    }
    sum = sum % 10007;
    cout << sum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solve();

    return 0;
}