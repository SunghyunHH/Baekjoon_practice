#include <iostream>
using namespace std;
string wb[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string bw[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];

// 현재 문제는 같은 값인데도 왜 다르다고 나올까?
int wb_check(int h, int w){
	int score =0;
	for (int i =0; i<8; i++){
		for (int j=0; j<8; j++){
			if (wb[i][j] != board[i+h][j+w]){
				score++;
			}
		}
	}
	return score;
}
int bw_check(int h, int w){
	int score =0;
	for (int i =0; i<8; i++){
		for (int j=0; j<8; j++){
			if (bw[i][j] != board[i+h][j+w]){
				score++;
			}
		}
	}
	return score;
}
int main(){
    int n, m;
	int min = 2500;
	int tmp = 0;
    cin >> n >> m;

    // board 만들기
    for (int i = 0 ; i<n; i++){
			cin >> board[i];
		} 	

	for (int h =0; h<=n-8; h++){
		for (int w =0; w<=m-8; w++){
			int br = bw_check(h, w);
			int wr = wb_check(h, w);
			tmp = (br >= wr) ? wr : br;
			min = (min >= tmp) ? tmp : min;
		}
	}
	cout << min;
    return 0;
}