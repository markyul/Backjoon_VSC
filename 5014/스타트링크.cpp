#include <iostream>
#include <queue>
using namespace std;

bool visit[1000001];
queue<int> nextLoc;
queue<int> nextCount;

int F, S, G, U, D;
int answer = -1;

void move(int location, int counting) {
    if (location == G) {
        answer = counting;
        return;
    }

    if(visit[location]) {
        return;
    }
    else {
        visit[location] = true;
    }

    int up = location + U;
    int down = location - D;

    if(up <= F) {
        nextLoc.push(up);
        nextCount.push(counting + 1);
    }
    if(down > 0) {
        nextLoc.push(down);
        nextCount.push(counting + 1);
    }
}

void input(){
    cin >> F >> S >> G >> U >> D;
}

void solve(){
    while(!nextLoc.empty()){
        int nextFloor = nextLoc.front();
        int counting = nextCount.front();
        nextLoc.pop();
        nextCount.pop();

        move(nextFloor, counting);

        if(answer != -1)
            break;
    }

    if(answer == -1) {
        cout << "use the stairs";
    }
    else {
        cout <<  answer;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    nextLoc.push(S);
    nextCount.push(0);
    solve();

    return 0;
}