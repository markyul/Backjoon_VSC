#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, deleteNode, rootNode;
int answer = 0;
vector<int> tree[51];
queue<int> nextNode;

void deleteTree() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if(tree[i][j] == deleteNode) {
                tree[i][j] = -1;
            }
        }
    }
}

void searchLeaf() {
    nextNode.push(rootNode);
    int next;

    while(!nextNode.empty()) {
        next = nextNode.front();
        nextNode.pop();

        if(tree[next].empty()) {
            answer++;
        }
        else {
            if(tree[next].size() == 1 && tree[next][0] == -1) {
                answer++;
            }
            else {
                for (int i = 0; i < tree[next].size(); i++) {
                    if(tree[next][i] == -1)
                        continue;
                    nextNode.push(tree[next][i]);
                }
            }
            
        }
    }
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int parentNode;
        cin >> parentNode;

        if(parentNode == -1) {
            rootNode = i;
            continue;
        }

        tree[parentNode].push_back(i);
    }

    cin >> deleteNode;
}

void solve() {
    if(deleteNode == rootNode) {
        cout << 0;
    }
    else {
        deleteTree();
        searchLeaf();

        cout << answer;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}