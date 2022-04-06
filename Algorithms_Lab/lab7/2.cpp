#include<bits/stdc++.h>
using namespace std;

struct node {
  int vertex;
  struct node* next;
};
struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newnode = malloc(sizeof(struct node));
  newnode->vertex = v;
  newnode->next = NULL;
  return newnode;
}
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    bool visited[V];
    for(int i = 0; i < V; i++) 
    visited[i] = false; 
    
    queue<int> q;
    visited[0]=true;
    q.push(0);
    
    while(q.empty()==false)
    {
        int k=q.front();
        q.pop();
        bfs.push_back(k);
        
        for(int x:adj[k])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return bfs;
}

int main(){
    struct Graph* graph = createGraph(4);
    addEdge(graph, 2,2);
    addEdge(graph, 3,3);
    addEdge(graph, 5,4);
    addEdge(graph, 6, 3);
    bfsOfGraph(graph,3);
    return 0;
}