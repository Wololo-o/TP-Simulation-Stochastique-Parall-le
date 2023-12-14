# TP Simulation Stochastique Parallèle
Ce TP a pour but de nous faire découvrir des moyens de mettre en place du parallélisme dans le cadre de la réalisation de calculs stochastiques.

On utilise ici la méthode de Monte Carlo pour calculer une estimation de PI.

## Pré-requis
Il est nécessaire d'avoir CMake pour compiler ce projet

## Compilation de la librairie
D'abord, il faut compiler la librairie CLHEP qui nous donne accès (entre autres) à un générateur de nombres pseudo-aléatoires.

A exécuter depuis le répertoire racine du projet
```
cd lib/Random
./configure --prefix=$PWD
make
make install
```

## Compilation du projet
A exécuter depuis le répertoire racine du projet
```
cd build
cmake ..
make
```

## Exécutables produits
* `sequentiel` : estimation de PI avec du calcul séquentiel (sans parallélisme) en calculant une moyenne de 10 estimations avec 1 milliard de points chacunes.
* `genStatus` : fais tourner le générateur dans le vide et sauvegarde un statut tous les 2 milliards de tirages (utilisé ensuite pour la parallélisation).
* `estimationPI` : fait une estimation de PI avec 1 milliard de points. A utiliser avec le script `parallel.sh`.
* `estimationPIThread` : programme utilisant des threads pour faire le calcul parallèle, puis fait la moyenne des calculs.

## Utilisation
(depuis le répertoire `build`)
* `./genStatus` pour générer les fichiers d'état du générateur pseudo-aléatoire
* `./sequentiel` pour lancer le programme réalisant un calcul séquentiel
* `./parallel.sh` pour lancer le script lançant 10 fois `estimationPI`.
* `./estimationPIThread` : pour lancer le programme utilisant des threads.
