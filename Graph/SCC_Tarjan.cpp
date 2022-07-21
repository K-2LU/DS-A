#include <bits/stdc++.h>
using namespace std;

#define UNVISITED -1
typedef vector <int> vi;
typedef vector <vi> vvi;

const int MAX = 1000 + 9;

vi adList[MAX];
vvi scc;
int id = 1, sccCount = 0;
int ids[MAX], low[MAX];
bool onStack[MAX];

void tarjanDFS(int at)	{
	static stack <int> st;
	
	ids[at] = low[at] = id++;
	st.push(at);
	onStack[at] = true;
	
	for(auto i: adList[at])	{
		if(ids[i]==UNVISITED)	{
			tarjanDFS(i);
			low[at] = min(low[at], low[i]);
		}
		
		else if (onStack[i])
			low[at] = min(low[at], low[i]);
	}
	
	if (ids[at] == low[at])	{
		vi temp;
		while(1)	{
			int v = st.top();
			st.pop();
			onStack[v] = false;
			temp.push_back(v);
			if(at == v)	break;
		}
		scc.push_back(temp);
		sccCount++;
	}
}

void findScc(int n)	{
	cout << "debug: findSCC\n";
	for(int i = 0; i < n; i++)	ids[i] = UNVISITED;
	for(int i = 0; i < n; i++)
		if(ids[i]==UNVISITED)
			tarjanDFS(i);
}
int main()	{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int x, y, nodes, edges;	
	cin >> nodes >>	edges;
	
	for(int i = 0; i < edges; i++)	{
		cin >> x >> y;
		adList[x].push_back(y);
	}
	
	findScc(nodes);
	cout << sccCount << endl;
	for(int i = 0; i < sccCount; i++)
		for(int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << ",\n"[j == adList[i].size()-1];
		
}