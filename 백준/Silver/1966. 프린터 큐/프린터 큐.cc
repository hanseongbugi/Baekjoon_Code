#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Element {
    int priority;
    int value;
} Element;

bool bigger(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        queue<Element> q;
        vector<int> p;
        int N, M;
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            Element e;
            e.priority = input;
            e.value = j;
            q.push(e);
            p.push_back(input);
        }
        sort(p.begin(), p.end(), bigger);
        
        int maxIndex = 0;

        int max = p[maxIndex];
        int find = -1;
        int count = 0;
        while (M != find) {
            Element e = q.front();
            q.pop();
            if (e.priority < max) {
                q.push(e);
            }
            else {
                count += 1;
                find = e.value;
                maxIndex += 1;
                if (maxIndex < p.size())
                    max = p[maxIndex];
                else
                    break;
            }
        }
        cout << count << '\n';

    }
}