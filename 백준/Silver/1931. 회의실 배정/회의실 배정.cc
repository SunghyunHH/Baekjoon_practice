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
	int res =0, end = 0;
    P data[N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i].x >> data[i].y;
    }
    mergesort(data, 0, n - 1);
// 여기까지 끝나는 시간으로 회의가 정렬되어있음
// 끝나는 점을 다시 시작점으로 바꿔주면서 회의의 갯수를 세기 
// 위 좌표 배열이 끝나는 시점으로 오름차순 정렬되어있으니까 끝 시간이 가장 낮은 애를 잡아가면서
// 한 회의 끝점을 시작점으로 바꿔주면서 그 분기에서 가장 끝 시간이 작은 애를 선택해나가면 됨
// 회의 시간의 시작점이 가장 가까운 애들은 고려하지 않고 끝 시간을 기준으로 봄!
	for (int i = 0; i < n; i++){
			if (data[i].x >= end){
				res +=1;
				end = data[i].y;
		}
    }
cout << res;
return 0;
}