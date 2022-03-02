#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> citire(int &n)
{
      ifstream fin("input.in");

      fin >> n;
      vector<vector<int>> vect;

      int input;
      for (int i = 0; i < n; i++)
            while ((fin >> input) && (fin.peek() != '\n'))
                  vect[i].push_back(input);
      return vect;
}

void afisareStraziPopulare(int n, vector<vector<int>> vect)
{
      cout << '\n';
      for (int i = 0; i < n; i++)
      {
            for (auto it = vect[i].begin(); it != vect[i].end(); it++)
            {
                  if (*it >= 500)
                  {
                        cout << i << " - " << it - vect[i].begin() << " - " << *it << '\n';
                  }
            }
      }
      cout << '\n';
}

void quickSort(int st, int dr, vector<int> v)
{
      int i = st, j = dr;
      int pivot = v[(st + dr) / 2];
      while (i < j)
      {
            while (v[i] > pivot)
                  i++;
            while (v[j] < pivot)
                  j--;
            if (i < j)
            {
                  swap(v[i], v[j]);
                  i++;
                  j--;
            }
      }
      if (j > st)
            quickSort(st, j - 1, v);
      if (i < dr)
            quickSort(i + 1, dr, v);
}

void sortareCartiere(int n, vector<vector<int>> vect)
{
      for (int i = 0; i < n; i++)
      {
            int st = 0, dr = vect[i].size() - 1;
            quickSort(st, dr, vect[i]);
      }
}

void afisareCartiere(int n, vector<vector<int>> vect)
{
      cout << '\n';
      for (int i = 0; i < n; i++)
      {
            for (auto it = vect[i].begin(); it != vect[i].end(); it++)
            {
                  cout << *it << " ";
            }
            cout << '\n';
      }
      cout << '\n';
}

int sumaVector(vector<int> vect)
{
      int s = 0;
      for (auto it : vect)
            s += it;
      return s;
}

void maxSuma(int n, vector<vector<int>> vect)
{
      int maxiSuma = -1, nrCartier = -1;
      for (int i = 0; i < n; i++)
      {
            int sumaCurenta = sumaVector(vect[i]);
            if (sumaCurenta > maxiSuma)
            {
                  maxiSuma = sumaCurenta;
                  nrCartier = i;
            }
      }
      cout << nrCartier << " -> " << maxiSuma << '\n';
}

int main(int argc, char const *argv[])
{
      int n;
      cout << "ok";
      vector<vector<int>> v = citire(n);
      cout << "ok";
      afisareStraziPopulare(n, v);
      cout << "ok";
      sortareCartiere(n, v);
      cout << "ok";
      afisareCartiere(n, v);
      cout << "ok";
      maxSuma(n, v);
      return 0;
}
