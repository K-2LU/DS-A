#include <bits/stdc++.h>
using namespace std;

#define sz 1000

vector <int> adList[sz];
int indeg[sz];

vector <int> toposort(int node)	{
	queue <int> q;
	vector <int> result;
	
	for(int i = 0; i < node; i++)
		if (indeg[i]==0)
			q.push(i);
	
	int x;
	while(!q.empty())	{
		x = q.front();
		result.push_back(x);
		q.pop();
		
		for(int i = 0; i < adList[x].size(); i++)
			if(--indeg[adList[x][i]]==0)
				q.push(adList[x][i]);
	}
	
	return result;
}

int main()	{
	freopen("in.txt", "r", stdin);
	int nodes, edges, x, y;
	cin >> nodes >> edges;
	
	for(int i = 0; i < edges; i++)	{
		cin >> x >> y;
		adList[x].push_back(y);
		indeg[y] += 1;
	}
	
	vector <int> sorted = toposort(nodes);
	for(int i=0; i < sorted.size(); i++)
		cout << sorted[i] << " \n"[i==sorted.size()-1];
}