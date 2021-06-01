# Introduction au langage C

Zero overhead principe : C ne va pas faire de verifications inutiles -> ca va vite

Permet d'acceder au hardware (systemes embarques)

"C'est pas evident de savoir comment enseigner l'informatique"

Le seul moyen pour un processeur de communiquer avec l'exterieur est a travers ses pattes et des signaux electriques (0 ou 1 pour l'informaticien).
Mais alors comment passer de langages haut niveaux au hardware? (par exemple python). Le C est un langage compile, la compilation va faire passer notre code
C vers un code assembler specifique au processeur.

## Assembler

il n'y a pas de variables. Le processeur a des registres (30 ~ 60), dans lesquelles je peux mettre des valeurs.

Code C :
```C
int a = 5;
int b = a + 3;
```

Code assembler:
```asm
MOV R1, 5	;on met 5 dans la boite R1
MOV R2, R1	;on copie la valeur de R1 dans R2
ADD R2, 3	;on ajoute 3 a la valeur dans R2
```
Un autre exemple:
```asm
MOV R3, 0
debut:
CMP R3, 10, fin
CALL "print"
ADD R3, 1
JMP debut
fin:
```

En fait l'assembler ne suffit pas, il faut encore le traduire en 0 et 1 pour que le processeur nous comprenne.
Pour ce faire, le fabriquant du processeur fournit un "assembler" (AS), qui va traduire le code assembler en langage machine.
La plupart de ces operations se font en un cycle de processeur. Par exemple, un processeur 64bit va pouvoir faire des operations sur des
entiers 64bits en un cycle.

## Compilation

Code C  ---- cc ---->	Assembler   ----- AS ----->	Code machine

Ce qui est le plus difficile c'est de choisir dans quel niveau de memoire mettre les differentes informations, pour pouvoir optimiser la vitesse
A ce niveau, meme les deplacement physiques de l'information (les quelques millimettres) peuvent faire la difference.

## Donnes de base du C

`int` Entier avec signe code sur 32 bits (au moins)
`long` Entier avec signe code sur 64 bits (au moins)
`char` Caractere (ou entier) code sur 8 bits (au moins)

## Structures de base

Tableaux:
> `int a[10]`

>`a` est un tableau de taille 10. De base, C ne nettoie pas le tableau. Attention, C ne verifie pas si nous sommes toujours dans le tableau. En sortant des limites, nous ne pouvons plus savoir ce qu'il va se passer
