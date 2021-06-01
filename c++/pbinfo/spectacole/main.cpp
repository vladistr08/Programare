#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

struct spec{
      int nr = 0;
      bool st = false, sf = false;
}a[1000000];

int mini = 100000001, maxi = -1;

void citire(){
      int n ,x , y;
      fin >> n;
      for(int i = 0; i < n; i++){
            fin >> x >> y;
            if(x < mini)
                  mini = x;
            if(y > maxi)
                  maxi = y;
            for(int j = x; j <= y; j++){
                  a[j].nr++;
            }
            a[x].st = true;
            a[y].sf = true;
      } 
}

void nr_spec(){
      int i = mini, nr = 0;
      while(i <= maxi){
            if(a[i].st == true){
                  int ok = 1;
                  while(a[i].sf == false){
                        if(a[i].st == true || a[i].nr > 1){
                              ok = 0;
                              break;
                        }
                        i++;
                  }
                  if(ok == 1)
                        nr++;
            }
            i++;
      }
      fout << nr;
}

int main(int argc, char const *argv[])
{
      citire();
      nr_spec();
      return 0;
}
