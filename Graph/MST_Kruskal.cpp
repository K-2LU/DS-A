#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+9;
int id[MAX_N], nodes, edges;
pair <long long, pair<int, int> > p[MAX_N];
vector <pair <int, int>> path;
void initialize()	{
	for (int i = 0; i < MAX_N; i++)	
		id[i] = i;
}

int root(int x)	{
	while(id[x] != x)	{
		id[x] = id[id[x]];
		x = id[x];
	}
	
	return x;
}

void unify(int x, int y)	{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])	{
	int x, y;
	long long cost, minCost = 0;
	
	for(int i = 0; i < edges; i++)	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		
		if (root(x) != root(y))	{
			minCost += cost;
			unify(x, y);
			path.push_back({x, y});
		}
	}
	
	return minCost;
}

int main()	{
	int x, y;
	long long weight, cost, minimumCost;
	
	initialize();
	
	cin >> nodes >> edges;
	
	for (int i =0; i < edges; i++)	{
		cin >> x >> y >> weight;
		p[i] = {weight, {x, y}}; // make_pair(weight, make_pair(x, y))
	}
	
	sort(p, p+edges);
	minimumCost = kruskal(p);
	
	cout << minimumCost << endl;
	for (int i = 0; i < path.size(); i++)	{
		cout << path[i].first << ' ' << path[i].second << endl;
 	}
	return 0;
}