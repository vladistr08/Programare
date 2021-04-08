#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

int n, e;
long long sum;
void citire(){
      fin >> sum >> n >> e;
}

int power[12];

void afisare(){
      int nr = 0;
      for(int i = 9; i >= 0; i--){
            if(power[i] != 0){
                  fout << pow(e, i) << " " << power[i] << '\n';
                  nr += power[i]; 
            }
      }
      fout << nr;
}

void backtr(long long s, int p){
      if(s == sum){
            afisare();
            exit(0);
      }
      if(s > sum){
            return;
      }
      for(int i = p; i >= 0; i--){
            s += pow(e, i);
            power[i]++;
            backtr(s, i);
            s -= pow(e, i);
            power[i]--;
      }
}

int main(int argc, char const *argv[])
{
      citire();
      backtr(0, n);
      return 0;
}
