#include <iostream>

using namespace std;


void citire(int &n, int a[1001], int &k, int &s){
      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
      }
      cin >> k;
}

void sortare(int n, int a[1001]){
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

void knr(int n, int a[1001], int k, int s){
      for(int i = 0; i < k; i++){
            if(a[i] < 0){
                  s += -2 * a[i];
            }
            else{
                  s -= 2 * a[i];
            }
      }
      cout << s;
}

int main(int argc, char const *argv[])
{
      int a[1001], n, k, s = 0;
      citire(n, a, k, s);
      sortare(n, a);
      knr(n, a, k, s);
      return 0;
}
