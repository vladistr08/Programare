#include <iostream>
#include <fstream>
using namespace std;

struct Calendar
{
      int zi, luna, an;
};

bool verificareData(Calendar data)
{
      if (data.zi > 0 && data.luna > 0 && data.an > 0 && data.zi <= 31 && data.luna <= 12)
      {
            if (data.luna <= 8)
            {
                  if ((data.luna % 2 == 1 || data.luna == 8) && data.zi > 31)
                        return false;
                  if (data.luna == 2 && data.zi > 28)
                        return false;
                  if (data.luna % 2 == 0 && data.zi > 30)
                        return false;
            }
            else if (data.luna <= 12)
            {
                  if (data.luna % 2 == 0 && data.zi > 31)
                        return false;
                  if (data.luna % 2 == 1 && data.zi > 30)
                        return false;
            }
            return true;
      }
      else
            return false;
}

void citire(int &n, Calendar v[])
{
      ifstream fin("fisier.in");
      n = 0;
      Calendar aux;
      int zi, luna, an;
      while (fin >> zi >> luna >> an)
      {
            aux.zi = zi, aux.luna = luna, aux.an = an;
            if (verificareData(aux) == true)
            {
                  v[n].zi = zi;
                  v[n].luna = luna;
                  v[n].an = an;
                  n++;
            }
      }
}

bool comparaDateLess(Calendar c1, Calendar c2)
{
      if (c1.an < c2.an)
            return true;
      else if (c1.an == c2.an)
      {
            if (c1.luna < c2.luna)
                  return true;
            else if (c1.luna == c2.luna)
            {
                  if (c1.zi < c2.zi)
                        return true;
                  else
                        return false;
            }
            else
                  return false;
      }
      else
            return false;
}

void sortare(int n, Calendar v[])
{
      for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                  if (comparaDateLess(v[j], v[i]) == true)
                        swap(v[i], v[j]);
}

void afisare(int n, Calendar v[])
{
      for (int i = 0; i < n; i++)
      {
            cout << v[i].zi << " " << v[i].luna << " " << v[i].an << '\n';
      }
}

int main(int argc, char const *argv[])
{
      int n;
      Calendar v[50];
      citire(n, v);
      sortare(n, v);
      afisare(n, v);
      return 0;
}
