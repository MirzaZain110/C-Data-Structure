//  # C-Data-Structure
//this repository for the data structure students for providing them more codes .
//n// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) 
{
  adj[s].push_back(d);  //for starting index
  adj[d].push_back(s); // for second index
}
// delete
void delEdge(vector<int> adj[], int u, int v)
{
    // Traversing through the first vector list
    // and removing the second element from it
    for (int i = 0; i < adj[u].size(); i++) 
	{
        if (adj[u][i] == v) 
		{
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
 
    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < adj[v].size(); i++) 
	{
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}
// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << " : ";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int V = 5;

  // Create a graph
  vector<int> adj[V];
	int vis[V];
  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 0, 4);
  printGraph(adj, V);
  cout<<"\n\tAfter delete : \n";
  delEdge(adj,0,2);
  
  printGraph(adj, V);
  queue<int> q;
  int temp = q.front();
  q.push(0);
  cout<<" Visited : "<<temp;
  vector<int> :: iterator i;
  for(int i=adj[temp].front();i != adj[temp].empty();i++ )
  	{
  		if( vis[i]  == 0 )
  		{
  			vis[i] = 1;
			  q.push(i); 
		}
	} 
}
