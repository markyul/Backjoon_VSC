#include <iostream>
using namespace std;

int N;
int heap[100001];
int maxIdx = 1;

void insertHeap(int num, int end) {
    heap[end] = num;
    int idx = end;

    // 루트 전까지 반복하면서 노드 교환
    while(idx > 1) {
        int parent = idx / 2;
        // 부모 노드가 자식 노드보다 더 크면 노드 교환
        if(heap[parent] < heap[idx]) {
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
    // 일단 출력
    if(heap[1] == 0) {
        cout << 0 << "\n";
        return;
    }
    else {
        cout << heap[1] << "\n";
    }

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
            child = heap[idx * 2] > heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
        }

        if(heap[idx] < heap[child]) {
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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    int end = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;

        if(x > 0){
            insertHeap(x, end);
            end++;

            if(end - 1 >= maxIdx) {
                maxIdx = maxIdx * 2;
            }
        }
        else {
            deleteHeap(end - 1);
            if(end > 1)
                end--;
        }
    }

        return 0;
}