#include <iostream>

using namespace std;

int n, a[101];

void citire(){
      cin >> n;
      for(int i = 0; i < n; i++)
            cin >> a[i];
}

void sortare(){
      for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                  if(a[i] > a[j]){
                        a[i] ^= a[j];
                        a[j] ^= a[i];
                        a[i] ^= a[j];
                  }
            }
      }
}

void afisare(){
      if(a[0] != 1){
            cout << 1;
            return;
      }
      else{
            int ant = 1;
            for(int i = 1; i < n; i++){
                  if(a[i] != ant + 1 && a[i] != ant){
                        cout << ant + 1;
                        return;
                  }
                  ant = a[i];
            }
            cout << ant + 1;
      }
}

int main(int argc, char const *argv[])
{
      citire();
      sortare();
      afisare();
      return 0;
}
