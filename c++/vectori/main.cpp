#include <iostream>

using namespace std;

int *citire(int &n)
{
      cin >> n;
      int *v = new int[n];
      for (int i = 0; i < n; i++)
            cin >> v[i];
      return v;
}

void sortare(int n, int *v)
{
      for (int i = 0; i < n / 2 - 1; i++)
            for (int j = i + 1; j < n / 2; j++)
                  if (v[i] > v[j])
                        swap(v[i], v[j]);
      for (int i = n / 2; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                  if (v[i] < v[j])
                        swap(v[i], v[j]);
}

void afisare(int n, int *v)
{
      for (int i = 0; i < n; i++)
            cout << v[i] << " ";
}

int main(int argc, char const *argv[])
{
      int n, *v;
      v = citire(n);
      sortare(n, v);
      afisare(n, v);
      return 0;
}
