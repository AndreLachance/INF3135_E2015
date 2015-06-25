#ifndef INVENTAIRE_H
#	define INVENTAIRE_H

typedef int** INVENTAIRE;

void inventaireCharger (INVENTAIRE);

void inventaireAfficher (INVENTAIRE);

int* inventaireSelectionPneu (INVENTAIRE);

void inventaireSauvegarder (INVENTAIRE);

#endif /* INVENTAIRE_H */