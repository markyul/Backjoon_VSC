#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int heap[270000];
int maxIdx = 1;
vector<pair<int, int>> lesson;

void insertHeap(int num, int end) {
    heap[end] = num;
    int idx = end;

    // 루트 전까지 반복하면서 노드 교환
    while(idx > 1) {
        int parent = idx / 2;
        // 부모 노드가 자식 노드보다 더 크면 노드 교환
        if(heap[parent] > heap[idx]) {
            int temp = heap[parent];
            heap[parent] = heap[idx];
            heap[idx] = temp;
            idx = parent;
        }
        else {
            break;
        }
    }
}

void deleteHeap(int end) {
    // 루트 노드와 마지막 노드 교환 후 마지막 노드 삭제
    int idx = 1;
    heap[1] = heap[end];
    heap[end] = 0;
    // while문을 위한 높이 조정
    if(end - 1 < maxIdx / 2)
        maxIdx = maxIdx / 2;

    while(idx * 2 < maxIdx) {
        if(heap[idx * 2] == 0 && heap[idx * 2 + 1] == 0)
            break;

        int child;
        // 자식 중 작은 노드 또는 혼자 있는 노드 선택
        if(heap[idx * 2 + 1] == 0)
            child = idx * 2;
        else {
            child = heap[idx * 2] < heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
        }

        if(heap[idx] > heap[child]) {
            int temp = heap[idx];
            heap[idx] = heap[child];
            heap[child] = temp;
            idx = child;
        }
        else {
            break;
        }
    }
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        lesson.push_back(pair<int, int>(start, end));
    }
}

void solve() {
    int answer = 0;
    int end = 1;
    sort(lesson.begin(), lesson.end());
    insertHeap(lesson[0].second, end);
    end++;
    if(end - 1 >= maxIdx) {
        maxIdx = maxIdx * 2;
    }

    for (int i = 1; i < N; i++) {
        // 힙 가장 위의 시간이 시작 시간보다 크면 그냥 추가
        if(heap[1] > lesson[i].first) {
            insertHeap(lesson[i].second, end);
            end++;
            if(end - 1 >= maxIdx) {
                maxIdx = maxIdx * 2;
            }
        }
        else {
            // 아니면 pop후 추가
            deleteHeap(end - 1);
            if(end > 1)
                end--;

            insertHeap(lesson[i].second, end);
            end++;
            if(end - 1 >= maxIdx) {
                maxIdx = maxIdx * 2;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if(heap[i] == 0) {
            answer = i - 1;
            break;
        }
    }

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