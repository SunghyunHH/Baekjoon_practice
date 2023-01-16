// https://bloodstrawberry.tistory.com/182 를 통해 공부했음
#include <iostream>
#define MAX (1000000 + 10000)
using namespace std;
int T;
// 들어오는 대로 그냥 저장하기 위한 배열
typedef struct st1 {
	int value;
	int deleteFlag; // data의 삭제 여부를 확인
}DATA;

DATA d[MAX];
// data의 수 확인용
int dcnt;

typedef struct st2 {
	int value;
	int dataIdx; // DATA 배열에서의 index
}HEAP;
HEAP minHeap[MAX];
int minHn; // 최소 힙에서의 데이터 갯수

HEAP maxHeap[MAX];
int maxHn; // 최대 힙에서의 데이터 갯수
// hn을 지역 변수로 만들어 놓을 것이기 때문에 주소값을 참조함
HEAP maxPop(HEAP* heap, int& hn) {
	HEAP tmp, ret;
	/* 최대값이 배열의 첫번째에 위치하고 있음 그래서 pop연산 수행시 마지막 인덱스에 있는 값을
	첫번째 인덱스로 올리고 최대값을 삭제해주는 방식*/
	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--].value = 0x80000000; /* -2147483648 */
	/* 앞서 최대값을 삭제하고 맨 마지막 노드를 맨 앞 노드로 올린 후 비교 연산을 통해 힙구조 완성*/
	for (int i = 1; i * 2 <= hn;) {
		if (heap[i].value > heap[i * 2].value && heap[i].value > heap[i * 2 + 1].value) { break; }
		else if (heap[i * 2].value > heap[i * 2 + 1].value) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;
			// 값 변환 후 그 밑의 자식 노드와의 비교 연산을 위함
			i = i * 2;
		}
		else {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;
			i = i * 2 + 1;
		}
	}
	return ret;
}
void maxPush(HEAP* heap, int& hn, HEAP x) {
	HEAP tmp;
	/* push 연산은 맨 마지막 노드에 우선 값을 추가하고 비교연산을 통해 상위 노드와의 위치를 변경해나감 */
	heap[++hn] = x;

	for (int i = hn; i > 1; i /= 2) {
		if (heap[i / 2].value > heap[i].value) { break; }
		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}
HEAP minPop(HEAP* heap, int& hn)
{
	HEAP tmp, ret;

	ret = heap[1];
	heap[1] = heap[hn];
	heap[hn--].value = 0x7fffffff; /* 2147483647 */

	for (int i = 1; i * 2 <= hn;)
	{
		if (heap[i].value < heap[i * 2].value && heap[i].value < heap[i * 2 + 1].value) break;
		else if (heap[i * 2].value < heap[i * 2 + 1].value)
		{
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;
			i = i * 2;
		}
		else
		{
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;
			i = i * 2 + 1;
		}
	}

	return ret;
}
void minPush(HEAP* heap, int& hn, HEAP x)
{
	HEAP tmp;

	heap[++hn] = x;

	for (int i = hn; i > 1; i /= 2)
	{
		if (heap[i / 2].value < heap[i].value) break;

		tmp = heap[i / 2];
		heap[i / 2] = heap[i];
		heap[i] = tmp;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int k, dataCount;
		cin >> k;
		/* data, heap, 실제 존재하는 data 초기화 */
		dcnt = minHn = maxHn = dataCount = 0;
		for (int i = 0; i < k; i++) {
			char command;
			int value;
			cin >> command >> value;
			if (command == 'I') {
				d[dcnt].value = value;
				d[dcnt].deleteFlag = 0; // 삭제 여부 초기화
				maxPush(maxHeap, maxHn, { value, dcnt }); // 구조체니까 {a,b}로 전달
				minPush(minHeap, minHn, { value, dcnt });
				dcnt++;
				dataCount++;
			}
			// D연산
			else {
				// Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시
				if (dataCount == 0) {
					maxHn = minHn = 0;
					continue;
				}
				/* 우선순위가 높은 data가 삭제되었으면 불필요하므로 제거 */
				/* pop 연산을 수행하면 pop되는 값 return을 해주고 또 힙에서 가장 첫번째 노드가 바뀜*/
				while (d[maxHeap[1].dataIdx].deleteFlag) maxPop(maxHeap, maxHn);
				while (d[minHeap[1].dataIdx].deleteFlag) minPop(minHeap, minHn);
				dataCount--;

				HEAP tmp;
				// 최대값 삭제
				if (value == 1) {
					tmp = maxPop(maxHeap, maxHn);
					d[tmp.dataIdx].deleteFlag = 1;
				}
				// 최소값 삭제
				else {
					tmp = minPop(minHeap, minHn);
					d[tmp.dataIdx].deleteFlag = -1;
				}
			}
		}
		// 결과 값 출력
		if (dataCount)
		{
			/* 우선순위가 높은 data가 삭제되었으면 불필요하므로 제거 */
			while (d[maxHeap[1].dataIdx].deleteFlag) maxPop(maxHeap, maxHn);
			while (d[minHeap[1].dataIdx].deleteFlag) minPop(minHeap, minHn);

			HEAP maxValue = maxPop(maxHeap, maxHn);
			HEAP minValue = minPop(minHeap, minHn);

			printf("%d %d\n", maxValue.value, minValue.value);
		}
		else
			printf("EMPTY\n");
	}
	return 0;
}