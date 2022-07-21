#include <bits/stdc++.h>
using namespace std;

#define sz 1000+9

int adj[sz][sz], indeg[sz];
int source, nodes, edges, stat = 1;
vector <int> ePath, used(sz+1, 0);

void addEdge(int a, int b)	{
	adj[a][b] = adj[b][a] = 1;
}

void deleteEdge(int a, int b)	{
	adj[a][b] = adj[b][a] = 0;
}

bool isValid()	{
	int odd = 0;
	
	for(int i = 0; i < nodes; i++)
		if(indeg[i] & 1) odd++, source = i;
	
	return (odd==0 || odd==2);
}

void dfs(int node, int stat)	{
	if (used[node]==stat)	return;
	used[node] = stat;
	
	for(int i = 0; i < nodes; i++)
		if(adj[node][i])
			dfs(adj[node][i], stat);
}

bool artiBridge(int a, int b)	{
	dfs(a, stat++);
	int before = 0;
	
	for(int i = 0; i < nodes; i++)
		if(used[i]==stat - 1)
			++before;
		
	deleteEdge(a, b);
	int after = 0;
	dfs(a, stat++);
	
	for(int i = 0; i < nodes; i++)
		if(used[i] == stat - 1)
			after++;
	addEdge(a, b);
	
	return before != after;
}

void eulerPath(int source)	{
	vector <int> bridge;
	ePath.push_back(source);
	
	for(int i = 0; i < nodes; i++)	{
		if(adj[source][i] == 0) continue;
		
		if(artiBridge(source, i))	{
			bridge.push_back(i);
			continue;
		}
		
		deleteEdge(source, i);
		eulerPath(i);
		
		return;
	}
	
	if(bridge.size())	{
		deleteEdge(source, bridge.back());
		eulerPath(bridge.back());
	}
}

int main()	{
	freopen("in.txt", "r", stdin);
	cin >> nodes >> edges;
	
	for(int i = 0, a, b; i < edges; i++)	{
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
		indeg[a] += 1;
		indeg[b] += 1;
	}
	
	if(!isValid())	{
		cout << "No euler path exists\n";
		return 0;
	}
	eulerPath(source);
	
	for(int i: ePath)
		cout << i << " ";
	cout << endl;
}