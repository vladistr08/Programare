#include <stdio.h>

int main(int argc, char const *argv[])
{
      char nume1[50], nume2[50], nume3[50];
      int v1, v2, v3;
      float s1, s2, s3;

      printf("Dati nume, varsta si salariu persoana 1:\n");
      scanf("%s%d%f", nume1, &v1, &s1);

      printf("Dati nume, varsta si salariu persoana 2:\n");
      scanf("%s%d%f", nume2, &v2, &s2);

      printf("Dati nume, varsta si salariu persoana 3:\n");
      scanf("%s%d%f", nume3, &v3, &s3);

      return 0;
}
