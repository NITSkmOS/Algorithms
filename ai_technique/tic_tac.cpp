#include <bits/stdc++.h>
using namespace std;
class tic_tac_toe {
  public:
    int board[10];
  int i, turn, n;
  tic_tac_toe() {
    turn = 0;
    for (i = 0; i < 10; i++)
      board[i] = 2;
  }
  void get() {
    cout << "\n Enter ur turn\n";
    cout << "enter box num from 1 to 9= ";
    cin >> n;
  }
  void disp(int a) {
    if (a == 3)
      cout << "X";
    else if (a == 5)
      cout << "O";
    else if (a == 2)
      cout << " ";
  }
  void display() {
    int a = 0;
    cout << "\n\t----------------\n";
    for (i = 1; i < 10; i += 3) {
      cout << "\t| ";
      a = board[i];
      disp(a);
      cout << " | ";
      a = board[i + 1];
      disp(a);
      cout << " | ";
      a = board[i + 2];
      disp(a);
      cout << " |";
      cout << endl << "\n\t----------------\n";
    }
  }
  int make2() {
    if (board[5] == 2)
      return 5;
    else if (board[2] == 2)
      return 2;
    else if (board[4] == 2)
      return 4;
    else if (board[6] == 2)
      return 6;
    else if (board[8] == 2)
      return 8;
    else if (board[1] == 2)
      return 1;
    else if (board[7] == 2)
      return 7;
  }
  void go(int n) {
    if (board[n] == 2) {
      turn++;
      if (turn % 2 == 0)
        board[n] = 5;
      else
        board[n] = 3;
    } else
      get();
  }
  int posswin(char p) {
    if (p == 'X') {
      if ((board[2] * board[5] * board[8]) == 30) {
        if (board[1] == 2)
          return 1;
      }
      if ((board[4] * board[5] * board[6]) == 30) {
        if (board[7] == 2)
          return 7;
      }
      if ((board[8] * board[5] * board[2]) == 30) {
        if (board[9] == 2)
          return 9;
      }
      if ((board[6] * board[5] * board[4]) == 30) {
        if (board[3] == 2)
          return 3;
      }
      if ((board[1] * board[5] * board[9]) == 45 && board[1] == 5) {
        if (board[3] == 2)
          return 3;
      }
      if ((board[7] * board[5] * board[3]) == 18) {
        if (board[7] == 2)
          return 7;
        if (board[5] == 2)
          return 5;
        if (board[3] == 2)
          return 3;
      }
      if ((board[1] * board[5] * board[9]) == 18) {
        if (board[1] == 2)
          return 1;
        if (board[5] == 2)
          return 5;
        if (board[9] == 2)
          return 9;
      }
      if ((board[1] * board[2] * board[3]) == 18) {
        if (board[1] == 2)
          return 1;
        if (board[2] == 2)
          return 2;
        if (board[3] == 2)
          return 3;
      }
      if ((board[4] * board[5] * board[6]) == 18) {
        if (board[4] == 2)
          return 4;
        if (board[5] == 2)
          return 5;
        if (board[6] == 2)
          return 6;
      }
      if ((board[7] * board[8] * board[9]) == 18) {
        if (board[7] == 2)
          return 7;
        if (board[8] == 2)
          return 8;
        if (board[9] == 2)
          return 9;
      }
      if ((board[1] * board[4] * board[7]) == 18) {
        if (board[1] == 2)
          return 1;
        if (board[4] == 2)
          return 4;
        if (board[7] == 2)
          return 7;
      }
      if ((board[2] * board[5] * board[8]) == 18) {
        if (board[2] == 2)
          return 2;
        if (board[5] == 2)
          return 5;
        if (board[8] == 2)
          return 8;
      }
      if ((board[3] * board[6] * board[9]) == 18) {
        if (board[3] == 2)
          return 3;
        if (board[6] == 2)
          return 6;
        if (board[9] == 2)
          return 9;
      } else
        return 0;
    }
    if (p == 'O') {
      if ((board[7] * board[5] * board[3]) == 50) {
        if (board[7] == 2)
          return 7;
        if (board[5] == 2)
          return 5;
        if (board[3] == 2)
          return 3;
      }
      if ((board[1] * board[5] * board[9]) == 50) {
        if (board[1] == 2)
          return 1;
        if (board[5] == 2)
          return 5;
        if (board[9] == 2)
          return 9;
      }
      if ((board[1] * board[2] * board[3]) == 50) {
        if (board[1] == 2)
          return 1;
        if (board[2] == 2)
          return 2;
        if (board[3] == 2)
          return 3;
      }
      if ((board[4] * board[5] * board[6]) == 50) {
        if (board[4] == 2)
          return 4;
        if (board[5] == 2)
          return 5;
        if (board[6] == 2)
          return 6;
      }
      if ((board[7] * board[8] * board[9]) == 50) {
        if (board[7] == 2)
          return 7;
        if (board[8] == 2)
          return 8;
        if (board[9] == 2)
          return 9;
      }
      if ((board[1] * board[4] * board[7]) == 50) {
        if (board[1] == 2)
          return 1;
        if (board[4] == 2)
          return 4;
        if (board[7] == 2)
          return 7;
      }
      if ((board[2] * board[5] * board[8]) == 50) {
        if (board[2] == 2)
          return 2;
        if (board[5] == 2)
          return 5;
        if (board[8] == 2)
          return 8;
      }
      if ((board[3] * board[6] * board[9]) == 50) {
        if (board[3] == 2)
          return 3;
        if (board[6] == 2)
          return 6;
        if (board[9] == 2)
          return 9;
      } else
        return 0;
    }
  }
};

int main() {
  tic_tac_toe tic;
  tic.display();

  //turn=1
  tic.get();
  tic.go(tic.n);
  tic.display();

  //turn=2;
  cout << "\nComputers turn\n";
  if (tic.board[5] == 2) {
    tic.go(5);
    tic.display();
  } else {
    tic.go(1);
    tic.display();
  }

  //turn=3
  tic.get();
  tic.go(tic.n);
  tic.display();

  //turn=4;
  cout << "\nComputers turn\n";
  if (tic.posswin('X') != 0) {
    tic.go(tic.posswin('X'));
    tic.display();
  } else {
    tic.go(tic.make2());
    tic.display();
  }

  //turn=5
  tic.get();
  tic.go(tic.n);
  tic.display();

  //turn=6;
  cout << "\nComputers turn\n";
  if (tic.posswin('O') != 0) {
    tic.go(tic.posswin('O'));
    tic.display();
    cout << "\nyou lost\n";
    goto last;
  } else if (tic.posswin('X') != 0) {
    tic.go(tic.posswin('X'));
    tic.display();
  } else {
    tic.go(tic.make2());
    tic.display();
  }

  //turn=7
  tic.get();
  tic.go(tic.n);
  tic.display();

  //turn=8;
  cout << "\nComputers turn\n";
  if (tic.posswin('O') != 0) {
    tic.go(tic.posswin('O'));
    tic.display();
    cout << "\nyou lost\n";
    goto last;
  } else if (tic.posswin('X') != 0) {
    tic.go(tic.posswin('X'));
    tic.display();
  } else {
    tic.go(tic.make2());
    tic.display();
  }

  //turn=9
  tic.get();
  tic.go(tic.n);
  tic.display();

  last:
    cout << "\nGame over\n\n";
  return 0;
}