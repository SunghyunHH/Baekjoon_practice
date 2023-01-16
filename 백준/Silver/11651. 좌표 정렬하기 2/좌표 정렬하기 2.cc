#include <iostream>
using namespace std;
#define N 100001
typedef struct Point {
    int x;
    int y;
}P;
P sorted[N];

void merge(P arr[], int s, int m, int e) {
    int k1 = s;
    int k2 = m + 1;
    int z = s;

    while (k1 <= m && k2 <= e) {
        if (arr[k1].y < arr[k2].y) {
            sorted[z] = arr[k1];
            k1++;
        }
        else if (arr[k1].y > arr[k2].y) {
            sorted[z] = arr[k2];
            k2++;
        }
        // x가 같은 경우 y를 비교해야함!
        else {
            if (arr[k1].x < arr[k2].x) {
                sorted[z] = arr[k1];
                k1++;
            }
            else {
                sorted[z] = arr[k2];
                k2++;
            }
        }
        z++;
    }
    // 좌측 배열에서 다 나온 경우
    if (k1 > m) {
        for (int a = k2; a <= e; a++) {
            sorted[z] = arr[a];
            z++;
        }
    }
    // 우측 배열에서 다 나온 경우
    else {
        for (int a = k1; a <= m; a++) {
            sorted[z] = arr[a];
            z++;
        }
    }
    for (int a = s; a <= e; a++) {
        arr[a] = sorted[a];
    }
}

void mergesort(P arr[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergesort(arr, s, m);     // 좌측 정렬
        mergesort(arr, m + 1, e); // 우측 정렬
        merge(arr, s, m, e);
    }
}

int main() {
    int n;
    P data[N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i].x >> data[i].y;
    }
    mergesort(data, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << sorted[i].x << ' ' << sorted[i].y << '\n';
    }
    return 0;
}