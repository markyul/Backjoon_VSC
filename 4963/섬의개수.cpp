#include <iostream>
using namespace std;

int field[50][50];
// 상, 우상, 우, 우하, 하, 좌하, 좌, 좌상
int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void connected(int w, int h, int maxW, int maxH) {
    if(w < 0 || h < 0 || w >= maxW || h >= maxH)
        return;

    if(field[h][w] == 1) {
        field[h][w] = 0;
        for (int k = 0; k < 8; k++) {
            connected(w + x[k], h + y[k], maxW, maxH);
        }
    }
}

int searchIsland(int w, int h) {
    int count = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(field[i][j] == 1) {
                count++;
                field[i][j] = 0;
                for (int k = 0; k < 8; k++) {
                    connected(j + x[k], i + y[k], w, h);
                }
            }
        }
    }

    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h, answer;

    cin >> w >> h;

    while(w != 0 || h !=0 ) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> field[i][j];
            }
        }

        answer = searchIsland(w, h);

        cout << answer << "\n";

        cin >> w >> h;
    }

    return 0;
}