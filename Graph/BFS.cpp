#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+9;

vector <int> adjlist[MAX_N];
vector <bool> visited(MAX_N, false);

void bfs(int source, int destination)   {
   queue <int> q;
   q.push(source);
   visited[source] = true;

   while(!q.empty()) {
      int p = q.front();
      q.pop();

      for (int i : adjlist[p])   
         if(!visited[i])   {
            cout << "Visiting : \t" << i << "\t"; 
            cout << "Parent : \t" << p << endl;
            q.push(i);
            visited[i] = true;
            if(i==destination)   {
               cout << "Destination reached";
               return;
            }
         }
   }
}

int main()  {
   
   int nodes, edges, a, b;
   cin >> nodes >> edges;

   for (int i = 0; i < edges; i++){
      cin >> a >> b;
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
   }

   int s, d;
   cin >> s >> d;

   bfs(s, d);

   return 0;
}