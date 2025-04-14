#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

typedef struct {
    int id;
    char tip[50];
    char locatie[50];
    char stare[20];
} Bicicleta;

void meniu();
void submenuAfisare();
void submenuRezervare();
void submenuAdaugare();
void submenuCautare();
void submenuImprumut();
void submenuReturnare();
void afisareBiciclete();
void adaugareBicicleta();
int idExista();

int main() {
    meniu();
    return 0;
}

void meniu()
{
    int optiuneMain;
    do {
        clearScreen();
        printf("=== MENIU PRINCIPAL ===\n");
        printf("1. Afisare biciclete disponibile\n");
        printf("2. Rezervare bicicleta\n");
        printf("3. Adaugare bicicleta\n");
        printf("4. Cautare bicicleta\n");
        printf("5. Imprumut bicicleta\n");
        printf("6. Returnare bicicleta\n");
        printf("7. Iesire\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneMain);

        switch (optiuneMain) {
            case 1:
                submenuAfisare();
                break;
            case 2:
                submenuRezervare();
                break;
            case 3:
                submenuAdaugare();
                break;
            case 4:
                submenuCautare();
                break;
            case 5:
                submenuImprumut();
                break;
            case 6:
                submenuReturnare();
                break;
            case 7:
                printf("Iesire din program...\n");
                break;
            default:
                printf("Optiune invalida! Apasati Enter pentru a incerca din nou...");
                getchar();
                getchar();
                break;
        }
    } while (optiuneMain != 7);


}

void submenuAfisare() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Afisare biciclete disponibile ===\n");
        printf("1. Afisare lista completa de biciclete\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                clearScreen();
                afisareBiciclete();
                printf("Apasati Enter pentru a continua.");
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void submenuRezervare() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Rezervare bicicleta ===\n");
        printf("1. Rezerva o bicicleta\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                //fct rezervare bicla
                printf("\nBicicleta a fost rezervata.\n");
                printf("Apasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void submenuAdaugare() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Adaugare bicicleta ===\n");
        printf("1. Adauga o bicicleta\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                adaugareBicicleta();
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void submenuCautare() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Cautare bicicleta ===\n");
        printf("1. Cauta bicicleta dupa tip si disponibilitate\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                printf("\nRezultatele cautarii:\n");
                //fct afis bicla cautata
                printf("Apasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void submenuImprumut() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Imprumut bicicleta ===\n");
        printf("1. Imprumuta bicicleta pentru 10 ore\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                //fct imprumut (default imprumut=10h, se poate modifica din funtie)
                printf("\nBicicleta a fost imprumutata pentru 10 ore.\n");
                printf("Apasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void submenuReturnare() {
    int optiuneSub;
    do {
        clearScreen();
        printf("=== Returnare bicicleta ===\n");
        printf("1. Returneaza bicicleta\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                //fct returnare bicla
                printf("\nBicicleta a fost returnata.\n");
                printf("Apasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOptiune invalida! Apasati Enter pentru a incerca din nou.");
                getchar();
                getchar();
                break;
        }
    } while (optiuneSub != 0);
}

void afisareBiciclete() {
    FILE *f = fopen("biciclete.txt", "r");
    if (f == NULL) {
        printf("Nu se poate deschide fisierul.\n");
        return;
    }

    char linie[200];
    printf("=== Lista Bicicletelor ===\n");
    while (fgets(linie, sizeof(linie), f) != NULL) {
        linie[strcspn(linie, "\n")] = '\0';
        Bicicleta b;
        //presupunand ca datele din fisier sunt stocate sub forma: "id;tip;locatie;stare"
        char *p = strtok(linie, ";");
        if (p != NULL)
            b.id = atoi(p);
        
        p = strtok(NULL, ";");
        if (p != NULL)
            strcpy(b.tip, p);
        
        p = strtok(NULL, ";");
        if (p != NULL)
            strcpy(b.locatie, p);
        
        p = strtok(NULL, ";");
        if (p != NULL)
            strcpy(b.stare, p);

        printf("ID: %-5d | Tip: %-15s | Locatie: %-15s | Stare: %s\n", b.id, b.tip, b.locatie, b.stare);

    }
    fclose(f);
    printf("\nApasati Enter pentru a continua.");
    getchar();
    getchar();
}

int idExista(int idCautat) {
    FILE *f = fopen("biciclete.txt", "r");
    if (f == NULL) return 0;

    int id;
    char linie[256];

    while (fgets(linie, sizeof(linie), f)) {
        sscanf(linie, "%d;", &id);
        if (id == idCautat) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void adaugareBicicleta() {
    FILE *f = fopen("biciclete.txt", "a");
    if (f == NULL) {
        printf("Eroare: nu se poate deschide fisierul pentru a adauga o bicicleta.\n");
        return;
    }

    Bicicleta b;
    printf("Introduceti ID-ul bicicletei: ");
    do {
        printf("Introduceti ID-ul bicicletei: ");
        scanf("%d", &b.id);
        while (getchar() != '\n');

        if (idExista(b.id)) {
            printf("Eroare: Exista deja o bicicleta cu acest ID. Introduceti un ID diferit.\n");
        }
    } while (idExista(b.id));

    printf("Introduceti tipul bicicletei: ");
    fgets(b.tip, sizeof(b.tip), stdin);
    b.tip[strcspn(b.tip, "\n")] = '\0';

    printf("Introduceti locatia bicicletei: ");
    fgets(b.locatie, sizeof(b.locatie), stdin);
    b.locatie[strcspn(b.locatie, "\n")] = '\0';

    do {
        printf("Introduceti starea bicicletei (disponibila/indisponibila): ");
        fgets(b.stare, sizeof(b.stare), stdin);
        b.stare[strcspn(b.stare, "\n")] = '\0';
        if (strcmp(b.stare, "disponibila") != 0 && strcmp(b.stare, "indisponibila") != 0) {
            printf("Eroare: Starea trebuie sa fie 'disponibila' sau 'indisponibila'. Incercati din nou.\n");
        }
    } while (strcmp(b.stare, "disponibila") != 0 && strcmp(b.stare, "indisponibila") != 0);


    fprintf(f, "%d;%s;%s;%s\n", b.id, b.tip, b.locatie, b.stare);
    fclose(f);

    printf("Bicicleta a fost adaugata cu succes.\n");
    printf("Apasati Enter pentru a continua...");
    getchar();
}

