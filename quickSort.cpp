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
#define rep1(i,n) for (i=1;i<=n;i++)

int a[MAX];

int partition (int arr[], int left, int right) {
	int pivotValue = arr[right];
	// swap (arr[pivotIndex], arr[right]);
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

int quickSort(int arr[], int low, int high) {
 	if (low < high) {
    	int pivotIndex = partition(arr, low, high);
    	quickSort(arr, low, pivotIndex - 1);
    	quickSort(arr, pivotIndex + 1, high);
    }
}

int main () {

	int i, n, q, k, res;

	freopen ("in.txt", "r", stdin);
	// number of elements in array
	scanf ("%d", &n);
	// array elements
	rep1 (i, n) {
		scanf ("%d", &a[i]);
	}
	// Calls the routine quickSort
	quickSort(a, 1, n);

	// print the sorted array
	printf("Sorted Array: ");
	rep1 (i, n) {
		printf("%d ", a[i]);
	}

	return 0;
}