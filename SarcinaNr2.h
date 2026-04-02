#ifndef SARCINANR2_H_INCLUDED
#define SARCINANR2_H_INCLUDED

// Structura pentru datele automobilului
typedef struct {
    char model[50];
    char tara[50];
    int an;
    int putere;
    double pret;
} Auto;

// Structura pentru nodul listei
typedef struct Nod {
    Auto date;
    struct Nod* urmat;
} Nod;

// Pointer global la capul listei
extern Nod *cap;

// Prototipurile functiilor
int createList(int n);
void readInfo(void);
void showInfo(void);
Nod* searchElement(char model[]);
void modifyInfo(Nod* element);
Nod* lastElement(void);
int sizeList(void);
void swapElements(int poz1, int poz2);
void sortList(void);
void addEnd(int v);
void addBeginning(int v);
void insertAfter(int pozitie, Auto date);
void insertBefore(int pozitie, Auto date);
void deleteElement(int pozitie);
void splitList(Nod** lista1, Nod** lista2);
void concatenateLists(Nod* lista2);
void saveToFile(char numeFisier[]);
void loadFromFile(char numeFisier[]);
void freeMemory(void);


#endif // SARCINANR2_H_INCLUDED
