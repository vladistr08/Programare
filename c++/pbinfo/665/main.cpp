#include <iostream>

using namespace std;

int n, a[1001], b[1001], na1, na2, nb1, nb2, nr;

void citire(){
      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1)
                  na1++;
            else
                  na2++;
      }

      for(int i = 0; i < n; i++){
            cin >> b[i];
            if(a[i] == 1)
                  nb1++;
            else
                  nb2++;
      }
      if(na1 > nb1){
            nb2 -= na1 - nb1;
            nb1 += na1 - nb1;
            nr += na1 - nb1;
      }
      else if(na1 < nb1){
            nb2 += nb1 - na1;
            nb1 -= nb1 - na1;
            nr += nb1 - na1;
      }
}

void cauta(){
      int c1 = 0, c2 = 0;
      for(int i = 0; i < n; i++){
            if(b[i] == 1 && a[i] == 2){
                  c1++;
            }
            else if(b[i] == 2 && a[i] == 1){
                  c2++;
            }
            else{
                  continue;
            }
      }
      
}

int main(int argc, char const *argv[])
{
      
      return 0;
}
