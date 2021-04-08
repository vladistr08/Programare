#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("masini.in");
ofstream fout("masini.out");

int n, t, fr[101];
int mini = 101, maxi = 0;

void citire(){
      fin >> n >> t;
      int x;
      for(int i = 0; i < n; i++){
            fin >> x;
            fr[x]++;
            if(x < mini)
                  mini = x;
            if(x > maxi)
                  maxi = x;
      }
}

int nr_masini(){
      int nr = 0, tcurent = 0;
      for(int i = mini; i <= maxi; i++){
            //cout << i << " " << fr[i] << "  ";
            while(fr[i] != 0){
                  if(tcurent + i <= t){
                        tcurent += i;
                        nr++;
                  }
                  else
                        return nr;
                  fr[i]--;
            }
      }
      return nr;
}

int main(int argc, char const *argv[])
{
      citire();
      fout << nr_masini();
      return 0;
}
