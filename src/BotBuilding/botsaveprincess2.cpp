#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief      calculates the next move to get mario and princess close
 *
 * @param[in]  n     size of grid (n x n)
 * @param[in]  r     row position of mario
 * @param[in]  c     column position of mario
 * @param[in]  grid  the grid (n x n)
 */
void nextMove(int n, int r, int c, vector <string> grid){
  short princess[2];
  int up, left;

  for(size_t i=0; i<n; i++) {
    for (size_t j=0; j<n; j++) {
      if(grid[i][j] == 'p') {
        princess[0] = i;
        princess[1] = j;
      }
    }
  }

  /**
   * check vertical moves
   * if no moves available, move horizontally
   */
  if((up = princess[0] - r) == 0) {
    if ((left = princess[1] - c) < 0) {
      cout << "LEFT" << endl;
    } else {
      cout << "RIGHT" << endl;
    }
  } else {
    if ((up = princess[0] - r) < 0) {
      cout << "UP" << endl;
    } else {
      cout << "DOWN" << endl;
    }
  }
}


int main(int argc, char* argv[]) {
  int n, r, c;
  vector <string> grid;

  cin >> n;
  cin >> r;
  cin >> c;

  for(int i=0; i<n; i++) {
      string s; cin >> s;
      grid.push_back(s);
  }

  nextMove(n, r, c, grid);
  return 0;
}
