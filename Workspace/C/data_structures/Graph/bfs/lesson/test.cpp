// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// struct Edge
// {
// 	int src, dest;
// };

// class Graph
// {
// public:
// 	vector<vector<int> > adjList;

// 	Graph(vector<Edge> const &edges, int n)
// 	{
// 		adjList.resize(n);
// 		for (auto &edge : edges)
// 		{
// 			adjList[edge.src].push_back(edge.dest);
// 			adjList[edge.dest].push_back(edge.src);
// 		}
// 	}
// };

// void BFS(Graph const &graph, int v, vector<bool> &discovered)
// {
// 	queue<int> q;
// 	discovered[v] = true;

// 	q.push(v);

// 	while (!q.empty())
// 	{
// 		v = q.front();
// 		q.pop();
// 		cout << v << " ";

// 		for (int u : graph.adjList[v])
// 		{
// 			if (!discovered(u))
// 			{
// 				discovered[u] = true;
// 				q.push(u);
// 			}
// 		}
// 	}
// }
