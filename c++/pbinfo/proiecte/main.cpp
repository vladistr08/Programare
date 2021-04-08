#include <iostream>
#include <fstream>

using namespace std;

struct aux{
      int apoz[101], k;
}fr[101];

int n, x;

void citire(){
      ifstream fin("proiecte.in");
      fin >> n;
      for(int i = 1; i <= n; i++){
            fin >> x;
            fr[x].apoz[fr[x].k++] = i;
      }
      ofstream fout("proiecte.out");
      for(int i = 1; i <= 100; i++){
            for(int j = 0; j < fr[i].k; j++){
                  fout << fr[i].apoz[j] << " ";
            }
      }
}

int main(int argc, char const *argv[])
{
      citire();
      return 0;
}
