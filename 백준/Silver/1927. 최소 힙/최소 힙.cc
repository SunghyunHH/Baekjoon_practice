#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    unsigned int t;
    // 최소 힙
    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t)
            pq.push(t);
        else {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}