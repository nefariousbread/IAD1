#include<iostream>
#include<random>
std::random_device auri;
std::mt19937 gen(auri());
int main (int argc, char *argv[])
{  
  while (1) {
    // Rest of your code

      std::uniform_int_distribution<> distr(0, 10);
      int pivot = distr(gen);
    std::cout << pivot << std::endl;
    // Rest of your code

    // Rest of your code
  }
  return 0;
}
