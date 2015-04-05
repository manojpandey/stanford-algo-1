/*
Author 		:	manojpandey
Algorithm	:	Kosraju's Two Pass Algorithm for
				finding strongly connected components
				in a graph

		1. Let G be a directed graph and S be an empty stack.
		2. While S does not contain all vertices:
		3.		Choose an arbitrary vertex v not in S. Perform a depth-first search starting at v. Each time that depth-first search finishes expanding a vertex u, push u onto S.
		4. Reverse the directions of all arcs to obtain the transpose graph.
		5. While S is nonempty:
		6. 		Pop the top vertex v from S. Perform a depth-first search starting at v in the transpose graph. The set of visited vertices will give the strongly connected component containing v; record this and remove all these vertices from the graph G and the stack S. Equivalently, breadth-first search (BFS) can be used instead of depth-first search.

Time Complexity	:	O(V+E) <-- Optimal
					O(V^2) , if adjacency matrix is used
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
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

// Assuming vertices are labeled 0...V-1
vi G[MAX], Grev[MAX];
bool explored[MAX];
int leader[MAX], finish[MAX], order[MAX], t = -1, parent = 0, V, E;

// running DFS on the reverse graph
void dfs_reverse(int i) {
    explored[i] = true;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}

// running DFS on the actual graph
void dfs(int i) {
    explored[i] = true;
    leader[i] = parent;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++) {
        cout << *it << " "; 
        if(!explored[*it]) {
            dfs(*it);
        }
    }
    cout << "\n";
}

// check if u & v are in the same connected component
bool stronglyConnected(int u, int v)    {
    return leader[u] == leader[v];
}

int main()  {
    int i, u, v, countCC, Q;

    //freopen("input.txt", "r", stdin);

    scanf("%d %d", &V, &E); // Enter the number of vertices & edges
    for(i=0; i<E; i++)  {   // Enter E edges : u -> v
        scanf("%d %d", &u, &v);
        G[u].push_back(v);  // Insert into the adjacency list of the graph
        Grev[v].push_back(u);   // and the reverse graph
    }

    printf("Original graph :\n");
    for(i=0; i<V; i++)  {
        if(!G[i].empty())   {
            printf("%d : ", i);
            for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
                printf("%d ", *it);
            printf("\n");
        }
    }

    printf("Reverse graph :\n");
    for(i=0; i<V; i++)  {
        if(!Grev[i].empty())   {
            printf("%d : ", i);
            for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
                printf("%d ", *it);
            printf("\n");
        }
    }

    // run dfs on the reverse graph to get reverse postorder
    memset(explored, false, V*sizeof(bool));
    for(i=0; i<V; i++)  {
        if(!explored[i])
            dfs_reverse(i);
        order[finish[i]] = i;
    }

    printf("Strongly Connected Components: \n");
    // run dfs on the actual graph in reverse postorder
    memset(explored, false, V*sizeof(bool));
    countCC = 0;
    for(i=V-1; i>=0; i--)
        if(!explored[order[i]]) {
            parent = order[i];
            dfs(order[i]);
            countCC++;
        }

    printf("Total no. of strongly connected components : %d\n", countCC);
    
    return 0;
}

/*
Sample:

5 5	// vertices, edges
1 3
2 1
3 2
1 4
4 5

SCC:
3 SCC's in given graph

{{5}, {4}, {1, 2, 3}}
*/