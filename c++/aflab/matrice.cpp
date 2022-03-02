#include <iostream>

using namespace std;

struct MatriceEconomica
{
      int val, lin, col;
};

void citireMatrice(int n, MatriceEconomica M[])
{
      for (int i = 0; i < n; i++)
      {
            cin >> M[i].val;
      }
      for (int i = 0; i < n; i++)
      {
            cin >> M[i].lin;
      }
      for (int i = 0; i < n; i++)
      {
            cin >> M[i].col;
      }
}

void afisareMatrice(int n, int **matrice)
{
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cout << matrice[i][j] << " ";
            }
            cout << '\n';
      }
}

int **contruiesteMatrice(int n, MatriceEconomica M[], int dim)
{
      int **matrix = new int *[n];
      for (int i = 0; i < n; i++)
            matrix[i] = new int[n];

      for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                  matrix[i][j] = 0;

      for (int i = 0; i < dim; i++)
            matrix[M[i].lin][M[i].col] = M[i].val;

      return matrix;
}

void adunaMatrice(int dim, int n, int m, MatriceEconomica A[], MatriceEconomica B[])
{
      MatriceEconomica C[15];
      int k = n;
      for (int i = 0; i < n; i++)
      {
            C[i].lin = A[i].lin;
            C[i].col = A[i].col;
            C[i].val = A[i].val;
      }
      for (int i = 0; i < m; i++)
      {
            int j = 0, ok = 0;
            while (B[i].lin <= A[j].lin)
            {
                  if (B[i].lin == A[j].lin && B[i].col == A[j].col)
                  {
                        C[i].val += B[i].val;
                        ok = 1;
                  }
                  j++;
            }
            if (ok == 0)
            {
                  C[k].val = B[i].val;
                  C[k].lin = B[i].lin;
                  C[k++].col = B[i].col;
            }
      }
      afisareMatrice(dim, contruiesteMatrice(k, C, dim));
}

int main(int argc, char const *argv[])
{
      MatriceEconomica A[10], B[10], C[10];
      int n, m, k = 0, dim;
      cin >> dim;
      cin >> n;
      citireMatrice(n, A);
      cout << '\n';
      afisareMatrice(dim, contruiesteMatrice(dim, A, n));
      cout << '\n';
      cin >> m;
      citireMatrice(m, B);
      cout << '\n';
      afisareMatrice(dim, contruiesteMatrice(dim, B, m));
      cout << '\n';

      adunaMatrice(dim, n, m, A, B);

      return 0;
}
