/* 	QUICKSELECT ALGORITHM

	Finding the kth order statistic
   	using Hoare's Selection Algorithm

	Worst Case	: O(n)
	Best Case	: O(n)
	Extra Space	:  -
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <queue>
#include <deque>
#include <climits>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAX 1111111
#define MOD 10000000007
#define PI acos(-1.0)
#define rep(i,n) for (i=0;i<n;i++)

int a[MAX];

int partition (int arr[], int left, int right, int pivotIndex) {
	int pivotValue = arr[pivotIndex];
	swap (arr[pivotIndex], arr[right]);
	int storeIndex = left;
	for (int i = left; i < right ; ++i) {
		if (arr[i] < pivotValue) {
			swap (arr[storeIndex], arr[i]);
			storeIndex ++;
		}
	}
	swap (arr[right], arr[storeIndex]);
	return storeIndex;
}

int selectRecur (int arr[], int left, int right, int n) {
	if (left == right)
		return arr[left];
	int pivotIndex = floor ((left+right)/2);
	pivotIndex = partition (arr, left, right, pivotIndex);

	if (n == pivotIndex)
		return arr[n];

	else if (n < pivotIndex)
		return selectRecur (arr, left, pivotIndex-1, n);
	else
		return selectRecur (arr, pivotIndex+1, right, n);
}

int selectLoop (int arr[], int left, int right, int n) {
	if (left == right)
		return arr[left];
	for (int i = 0 ; i< n ; i++) {
		int pivotIndex = floor ((left+right)/2);
		pivotIndex = partition (arr, left, right, pivotIndex);
		if (n == pivotIndex)
			return arr[n];
		else if (n < pivotIndex)
			right = pivotIndex - 1;
		else
			left = pivotIndex + 1;
	}
	return 0;
}

int main () {

	int i, n, q, k, res;

	freopen ("in.txt", "r", stdin);
	// number of elements in array
	scanf ("%d", &n);
	// array elements
	rep (i, n) {
		scanf ("%d", &a[i]);
	}
	scanf ("%d", &q);
	while (q--) {
		// Enter the order for which kth 
		// order statistic is to be found
		scanf ("%d", &k);
		res = selectRecur(a, 0, n, k);
		printf("%d\n", res);
	}

}


