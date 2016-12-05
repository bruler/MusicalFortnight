#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief      calculates the next move for the bot
 *
 * @param[in]  posr   row position of bot
 * @param[in]  posc   column position of bot
 * @param[in]  board  the board size ( n x n )
 */

struct Pos {
  int posr;
  int posc;
};

std::vector <Pos> vec;

void find_all(std::vector<string> board) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if(board[i][j] == 'd') {
        Pos posbuf;
        posbuf.posr = i;
        posbuf.posc = j;
        vec.push_back(posbuf);
      }
    }
  }
}

void next_move(int posr, int posc, vector <string> board) {
  int up, left;
  if(((up = vec[0].posr - posr) == 0) && ((left = vec[0].posc - posc) == 0)) {
    cout << "CLEAN" << endl;
    vec.erase(vec.begin());
  } else {
    if((up = vec[0].posr - posr) == 0) {
      if ((left = vec[0].posc - posc) < 0) {
        cout << "LEFT" << endl;
      } else {
        cout << "RIGHT" << endl;
      }
    } else {
      if ((up = vec[0].posr - posr) < 0) {
        cout << "UP" << endl;
      } else {
        cout << "DOWN" << endl;
      }
    }
  }
}


int main(int argc, char* argv[]) {
  int pos[2];
  vector <string> board;

  cin >> pos[0] >> pos[1];

  for(int i=0;i<5;i++) {
    string s;cin >> s;
    board.push_back(s);
  }

  find_all(board);
  next_move(pos[0], pos[1], board);
  return 0;
}
