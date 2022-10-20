#include <iostream>
#include <string>

int frecventaChar(const char &c, const std::string &s)
{
      int counter = 0;
      for (auto chr : s)
            if (c == chr)
                  counter++;
      return counter;
}

int main(int argc, char const *argv[])
{
      std::cout << frecventaChar('c', "CaCaccca");
      return 0;
}
