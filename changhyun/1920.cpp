/*입력
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
모든 정수들의 범위는 int 로 한다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.*/

#include <iostream>
#include <algorithm>
using namespace std;
int A[100001] = { 0 };
int B[100001] = { 0 };
void Solution(int n, int key) {

	int start = 0;
	int end = n - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (A[mid] == key) {   //key 값이 배열의 중앙 값과 같을때
			printf("1\n");
			return;

		}
		else if (A[mid] > key) { //key 값이 배열의 중앙 값보다 작을때 (왼쪽으로)
			end = mid - 1;

		}
		else {  //key 값이 배열의 중앙 값보다 클때 (오른쪽으로)
			start = mid + 1;
		}
	}

	printf("0\n");
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a;
	cin >> a;

	for (size_t i = 0; i < a; i++)
		cin >> A[i];
	
	sort(A,A+a);

	int b;
	cin >> b;

	for (size_t i = 0; i < b; i++) {
		cin >> B[i];
		Solution(a, B[i]);
	}
}
/* 이렇게 짰는데 시간 초과가 떴다. 입력 부분에서 시간을 줄여줘야 할거같은데 어떻게 줄일지 감이 안온다.
첫번째 배열을 입력받을때 아에 배열크기를 int범위로 해서 입력을 받고 싶었는데 배열크기에는 한계가 있어서 불가능했다.*/
// 입력말고 B행렬을 입력받고 탐색을 하는 부분에서 시간을 줄여주는 문제였다.
