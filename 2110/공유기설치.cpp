#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int house[200001];

// 설치를 다 못했으면 false 반환
bool isInstall(int interval, int num) {
    bool flag = false;
    int next = 0;
    int install = house[0] + interval;

    for (int i = 0; i < num; i++) {
        // 설치를 다 못했을 경우
        if(install > house[N - 1]) {
            flag = true;
            break;
        }

        for (int j = next; j < N; j++)
        {
            // 집의 좌표가 앞 집 좌표 + 간격 보다 크거나 같으면 다음 설치할 집
            if (house[j] >= install)
            {
                install = house[j] + interval;
                next = j + 1;
                break;
            }
        }
    }

    if(flag)
        return false;
    else
        return true;
}

int binarySearch(int start, int end, int num) {
    int mid = (start + end) / 2;
    int firstHouse = house[0];
    int lastHouse = house[N - 1];
    bool success;

    while(start + 1 < end) {
        mid = (start + end) / 2;
        if(isInstall(mid, num))
            start = mid;
        else
            end = mid;
    }

    return start;
}

void input() {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }
}

void solve() {
    int start, end;
    int answer = 0;
    sort(house, house + N);

    start = 1;
    end = (house[N - 1] - house[0]) / (C - 1);

    if(C == 2){
        answer = house[N - 1] - house[0];
        cout << answer;
    }
    else {
        if(isInstall(end, C - 1))
            answer = end;
        else {
            answer = binarySearch(start, end, C - 1);
        }
        cout << answer;
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