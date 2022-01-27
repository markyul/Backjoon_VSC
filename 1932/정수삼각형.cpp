#include <iostream>
using namespace std;

int N;
int triangle[501][501], sum[501], dp[501];

void input() {
    int width = 1;

    cin >> N;

    while(width <= N) {
        for (int i = 1; i <= width; i++) {
            cin >> triangle[width][i];
        }
        width++;
    }
}

void solve() {
    int width = 1;
    int answer = 0;

    while(width <= N) {
        for (int i = 1; i <= width; i++) {
            sum[i] = dp[i - 1] < dp[i] ? dp[i] + triangle[width][i] : dp[i - 1] + triangle[width][i];
        }
        for (int i = 1; i <= width; i++) {
            dp[i] = sum[i];
        }
        width++;
    }

    for (int i = 1; i <= N; i++) {
        if(answer < sum[i])
            answer = sum[i];
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