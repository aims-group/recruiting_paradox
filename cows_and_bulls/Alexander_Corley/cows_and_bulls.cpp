#include <iostream>
#include <sstream>


using namespace std;

int count_cows(string one, string two);

int main() {
   bool playing = true;
   while (playing) {
      string player_1 = "", player_2 = "";
      cout << "Player 1: The word:";
      cin >> player_1;
      cout << "\nPlayer 2: The guess:";
      cin >> player_2;
      int cows = count_cows(player_1, player_2);
      cout << "\nbulls - " << player_1.size()-cows << ", cows - ";
      cout << cows << endl; 
      


      bool trying = false;
      do {
         cout << "\nPlay again? [Y/n]";
         string response;
         cin >> response;
         if (response == "n" || response == "N") {
            playing = false;
            trying = false;
         } else if (response == "y" || response == "Y")
            trying = false;
         else trying = true;
      } while (trying);
   }
   return 0;
}

int count_cows(string one, string two) {
   stringstream p1, p2;
   p1 << one;
   p2 << two;
   int cows = 0;
   while (p1.peek() != EOF && p2.peek() != EOF) {
      if (tolower(p1.get()) == tolower(p2.get()))
         cows++;
   }
   return cows;
}
