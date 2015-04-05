// Building a Max Heap and Min Heap

#include <iostream>
#include <cstdio>
#include <string>
#include <utility> // pair
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> //memset
using namespace std;
  
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define PRINTesent(c,x) ((c).find(x) != (c).end()) 
#define cPRINTesent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define rep(i,n) for (i=0; i<n ; i++)
#define rep1(i,n) for (i=1; i<=n ; i++)
#define MAX 1111111

#define parent(i) (i/2)
#define left(i) (2*i)
#define right(i) (2*i)+1

int a[MAX];
int N;

void PRINT(int a[], int i) {

    if(i<=N/2) {
        for (int k = 1;k<=log2(2*i);k++)
            cout << "  |";
        cout << a[2*i] << "\n";
        PRINT(a, 2*i);
        for (int k = 1;k<=log2(2*i+1);k++)
            cout << "  |";
        cout << a[2*i+1] << "\n";
        PRINT(a,2*i+1);
    }
}

void maxHeapify(int a[], int i) {

    int l, r, largest, j;

    l = left(i);
    r = right(i);
    if(l <= N && a[l] > a[i])
        largest = l;
    else largest = i;
    if(r <= N && a[r] > a[largest])
        largest = r;
    if(largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, largest);
    }
}

void buildMaxHeap(int a[]) {    
    for (int i = N/2 ; i >0 ; i--)
        maxHeapify(a, i);
}

void minHeapify(int a[], int i) {

    int l, r, smallest, j;

    l = left(i);
    r = right(i);
    if(l <= N && a[l] < a[i])
        smallest = l;
    else smallest = i;
    if(r <= N && a[r] < a[smallest])
        smallest = r;
    if(smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, smallest);
    }
}

void buildMinHeap(int a[]) {
    
    for (int i = N/2 ; i >0 ; i--)
        minHeapify(a, i);
}

int main() {

    freopen ("in.txt", "r", stdin);
    int i;
    cin >> N;
    rep1(i, N) cin >> a[i];
    
    cout << "INPUT:\n" << a[1] << "\n";
    PRINT(a, 1);
    
    cout << "\n+++++\nMax-Heap:\n";
    buildMaxHeap(a);
    cout << a[1] << "\n";
    PRINT(a, 1);

    cout << "\n+++++\nMin-Heap:\n";
    buildMinHeap(a);
    cout << a[1] << "\n";
    PRINT(a, 1);

    return 0;
}


/*

10
4 1 3 2 16 9 10 14 8 7


INPUT:
4
  |1
  |  |2
  |  |  |14
  |  |  |8
  |  |16
  |  |  |7
  |  |  |0
  |3
  |  |9
  |  |10

+++++
Max-Heap:
16
  |14
  |  |8
  |  |  |2
  |  |  |4
  |  |7
  |  |  |1
  |  |  |0
  |10
  |  |9
  |  |3

+++++
Min-Heap:
1
  |2
  |  |4
  |  |  |8
  |  |  |16
  |  |7
  |  |  |14
  |  |  |0
  |3
  |  |9
  |  |10


*/