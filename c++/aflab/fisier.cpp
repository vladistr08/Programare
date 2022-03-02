#include <iostream>
#include <fstream>

using namespace std;

void afisareFrecventa(int fr[1001])
{
      for (int i = 1; i < 1001; i += 2)
      {
            while (fr[i] != 0)
            {
                  cout << i << " ";
                  fr[i]--;
            }
      }
      for (int i = 0; i < 1001; i += 2)
      {
            while (fr[i] != 0)
            {
                  cout << i << " ";
                  fr[i]--;
            }
      }
}

void citire(int fr[1001])
{
      ifstream fin("file.in");
      int x;
      while (fin >> x)
            fr[x]++;
}

int main(int argc, char const *argv[])
{
      int fr[1001] = {0};
      citire(fr);
      afisareFrecventa(fr);
      return 0;
}
