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

### Decomposer en plusieurs fichiers

un seul fichier avec `int main() {...}`. Les autres fichiers existent sous deux formes : `module1.c` et `module1.h`
>`module1.h` contient les declarations des fonctions de `module.c`
```C
#ifndef MODULE_1_H
#define MODULE_1_H
// declaration des fonctions et structures

#endif
```

ceci permet d'annoncer les fonctions et structures qu'une seule fois, si le module est utilise dans plusieurs fichiers source.
On ajoute `#include "path/to/module1.h"` dans tous les fichiers qui utilisent les fonctions de `module1.c`
et aussi parfois a `module1.c` lui-meme.

### Compilation separee

Jusqu'ici nous avons compile tous les fichiers ensemble. Ce n'est pas possible une fois que les projets deviennent consequents

#### Compilation :
```Bash
gcc -c triangle.c
```
On va avoir un fichier triangle.o dans notre repertoire

#### Linking :
a la fin, `gcc -o main main.o point.o triangle.o` va nous fournir `main`

#### interet :
Avec une compilation separee, on peut facilement modifier un fichier, et ne recompiler **QUE LUI**.

Pour automatiser la compilation, on se tourne vers des `makefile`
*(cf exemple dans 4_example_point)*.

syntaxe:
```makefile
target: dependencies
	recipy
```

exemple de makefile:
```makefile
all: main

main: main.o
	gcc -o main main.o
```

## Donnes de base du C

`int` Entier avec signe code sur 32 bits (au moins)

`long` Entier avec signe code sur 64 bits (au moins)

`char` Caractere (ou entier) code sur 8 bits (au moins)

## Structures de base

Tableaux:
>`int a[10]`

>`a` est un tableau de taille 10. De base, C ne nettoie pas le tableau. Attention, C ne verifie pas si nous sommes toujours dans le tableau. En sortant des limites, nous ne pouvons plus savoir ce qu'il va se passer

## Assert

```C
#include <assert.h>

asser(expression);
```
Permet en mode DEBUG d'avoir une erreur (gcc ... -g)

## Best practices

Toujours mettre des accolades : `if (...) {...}` car si l'on n'en met pas, et que nous commentons l'expression, on peut se retrouver
a changer le comportement du programme apres.

## Bitwise operators

`~` inversion des bites 0 -> 1 et 1 -> 0

`^` XOR

`&` et binaire sur la representation de l'entier

`|` ou binaire sur la representation de l'entier

`<<` decalage a gauche, avec insertion de 0 a droite

`>>` decalage a droite, avec insertion de 0 a gauche

## Pointeurs

En C on peut recuperer les pointeurs vers les differentes variables.
C'est une facon d'agir sur des variables qui sont declarees dans d'autres fonctions.

**Attention**, toutes les variables sont donnees par valeur aux fonctions. Il en est de meme pour les pointeurs.

## Organisation de la memoire

Lors de l'execution d'une fonction, les variables propres a la fonction sont stockees dans la "pile" de la fonction. Elle est
detruite lorsque la fonction termine.
Si l'on veut stocker des plus grands objets, ou des objets de facon plus persistante, il faut les creer dans le "tas".
>On utilise `malloc(size_in_bytes) -> void *`.

Attention, on peut ecrire `char *s = "string"`, qui est valide. Cependant, on ne pourra PAS modifier cette chaine. Elle vit dans
un espace memoir reserve aux chaines immuables.

"la notion d'etiquettes en python correspond aux pointeurs en C"
```C
char *s = "abc";
char *c = s;
```
Representation dans la memoire (pile)
```
s	| 720 |
	-------
c	| 720 |
	-------
	|     |
	-------
	|     |
	-------
```

`malloc()` nous permet de faire de l'allocation dynamique, contrairement aux tableaux. Attention, une allocation dynamique peut echouer!
(par exemple sur les avions, on n'a pas le droit d'utiliser `malloc`)

`void *realloc(void *, size_t)` permet de reallouer la memoire. Renvoie un pointeur
vers la nouvelle addresse de debut. On peut ainsi agrandir un espace memoire. `realloc`
copie le contenu s'il faut deplacer la section de memoire.

`free(void *)` nous permet de liberer la memoire, et de la rendre au systeme (elle va
pouvoir etre redonnee a quelqu'un d'autre).

Des erreurs de programmation peuvent etre critiques, memes dans les dommaines qui ne le semblent pas. Par exemple hier, les numeros 15
et 17 n'etaient pas accessibles. Ceci peut cause des centaines de morts.

On peut acceder a l'addresse memoire d'une valeur :
```C
int a = 5;
int *p = &a;
*p = 12;
printf("%i\n", a);
```
>`12`

**Attention**, ne jamais retourner des pointeurs vers le tas par des fonctions.
Cela n'a aucun sens! (l'addresse retournee va surement etre reecrite, et ne va pas
correspondre a la meme chose).

## Struct

```C
struct Point {
	int x;
	int y;
};

struct Point p;
p.x = 5;
p.y = 12;
```

```
int a = 5;				a|  5	|
						---------
int b = f(a);			b|		|
						---------
						 |		| pour le retour de f(a)
						---------
						a|		| pour l'appel de f
						---------
```
a la fin on depile les cases inherantes a l'appel de f.

**Attention**, meme les structures sont donnees par valeur. Par exemple un fonction du type `void f(struct Point p)`
va recevoir un nouveau point. Modifier p dans le corps de la fonction ne va pas modifier la structure fournie en parametre.

```C
(*p).x = 5;
<==>
p->x = 5;
```


