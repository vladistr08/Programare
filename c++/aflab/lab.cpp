#include <iostream>
#include <fstream>
using namespace std;

int *citire(int &n)
{
      ifstream fin("fisier.in");
      fin >> n;
      int *v = new int[n + 1];
      for (int i = 0; i < n; i++)
            fin >> v[i];
      return v;
}

int cautareBinara(int val, int n, int *v)
{
      int st = 0, dr = n - 1, mij;
      while (st <= dr)
      {
            mij = (st + dr) / 2;
            if (val == v[mij])
                  return mij;
            else
            {
                  if (val < v[mij])
                        dr = mij - 1;
                  else
                        st = mij + 1;
            }
      }
      return -1;
}

void cautaElemente(int n, int *v)
{
      int m, x, auxVal;
      cout << "m: ";
      cin >> m;
      for (int i = 0; i < m; i++)
      {
            cout << "Valoare de cautat: ";
            cin >> x;
            auxVal = cautareBinara(x, n, v);
            if (auxVal != -1)
                  cout << "Elementul a fost gasit pe pozitia -> " << auxVal << '\n';
            else
                  cout << "Elementul nu a fost gasit!\n";
      }
}

int main()
{
      int n, *v;
      v = citire(n);
      cautaElemente(n, v);
      return 0;
}
