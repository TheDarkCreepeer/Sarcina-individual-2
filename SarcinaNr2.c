#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SarcinaNr2.h"

Nod *cap = NULL;  // definirea pointerului global

// 1. Crearea listei in memoria dinamica
int createList(int n) {
    Nod *c, *p;
    for(int i = 0; i < n; i++) {
        c = (Nod*)calloc(1, sizeof(Nod));
        if(c == NULL) {
            cap = NULL;
            return 0;  // eroare
        }
        if(i == 0) {
            cap = c;
        } else {
            p->urmat = c;
        }
        p = c;
    }
    if(c != NULL) {
        c->urmat = NULL;
    }
    return 1;  // succes
}

// 2. Introducerea informatiei de la tastatura
void readInfo(void) {
    if(cap == NULL) {
        printf("\nLista este goala! Creati mai intai lista.\n");
        return;
    }

    Nod* curent = cap;
    int nr = 1;

    printf("\n--- Introduceti datele automobilelor ---\n");
    while(curent != NULL) {
        printf("\nAutomobilul %d:\n", nr);
        printf("  Model: ");
        scanf("%s", curent->date.model);
        printf("  Tara de fabricatie: ");
        scanf("%s", curent->date.tara);
        printf("  An fabricatie: ");
        scanf("%d", &curent->date.an);
        printf("  Putere motor (CP): ");
        scanf("%d", &curent->date.putere);
        printf("  Pret (euro): ");
        scanf("%lf", &curent->date.pret);

        curent = curent->urmat;
        nr++;
    }
    printf("\nDatele au fost introduse cu succes!\n");
}

// 3. Afisarea informatiei despre elemente
void showInfo(void) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    Nod* curent = cap;
    int nr = 1;

    printf("\n=============================================================================\n");
    printf(" Nr.  Model                Tara                An    Putere    Pret(euro)\n");
    printf("=============================================================================\n");

    while(curent != NULL) {
        printf("%-4d %-20s %-18s %-6d %-8d %10.2f\n",
               nr,
               curent->date.model,
               curent->date.tara,
               curent->date.an,
               curent->date.putere,
               curent->date.pret);
        curent = curent->urmat;
        nr++;
    }
    printf("=============================================================================\n");
    printf("Total: %d automobile\n", nr-1);
}

// 4. Cautarea elementului in lista (dupa model)
Nod* searchElement(char model[]) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return NULL;
    }

    Nod* curent = cap;
    int poz = 1;

    while(curent != NULL) {
        if(strcmp(curent->date.model, model) == 0) {
            printf("\nElement gasit la pozitia %d!\n", poz);
            return curent;
        }
        curent = curent->urmat;
        poz++;
    }

    printf("\nElementul cu modelul '%s' NU a fost gasit!\n", model);
    return NULL;
}

// 5. Modificarea campurilor unui element
void modifyInfo(Nod* element) {
    if(element == NULL) {
        printf("\nElement invalid!\n");
        return;
    }

    int opt;
    printf("\n--- Modificare automobil ---\n");
    printf("Model actual: %s\n", element->date.model);
    printf("Tara actuala: %s\n", element->date.tara);
    printf("An actual: %d\n", element->date.an);
    printf("Putere actuala: %d CP\n", element->date.putere);
    printf("Pret actual: %.2f euro\n", element->date.pret);

    printf("\nCe doriti sa modificati?\n");
    printf("1. Model\n2. Tara\n3. An\n4. Putere\n5. Pret\n");
    printf("Optiunea: ");
    scanf("%d", &opt);

    switch(opt) {
        case 1:
            printf("Nou model: ");
            scanf("%s", element->date.model);
            break;
        case 2:
            printf("Noua tara: ");
            scanf("%s", element->date.tara);
            break;
        case 3:
            printf("Nou an: ");
            scanf("%d", &element->date.an);
            break;
        case 4:
            printf("Noua putere: ");
            scanf("%d", &element->date.putere);
            break;
        case 5:
            printf("Nou pret: ");
            scanf("%lf", &element->date.pret);
            break;
        default:
            printf("Optiune invalida!\n");
    }
    printf("\nDatele au fost modificate cu succes!\n");
}

// 6. Determinarea adresei ultimului element
Nod* lastElement(void) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return NULL;
    }

    Nod* curent = cap;
    while(curent->urmat != NULL) {
        curent = curent->urmat;
    }

    printf("\nUltimul element se afla la adresa: %p\n", (void*)curent);
    printf("Model: %s, Tara: %s, An: %d, Putere: %d CP, Pret: %.2f euro\n",
           curent->date.model, curent->date.tara, curent->date.an,
           curent->date.putere, curent->date.pret);

    return curent;
}

// 7. Determinarea lungimii listei
int sizeList(void) {
    int n = 0;
    Nod* curent = cap;

    while(curent != NULL) {
        n++;
        curent = curent->urmat;
    }

    printf("\nLungimea listei: %d elemente\n", n);
    return n;
}

// 8. Interschimbarea a doua elemente (prin schimb de date)
void swapElements(int poz1, int poz2) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    int len = sizeList();
    if(poz1 < 1 || poz1 > len || poz2 < 1 || poz2 > len) {
        printf("\nPozitii invalide!\n");
        return;
    }

    if(poz1 == poz2) {
        printf("\nAceeasi pozitie, nu e necesar interschimbul.\n");
        return;
    }

    Nod *n1 = cap, *n2 = cap;
    Auto temp;

    // Gasim nodul de la pozitia 1
    for(int i = 1; i < poz1; i++) {
        n1 = n1->urmat;
    }

    // Gasim nodul de la pozitia 2
    for(int i = 1; i < poz2; i++) {
        n2 = n2->urmat;
    }

    // Interschimbam datele (nu pointerii)
    temp = n1->date;
    n1->date = n2->date;
    n2->date = temp;

    printf("\nElementele de la pozitiile %d si %d au fost interschimbate!\n", poz1, poz2);
}

// 9. Sortarea listei (dupa model alfabetic)
void sortList(void) {
    if(cap == NULL || cap->urmat == NULL) {
        printf("\nLista nu necesita sortare (0 sau 1 element)!\n");
        return;
    }

    int swapped;
    Nod *ptr1;
    Nod *lptr = NULL;
    Auto temp;

    do {
        swapped = 0;
        ptr1 = cap;

        while(ptr1->urmat != lptr) {
            if(strcmp(ptr1->date.model, ptr1->urmat->date.model) > 0) {
                // Interschimbam datele
                temp = ptr1->date;
                ptr1->date = ptr1->urmat->date;
                ptr1->urmat->date = temp;
                swapped = 1;
            }
            ptr1 = ptr1->urmat;
        }
        lptr = ptr1;
    } while(swapped);

    printf("\nLista a fost sortata alfabetic dupa model!\n");
}

// 10. Adaugare la sfarsit
void addEnd(int v) {
    Nod* nou = (Nod*)calloc(1, sizeof(Nod));
    if(nou == NULL) {
        printf("\nEroare la alocarea memoriei!\n");
        return;
    }

    // Pentru simplitate, cream un automobil default
    sprintf(nou->date.model, "Auto%d", v);
    sprintf(nou->date.tara, "Necunoscuta");
    nou->date.an = 2000;
    nou->date.putere = 100;
    nou->date.pret = 10000;
    nou->urmat = NULL;

    if(cap == NULL) {
        cap = nou;
    } else {
        Nod* ultim = lastElement();
        ultim->urmat = nou;
    }

    printf("\nElement nou adaugat la sfarsit!\n");
}

// 11. Adaugare la inceput
void addBeginning(int v) {
    Nod* nou = (Nod*)calloc(1, sizeof(Nod));
    if(nou == NULL) {
        printf("\nEroare la alocarea memoriei!\n");
        return;
    }

    sprintf(nou->date.model, "Auto%d", v);
    sprintf(nou->date.tara, "Necunoscuta");
    nou->date.an = 2000;
    nou->date.putere = 100;
    nou->date.pret = 10000;
    nou->urmat = cap;
    cap = nou;

    printf("\nElement nou adaugat la inceput!\n");
}

// 12. Inserare dupa elementul indicat
void insertAfter(int pozitie, Auto date) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    int len = sizeList();
    if(pozitie < 1 || pozitie > len) {
        printf("\nPozitie invalida!\n");
        return;
    }

    Nod* curent = cap;
    for(int i = 1; i < pozitie; i++) {
        curent = curent->urmat;
    }

    Nod* nou = (Nod*)calloc(1, sizeof(Nod));
    nou->date = date;
    nou->urmat = curent->urmat;
    curent->urmat = nou;

    printf("\nElement inserat dupa pozitia %d!\n", pozitie);
}

// 13. Inserare inaintea elementului indicat
void insertBefore(int pozitie, Auto date) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    int len = sizeList();
    if(pozitie < 1 || pozitie > len) {
        printf("\nPozitie invalida!\n");
        return;
    }

    if(pozitie == 1) {
        Nod* nou = (Nod*)calloc(1, sizeof(Nod));
        nou->date = date;
        nou->urmat = cap;
        cap = nou;
    } else {
        Nod* curent = cap;
        for(int i = 1; i < pozitie - 1; i++) {
            curent = curent->urmat;
        }

        Nod* nou = (Nod*)calloc(1, sizeof(Nod));
        nou->date = date;
        nou->urmat = curent->urmat;
        curent->urmat = nou;
    }

    printf("\nElement inserat inaintea pozitiei %d!\n", pozitie);
}

// 14. Stergerea elementului indicat
void deleteElement(int pozitie) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    int len = sizeList();
    if(pozitie < 1 || pozitie > len) {
        printf("\nPozitie invalida!\n");
        return;
    }

    Nod* temp;

    if(pozitie == 1) {
        temp = cap;
        cap = cap->urmat;
        free(temp);
    } else {
        Nod* curent = cap;
        for(int i = 1; i < pozitie - 1; i++) {
            curent = curent->urmat;
        }
        temp = curent->urmat;
        curent->urmat = temp->urmat;
        free(temp);
    }

    printf("\nElementul de la pozitia %d a fost sters!\n", pozitie);
}

// 15. Divizarea listei in doua liste
void splitList(Nod** lista1, Nod** lista2) {
    if(cap == NULL) {
        printf("\nLista este goala!\n");
        return;
    }

    int len = sizeList();
    int mid = len / 2;

    *lista1 = cap;

    Nod* curent = cap;
    for(int i = 1; i < mid; i++) {
        curent = curent->urmat;
    }

    *lista2 = curent->urmat;
    curent->urmat = NULL;

    printf("\nLista a fost divizata in doua liste!\n");
    printf("Lista1 are %d elemente, Lista2 are %d elemente\n", mid, len - mid);
}

// 16. Concatenarea a doua liste
void concatenateLists(Nod* lista2) {
    if(cap == NULL) {
        cap = lista2;
        printf("\nLista a fost concatenata!\n");
        return;
    }

    if(lista2 == NULL) {
        printf("\nA doua lista este goala!\n");
        return;
    }

    Nod* ultim = cap;
    while(ultim->urmat != NULL) {
        ultim = ultim->urmat;
    }
    ultim->urmat = lista2;

    printf("\nListele au fost concatenate!\n");
}

// 17. Salvarea informatiei in fisier
void saveToFile(char numeFisier[]) {
    if(cap == NULL) {
        printf("\nLista este goala, nimic de salvat!\n");
        return;
    }

    FILE* f = fopen(numeFisier, "w");
    if(f == NULL) {
        printf("\nEroare la deschiderea fisierului!\n");
        return;
    }

    Nod* curent = cap;
    int nr = 0;

    while(curent != NULL) {
        fprintf(f, "%s\n%s\n%d\n%d\n%.2f\n",
                curent->date.model,
                curent->date.tara,
                curent->date.an,
                curent->date.putere,
                curent->date.pret);
        curent = curent->urmat;
        nr++;
    }

    fclose(f);
    printf("\nAu fost salvate %d automobile in fisierul '%s'!\n", nr, numeFisier);
}

// 18. Citirea informatiei din fisier
void loadFromFile(char numeFisier[]) {
    FILE* f = fopen(numeFisier, "r");
    if(f == NULL) {
        printf("\nEroare la deschiderea fisierului!\n");
        return;
    }

    // Eliberam memoria existenta
    freeMemory();

    Nod *c = NULL, *p = NULL;
    int count = 0;

    while(!feof(f)) {
        c = (Nod*)calloc(1, sizeof(Nod));
        if(c == NULL) break;

        if(fscanf(f, "%s", c->date.model) != 1) {
            free(c);
            break;
        }
        fscanf(f, "%s", c->date.tara);
        fscanf(f, "%d", &c->date.an);
        fscanf(f, "%d", &c->date.putere);
        fscanf(f, "%lf", &c->date.pret);

        if(count == 0) {
            cap = c;
        } else {
            p->urmat = c;
        }
        p = c;
        count++;
    }

    if(c != NULL) {
        c->urmat = NULL;
    }

    fclose(f);
    printf("\nAu fost citite %d automobile din fisierul '%s'!\n", count, numeFisier);
}

// 19. Eliberarea memoriei
void freeMemory(void) {
    Nod* curent = cap;
    Nod* temp;

    while(curent != NULL) {
        temp = curent;
        curent = curent->urmat;
        free(temp);
    }

    cap = NULL;
    printf("\nMemoria a fost eliberata cu succes!\n");
}
