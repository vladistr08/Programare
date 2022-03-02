#include <stdio.h>
#include <stdlib.h>

void alocare(int n, int m, int ***a)
{
      *a = (int **)malloc(n * sizeof(int *));
      for (int i = 0; i < n; i++)
      {
            (*a)[i] = (int *)malloc(m * sizeof(int));
      }
}

void citire(int n, int m, int **a)
{
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  scanf("%d", &(a[i][j]));
            }
      }
}

void afisare(int n, int m, int **a)
{
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  printf("%d ", a[i][j]);
            }
            printf("\n");
      }
}

void eliminare(int n, int m, int **a)
{
      for (int i = 0; i < n; i++)
      {
            free(a[i]);
      }
      free(a);
}

int **adunareMatrici(int n, int m, int **a, int **b)
{
      int **c;
      alocare(n, m, &c);
      for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                  c[i][j] = a[i][j] + b[i][j];
      return c;
}

int main(int argc, char const *argv[])
{
      int n, m, **a, **b;
      scanf("%d%d", &n, &m);
      alocare(n, m, &a);
      alocare(n, m, &b);
      citire(n, m, a);
      citire(n, m, b);
      afisare(n, m, adunareMatrici(n, m, a, b));
      eliminare(n, m, a);
      eliminare(n, m, b);
      return 0;
}
