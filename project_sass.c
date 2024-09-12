#include <stdio.h>
#include <string.h>

typedef struct
{
  int numero_unique;
  char nom[100];
  char prenom[100];
  char date_de_naissance[50];
  char departement[50];
  float note_generale;
} Etudiants;

Etudiants etudiant[100];
int count = 0;

void ajouter();
void modifier_supprimer();
void modifier();
void supprimer();
void afficher();
void print_liste_donner(int x);
void moyenne_generale();
void moyenne_generale_departement();
void moyenne_generale_de_luniversit();
void statistiques();
void nombre_detudiants();
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
    printf("3 : Afficher les details dun etudiant \n");
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
    case 7:

      break;

    default:
      printf("votre choix est invalide\n");
    }

  } while (choix != 8);

  return 0;
}

void ajouter()
{
  char departement[20];
  printf("Siser numero unique de l'etudiant : ");
  scanf("%d", &etudiant[count].numero_unique);
  printf("Siser nom de l'etudiant : ");
  scanf("%s", etudiant[count].nom);
  printf("Siser prenom de l'etudiant : ");
  scanf("%s", etudiant[count].prenom);
  printf("Siser date de naissance de l'etudiant : ");
  scanf("%s", etudiant[count].date_de_naissance);

  int valid = 0;

  do
  {
    printf("Siser departement de l'etudiant [economie ou math ou physique] : ");
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

  printf("Siser note generale de l'etudiant : ");
  scanf("%f", &etudiant[count].note_generale);
  printf("____________________________________\n");

  count++;
  printf("etudiant est ajoute\n");
}

void modifier_supprimer()
{
  int choix_2;
  printf("____________________________________\n");

  printf("1 : pour modifier \n");
  printf("2 : pour supprimer \n");
  printf("3 : Quitter le menu modifier/supprimer \n");
  printf("Siser votre choix \n");

  scanf("%d", &choix_2);
  printf("____________________________________\n \n");

  switch (choix_2)
  {
  case 1:
    modifier();
    break;
  case 2:
    supprimer();
    break;
  case 3:
    return;
  default:
    printf("votre Choix est invalide\n");
  }
}

void modifier()
{
  int numero_unique_siser;
  printf("Entrez le numéro unique de l'étudiant à modifier : ");
  scanf("%d", &numero_unique_siser);
  for (int i = 0; i < count; i++)
  {
    if (etudiant[i].numero_unique == numero_unique_siser)
    {
      printf("Modifiez les informations de l'etudiant\n");
      printf("Siser numero unique de l'etudiant : \n");
      scanf("%d", &etudiant[i].numero_unique);
      printf("Siser nom de l'etudiant : \n");
      scanf("%s", etudiant[i].nom);
      printf("Siser prénom de l'etudiant : \n");
      scanf("%s", etudiant[i].prenom);
      printf("Siser date de naissance de l'etudiant : \n");
      scanf("%s", etudiant[i].date_de_naissance);

      int valid_2 = 0;
      do
      {
        printf("Siser departement de l'etudiant [economie ou math ou physique] : \n");
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

      printf("Siser note generale de l'etudiant : \n");
      scanf("%f", &etudiant[i].note_generale);

      printf("Informations de l'etudiant sont modifiees \n");
      return;
    }
  }
  printf("Etudiant non trouve\n");
}

void supprimer()
{
  int numero_unique_siser_2;
  printf("Entrez le numero unique de letudiant a supprimer : \n ");
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
      printf("Etudiant est supprime \n");
      return;
    }
  }
  printf("Etudiant non trouve\n");
}

void afficher()
{
  for (int i = 0; i < count; i++)
  {
    printf("____________________________________\n");
    print_liste_donner(i);
    printf("____________________________________\n");
  }
}
void print_liste_donner(int x_count)
{
  printf("____________________________________________________________\n");
  printf("Numero unique de l'etudiant est : %d \n", etudiant[x_count].numero_unique);
  printf("Nom de l'etudiant est : %s \n", etudiant[x_count].nom);
  printf("Prenom de l'etudiant est : %s \n", etudiant[x_count].prenom);
  printf("Date de naissance de l'etudiant est : %s \n", etudiant[x_count].date_de_naissance);
  printf("Departement de l'etudiant est : %s \n", etudiant[x_count].departement);
  printf("Note generale de l'etudiant est : %.2f \n", etudiant[x_count].note_generale);
}

void moyenne_generale()
{
  int choix_5;

  printf("1 : la moyenne generale de chaque departement \n");
  printf("2 : la moyenne generale de luniversite entiere \n");
  printf("3 : Quitter le menu moyenne generale \n");
  printf("Siser votre choix: ");

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
  case 3:
    return;
  default:
    printf("votre hoix est invalide\n");
  }
}

void moyenne_generale_departement()
{
  int count_economie = 0, count_math = 0, count_physique = 0;
  float note_generale_economie = 0, note_generale_math = 0, note_generale_physique = 0;

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
  float moyenne_generale_economie = (count_economie > 0) ? (note_generale_economie / count_economie) : 0;
  float moyenne_generale_math = (count_math > 0) ? (note_generale_math / count_math) : 0;
  float moyenne_generale_physique = (count_physique > 0) ? (note_generale_physique / count_physique) : 0;

  printf("Moyenne générale de l'économie est : %.2f \n", moyenne_generale_economie);
  printf("Moyenne générale de math est : %.2f \n", moyenne_generale_math);
  printf("Moyenne générale de physique est : %.2f \n", moyenne_generale_physique);
}

void moyenne_generale_de_luniversit()
{
  float moyenne_generale_total = 0.00;
  for (int i = 0; i < count; i++)
  {
    moyenne_generale_total += etudiant[i].note_generale;
  }

  float moyenne_generale_calc = (count > 0) ? (moyenne_generale_total / count) : 0;
  printf("La moyenne generale de l'universite est : %.2f \n", moyenne_generale_calc);
}

void statistiques()
{
  int choix_6;

  do
  {
    printf("1 : nombre total d'etudiants inscrits\n");
    printf("2 : nombre d'etudiants dans chaque departement\n");
    printf("3 : les etudiants ayant une moyenne generale superieure a un certain seuil\n");
    printf("4 : les 3 etudiants ayant les meilleures notes\n");
    printf("5 : Afficher le nombre detudiants ayant reussi dans chaque departement\n");
    printf("6 : Quitter le menu statistiques \n");
    printf("Siser votre choix : ");

    scanf("%d", &choix_6);
    printf("____________________________________ \n");

    switch (choix_6)
    {
    case 1:
      printf("Le nombre total d'etudiants inscrits est : %d \n", count);
      break;
    case 2:
      nombre_detudiants();
      break;
    case 3:

      break;
    case 4:
      etudiants_reussi();
      break;
    case 5:

      break;
    case 6:
      return;
    }

  } while (choix_6 != 6);
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
    else if (strcmp(etudiant[i].departement, "math") == 0)
    {
      nombre_math++;
    }
    else if (strcmp(etudiant[i].departement, "physique") == 0)
    {
      nombre_physique++;
    }
  }
  printf("Le nombre d'etudiants en economie est : %d \n", nombre_economie);
  printf("Le nombre d'etudiants en math est : %d \n", nombre_math);
  printf("Le nombre d'etudiants en physique est : %d \n", nombre_physique);
}

void etudiants_reussi()
{
  int nombre_reusite = 0;
  for (int i = 0; i < count; i++)
  {
    if (etudiant[i].note_generale >= 10)
    {
      nombre_reusite++;
    }
  }
  printf("Le nombre detudiants reussi est : %d\n", nombre_reusite);
}

void Rechercher_etudiant()
{
  int choix_7;

  do
  {
    printf("1 : Rechercher un etudiant par son nom\n");
    printf("2 : Liste departement specifique\n");
    printf("3 : Quitter le menu de recherche\n\n");
    printf("    Siser votre choix : ");

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
    case 3:
      return;
    default:
      printf("Choix invalide. Veuillez essayer de nouveau.\n");
    }

  } while (choix_7 != 3);
}

void recherche_nom()
{
  char nom_saiser[100];
  printf("Entrez le nom de l'etudiant a afficher : ");
  scanf("%s", nom_saiser);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(etudiant[i].nom, nom_saiser) == 0)
    {
      printf("Numero unique de l'etudiant est : %d \n", etudiant[i].numero_unique);
      printf("Nom de l'etudiant est : %s \n", etudiant[i].nom);
      printf("Prenom de l'etudiant est : %s \n", etudiant[i].prenom);
      printf("Date de naissance de l'etudiant est : %s \n", etudiant[i].date_de_naissance);
      printf("Departement de l'etudiant est : %s \n", etudiant[i].departement);
      printf("Note generale de l'etudiant est : %.2f \n", etudiant[i].note_generale);
      return;
    }
  }
  printf("etudient non existe\n");
}

void liste_departement()
{
  int choix_8;
  do
  {
    printf("1 : Afficher la liste des étudiants economie : \n");
    printf("2 : Afficher la liste des étudiants math : \n");
    printf("3 : Afficher la liste des étudiants physique : \n");
    printf("4 : Quitter le menu liste departement\n");

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
    case 4:
      return;
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
