#include <iostream>

using namespace std;

int *citireDinamica(int &n)
{
      cin >> n;
      int *a = new int[n];
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }
      return a;
}

void citire(int &n, int a[])
{
      cin >> n;
      for (int i = 0; i < n; i++)
            cin >> a[i];
}

void afisare(int n, int a[])
{
      for (int i = 0; i < n; i++)
            cout << a[i] << " ";
}

//////////////////////////////////////////////////////////////////////
//se citeste vect n elemente, sa se inlocuiasca elem de pe poz pare
//cu cea mai mica cifra a elem si cele de pe poz imp cu 0 daca elem e prim

bool prim(int x)
{
      if (x < 2 || x > 2 && x % 2 == 0)
            return 0;
      for (int d = 3; d * d <= x; d += 2)
            if (x % d == 0)
                  return 0;
      return 1;
}

int minimCifra(int x)
{
      int cifra = 10;
      do
      {
            if (x % 10 < cifra)
                  cifra = x % 10;
            x /= 10;
      } while (x != 0);
      return cifra;
}

void inlocuireElemente(int n, int a[])
{
      for (int i = 0; i < n; i++)
      {
            if (i % 2 == 0)
            {
                  a[i] = minimCifra(a[i]);
            }
            else
            {
                  if (prim(a[i]) == true)
                        a[i] = 0;
            }
      }
}

void rezolvareProblema1()
{
      int n, a[500];
      citire(n, a);
      inlocuireElemente(n, a);
      afisare(n, a);
}
///////////////////////////////////////////////////////////////
//sa se elimine elementele care sunt egale cu suma vecinilor

void eliminareElemente(int &n, int v[])
{
      int eliminate = 0;
      for (int i = 1; i < n - 1; i++)
      {
            if (v[i] == v[i - 1] + v[i + 1])
                  eliminate++;
            else
                  v[i - eliminate] = v[i];
      }
      v[n - eliminate - 1] = v[n - 1];
      n -= eliminate;
}

void rezolvareProblema2()
{
      int n, a[100];
      citire(n, a);
      eliminareElemente(n, a);
      afisare(n, a);
}
///////////////////////////////////////

int *inmultire(int nrcif, int *numar, int digit)
{
      int *rezultat = new int[nrcif + 1];
      //rezolvare
      return rezultat;
}

void rezolvareProblema3()
{
      int nrcif, *numar;
      cin >> nrcif;
      numar = citireDinamica(nrcif);
}

int main(int argc, char const *argv[])
{
      rezolvareProblema2();
      return 0;
}
