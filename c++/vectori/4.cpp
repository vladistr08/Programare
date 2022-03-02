#include <iostream>
#include <fstream>
using namespace std;

void citire(int &n, int v[])
{
      ifstream fin("fisier.in");
      n = 0;
      int x;
      while (fin >> x)
            v[n++] = x;
}

bool isSorted(int n, int v[])
{
      for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1])
                  return false;
      return true;
}

void deleteElement(int &n, int v[], int poz)
{
      for (int i = poz; i < n - 1; i++)
            v[i] = v[i + 1];
      n--;
}

void insertElement(int &n, int v[], int poz, int el)
{
      for (int i = n; i > poz; i--)
            v[i] = v[i - 1];
      v[poz] = el;
      n++;
}

int findWrongElement(int n, int v[])
{
      int wrong = 0, poz = -1;
      if (v[0] > v[1])
      {
            wrong++;
            poz = 0;
      }
      for (int i = 1; i < n - 1; i++)
            if ((v[i] > v[i + 1] && v[i] > v[i - 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]) || (i == poz + 1 && v[i] == v[i - 1]))
            {
                  wrong++;
                  poz = i;
            }
      return wrong == 1 ? poz : -1;
}

int findInsertPoint(int n, int v[], int el)
{
      if (el < v[0])
            return 0;
      for (int i = 1; i < n; i++)
      {
            if (el <= v[i] && el >= v[i - 1])
                  return i;
      }
      return n;
}

void afisare(int n, int v[])
{
      for (int i = 0; i < n; i++)
            cout << v[i] << " ";
}

void rezolvare(int n, int v[])
{
      if (isSorted(n, v) == true)
      {
            int x;
            cout << "Vectorul este sortat, introduceti elementul de inserat: ";
            cin >> x;
            cout << '\n';
            insertElement(n, v, findInsertPoint(n, v, x), x);
            afisare(n, v);
      }
      else
      {
            if (findWrongElement(n, v) != -1)
            {
                  deleteElement(n, v, findWrongElement(n, v));
                  cout << "Vectorul a fost refacut!\n";
                  afisare(n, v);
            }
            else
            {
                  cout << "Vectorul nu este ok!\n";
            }
      }
}

int main(int argc, char const *argv[])
{
      int n, v[100];
      citire(n, v);
      rezolvare(n, v);
      return 0;
}
