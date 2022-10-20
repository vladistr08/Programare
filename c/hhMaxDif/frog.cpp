#include <iostream>

int main(int argc, char const *argv[])
{
      int x, y, s, t;
      std::cin >> x >> y >> s >> t;
      t -= x + y;
      std::cout << (t + 1) * (t + 2) / 2;
      return 0;
}
