#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SarcinaNr2.c"






int main() {
    int optiune, n, poz1, poz2, pozitie;
    char model[50];
    char numeFisier[100];
    Nod* element;
    Nod* lista2 = NULL;
    Auto autoNou;

    cap = NULL;
system("cls");
    while(1) {
        puts("\n\t==============================================");
        puts("\t        TAD LISTA SIMPLU INLANTUITA");
        puts("\t              AUTOMOBILE");
        puts("\t==============================================");
        puts("\t1.  Crearea listei in memoria dinamica");
        puts("\t2.  Introducerea informatiei despre elemente");
        puts("\t3.  Afisarea informatiei despre elemente");
        puts("\t4.  Cautarea elementului in lista");
        puts("\t5.  Modificarea campurilor unui element");
        puts("\t6.  Determinarea adresei ultimului element");
        puts("\t7.  Determinarea lungimii listei");
        puts("\t8.  Interschimbarea a doua elemente");
        puts("\t9.  Sortarea listei");
        puts("\t10. Adaugare element la sfarsit");
        puts("\t11. Adaugare element la inceput");
        puts("\t12. Inserare element dupa o pozitie");
        puts("\t13. Inserare element inaintea unei pozitii");
        puts("\t14. Stergerea unui element");
        puts("\t15. Divizarea listei in doua liste");
        puts("\t16. Concatenarea a doua liste");
        puts("\t17. Salvare informatie in fisier");
        puts("\t18. Citire informatie din fisier");
        puts("\t19. Eliberarea memoriei alocate");
        puts("\t0.  Iesire din program");
        puts("\t==============================================");
        printf("\nAlege optiunea: ");
        scanf("%d", &optiune);

        switch(optiune) {
            case 1:
                printf("Dati numarul de elemente: ");
                scanf("%d", &n);
                if(createList(n)) {
                    printf("\nLista a fost creata cu succes cu %d noduri!\n", n);
                    printf("Acum puteti introduce datele folosind optiunea 2.\n");
                } else {
                    printf("\nEroare la alocarea memoriei!\n");
                }
                break;

            case 2:
                readInfo();
                break;

            case 3:
                showInfo();

                break;

            case 4:
                printf("Introduceti modelul cautat: ");
                scanf("%s", model);
                element = searchElement(model);
                if(element != NULL) {
                    printf("\nModel: %s\n", element->date.model);
                    printf("Tara: %s\n", element->date.tara);
                    printf("An: %d\n", element->date.an);
                    printf("Putere: %d CP\n", element->date.putere);
                    printf("Pret: %.2f euro\n", element->date.pret);
                }

                break;

            case 5:
                printf("Introduceti modelul automobilului de modificat: ");
                scanf("%s", model);
                element = searchElement(model);
                modifyInfo(element);

                break;

            case 6:
                lastElement();

                break;

            case 7:
                sizeList();

                break;

            case 8:
                printf("Dati prima pozitie: ");
                scanf("%d", &poz1);
                printf("Dati a doua pozitie: ");
                scanf("%d", &poz2);
                swapElements(poz1, poz2);

                break;

            case 9:
                sortList();

                break;

            case 10:
                printf("Dati un numar pentru identificare: ");
                scanf("%d", &n);
                addEnd(n);

                break;

            case 11:
                printf("Dati un numar pentru identificare: ");
                scanf("%d", &n);
                addBeginning(n);

                break;

            case 12:
                printf("Introduceti datele noului automobil:\n");
                printf("Model: ");
                scanf("%s", autoNou.model);
                printf("Tara: ");
                scanf("%s", autoNou.tara);
                printf("An: ");
                scanf("%d", &autoNou.an);
                printf("Putere: ");
                scanf("%d", &autoNou.putere);
                printf("Pret: ");
                scanf("%lf", &autoNou.pret);
                printf("Dupa ce pozitie sa fie inserat: ");
                scanf("%d", &pozitie);
                insertAfter(pozitie, autoNou);

                break;

            case 13:
                printf("Introduceti datele noului automobil:\n");
                printf("Model: ");
                scanf("%s", autoNou.model);
                printf("Tara: ");
                scanf("%s", autoNou.tara);
                printf("An: ");
                scanf("%d", &autoNou.an);
                printf("Putere: ");
                scanf("%d", &autoNou.putere);
                printf("Pret: ");
                scanf("%lf", &autoNou.pret);
                printf("Inaintea carei pozitii sa fie inserat: ");
                scanf("%d", &pozitie);
                insertBefore(pozitie, autoNou);

                break;

            case 14:
                printf("Dati pozitia elementului de sters: ");
                scanf("%d", &pozitie);
                deleteElement(pozitie);

                break;

            case 15:
                splitList(&cap, &lista2);
                printf("\nLista1 (cap):\n");
                showInfo();
                printf("\nLista2 (separata):\n");
                Nod* temp = cap;
                cap = lista2;
                showInfo();
                cap = temp;

                break;

            case 16:
                if(lista2 == NULL) {
                    printf("\nMai intai faceti divizarea listei (optiunea 15)!\n");
                } else {
                    concatenateLists(lista2);
                    lista2 = NULL;
                }

                break;

            case 17:
                printf("Numele fisierului: ");
                scanf("%s", numeFisier);
                saveToFile(numeFisier);

                break;

            case 18:
                printf("Numele fisierului: ");
                scanf("%s", numeFisier);
                loadFromFile(numeFisier);

                break;

            case 19:
                freeMemory();

                break;

            case 0:
                freeMemory();
                printf("\nLa revedere!\n");
                return 0;

            default:
                printf("\nOptiune invalida! Incercati din nou.\n");

        }
    }

    return 0;
}
