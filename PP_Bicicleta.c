#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

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
void rezervareBicicleta();
void cautaBicicleta();
void imprumutaBicicleta();
void returneazaBicicleta();
void meniuAdmin();
int cerereParolaAdmin();
void stergeBicicleta();

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
        printf("1. Afisare biciclete\n");
        printf("2. Rezervare bicicleta\n");
        printf("3. Cautare bicicleta\n");
        printf("4. Imprumut bicicleta\n");
        printf("5. Returnare bicicleta\n");
        printf("6. Meniu administrator\n");
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
                submenuCautare();
                break;
            case 4:
                submenuImprumut();
                break;
            case 5:
                submenuReturnare();
                break;
            case 6:
                if (cerereParolaAdmin()) {
                    meniuAdmin();
                } else {
                    printf(RED "Parola incorecta! Revenire la meniul principal.\n" RESET);
                    getchar();
                    getchar();
                } 
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
        printf("=== Afisare biciclete ===\n");
        printf("1. Afisare toate bicicletele\n");
        printf("2. Afisare doar biciclete disponibile\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                clearScreen();
                afisareBiciclete(0); // toate
                printf("\nApasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 2:
                clearScreen();
                afisareBiciclete(1); // doar disponibile
                printf("\nApasati Enter pentru a continua.");
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
                clearScreen();
                afisareBiciclete(1);
                rezervareBicicleta();
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
        printf("1. Cauta bicicleta dupa tip si localitate\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                cautaBicicleta();
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
        printf("1. Imprumuta o bicicleta\n");
        printf("0. Revenire la meniul principal\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiuneSub);

        switch (optiuneSub) {
            case 1:
                clearScreen();
                afisareBiciclete(1);
                imprumutaBicicleta();
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
                returneazaBicicleta();
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

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void afisareBiciclete(int doarDisponibile) {
    FILE *f = fopen("biciclete.txt", "r");
    if (f == NULL) {
        printf(RED "Eroare: nu se poate deschide fisierul." RESET "\n");
        return;
    }

    char linie[200];
    int gasit = 0;
    printf("=== Lista Bicicletelor ===\n");

    while (fgets(linie, sizeof(linie), f) != NULL) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';
        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (!doarDisponibile || strcmp(b.stare, "disponibila") == 0) {
            gasit = 1;
            printf("ID: %-5d | ", b.id);
            printf("Tip: " GREEN "%-15s" RESET " | ", b.tip);
            printf("Locatie: " YELLOW "%-15s" RESET " | ", b.locatie);
            if (strcmp(b.stare, "disponibila") == 0) {
                printf("Stare: " GREEN "%s" RESET "\n", b.stare);
            } else {
                printf("Stare: " RED "%s" RESET "\n", b.stare);
            }
        }
    }

    if (!gasit)
        printf(YELLOW "Nu exista biciclete pentru afisare." RESET "\n");

    fclose(f);
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

    printf(GREEN "Bicicleta a fost adaugata cu succes." RESET "\n");
    printf("Apasati Enter pentru a continua...");
    getchar();
}

void rezervareBicicleta() {
    int id;
    printf("Introduceti ID-ul bicicletei pentru rezervare: ");
    scanf("%d", &id);

    FILE *f = fopen("biciclete.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf("Eroare la deschiderea fisierelor.\n");
        return;
    }

    char linie[200];
    int gasit = 0;

    while (fgets(linie, sizeof(linie), f)) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';
        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (b.id == id && strcmp(b.stare, "disponibila") == 0) {
            strcpy(b.stare, "indisponibila");
            gasit = 1;
        }

        fprintf(temp, "%d;%s;%s;%s\n", b.id, b.tip, b.locatie, b.stare);
    }

    fclose(f);
    fclose(temp);
    remove("biciclete.txt");
    rename("temp.txt", "biciclete.txt");

    if (gasit)
        printf(GREEN "Bicicleta a fost rezervata cu succes." RESET "\n");
    else {
        printf("Bicicleta ");
        printf(RED "nu exista" RESET);
        printf(" sau ");
        printf(YELLOW "nu este disponibila" RESET ".\n");
    }
}

void cautaBicicleta() {
    char tipCautat[50];
    char locatieCautata[50];

    printf("Introduceti tipul bicicletei: ");
    scanf(" %[^\n]", tipCautat);
    printf("Introduceti localitatea: ");
    scanf(" %[^\n]", locatieCautata);

    FILE *f = fopen("biciclete.txt", "r");
    if (f == NULL) {
        printf("Nu se poate deschide fisierul.\n");
        return;
    }

    char linie[200];
    int gasit = 0;
    while (fgets(linie, sizeof(linie), f)) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';

        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (strcmp(b.tip, tipCautat) == 0 && strcmp(b.locatie, locatieCautata) == 0) {
            printf("ID: %-5d | Tip: %-15s | Locatie: %-15s | Stare: %s\n", b.id, b.tip, b.locatie, b.stare);
            gasit = 1;
        }
    }

    if (!gasit)
        printf(RED "Nu au fost gasite biciclete conform criteriilor." RESET "\n" );

    fclose(f);
}


void imprumutaBicicleta() {
    int id;
    printf("Introduceti ID-ul bicicletei pentru imprumut: ");
    scanf("%d", &id);

    FILE *f = fopen("biciclete.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf(RED "Eroare la deschiderea fisierelor." RESET "\n");
        return;
    }

    char linie[200];
    int gasit = 0;
    int exista = 0;
    int ore = 0;

    while (fgets(linie, sizeof(linie), f)) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';
        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (b.id == id) {
            exista = 1;
            if (strcmp(b.stare, "disponibila") == 0) {
                printf("Introduceti durata imprumutului (in ore): ");
                scanf("%d", &ore);
                strcpy(b.stare, "indisponibila");
                gasit = 1;
            }
        }

        fprintf(temp, "%d;%s;%s;%s\n", b.id, b.tip, b.locatie, b.stare);
    }

    fclose(f);
    fclose(temp);
    remove("biciclete.txt");
    rename("temp.txt", "biciclete.txt");

    if (gasit) {
        printf(GREEN "Bicicleta a fost imprumutata pentru %d ore." RESET "\n", ore);
    } else {
        printf("Bicicleta ");
        if (!exista)
            printf(RED "nu exista" RESET ".\n");
        else
            printf(YELLOW "nu este disponibila" RESET ".\n");
    }
}



void returneazaBicicleta() {
    int id;
    printf("Introduceti ID-ul bicicletei de returnat: ");
    scanf("%d", &id);

    FILE *f = fopen("biciclete.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf("Eroare la deschiderea fisierelor.\n");
        return;
    }

    char linie[200];
    int gasit = 0;

    while (fgets(linie, sizeof(linie), f)) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';
        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (b.id == id && strcmp(b.stare, "indisponibila") == 0) {
            strcpy(b.stare, "disponibila");
            gasit = 1;
        }

        fprintf(temp, "%d;%s;%s;%s\n", b.id, b.tip, b.locatie, b.stare);
    }

    fclose(f);
    fclose(temp);
    remove("biciclete.txt");
    rename("temp.txt", "biciclete.txt");

    if (gasit)
        printf(GREEN "Bicicleta a fost returnata cu succes." RESET "\n");
    else {
        printf("Bicicleta ");
        printf(RED "nu exista" RESET);
        printf(" sau ");
        printf(YELLOW "nu este imprumutata" RESET ".\n");
    }

}

void meniuAdmin() {
    int opt;
    do {
        clearScreen();
        printf(YELLOW "\n=== MENIU ADMIN ===\n" RESET);
        printf("1. Adauga bicicleta\n");
        printf("2. Sterge bicicleta\n");
        printf("3. Afiseaza toate bicicletele\n");
        printf("0. Revenire la meniul principal\n");
        printf("Alege o optiune: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                adaugareBicicleta();
                break;
            case 2:
                stergeBicicleta();
                break;
            case 3:
                afisareBiciclete(0);
                printf("\nApasati Enter pentru a continua.");
                getchar();
                getchar();
                break;
            case 0:
                return;
            default:
                printf(RED "Optiune invalida!\n" RESET);
        }

        break;
    } while (1);
}

int cerereParolaAdmin() {
    char parola[50];
    printf(YELLOW "Introduceti parola de administrator: " RESET);
    scanf("%s", parola);

    if (strcmp(parola, "admin123") == 0) {
        return 1;
    }
    return 0;
}

void stergeBicicleta() {
    int id;
    printf("Introduceti ID-ul bicicletei de sters: ");
    scanf("%d", &id);

    FILE *f = fopen("biciclete.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (f == NULL || temp == NULL) {
        printf(RED "Eroare la deschiderea fisierelor." RESET "\n");
        return;
    }

    char linie[200];
    int gasit = 0;

    while (fgets(linie, sizeof(linie), f)) {
        Bicicleta b;
        linie[strcspn(linie, "\n")] = '\0';
        char *p = strtok(linie, ";");
        if (p != NULL) b.id = atoi(p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.tip, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.locatie, p);
        p = strtok(NULL, ";"); if (p != NULL) strcpy(b.stare, p);

        if (b.id == id) {
            gasit = 1;
            continue;  // sar peste scrierea bicicletei găsite, deci o „șterg”
        }

        fprintf(temp, "%d;%s;%s;%s\n", b.id, b.tip, b.locatie, b.stare);
    }

    fclose(f);
    fclose(temp);
    remove("biciclete.txt");
    rename("temp.txt", "biciclete.txt");

    if (gasit) {
        printf(GREEN "Bicicleta cu" YELLOW "ID-ul  %d " GREEN "a fost stearsa cu succes." RESET "\n", id);
        getchar();
        getchar();
    } else {
        printf("Bicicleta cu " YELLOW " ID-ul %d ");
        printf(RED "nu exista." RESET "\n", id);
        getchar();
        getchar();
    }
}
