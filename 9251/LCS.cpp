#include <iostream>

using namespace std;

string word1, word2;
int dp[1001][1001];

int LCSCount() {
    for (int i = 1; i < word2.size(); i++) {
        for (int j = 1; j < word1.size(); j++) {
            // 문자가 같으면 그 전까지 가장 길었던 LCS의 수 + 1
            if(word1[j] == word2[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // 문자가 다르면 그 전까지 가장 길었던 LCS의 수를 가져간다.
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[word2.size() - 1][word1.size() - 1];
}

void input() {
    string temp1, temp2;
    cin >> temp1 >> temp2;

    word1.push_back('0');
    word2.push_back('1');

    for (int i = 0; i < temp1.size(); i++) {
        word1.push_back(temp1[i]);
    }

    for (int i = 0; i < temp2.size(); i++) {
        word2.push_back(temp2[i]);
    }
}

void solve() {
    int answer = LCSCount();

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