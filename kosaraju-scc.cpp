Let G be a directed graph and S be an empty stack.
While S does not contain all vertices:
Choose an arbitrary vertex v not in S. Perform a depth-first search starting at v. Each time that depth-first search finishes expanding a vertex u, push u onto S.
Reverse the directions of all arcs to obtain the transpose graph.
While S is nonempty:
Pop the top vertex v from S. Perform a depth-first search starting at v in the transpose graph. The set of visited vertices will give the strongly connected component containing v; record this and remove all these vertices from the graph G and the stack S. Equivalently, breadth-first search (BFS) can be used instead of depth-first search.

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>

using namespace std;

// From TopCoder
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define rep(i,n) for (i=0; i<n ; i++)
#define rep1(i,n) for (i=1; i<=n ; i++)
#define MAX 11111

int n, e; // number of vertices, edges
vi g[MAX]; // lists of adjacent vertices

bool dfs(int start_vertex) {
	int i, u, v, len;
    vi visited(n+1, false);
    stack <int> S;
    S.push(start_vertex);
    while (!S.empty()) {
        u = S.top();
        S.pop();
        cout << u << " ";
        if (!(visited[u])) {
            visited[u] = true;
            tr(g[u], it) { 
                S.push(*it);
            }
        }
    }
}


int main () {

	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &e);
	int i, u, v;
	rep(i,e) {
		scanf("%d%d", &u, &v);
		cout << u <<" --> " << v << "\n";
		g[u].push_back(v);
	}
	
	//Traverse the given graph from vertex-0
	dfs(1);
	
	return 0;
}

/*
Sample:

5	// vertices
1 3
2 1
3 2
1 4
4 5

SCC:

5
4
1 2 3
*/