#include <stdio.h>

char *palindrom(int x)
{
      int aux = x, inv = 0;
      while (aux)
      {
            inv = inv * 10 + aux % 10;
            aux /= 10;
      }
      return inv == x ? "DA" : "NU";
}

int main(int argc, char const *argv[])
{
      int nemaPute;
      scanf("%d", &nemaPute);
      printf("%s", palindrom(nemaPute));
      return 0;
}
