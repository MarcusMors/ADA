#include <iostream>
#include <vector>

using namespace std;

char g[16][16] = {
  //
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', 'c', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', 'b', ' ' },
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', 'a', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'd', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  { ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
  //
};

void print()
{
  int x, y;
  std::cout << "\n";
  for (x = 0; x < 16; x++) {
    for (y = 0; y < 16; y++) std::cout << g[x][y] << " ";
    std::cout << "\n";
  }
  std::cout << "\n";
}

bool is_in_path(std::vector<char *> &path, const char *wanted)
{
  for (int i = 0; i < path.size(); i++) {
    if (wanted == path[i]) { return true; }
  }

  return false;
}

std::vector<char *> dijkstra(int c_x, int c_y, const char to)
{
  std::vector<char *> path{};
  std::vector<char *> best_path_until_now{};

  int steps = 0;
  int dirs[4];
  int lower_until_now = 10000000;

  path.push_back(&(g[c_x][c_y]));
  best_path_until_now = path;

  if (g[c_x][c_y] == to) { return path; }

  const bool can_go_up = c_y < 15 and g[c_x][c_y + 1] != '#';
  if (can_go_up and not is_in_path(best_path_until_now, &(g[c_x][c_y + 1]))) {
    std::vector<char *> new_path = path;
    new_path.push_back(&(g[c_x][c_y + 1]));

    std::vector<char *> result_path = dijkstra(c_x, c_y + 1, to);
    if (result_path.size() > 0) {
      dirs[2] = result_path.size();
      if (dirs[2] < lower_until_now) {
        lower_until_now = dirs[2];
        best_path_until_now = new_path;
      }
    }
  }
  const bool can_go_right = c_x < 15 and g[c_x + 1][c_y] != '#';
  if (can_go_right and not is_in_path(best_path_until_now, &(g[c_x + 1][c_y]))) {
    std::vector<char *> new_path = path;
    new_path.push_back(&(g[c_x + 1][c_y]));

    std::vector<char *> result_path = dijkstra(c_x + 1, c_y, to);
    if (result_path.size() > 0) {
      dirs[1] = result_path.size();
      if (dirs[1] < lower_until_now) {
        lower_until_now = dirs[1];
        best_path_until_now = new_path;
      }
    }
  }

  const bool can_go_down = c_y > 0 and g[c_x][c_y - 1] != '#';
  if (can_go_down and not is_in_path(best_path_until_now, &(g[c_x][c_y - 1]))) {
    std::vector<char *> new_path = path;
    new_path.push_back(&(g[c_x][c_y - 1]));

    std::vector<char *> result_path = dijkstra(c_x, c_y - 1, to);
    if (result_path.size() > 0) {
      dirs[3] = result_path.size();
      if (dirs[3] < lower_until_now) {
        lower_until_now = dirs[3];
        best_path_until_now = new_path;
      }
    }
  }
  const bool can_go_left = c_x > 0 and g[c_x - 1][c_y] != '#';
  if (can_go_left and not is_in_path(best_path_until_now, &(g[c_x - 1][c_y]))) {
    std::vector<char *> new_path = path;
    new_path.push_back(&(g[c_x - 1][c_y]));

    std::vector<char *> result_path = dijkstra(c_x - 1, c_y, to);
    if (result_path.size() > 0) {
      dirs[0] = result_path.size();
      if (dirs[0] < lower_until_now) {
        lower_until_now = dirs[0];
        best_path_until_now = new_path;
      }
    }
  }

  return best_path_until_now;
}

void proc()
{
  std::vector<char *> path = dijkstra(2, 1, 'd');
  for (char *c : path) { *c = 'X'; }
  std::cout << "Shortest path from c to d: ";
  for (char *c : path) { std::cout << *c << " "; }
  std::cout << std::endl;
}

int main()
{
  print();
  proc();
  print();
}
