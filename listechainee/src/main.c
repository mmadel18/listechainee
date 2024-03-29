// Projet Langage C liste chainée 

//Lucie LY
//Jonathan KOK
//Paul-Alexandre FRANCIS
//Loïc JEAN OPHOVEN
//Corentin GERVAIS
//Michael MADELAINE
// Juan Camilo GALINDO

#include <stdio.h>
#include <stdlib.h>

// Définition de la structure de cellule
typedef struct _cell cell;

struct _cell {
    int donnee;
    cell* suivant;
};

// Fonction de création d'une cellule
cell* cell_create(int d) {
    cell* cellule = malloc(sizeof(cell));
    cellule->donnee = d;
    cellule->suivant = NULL;
    return cellule;
}

// Insertion en tête de liste
cell* head_insert(int d, cell* liste) {
    cell* newCell = cell_create(d);
    newCell->suivant = liste;
    return newCell;
}

// Insertion en queue de liste
cell* end_insert(int d, cell* liste) {
    cell* pL = liste;
    cell* newCell = cell_create(d);
    if(liste != NULL) {
        while(pL->suivant != NULL) {
            pL = pL->suivant;
        }
        pL->suivant = newCell;
        return liste;
    }
    return newCell;
}

// Insertion à une position donnée
cell* insert_at_pos(int d, int pos, cell* liste) {
    cell* newCell = cell_create(d);
    cell* ptr = liste;
    if(liste == NULL) return newCell;
    if(pos == 0) {
        newCell->suivant = liste;
        return newCell;
    }
    for(int i = 0; i < pos-1; i++) {
        if(ptr->suivant != NULL) ptr = ptr->suivant;
    }
    newCell->suivant = ptr->suivant;
    ptr->suivant = newCell;
    return liste;
}

// Affichage de la liste
void affichage(cell* liste) {
    while(liste != NULL) {
        printf("%d\n", liste->donnee);
        liste = liste->suivant;
    }
}

// Suppression de l'élément après une position donnée
cell* delete_after_pos(int pos, cell* liste) {
    if (liste == NULL || liste->suivant == NULL) return liste;
    cell* temp = liste;
    cell* toDelete = NULL;
    if (pos == 0) {
        toDelete = liste->suivant;
        liste->suivant = toDelete->suivant;
    } else {
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->suivant;
        }
        if (temp == NULL || temp->suivant == NULL || temp->suivant->suivant == NULL) {
            return liste;
        }
        toDelete = temp->suivant;
        temp->suivant = toDelete->suivant;
    }
    free(toDelete);
    return liste;
}

int main() {
    // Création d'une liste vide
    cell* pL = NULL;

    // Insertion de quelques éléments en tête de liste
    pL = head_insert(3, pL);
    pL = head_insert(2, pL);
    pL = head_insert(1, pL);

    // Affichage de la liste avant insertion
    printf("Liste avant insertion :\n");
    affichage(pL);

    // Insertion à une position donnée
    printf("\nListe après insertion :\n");
    pL = insert_at_pos(4, 2, pL);
    affichage(pL);

    // Suppression de l'élément après la position donnée
    printf("\nListe après suppression :\n");
    pL = delete_after_pos(1, pL); // Supprime l'élément après la position 1
    affichage(pL);

    return 0;
}
