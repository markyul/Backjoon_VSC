#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> meeting;

int meetingCount(int searchStart, int count) {
    if(searchStart >= N)
        return count;

    if(meeting[searchStart].first == meeting[searchStart].second) {
        searchStart += 1;
        return meetingCount(searchStart, count + 1);
    }
    else {

    int minEnd = meeting[searchStart].second;
    bool flag = false;

    for (int i = searchStart; i < N; i++) {
        if(meeting[i].first >= minEnd){
            searchStart = i;
            break;
        }
        
        if(meeting[i].second <= minEnd) {
            minEnd = meeting[i].second;
            searchStart = i;
        }
        if(i == N - 1)
            flag = true;
    }

    if(flag)
        return count + 1;

    return meetingCount(searchStart, count + 1);
}

}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meeting.push_back(pair<int, int>(start, end));
    }
}

void solve() {
    int minEnd, searchStart = 0, answer;
    int count = 1;

    sort(meeting.begin(), meeting.end());
    minEnd = meeting[0].second;

    // for (int i = 0; i < N; i++) {
    //     cout << meeting[i].first << " " << meeting[i].second << endl;
    // }

    // 가장 먼저 끝나는 회의 시간 찾기
    for (int i = 0; i < N; i++) {
        if(meeting[i].second < minEnd) {
            minEnd = meeting[i].second;
            searchStart = i;
        }
    }

    // 먼저 끝나는 회의시간 이상에 시작하는 첫 지점 찾기
    for (int i = searchStart; i < N; i++) {
        if(meeting[i].first >= minEnd) {
            if(meeting[i].first == meeting[i].second) {
                if(i != searchStart)
                    count++;
                searchStart = i + 1;
            }
            else
                searchStart = i;

            break;
        }
    }


    answer = meetingCount(searchStart, count);

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