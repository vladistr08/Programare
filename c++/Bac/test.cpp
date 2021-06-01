#include <iostream>

using namespace std;

void f(int x){
      cout<<x;
      while(x>0){
            f(x-1);
            x--;
      }
}

int main(int argc, char const *argv[])
{
      f(3);
      return 0;
}
