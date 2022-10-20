#include <stdio.h>
#include <malloc.h>

void input(int *t, int *n, int **a)
{
}

void run()
{
      int t, n;
      scanf("%d%d", &t, &n);
      int *a = (int *)malloc(n * sizeof(int));
      for (int i = 0; i < n; i++)
      {
            scanf("%d", a[i]);
      }
}

int main(int argc, char const *argv[])
{

      return 0;
}
