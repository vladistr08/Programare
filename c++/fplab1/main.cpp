#include <iostream>
#include <cmath>
using namespace std;

/*1.se citeste un numar natural n si apoi n nr naturale, afisati
cate dintre nr citite au rasturnatul egal cu primul numar citit
*/
/*
se citesc a si b, calculti cate numere palindrom sunt intre a si b
afisati numerele
*/
/*
sa se afiseze cel mai mic numar care se poate forma cu cifrele lui n,
fiecare cifra repetandu se de tot atatea ori ca si in n 
1204192 -> 112249
*/
/*
se citeste un nr k din intervalul 1..9, afisati toate numerele n formate din k cifre
care au vecinii numere prime
*/

int oglindit(int x)
{
      int aux = 0;
      while (x != 0)
      {
            aux = aux * 10 + x % 10;
            x /= 10;
      }
      return aux;
}

int pb1(int n)
{
      int x, primul, counter = 0;
      cin >> primul;
      for (int i = 1; i < n; i++)
      {
            cin >> x;
            cout << oglindit(x) << '\n';
            if (oglindit(x) == primul)
                  counter++;
      }
      return counter;
}

bool palindrom(int x)
{
      int aux = x, inv = 0;
      while (aux)
      {
            inv = inv * 10 + x % 10;
            aux /= 10;
      }
      if (x == inv)
            return 1;
      else
            return 0;
}

void pb2(int a, int b)
{
      for (int i = a; i <= b; i++)
      {
            if (palindrom(i) == 1)
                  cout << i << " ";
      }
}

void sortare(int a[], int n)
{
      for (int i = 0; i < n - 1; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  if (a[i] > a[j])
                  {
                        int aux = a[i];
                        a[i] = a[j];
                        a[j] = aux;
                  }
            }
      }
}

int pb3(int n)
{
      //sau mai eficient e cu frecventa
      int cif[10], k = 0, aux = n, nr_nou = 0;
      while (aux)
      {
            if (aux % 10 != 0)
                  cif[k++] = aux % 10;
            aux /= 10;
      }
      sortare(cif, k);
      for (int i = 0; i < k; i++)
      {
            nr_nou = nr_nou * 10 + cif[i];
      }
      return nr_nou;
}

bool prim(int x)
{
      if (x < 2 || x > 2 && x % 2 == 0)
            return 0;
      for (int d = 3; d * d <= x; d += 2)
      {
            if (x % d == 0)
                  return 0;
      }
      return 1;
}

void pb4(int k)
{
      int mini = pow(10, k - 1);
      int maxi = pow(10, k);
      for (int i = mini + 1; i < maxi - 2; i++)
      {
            if (prim(i - 1) == 1 && prim(i + 1) == 1)
                  cout << i << " ";
      }
}

int main(int argc, char const *argv[])
{
      pb4(2);
      return 0;
}
