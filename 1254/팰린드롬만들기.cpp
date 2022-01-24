#include <iostream>
using namespace std;

string str, answer;
int tail = 0, startIdx = 0;
int endIdx;

void solve(){
    endIdx = str.size() - 1;

    while(startIdx < endIdx) {
        if(str[startIdx] == str[endIdx]){
            startIdx++;
            endIdx--;
        }
        else {
            endIdx = str.size() - 1;
            startIdx = tail + 1;
            tail++;
        }
    }

    answer = str;
    tail--;
    for (; tail >= 0; tail--){
        answer.push_back(str[tail]);
    }

    cout << answer.size();
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    solve();

    return 0;
}