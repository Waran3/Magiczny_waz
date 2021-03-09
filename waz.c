//W¹¿ ver 1.1 

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int i = 0, j = 0, a = 0;

int main(void)
{

    // Deklaracja zmiennych
    int wiersze;
    int  kolumny;
    int** tab;
    char jedynka;
    char zero;
    char key;

    setlocale(LC_ALL, "polish");// polskie znaki

poczatek:
    i = 0, j = 0;

    printf("Wpisz dowolny znak z klawiatury dla wê¿a= ");
    jedynka = getc(stdin); //zamiana numeru znaku klawiatury na znak klawiatury
    getchar();
    
    printf("Wpisz dowolny znak z klawiatury dla pola wokó³ wê¿a= ");
    zero = getc(stdin);
    getchar();
    
    if (jedynka == zero)
    {
        printf("\n");
        printf("To jest bez sensu ale to Twój wybór :-)\n");
    }

    // Pobranie danych
    printf("Podaj iloœæ wierszy: ");
    scanf(" %d", &wiersze);
    if (wiersze <= 0)
        while (wiersze <=0)
    {
        printf("Ogarnij siê, podaj sensown¹ wartoœæ = ");
        scanf(" %d", &wiersze);
    }

    printf("Podaj iloœæ kolumn: ");
    scanf(" %d", &kolumny);
    if (kolumny <= 0)
        while (kolumny <= 0)
        {
            printf("Ogarnij siê, podaj sensown¹ wartoœæ = ");
            scanf(" %d", &kolumny);
        }

    printf("\n");
    getchar();

    // Alokacja pamiêci dla tablicy dwuwymiarowej
    tab = (int**)malloc(wiersze * sizeof(int*)); // alokacja pamiêci dla wierszy
    for (int i = 0; i < wiersze; i++)
        tab[i] = (int*)malloc(kolumny * sizeof(int)); // alokacja pamiêci dla kolumn

    for (i = 0; i < wiersze; i++) // wype³nienie tablicy znakiem pierwszym (0) - pocz¹tek
        for (j = 0; j < kolumny; j++)
            tab[i][j] = zero; // wype³nienie tablicy znakiem pierwszym (0) - koniec

    i = 0;
    j = 0;

    

    ///////////////////////////// w prawo ////////////////////////////
    for (j; j < kolumny && tab[i][j] == zero; j++)
    {

        //printf("W petli w prawo_1 i= %d j= %d tab= %d\n", i, j, tab[i][j]);
        tab[i][j] = jedynka;
    }
    //printf("Po wyjsciu z petli w prawo i= %d j= %d \n", i, j) ;

    j = j - 1;
    tab[i][j] = zero;

    //printf("Koniec bloku w prawo_1   i= %d j= %d\n", i, j);
    //printf("\n");

    /////////////////////////// w dó³ ////////////////////////////////

    for (i; i < wiersze && tab[i][j] == zero; i++)

    {
        //printf("W petli w dol_1 i= %d j= %d tab= %d\n", i, j, tab[i][j]);
        tab[i][j] = jedynka;
    }
    //printf("Po wyjsciu z petli w dol_1 i= %d j= %d \n", i, j );

    i = i - 1;
    tab[i][j] = zero;

    //printf("Koniec bloku w dol_1   i= %d j= %d\n", i, j);
    //printf("\n");

    
    if (wiersze > 2)
    {
        /////////////////////////// w lewo ////////////////////////////////

        for (j; j >= 0 && tab[i][j] == zero; j--)
        {
            //printf("W petli w lewo_1 i= %d j= %d tab= %d\n", i, j, tab[i][j]);
            tab[i][j] = jedynka;
        }
        //printf("Po wyjsciu z petli w lewo_1 i= %d j= %d \n", i, j);

        j = j + 1;
        tab[i][j] = zero;

        //printf("Koniec bloku w lewo_1   i= %d j= %d\n", i, j);
        //printf("\n");
    }



    while (a == a && wiersze>2 && kolumny >2) //pêtlna nieskoñczona 
    {
        a++;
        //printf("a= %d wiersze= %d kolumny= %d\n", a, wiersze, kolumny);
        /////////////////////////// w gore_2 ////////////////////////////////
        if (tab[i][j] == zero && tab[i - 1][j] == zero && tab[i - 2][j] == jedynka)
            goto skok;

        int g = i;
        for (i; tab[i][j] == zero && i >= 0; i--)
            if (tab[i - 1][j] == jedynka)
            {
                //printf("W petli w gore_1  i= %d j= %d tab= %d\n", i, j, tab[i][j]);
                tab[i][j] = zero;

            }
            else
            {
                tab[i][j] = jedynka;
            }
        i = i + 2;
        tab[i][j] = zero;
        if (g - i == 1)
            goto skok;

        //printf("Po wyjsciu z petli w gore_2 i= %d j= %d \n", i, j);
        //printf("\n");

        /////////////////////////// w prawo2 ////////////////////////////////
        if (tab[i][j] == zero && tab[i][j + 1] == zero && tab[i][j + 2] == jedynka)
            goto skok;

        int p = j;
        for (j; tab[i][j] == zero && j < kolumny; j++)
            if (tab[i][j + 1] == jedynka)
            {
                // printf("W petli w prawo_2  i= %d j= %d tab= %d\n", i, j, tab[i][j]);
                tab[i][j] = zero;

            }
            else
            {
                tab[i][j] = jedynka;
            }
        j = j - 2;
        tab[i][j] = zero;
        if (j - p == 1)
            goto skok;

        //printf("Po wyjsciu z petli w prawo_2 i= %d j= %d \n", i, j);
         //printf("\n");

         //////////////////////////// w dol_2 //////////////////////////////////////////////////

        if (tab[i][j] == zero && tab[i + 1][j] == zero && tab[i + 2][j] == jedynka)
            goto skok;

        int d = i;
        for (i; tab[i][j] == zero && i <= wiersze; i++)
            if (tab[i + 1][j] == jedynka)
            {
                // printf("W petli w dol_2  i= %d j= %d tab= %d\n", i, j, tab[i][j]);
                tab[i][j] = zero;

            }
            else
            {
                tab[i][j] = jedynka;
            }
        i = i - 2;
        tab[i][j] = zero;
        if (i - d == 1)
            goto skok;

        //printf("Po wyjsciu z petli w dol_2 i= %d j= %d \n", i, j);
        //printf("\n");

        /////////////////////////// w lewo_2 ////////////////////////////////

        if (tab[i][j] == zero && tab[i][j - 1] == zero && tab[i][j - 2] == jedynka)
            goto skok;

        int l = j;
        for (j; tab[i][j] == zero && j > 0; j--)
            if (tab[i][j - 1] == jedynka)
            {
                //printf("W petli w prawo_2  i= %d j= %d tab= %d\n", i, j, tab[i][j]);
                tab[i][j] = zero;

            }
            else
            {
                tab[i][j] = jedynka;
            }
        j = j + 2;
        tab[i][j] = zero;
        if (l - j == 1)
            goto skok;

        //printf("Po wyjsciu z petli w lewo_2 i= %d j= %d \n", i, j);
        //printf("\n");

    }

skok:

    tab[i][j] = jedynka;

    // Wypisywanie wartoœci
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            printf("%1c", tab[i][j]);
        }
        printf("\n");
    }
    // Czyszczenie pamiêci
    for (int i = 0; i < wiersze; i++)
        free(tab[i]);
    free(tab);

    printf("\n");
    printf("Chcesz powtórzyæ? (T/N)\n");
    key = _getch();
    if (key == 't')
    {
        system("cls");
        goto poczatek;
    }

    if (key == 'n');
    {
        system("cls");
        printf("Program zokoñczy³ dzia³anie\n");
    }

    return 0;
}