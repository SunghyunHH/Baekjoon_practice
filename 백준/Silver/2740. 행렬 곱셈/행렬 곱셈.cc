#include <iostream>
using namespace std;
// 곱하는 위치를 어떻게 맞춰줄 것인가?

int matrix_A[101][101];
int matrix_B[101][101];
int matrix_C[101][101];

int main(){
	int N, M, K;
	cin >> N >> M;
	// step 1 배열 만들기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix_A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> matrix_B[i][j];
		}
	}
	// step 2 배열 곱 위치 맞춰주기 -> 일반적인 알고리즘으로는 반복문 3번 사용(N에 관해 한번, M에 관해 한번, K에 관해 한번)
	// matrix_C의 인덱스는 N,K // M이 같아야 연산 수행이 가능
	int tmp;
	for (int i =0; i<N; i++ ) {
		for (int z = 0; z<K; z++){
			tmp = 0;
			for (int j=0; j < M; j++){
				 tmp += matrix_A[i][j] * matrix_B[j][z];
			}
			matrix_C[i][z] = tmp;
		}		 
	}
	// step 3 C 배열 출력
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			cout << matrix_C[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}