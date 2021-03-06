#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int vertices, edges, destination;
	cin >> vertices >> edges >> destination;
	--destination;
	vector<vector<int>> graph(vertices);
	for (int j = 0; j < edges; ++j) {
		int a, b; cin >> a >> b;
		graph[b - 1].push_back(a - 1);
	}
	vector<int> dist(vertices, -1);
	queue<int> q;
	q.push(destination);
	dist[destination] = 0;
	while (q.size() != 0) {
		int v = q.front();
		for (int j = 0; j < vertices; ++j) {
			if (find(graph[v].begin(), graph[v].end(), j) != graph[v].end() && dist[j] == -1) {
				dist[j] = dist[v] + 1;
				q.push(j);
			}
		}
		q.pop();
	}
	sort(dist.begin(), dist.end());
	cout << dist[dist.size() - 1];
    return 0;
}

