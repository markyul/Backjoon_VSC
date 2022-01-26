#include <iostream>
using namespace std;

int sumCount[81];
int S1, S2, S3;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxSum, answer, maxCount = 0;

    cin >> S1 >> S2 >> S3;
    maxSum = S1 + S2 + S3;

    for (int s1 = 1; s1 <= S1; s1++) {
        for (int s2 = 1; s2 <= S2; s2++) {
            for (int s3 = 1; s3 <= S3; s3++) {
                sumCount[s1 + s2 + s3]++;
            }
        }
    }

    for (int i = 3; i <= maxSum; i++) {
        if(sumCount[i] > maxCount) {
            maxCount = sumCount[i];
            answer = i;
        }
    }

    cout << answer;

    return 0;
}