#include <iostream>
#include <algorithm>
#include<queue>
#include<cstdlib>
using namespace std;
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            if (a > b) return true;
            else return false;
        }
        else {
            if (abs(a) > abs(b)) return true;
            else return false;
        }
    }
};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int t;
    // 절대힙
    priority_queue<int, vector<int>, cmp> pq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t == 0) {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(t);
        }
    }
    return 0;
}