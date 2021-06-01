#include <iostream>
#include <fstream>
using namespace std;

void rezolvare(){
      ifstream fin("plopi2.in");
      int n, x, mini = 129293, s = 0, nr = 0;
      fin >> n;
      for(int i = 0; i < n; i++){
            fin >> x;
            if(x < mini)
                  mini = x;
            if(x > mini){
                  nr++;
                  s += x - mini;
            }
      }
      ofstream fout("plopi2.out");
      fout << nr << " " << s;
      fin.close();
      fout.close();
}

int main(int argc, char const *argv[])
{
      rezolvare();
      return 0;
}
