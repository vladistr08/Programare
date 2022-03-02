#include <iostream>
#include <fstream>

using namespace std;

bool isDiv5(int x)
{
      if (x % 5 == 0)
            return true;
      return false;
}

void outputNumbers(string filePath1, string filePath2)
{
      ifstream fin1(filePath1);
      ifstream fin2(filePath2);

      int n, m, i = 0, j = 0, input1 = -1, input2 = -1;
      fin1 >> n;
      fin2 >> m;

      while (isDiv5(input1) == 0 && i <= n)
      {
            fin1 >> input1;
            i++;
      }

      while (isDiv5(input2) == 0 && j <= m)
      {
            fin2 >> input2;
            j++;
      }

      while (i <= n && j <= m)
      {
            if (input1 <= input2)
            {
                  cout << input1 << " ";
                  while (i <= n)
                  {
                        fin1 >> input1;
                        i++;
                        if (isDiv5(input1) == true)
                              break;
                  }
            }
            else
            {
                  cout << input2 << " ";
                  while (j <= m)
                  {
                        fin2 >> input2;
                        j++;
                        if (isDiv5(input2) == true)
                              break;
                  }
            }
      }
      while (i <= n)
      {
            fin1 >> input1;
            i++;
            if (isDiv5(input1) == true)
                  cout << input1 << " ";
      }
      while (j <= m)
      {
            fin2 >> input2;
            j++;
            if (isDiv5(input2) == true)
                  cout << input2 << " ";
      }
}

int main(int argc, char const *argv[])
{
      outputNumbers("1.in", "2.in");
      return 0;
}
