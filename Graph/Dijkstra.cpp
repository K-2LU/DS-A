#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000 + 1
#define INF 1000000 + 9
typedef pair <int, int> PII;

vector <int> v[SIZE], cost[SIZE];
int dist[SIZE];
int parent[SIZE];

vector<int> path;

void init()	{
	for(int i = 0; i < SIZE; i++)
		dist[i] = INF, parent[i] = -1;
}

int dijkstra(int source, int destination)	{
	priority_queue <PII, vector <PII>, greater <PII> > pq;
	pq.push({0, source});
	dist[source] = 0;
	
	while(!pq.empty())	{
		int x = pq.top().first; // weight;
		int y = pq.top().second;	// node;
		pq.pop();
		
		for(int i = 0; i < v[y].size(); i++)	{
			if( dist[v[y][i]] > x + cost[y][i] )	{
				dist[v[y][i]] = x + cost[y][i];
				pq.push({dist[ v[y][i] ], v[y][i]});
				parent[ v[y][i] ] = y;
			}
		}
	}
	return dist[destination];
}



int main()	{
	//freopen("sample.txt", "r", stdin);
	init();
	int x, y, nodes, edges, weight;
	cin >> nodes >> edges;
	
	for(int i = 0; i < edges; i++)	{
		cin >> x >> y >> weight;
		v[x].push_back(y);
		v[y].push_back(x);
		cost[x].push_back(weight);
		cost[y].push_back(weight);
	}	
	
	cin >> x >> y;
	int minimumCost = dijkstra(x, y);
	cout << minimumCost << endl;
	
	while(~y)	{
		path.push_back(y);
		y = parent[y];
	}	reverse(path.begin(), path.end());
	
	for(int i = 0; i< path.size(); i++)
		cout << path[i] << ",\n"[i==path.size()-1];
	
	return 0;
}