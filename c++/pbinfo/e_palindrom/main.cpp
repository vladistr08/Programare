#include <iostream>

using namespace std;

int n, fr[10001], mini, maxi;

void citire(){
      int x;
      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> x;
            fr[x]++;
            if(x < mini)
                  mini = x;
            if(X > maxi)
                  maxi = x;
      }
}

void palindrom(){
      int okimp = 0;
      for(int i = mini; i <= maxi; i++){
            if(fr[i] % 2 == 1){
                  okimp++;
                  if(okimp > 1){
                        cout << "NU";
                        return;
                  }
            }
      }
      cout << "DA";
}

int main(int argc, char const *argv[])
{
      citire();
      palindrom();
      return 0;
}
