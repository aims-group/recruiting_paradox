#include <iostream>
#include <map>
#include <algorithm>
#include <termios.h>
#include <unistd.h>
using namespace std;

void bullsAndCows(string &player1, string &player2, map<string, int> &bullsAndCowsMap)
{
  int bulls = 0;
  int cows = 0;
  for(int i = 0; i < player1.size(); i++)
  {
    if(player1[i] == player2[i])
      bulls++;
    for(int j = 0; j < player2.size(); j++)
    {
      if(player1[i] == player2[j])
        cows++;
    }
  }

  if(cows >= bulls)
    cows -= bulls;
  bullsAndCowsMap["bulls"] = bulls;
  bullsAndCowsMap["cows"] = cows;
}

int main()
{
  string player1 = "";
  string player2 = "";
  char contd = 'Y';
  map<string, int> bullsAndCowsMap = {{"bulls", 0}, {"cows", 0}};
  termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  while(true)
  {
    cout << "Player 1: The word: ";
    cin >> player1;
    cout << endl << endl;
    cout << "Player 2: The guess: ";
    cin >> player2;
    cout << endl << endl;
    transform(player1.begin(), player1.end(), player1.begin(), ::toupper);
    transform(player2.begin(), player2.end(), player2.begin(), ::toupper);
    bullsAndCows(player1, player2, bullsAndCowsMap);
    cout << "bulls - " << bullsAndCowsMap["bulls"] << ", cows - " << bullsAndCowsMap["cows"] << endl;
    cout << endl;
    cout << "Play again? [Y/n]" << endl;
    cin >> contd;
    cout << endl;
    if(contd == 'n' || contd == 'N')
      break;
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  cout << "Goodbye!" << endl;

  return 0;
}
