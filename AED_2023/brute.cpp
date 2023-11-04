#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 16;

char g[N][N] = {
  // graph as given in the question
};

int dist[N][N];// distance of each vertex from c
int prev[N][N];// previous vertex on shortest path from c

struct Vertex
{
  int x, y, dist;
  bool operator<(const Vertex &other) const { return dist > other.dist; }
};

void dijkstra(int sx, int sy)
{
  priority_queue<Vertex> pq;
  pq.push({ sx, sy, 0 });
  dist[sx][sy] = 0;
  while (!pq.empty()) {
    Vertex v = pq.top();
    pq.pop();
    if (v.dist > dist[v.x][v.y]) { continue; }
    if (g[v.x][v.y] == 'd') {
      // found shortest path to d
      return;
    }
    // check neighbors
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; i++) {
      int nx = v.x + dx[i];
      int ny = v.y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N && g[nx][ny] != '#' && v.dist + 1 < dist[nx][ny]) {
        dist[nx][ny] = v.dist + 1;
        prev[nx][ny] = v.x * N + v.y;// store previous vertex as a single integer
        pq.push({ nx, ny, dist[nx][ny] });
      }
    }
  }
}

void mark_path(int ex, int ey)
{
  while (ex != -1 && ey != -1) {
    g[ex][ey] = 'X';
    int px = prev[ex][ey] / N;
    int py = prev[ex][ey] % N;
    ex = px;
    ey = py;
  }
}

int main()
{
  // initialize distances to infinity
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = INT_MAX;
      prev[i][j] = -1;
    }
  }
  // find shortest path from c to d
  int cx, cy;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (g[i][j] == 'c') {
        cx = i;
        cy = j;
        break;
      }
    }
  }
  dijkstra(cx, cy);
  // mark shortest path with 'X'
  mark_path(12, 6);
  // print marked graph
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) { cout << g[i][j]; }
    cout << endl;
  }
  return 0;
}
