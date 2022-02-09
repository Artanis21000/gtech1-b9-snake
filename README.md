# gtech1-b9-snake
Attention! Ce programme n'as pas été essayé ni prévu pour des plateformes autres que Linux! Toute expérience sera à vos risques et périls!
Afin de compiler ce jeu, veullez exéciter cette commande:"g++ window.cpp move.cpp boucle.cpp -lSDL2 -o boucle && ./boucle" sous debian ou autre compilateur linux.
Librairies et outils nécessaires à la compilation: libsedl2-dev, make, ctime
Commande pour lancer le jeu : ./boucle
Vous contrôlez un serpent blanc avec les touches directionnelles de votre clavier (haut,bas,droite et gauche) et avez pour but de manger des fruit rouges afin de grandir le plus possible! Attention, vous perdrez la partie si vous entrez en collision avec un mur ou vous-même.
