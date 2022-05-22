#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etudiant
{
    int age,id;
    char nom[10],prenom[10],sex;
}etudiant;

typedef struct module
{
    int identifiant;
    char inti[10],prof[10];
}module;

typedef struct note
{
    etudiant et;
    module mt;
    float notes;
}note;

typedef struct cellule1
{
  etudiant e;
  struct cellule1 *next;
}cellule1;

typedef struct cellule2
{
  module m;
  struct cellule2 *next;
}cellule2;

typedef struct cellule3
{
  note n;
  struct cellule3 *next;
}cellule3;

cellule1* creer1(char n[], char p[], char s, int a, int idet)
{
    cellule1 *c;

    c=(cellule1*)malloc(sizeof(cellule1));
    strcpy((*c).e.nom,n);
    strcpy((*c).e.prenom,p);
    (*c).e.sex=s;
    (*c).e.age=a;
    (*c).e.id=idet;
     c->next=NULL;

    return c;
}

cellule2* creer2(char intit[], char prf[] , int ident)
{
    cellule2 *l;

    l=(cellule2*)malloc(sizeof(cellule2));
    strcpy((*l).m.inti,intit);
    strcpy((*l).m.prof,prf);
    (*l).m.identifiant=ident;
     l->next=NULL;

     return l;
}

cellule3* creer(cellule1* l1, cellule2* l2, float no)
{
    cellule3 *l;

    l=(cellule3*)malloc(sizeof(cellule3));
    strcpy(l->n.et.nom,(*l1).e.nom);
    l->n.et.id=(*l1).e.id;
    strcpy(l->n.mt.inti,(*l2).m.inti);
    l->n.mt.identifiant=(*l2).m.identifiant;
    l->n.notes=no;
    l->next=NULL;

    return l;
}

cellule1* saisie(cellule1 *debut1, char n[], char p[], char s, int a, int idet)
{
    cellule1 *c=creer1(n,p,s,a,idet);
    c->next=debut1;
    return c;
}

cellule2* saisiem(cellule2* debut2, char intit[], char prf[] , int ident)
{
    cellule2 *l=creer2(intit,prf,ident);
    l->next=debut2;
    return l;
}

void affiche1(cellule1 *debut)
{
    if(debut==NULL)
    printf("aucun etudiant enregiste");
    while(debut!=NULL)
    {
    printf("%s %s %c %d %d\n",debut->e.nom,debut->e.prenom,debut->e.sex,debut->e.age,debut->e.id);
    debut=debut->next;
    }
    printf("\n");
}

void affiche2(cellule2 *debut)
{
    if(debut==NULL)
    printf("aucun module enregistre");
    while(debut!=NULL)
    {
    printf("%s %s %d\n",debut->m.inti,debut->m.prof,debut->m.identifiant);
    debut=debut->next;
    }
    printf("\n");
}

void affiche3(cellule3 *debut)
{
    if(debut==NULL)
    printf("aucune note enregistre");

    while(debut!=NULL)
    {
    printf("id : %d nom :%s note :%.2f en matiere de :%s d'identifiant %d\n",debut->n.et.id,debut->n.et.nom,debut->n.notes,debut->n.mt.inti,debut->n.mt.identifiant);
    debut=debut->next;
    }
    printf("\n");
}

int exist1(cellule1* debut, int n)
{
    cellule1* l1=debut;

    while(l1!=NULL)
    {
       if(l1->e.id==n)
       {
        return 1;
       }
       l1=l1->next;
    }

    return 0;
}

int exist2(cellule2* debut, int in)
{
    cellule2* l1=debut;

    while(l1!=NULL)
    {
       if(l1->m.identifiant==in)
       {
        return 1;
       }
       l1=l1->next;
    }

    return 0;
}

int rechercheetn(cellule1* debut1, char n[])
{
    cellule1* l1=debut1;

    while(l1!=NULL)
    {
       if(strcmp((*l1).e.nom,n)==0)
       {
        return 1;
       }
       l1=l1->next;
    }

    return 0;
}

cellule1* rechercheetnr(cellule1* debut1, char n[])
{
    cellule1* l1=debut1;

    while(l1!=NULL)
    {
       if(strcmp((*l1).e.nom,n)==0)
       {
        return l1;
       }
       l1=l1->next;
    }

}

cellule1* rechercheetnr1(cellule1* debut1, int n)
{
    cellule1* l1=debut1;

    while(l1!=NULL)
    {
       if((*l1).e.id==n)
       {
        return l1;
       }
       l1=l1->next;
    }

}

int recherchemoi(cellule2* debut2, char in[])
{
   cellule2* l2=debut2;

    while(l2!=NULL)
    {
       if(strcmp(l2->m.inti,in)==0)
       return 1;
       l2=l2->next;
    }

    return 0;
}

cellule2* recherchemoir(cellule2* debut2, char n[])
{
    cellule2* l2=debut2;

    while(l2!=NULL)
    {
       if(strcmp((*l2).m.inti,n)==0)
       {
        return l2;
       }
       l2=l2->next;
    }

}

cellule2* recherchemoir1(cellule2* debut2, int n)
{
    cellule2* l2=debut2;

    while(l2!=NULL)
    {
       if((*l2).m.identifiant==n)
       {
        return l2;
       }
       l2=l2->next;
    }

}

int rechercheex(cellule3* debut, char n[])
{
    cellule3* l=debut;

    while(l!=NULL)
    {
       if(strcmp((*l).n.et.nom,n)==0)
       {
        return 1;
       }
       l=l->next;
    }

    return 0;
}

int rechercheex1(cellule3* debut, int n)
{
    cellule3* l1=debut;

    while(l1!=NULL)
    {
       if(l1->n.et.id==n)
       {
        return 1;
       }
       l1=l1->next;
    }

    return 0;
}

cellule3* affiche(cellule3 *debut, cellule1 *debut1, cellule2 *debut2)
{
    cellule3* l=debut;
    cellule1* l1=NULL;
    cellule2* l2=NULL;
    char n[10],in[10];
    float no;

    printf("affichage des etudiants :\n");
    affiche1(debut1);
    printf("affichage des modules :\n");
    affiche2(debut2);

    printf("saisie de la note :\n");
    printf("entrer le nom de l'etudiant :");
    scanf("%s",n);
    if(rechercheetn(debut1,n)==0 || rechercheex(debut,n)==1)
    {printf("insertion non valide \n");}
    else
    {
     printf("entrer l'intitulite du module :");
     scanf("%s",in);
       if(recherchemoi(debut2,in)==0)
       {printf("insertion non valide \n");}
       else
       {
       l1=rechercheetnr(debut1,n);
       l2=recherchemoir(debut2,in);
       printf("entrer la note correspondante :");
       scanf("%f",&no);
       l=creer(l1,l2,no);
       l->next=debut;
       return l;
       }
    }
    return debut;
}

cellule3* afficher(cellule3 *debut,cellule1 *debut1,cellule2 *debut2)
{
    cellule3* l=debut;
    cellule1* l1=NULL;
    cellule2* l2=NULL;
    int n,in;
    float no;

    printf("affichage des etudiants :\n");
    affiche1(debut1);
    printf("affichage des modules :\n");
    affiche2(debut2);

    printf("saisie de la note :\n");
    printf("entrer l'identifiant de l'etudiant :");
    scanf("%d",&n);
    if(exist1(debut1,n)==0 || rechercheex1(debut,n)==1)
    {printf("insertion non valide \n");}
    else
    {
     printf("entrer l'identifiant du module :");
     scanf("%d",&in);
       if(exist2(debut2,in)==0)
       {printf("insertion non valide\n");}
       else
       {
       l1=rechercheetnr1(debut1,n);
       l2=recherchemoir1(debut2,in);
       printf("entrer la note correspondante :");
       scanf("%f",&no);
       l=creer(l1,l2,no);
       l->next=debut;
       return l;
       }
    }
    return debut;
}

void main()
{
    cellule1* debut1=NULL;
    cellule2* debut2=NULL;
    cellule3* debut=NULL;
    int a,idet,l;
    char n[10],p[10],s,ch;

do{
    gotoxy(15,7);printf("GESTION DES NOTES");
    l=15;
    do{
    gotoxy(7,9);
    printf("ajouter un etudiant");
    gotoxy(7,10);
    printf("ajouter un module");
    gotoxy(7,11);
    printf("Ajouter une note sur la base du nom de l'etudiant et l'intitule de module");
    gotoxy(7,12);
    printf("Ajouter une note sur la base des identifiants de l'etudiant et de module");
    gotoxy(7,13);
    printf("afficher les notes enregistre");
    gotoxy(7,14);
    printf("Quitter");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>=15)l=9;
    if(l<=8)l=14;
     gotoxy(7,l);ch=getch();
    }while(ch!=13);
    clrscr();
    gotoxy(2,2);
    if(l==9)
    {
    printf("entrer le nom de l'etudiant :");
    scanf("%s",n);
    printf("entrer le prenom de l'etudiant :");
    scanf("%s",p);
    printf("entrer le sex de l'etudiant :");
    do{
    gotoxy(30,4);printf("  ");gotoxy(30,4);scanf(" %c",&s);
    }while(s!='m' && s!='f');
    printf("entrer le l'age de l'etudiant :");
    scanf("%d",&a);
    printf("entrer l'identifiant de l'etudiant :");
    scanf("%d",&idet);
    debut1=saisie(debut1,n,p,s,a,idet);
    getch();
    clrscr();;
    }
    if(l==10)
    {
     printf("entrer le nom du module :");
     scanf("%s",n);
     printf("entrer le professeur qui enseigne le module :");
     scanf("%s",p);
     printf("entrer l'identifiant du module :");
     scanf("%d",&idet);
     debut2=saisiem(debut2,n,p,idet);
     getch();
     clrscr();
    }
    if(l==11)
    {
      debut=affiche(debut,debut1,debut2);
      getch();
      clrscr();
    }
    if(l==12)
    {
      debut=afficher(debut,debut1,debut2);
      getch();
      clrscr();
    }
    if(l==13)
    {
      affiche3(debut);
      getch();
      clrscr();
    }
}while(l!=14);
}
