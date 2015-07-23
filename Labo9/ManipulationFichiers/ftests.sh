#!/bin/bash

mkdir tests_resultats

echo "Tests de la fonction de copie."
mkdir tests_resultats/tests_copie

echo "Test copie 1: fichier vide"
./Fichiers "tests_fonctionnels/tests_copie/fichier_vide.txt" "tests_resultats/tests_copie/fichier_vide.txt" < "tests_fonctionnels/tests_copie/commandes_copie.txt" > "tests_resultats/tests_copie/stdout_resultat.txt"
diff tests_fonctionnels/tests_copie/fichier_vide_resultat.txt tests_resultats/tests_copie/fichier_vide.txt

echo "Test copie 2: fichier régulier"
./Fichiers "tests_fonctionnels/tests_copie/fichier_regulier.txt" "tests_resultats/tests_copie/fichier_regulier.txt" < "tests_fonctionnels/tests_copie/commandes_copie.txt" > "tests_resultats/tests_copie/stdout_resultat.txt"
diff tests_fonctionnels/tests_copie/fichier_regulier_resultat.txt tests_resultats/tests_copie/fichier_regulier.txt

echo "Tests de la fonction d'ajout des lignes"
mkdir tests_resultats/tests_ajout

echo "Test ajout : ligne"
./Fichiers "tests_fonctionnels/tests_ajout/fichier_depart.txt" "tests_resultats/tests_ajout/ajout_ligne.txt" < "tests_fonctionnels/tests_ajout/commandes_ajout_ligne.txt" > "tests_resultats/tests_ajout/stdout_resultat.txt"
diff tests_fonctionnels/tests_ajout/ajout_ligne_resultat.txt tests_resultats/tests_ajout/ajout_ligne.txt 

echo "Tests de recherche."
mkdir tests_resultats/tests_recherche

echo "Test Recherche 1 : mot trouver"
./Fichiers "tests_fonctionnels/tests_recherche/fichier_depart.txt" "tests_resultats/tests_recherche/fichier_sortie.txt" < "tests_fonctionnels/tests_recherche/mot_trouver.txt" > "tests_resultats/tests_recherche/mot_trouver_stdout.txt"
diff tests_fonctionnels/tests_recherche/mot_trouver_resultat.txt tests_resultats/tests_recherche/mot_trouver_stdout.txt


echo "Test Recherche 2: mot non trouver"
./Fichiers "tests_fonctionnels/tests_recherche/fichier_depart.txt" "tests_resultats/tests_recherche/fichier_sortie.txt" < "tests_fonctionnels/tests_recherche/mot_non_trouver.txt" > "tests_resultats/tests_recherche/mot_non_trouver_stdout.txt"
diff tests_fonctionnels/tests_recherche/mot_non_trouver_resultat.txt tests_resultats/tests_recherche/mot_non_trouver_stdout.txt

rm -rf tests_resultats

echo "fin des tests"
