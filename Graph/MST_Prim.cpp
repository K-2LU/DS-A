#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 9;
typedef pair <long long, int> PII;
bool marked[MAX_N];
vector <PII> adj[MAX_N];

long long prim(int x)	{
	priority_queue <PII, vector<PII>, greater<PII> > Q;
	int y;
	long long minimumCost = 0;
	PII p;
	
	Q.push({0, x});
	while(!Q.empty())	{
		p = Q.top();
		Q.pop();
		
		x = p.second;
		if(marked[x])	continue;
		
		minimumCost += p.first;
		marked[x] = true;
		
		for(int i = 0; i < adj[x].size(); i++)	{
			y = adj[x][i].second;
			if(!marked[y])	Q.push(adj[x][i]);
		}
	}
	
	return minimumCost;
}

int main()	{
	int nodes, edges, x, y;
	long long weight, minimumCost;
	cin >> nodes >> edges;
	
	for(int i=0; i < edges; i++)	{
		cin >> x >> y >> weight;
		adj[x].push_back({weight, y});
		adj[y].push_back({weight, x});
	}
	
	minimumCost = prim(1);
	cout << minimumCost << endl;
}