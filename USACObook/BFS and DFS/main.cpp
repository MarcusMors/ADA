#include <cstring>
#include <queue>

int dist[1000000];
std::vector<int> adj[1000000];

void bfs(int start)
{
  memset(dist, -1, sizeof dist);// fill distance array with -1's
  std::queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    const int v = q.front();
    q.pop();
    for (int e : adj[v]) {
      if (dist[e] == -1) {
        dist[e] = dist[v] + 1;
        q.push(e);
      }
    }
  }
}
