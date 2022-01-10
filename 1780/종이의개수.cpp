#include <iostream>
using namespace std;

int papers[2200][2200];
int answer[3];
int N;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> papers[i][j];
        }
    }
}

void division(int y, int x, int N) {
    int color = papers[y][x];
    bool flag = false;

    for (int i = y; i < y + N; i++){
        for (int j = x; j < x + N; j++){
            if(papers[i][j] != color){
                int cut = N / 3;
                division(y, x, cut);
                division(y, x + cut, cut);
                division(y, x + (2 * cut), cut);

                division(y + cut, x, cut);
                division(y + cut, x + cut, cut);
                division(y + cut, x + (2 * cut), cut);

                division(y + (2 * cut), x, cut);
                division(y + (2 * cut), x + cut, cut);
                division(y + (2 * cut), x + (2 * cut), cut);

                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }

    if(!flag){
        if(color == -1)
            answer[0]++;
        else if(color == 0)
            answer[1]++;
        else
            answer[2]++;
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    division(0, 0, N);

    for (int i = 0; i < 3; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}