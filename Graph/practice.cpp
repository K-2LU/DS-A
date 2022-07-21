#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+9;
pair <long long, pair <int, int>> p[MAX_N];
int id[MAX_N];
int nodes, edges;

void initialize()	{
	for(int i = 0; i < MAX_N; i++)
		id[i] = i;
}

int root(int x)	{
	while(id[x] != x)	{
		id[x] = id[id[x]];
		x = id[x];
	}
	
	return x;
}

void unify(int a, int b)	{
	int p = root(a);
	int q = root(b);
	
	id[p] = id[q];
}

long long kruskal(pair <long long, pair<int, int> > p[])	{
	long long weight, minimumCost=0;
	int x, y;
	
	for(int i=0; i < edges; i++)	{
		x = p[i].second.first;
		y = p[i].second.second;
		weight = p[i].first;
		
		if(root(x) != root(y))	{
			minimumCost += weight;
			unify(x, y);
		}
	}
	return minimumCost;
}

int main()	{
	long long weight, cost, minimumCost;
	int x, y;
	cin >> nodes >> edges;
	
	initialize();
	for(int i=0; i < edges; i++)	{
		cin >> x >> y >> weight;
		p[i] = {weight, {x, y}};
	}
	sort(p, p+edges);
	
	minimumCost = kruskal(p);
	
	cout << minimumCost << endl;
	
	return 0;
}

/*
5 7
1 2 1
1 3 7
2 3 5
2 4 4
2 5 3
3 5 6
4 5 2
*/