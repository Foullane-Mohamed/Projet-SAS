#include <stdio.h>
#include <string.h>

typedef struct
{
  int numero_unique;
  char nom[50];
  char prenom[50];
  char date_de_naissance[20];
  char departement[20];
  float note_generale;
} Etudiants;

Etudiants etudiant[100];
int count = 0;

void ajouter();
void modifier_supprimer();
void modifier();
void supprimer();
void afficher();
// void afficher_note_generale();
// void afficher_details_personnels();
// void afficher_nemero_unique();
void print_liste_donner(int x);
void moyenne_generale();
void moyenne_generale_departement();
void moyenne_generale_de_luniversit();
void statistiques();
void nombre_detudiants();
// void etudiants_3_meilleures();
void etudiants_reussi();
void Rechercher_etudiant();
void recherche_nom();
void liste_economie();
void liste_math();
void liste_physique();
void liste_departement();

int main()
{
  int choix;
  printf("Gestion des etudiants de luniversite\n");
  do
  {
    printf("1 : Ajouter un etudiant \n");
    printf("2 : Modifier ou supprimer un etudiant \n");
    printf("3 : Afficher les details d'un etudiant \n");
    printf("4 : Calculer la moyenne generale \n");
    printf("5 : Statistiques \n");
    printf("6 : Rechercher un etudiant\n ");
    printf("7 : Trier  etudiant\n ");
    printf("8 : Quitter\n");
    printf("Siser votre choix : ");
    scanf("%d", &choix);
    printf("____________________________________\n");

    switch (choix)
    {
    case 1:
      ajouter();
      break;
    case 2:
      modifier_supprimer();
      break;
    case 3:
      afficher();
      break;
    case 4:
      moyenne_generale();
      break;
    case 5:
      statistiques();
      break;
    case 6:
      Rechercher_etudiant();
      break;
    }

  } while (choix != 9);
}

void ajouter()
{
  char departement[20];
  printf("Siser numero unique de ltudiant : ");
  scanf("%d", &etudiant[count].numero_unique);
  printf("Siser nom de letudiant : ");
  scanf("%s", etudiant[count].nom);
  printf("Siser prénom de letudiant : ");
  scanf("%s", etudiant[count].prenom);
  printf("Siser date de naissance de ltudiant : ");
  scanf("%s", etudiant[count].date_de_naissance);
  int valid = 0;

  do
  {
    printf("Siser departement de letudiant [economie ou math ou physique] : ");
    scanf("%s", etudiant[count].departement);
    if (strcmp(etudiant[count].departement, "economie") == 0 || strcmp(etudiant[count].departement, "math") == 0 || strcmp(etudiant[count].departement, "physique") == 0)
    {

      valid = 1;
    }
    else
    {
      printf("Le departement doit etre [economie ou math ou physique] \n");
    }

  } while (valid != 1);

  printf("Siser note generale de ltudiant : ");
  scanf("%f", &etudiant[count].note_generale);

  count++;
  printf("etudiant est ajoute\n");
}

void modifier_supprimer()
{
  int choix_2;

  do
  {
    printf("1 : pour modifier");
    printf("2 : pour supprimer");
    printf("3 : Quitter le menu modifier/supprimer \n");
    printf("Siser votre choix");

    scanf("%d", &choix_2);
    printf("____________________________________\n");

    switch (choix_2)
    {
    case 1:
      modifier();
      break;
    case 2:
      supprimer();
      break;
    }

  } while (choix_2 != 3);
}
void modifier()
{
  int numero_unique_siser;
  printf("Entrez le numéro unique de l'étudiant a modifier : ");
  scanf("%d", &numero_unique_siser);
  for (int i = 0; i < count; i++)
  {
    if (etudiant[i].numero_unique == numero_unique_siser)
    {
      printf("Modifiez les informations de letudiant\n");
      char departement_2[20];
      printf("Siser numero unique de ltudiant : \n");
      scanf("%d", &etudiant[i].numero_unique);
      printf("Siser nom de letudiant : \n");
      scanf("%s", etudiant[i].nom);
      printf("Siser prénom de letudiant : \n");
      scanf("%s", etudiant[i].prenom);
      printf("Siser date de naissance de ltudiant : \n");
      scanf("%s", etudiant[i].date_de_naissance);

      int valid_2 = 0;

      do
      {
        printf("Siser departement de letudiant [economie ou math ou physique] : \n");
        scanf("%s", etudiant[i].departement);
        if (strcmp(etudiant[i].departement, "economie") == 0 || strcmp(etudiant[i].departement, "math") == 0 || strcmp(etudiant[i].departement, "physique") == 0)
        {

          valid_2 = 1;
        }
        else
        {
          printf("Le departement doit etre [economie ou math ou physique] \n");
        }

      } while (valid_2 != 1);
      printf("Siser note generale de ltudiant : \n");
      scanf("%f", etudiant[i].note_generale);

      printf("Informations detudiant est modifiees \n");
      return;
    }
  }
  printf("etudiant non trouve\n");
}

void supprimer()
{
  int numero_unique_siser_2;
  printf("Entrez le numero unique de letudiant a modifier : \n ");
  scanf("%d", &numero_unique_siser_2);
  for (int i = 0; i < count; i++)
  {
    if (etudiant[i].numero_unique == numero_unique_siser_2)
    {
      for (int j = i; j < count - 1; j++)
      {
        etudiant[j] = etudiant[j + 1];
      }
      count--;
      printf("etudiant est supprime \n");
      return;
    }
  }
  printf("etudiant non trouve\n");
}

void afficher()
{
  for (int i = 0; i < count; i++)
  {

    print_liste_donner(i);
  }
}

void moyenne_generale()
{
  int choix_5;

  do
  {
    printf("1 : la moyenne generale de chaque departement \n");
    printf("2 : la moyenne generale et de luniversite entiere \n");
    printf("3 : Quitter le menu modifier/supprimer \n");
    printf("Siser votre choix");

    scanf("%d", &choix_5);
    printf("____________________________________\n");

    switch (choix_5)
    {
    case 1:
      moyenne_generale_departement();
      break;
    case 2:
      moyenne_generale_de_luniversit();
      break;
    }

  } while (choix_5 != 3);
}

void moyenne_generale_departement()
{
  int count_economie = 0, count_math = 0, count_physique = 0;
  float note_generale_economie = 0, note_generale_math = 0, note_generale_physique = 0;

  float moyenne_generale_economie, moyenne_generale_math, moyenne_generale_physique;

  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].departement, "economie") == 0)
    {
      count_economie++;
      note_generale_economie += etudiant[i].note_generale;
    }
    if (strcmp(etudiant[i].departement, "math") == 0)
    {
      count_math++;
      note_generale_math += etudiant[i].note_generale;
    }
    if (strcmp(etudiant[i].departement, "physique") == 0)
    {
      count_physique++;
      note_generale_physique += etudiant[i].note_generale;
    }
  }
  moyenne_generale_economie = note_generale_economie / count_economie;
  moyenne_generale_math = note_generale_math / count_math;
  moyenne_generale_physique = note_generale_physique / count_physique;

  printf("moyenne générale de leconomie est : %.2f \n", moyenne_generale_economie);
  printf("moyenne générale de math est : %.2f \n", moyenne_generale_math);
  printf("moyenne générale de physique est : %.2f \n", moyenne_generale_physique);
}

void moyenne_generale_de_luniversit()
{
  float moyenne_generale_total = 0.00, moyenne_generale_calc = 0.00;
  for (int i = 0; i < count; i++)
  {
    moyenne_generale_total += etudiant[i].note_generale;
  }

  moyenne_generale_calc = moyenne_generale_total / count;
  printf("la moyenne generale de luniversite est : %.2f \n", moyenne_generale_calc);
}

void statistiques()
{
  int choix_6;

  do
  {
    printf("1 : nombre total detudiants inscrits\n");
    printf("2 :  nombre detudiants dans chaque departement\n ");
    printf("3 : les etudiants ayant une moyenne generale superieure e un certain seuil\n ");
    printf("4 : les 3 etudiants ayant les meilleures notes ");
    printf("5 : Afficher le nombre detudiants ayant reussi dans chaque departement\n ");
    printf("6 : Quitter le menu dafficher \n");
    printf("Siser votre choix : ");

    scanf("%d", &choix_6);
    printf("____________________________________\n \n");

    switch (choix_6)
    {
    case 1:
      printf("le nombre total detudiants inscrits est : %d \n", count);
      break;
    case 2:
      nombre_detudiants();
    //     break;
    // case 3:
    //     etudiants_3_meilleures();
    //     break;
    case 4:
      etudiants_reussi();
      break;
    }

  } while (choix_6 != 7);
}

void nombre_detudiants()
{
  int nombre_economie = 0, nombre_math = 0, nombre_physique = 0;
  for (int i = 0; i < count; i++)
  {

    if (strcmp(etudiant[i].departement, "economie") == 0)
    {
      nombre_economie++;
    }
    else if ((etudiant[i].departement, "math") == 0)
    {
      nombre_math++;
    }
    else if ((etudiant[i].departement, "physique") == 0)
    {
      nombre_physique++;
    }
  }
  printf("le nombre detudiants economie est : %d \n", nombre_economie);
  printf("le nombre detudiants math est : %d \n", nombre_math);
  printf("le nombre detudiants physique est : %d \n", nombre_physique);
}

// void etudiants_3_meilleures()
// {

// }

void etudiants_reussi()
{
  int numbre_reusite = 0;
  for (int i = 0; i < count; i++)
  {
    if (etudiant[i].note_generale >= 10)
    {
      numbre_reusite++;
    }
  }
  printf(" le nombre detudiants ayant reussi est : %d\n", numbre_reusite);
}
void Rechercher_etudiant()
{
  int choix_7;

  do
  {
    printf("1 : Rechercher un etudiant par son nom\n");
    printf("2 : liste departement specifique\n");

    printf("Siser votre choix : ");

    scanf("%d", &choix_7);
    printf("____________________________________\n");

    switch (choix_7)
    {
    case 1:
      recherche_nom();
      break;
    case 2:
      liste_departement();
      break;
    }

  } while (choix_7 != 7);
}
void recherche_nom()
{
  char nom_saiser[100];
  printf("Entrez le nom de l'étudiant a afficher : ");
  scanf("%s", &nom_saiser);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].nom, nom_saiser) == 0)
    {

      printf("numero unique de ltudiant est : %d \n \n", etudiant[i].numero_unique);

      printf("nom de letudiant est : %s \n \n", etudiant[i].nom);

      printf("prenom de letudiant est : %s \n \n", etudiant[i].prenom);

      printf("date de naissance de ltudiant est : %s \n \n", etudiant[i].date_de_naissance);

      printf("departement de ltudiant est : %s \n \n", etudiant[i].departement);
      printf("Siser  ");
      printf("note generale de ltudiant est : %f \n \n", &etudiant[i].note_generale);

      return;
    }
  }
}

void liste_departement()
{
  int choix_8;
  do
  {
    printf("1 : Afficher la liste des étudiants economie : \n");
    printf("2 : Afficher la liste des étudiants math : \n");
    printf("3 : Afficher la liste des étudiants physique : \n");

    printf("Siser votre choix : ");

    scanf("%d", &choix_8);
    printf("____________________________________\n");

    switch (choix_8)
    {
    case 1:
      liste_economie();
      break;
    case 2:
      liste_math();
      break;
    case 3:
      liste_physique();
      break;
    }

  } while (choix_8 != 4);
}
void liste_economie()
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].departement, "economie") == 0)
    {
      print_liste_donner(i);
    }
  }
}
void liste_math()
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].departement, "math") == 0)
    {
      print_liste_donner(i);
    }
  }
}
void liste_physique()
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].departement, "physique") == 0)
    {
      print_liste_donner(i);
    }
  }
}
void print_liste_donner(int x_count)
{
  printf("____________________________________________________________");
  printf("numero unique de ltudiant est : %d \n", etudiant[x_count].numero_unique);

  printf("nom de letudiant est : %s \n", etudiant[x_count].nom);

  printf("prenom de letudiant est : %s \n", etudiant[x_count].prenom);

  printf("date de naissance de ltudiant est : %s \n", etudiant[x_count].date_de_naissance);

  printf("departement de ltudiant est : %s \n", etudiant[x_count].departement);
  printf("Siser  ");
  printf("note generale de ltudiant est : %f \n", etudiant[x_count].note_generale);
}

// void afficher_details_personnels()
// {
//     int choix_4;

//     do
//     {
//         printf("1 : Afficher details détudiant a Numéro unique ");
//         printf("2 : Afficher details detudiant a Nom ");
//         printf("3 : Quitter le menu dafficher \n");
//         printf("Siser votre choix");

//         scanf("%d", &choix_4);
//         printf("____________________________________\n");

//         switch (choix_4)
//         {
//         case 1:
//             nombre_total_detudiants();
//             break;
//         case 2:
//             afficher_nom();
//             break;
//         }

//     } while (choix_4 != 3);
// }

// void afficher_note_generale()
// {
//     int note_generale_saiser;
//     printf("Entrez le note general de l'étudiant a afficher : ");
//     scanf("%d", &note_generale_saiser);
//     for (int i = 0; i < count; i++)
//     {
//         if (etudiant[i].note_generale == note_generale_saiser)
//         {

//             printf("numero unique de ltudiant est : %d", etudiant[i].numero_unique);

//             printf("nom de letudiant est : %s", etudiant[i].nom);

//             printf("prenom de letudiant est : %s", etudiant[i].prenom);

//             printf("date de naissance de ltudiant est : %s", etudiant[i].date_de_naissance);

//             printf("departement de ltudiant est : %s", etudiant[i].departement);
//             printf("Siser  ");
//             printf("note generale de ltudiant est : %f", &etudiant[i].note_generale);

//             return;
//         }
//     }
// }
