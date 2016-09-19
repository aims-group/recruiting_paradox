#include <iostream>
int main() {
   for (int i = 1; i < 101; i++) std::cout << (i%15==0 ? "FizzBuzz":i%3==0 ? "Fizz":i%5==0 ? "Buzz":(std::to_string(i)))<< "\n";
   return 0;
}
