#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool field[101][101];
int M, N, K;
int answer = 0;
int area = 1;
vector<int> areas;

void infection(int y, int x) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return;
	
	if (field[y][x] == false) {
		area++;
		field[y][x] = true;
		infection(y, x + 1);
		infection(y - 1, x);
		infection(y, x - 1);
		infection(y + 1, x);
	}
}

void input() {
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		// 모눈종이 색칠
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				field[y][x] = true;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!field[i][j]) {
				answer++;
				field[i][j] = true;
				infection(i, j + 1);
				infection(i - 1, j);
				infection(i, j - 1);
				infection(i + 1, j);
				areas.push_back(area);
				area = 1;
			}
		}
	}
	sort(areas.begin(), areas.end());

	cout << answer << "\n";
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << " ";
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