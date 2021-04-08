#include <iostream>
#include <cstdlib>
using namespace std;

int maxneg1 = 0, maxneg2 = 0, max1 = -1, max2 = -1, minneg = -1111111111;

void citire(){
      int n, x;
      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> x;
            if(n == 1){
                  cout << x;
                  exit(0);
            }
            if(x < 0){
                  if(x < maxneg1){
                        maxneg2 = maxneg1;
                        maxneg1 = x;
                  }
                  else if(x < maxneg2){
                        maxneg2 = x;
                  }
                  if(x > minneg)
                        minneg = x;
            }
            else{
                  if(x > max1){
                        max2 = max1;
                        max1 = x;
                  }
                  else if(x > max2){
                        max2 = x;
                  }
            }
      }
}

long long produs(){

      if(maxneg1 < 0 && maxneg2 < 0 && max1 >= 0 && max2 >= 0){
            if(maxneg1 * maxneg2 > max1 * max2) return maxneg1 * maxneg2;
            else return max1 * max2;
      }
      
      else if(maxneg2 == 0 && max2 > 0)
            return max1 * max2;
      
      else if(maxneg2 < 0 && max2 < 0)
            return maxneg1 * maxneg2;

      else
            return max1 * minneg;
      
}

int main(int argc, char const *argv[])
{
      citire();
      cout << produs();
      return 0;
}
