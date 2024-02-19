## Exercice 3 - Questions (30 min)

A faire avec l'ensemble du groupe.  
Pensez à prendre des notes pour les donner à vos camarades absents.

1. Parlez de vos différents blocages avec le restant de la classe et discutez des solutions.

> Les blocages rencontrés sont les suivants : 
Attention à ne pas confondre les std::array et le type [] -> std::array est une class qui permet de créer des tableaux de taille fixe, tandis que [] est un type primitif en C qui est géré différement.

2. Expliquez la différence entre phase de build (compilation) et phase de link (édition des liens).  
En quoi consiste la précompilation et à quel moment est-elle effectuée ?

> Il y a 3 phases dans la compilation : la précompilation, la compilation et l'édition des liens. La précompilation consiste à remplacer les instructions préprocesseur par le code correspondant. Ce sont des manipulations purement textuelles (ex: les includes, les macros, etc.). La compilation consiste à traduire le code source en code machine. Il va construire l'arbre syntaxique du programme et vérifier que le code est correct. Si on lui a promis des fonction à un endroit (déclaration), il va laisser le code avec des trous (appels de fonctions). Pour les fonctions qui sont bien rédigées dans le fichier il remplace le code par du code machine. Puis on a l'edition des liens qui consiste à remplir les trous laissés par la compilation. Il va chercher les définitions des fonctions dans les fichiers objets et les insérer dans le code machine. Il va aussi chercher les fonctions dans les librairies externes et les insérer dans le code machine.

3. Que signifient les messages suivants ?  
a. error: 'qqchose' was not declared in this scope  
b. error: 'qqchose' is not a member of 'std'  
Ces erreurs se produisent-elles pendant la phase de build ou de link ?  
Que fait exactement l'instruction préprocesseur `#include` et pourquoi permet-elle généralement de résoudre ce type de problème ?

> a. la variable qqchose n'a pas été déclarée dans ce scope (fonction, classe, etc.).

> b. qqchose n'est pas un membre de la classe std. Souvent, on oublie d'inclure la librairie qui contient la définition de qqchose.

> Ces erreurs se produisent pendant la phase de compilation.

> L'instruction préprocesseur `#include` permet d'inclure le contenu d'un fichier dans un autre. Elle permet de résoudre ce type de problème car elle permet d'inclure les déclarations de variables, fonctions, classes, etc. qui sont définies dans d'autres fichiers.

4. Compilez le programme de l'exercice en ne linkant que le fichier-objet associé à `main.cpp` (c'est-à-dire en oubliant `utils.cpp`).  
Quelle est l'erreur qui s'affiche ?    
En quoi est-elle différente des erreurs de la question précédente ?  
Expliquez ce qu'elle signifie exactement.

> L'erreur qui s'affiche est : `/usr/bin/ld : main.o : dans la fonction « main » : main.cpp:(.text+0x5) : référence indéfinie vers « print_hello() » collect2: error: ld returned 1 exit status`. Ici on a une erreur de type référence indéfinie. Le programme a été compilé mais le linker n'a pas pu trouver la définition de la fonction `print_hello` qui est appelée dans le fichier `main.cpp`. Il ne sait donc pas où aller chercher la définition de cette fonction.

5. Décommentez maintenant les instructions commentées des fichiers [main.cpp](ex3/main.cpp) et [utils.hpp](ex3/utils.hpp).  
Compilez maintenant le programme complet (avec les modules main et utils).  
Quelle est l'erreur qui s'affiche ? S'agit-il d'une erreur de build ou de link ?  
Pourquoi se produit-elle ?  
Que faudrait-il faire pour la résoudre ?

> L'erreur qui s'affiche est : `/usr/bin/ld : utils.o : dans la fonction « print_bye() » : utils.cpp:(.text+0x0) : définitions multiples de « print_bye() »; main.o:main.cpp:(.text+0x0) : défini pour la première fois ici collect2: error: ld returned 1 exit status`. On nous indique qu'il y a une définition multiple de la fonction `print_bye`. Il s'agit d'une erreur de link. En effet, le linker a trouvé deux définitions de la fonction `print_bye` : une dans le fichier `main.cpp` et une dans le fichier `utils.cpp`. Il ne sait donc pas laquelle choisir. On a cette erreur ca dans le hpp il y a une définition de la fonction et non pas une déclaration. Il va donc y avoir la définition de la fonction dans chaque fichier .o qui inclut le hpp. Pour résoudre ce problème, il faut mettre la définition de la fonction dans le utils.cpp et la déclaration dans le utils.hpp.

6. Ajoutez le mot-clef `inline` devant la définition de la fonction `print_bye` dans [utils.hpp](ex3/utils.hpp). Que constatez-vous quand vous réessayez de compiler le programme ?  
Selon-vous, quel est l'effet du mot-clef `inline` sur le linker ?

> Il n'y a pas d'erreur lors de la compilation. Le mot-clef `inline` permet de dire de remplacer la déclaration de la fonction dans le fichier main.cpp par le code de la fonction. Ainsi je n'ai plus de définition multiple.