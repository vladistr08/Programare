#include <stdio.h>
/*
      -> o functie care citeste o adresa dintr un fisier si se transimte ca parametru
      fisieru
      ->afisare adresa
      ->compara adrese
      ->se citesc n adrese, sa se aloce dinamic si sa se afiseze srada cu cel mai
      lung nume, iar intr un fisier binar sa se scrie toate adresele sortate dupa
      strada, nr, bl, sc, ap
*/
typedef struct Adresa
{
      char strada[30];
      int numar, bloc, apartament;
      char scara;
} Adresa;

void inputAdresa(FILE *fis, Adresa *date)
{
      fis = fopen("input.in", "rw");
      fgets(date->strada, 30, fis);
      fscanf(fis, "%d%d%d\n%c", &(date->numar), &(date->bloc), &(date->apartament), &(date->scara));
}

void afisareAdresa(Adresa date)
{
      printf("%sNr.%d Bloc.%d ap.%d sc.%c", date.strada, date.numar, date.bloc, date.apartament, date.scara);
}

void comparareAdrese(Adresa date1, Adresa date2)
{
      //0 daca 1 < 2 si 1 daca 1 > 2
}

int main(int argc, char const *argv[])
{
      FILE *fis;
      Adresa a;
      inputAdresa(fis, &a);
      afisareAdresa(a);
      return 0;
}
