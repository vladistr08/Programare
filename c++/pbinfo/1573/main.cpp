#include <iostream>
#include <climits>
using namespace std;

int n, a[2501], r, maxi = INT_MIN;

void citire(){
      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > maxi)
                  maxi = a[i];
      }
}

int verifica_divizori(int d){
      for(int i = 0; i < n; i++){
            if(a[i] % d != 0)
                  return 0;
      }
      return 1;
}

void verifica(){
      for(int d = 2; d * d <= maxi; d++){
            if(maxi % d == 0){
                  if(verifica_divizori(d) == 1){
                        cout << "DA";
                        return;
                  }
                  if(verifica_divizori(maxi/d) == 1){
                        cout << "DA";
                        return;
                  }
            }
      }
      cout << "NU";
}

int main(int argc, char const *argv[])
{
      citire();
      verifica();
      return 0;
}
