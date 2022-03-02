#include <iostream>
#include <fstream>

using namespace std;

struct date
{
      int id;
      double pret, volum, greutate;

      void operator=(date aux)
      {
            this->id = aux.id;
            this->pret = aux.pret;
            this->greutate = aux.greutate;
            this->volum = aux.volum;
      }
};

bool comparatorPretCrescator(date o1, date o2)
{
      return o1.pret < o2.pret;
}

bool comparatorVolumDescrescator(date o1, date o2)
{
      return o1.volum > o2.volum;
}

bool comparatorGreutateCrescator(date o1, date o2)
{
      return o1.greutate < o2.greutate;
}

bool comparatorGreutateDescrescator(date o1, date o2)
{
      return o1.greutate > o2.greutate;
}

date *citire(int &n)
{
      ifstream fin("input.in");
      fin >> n;
      date *v = new date[n + 1];
      for (int i = 0; i < n; i++)
      {
            fin >> v[i].id >> v[i].pret >> v[i].volum >> v[i].greutate;
      }
      return v;
}

void QuickSort(date *arr, int st, int dr, bool (*func)(date, date))
{
      int i = st, j = dr;
      date pivot = arr[st + dr / 2];
      while (i <= j)
      {
            while (func(arr[i], pivot) == true)
                  i++;
            while (func(pivot, arr[j]) == true)
                  j--;
            if (i < j)
            {
                  swap(arr[i], arr[j]);
                  i++;
                  j--;
            }
      }
      if (j > st)
            QuickSort(arr, st, j - 1, func);
      if (i < dr)
            QuickSort(arr, i + 1, dr, func);
}

void afisare(int n, date *v)
{
      cout << "\n";
      for (int i = 0; i < n; i++)
      {
            cout << v[i].id << " " << v[i].pret << " " << v[i].volum << " " << v[i].greutate << '\n';
      }
}

int main(int argc, char const *argv[])
{
      int n;
      date *v = citire(n);
      QuickSort(v, 0, n - 1, comparatorPretCrescator);
      afisare(n, v);
      return 0;
}
