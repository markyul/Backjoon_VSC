#include <iostream>
#include <queue>
using namespace std;

int A, B;
queue<int> nextNum, counting;

bool booling(long long num, int count) {
    if(num > B) {
        return false;
    }
    else if(num == B) {
        return true;
    }
    else {
        nextNum.push(num);
        counting.push(count);
        return false;
    }
}

bool multiple(long long num, int count) {
    num = 2 * num;

    return booling(num, count);
}

bool connectOne(long long num, int count) {
    num = 10 * num + 1;

    return booling(num, count);
}

void solve() {
    long long num;
    int count;
    bool stop;

    nextNum.push(A);
    counting.push(1);

    while(!nextNum.empty()) {
        num = nextNum.front();
        count = counting.front();
        nextNum.pop();
        counting.pop();

        stop = multiple(num, count + 1);
        if(stop) {
            count++;
            break;
        }

        stop = connectOne(num, count + 1);
        if(stop) {
            count++;
            break;
        }
    }

    if(stop)
        cout << count;
    else
        cout << -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    solve();

    return 0;
}