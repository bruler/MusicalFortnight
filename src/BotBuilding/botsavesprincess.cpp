#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief      finds path from mario to princess
 *
 * @param[in]  n     size of grid (n x n)
 * @param[in]  grid  the (n x n) grid
 * " - " : empty [Ascii: 45]
 * "m" 	 : mario
 * "p"   : princess peach
 */

void displayPathtoPrincess(int n, vector <string> grid){
  // locate mario and princess
  short mario[2], princess[2];
  int up, left;
  
  for(size_t i=0; i<n; i++) {
    for (size_t j=0; j<n; j++) {
      if(grid[i][j] == 'm') {
        mario[0] = i;
        mario[1] = j;
      }

      if(grid[i][j] == 'p') {
        princess[0] = i;
        princess[1] = j;
      }
    }
  }

  if ((up = princess[0] - mario[0]) < 0) {
    for(; up < 0; ++up)
      printf("UP\n");
  } else {
    for(; up > 0; --up)
      printf("DOWN\n");
  }

  if ((left = princess[1] - mario[1]) < 0) {
    for(; left < 0; ++left)
      printf("LEFT\n");
  } else {
    for(; left > 0; --left)
      printf("RIGHT\n");
  }
}


int main(int argc, char* argv[]) {
  int m;
  vector <string> grid;

  cin >> m;
  for(int i=0; i<m; i++) {
      string s; cin >> s;
      grid.push_back(s);
  }

  displayPathtoPrincess(m, grid);
  return 0;
}
