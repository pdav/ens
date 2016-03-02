Supports de cours de systèmes d'exploitation de Pierre David
============================================================

Bienvenue sur cette page qui regroupe mes supports de cours de **systèmes
d'exploitation** et **systèmes concurrents** en licence d'informatique
à l'université de Strasbourg (France).


Licence
-------

Tous ces supports de cours sont placés sous licence « Creative Commons
Attribution - Pas d’Utilisation Commerciale 4.0 - International »

Pour accéder à une copie de cette licence, merci de vous rendre à
l'adresse suivante <http://creativecommons.org/licenses/by-nc/4.0/deed.fr>.

<img src="http://mirrors.creativecommons.org/presskit/buttons/88x31/png/by-nc.png" width="100">


Motivations
-----------

J'ai choisi de partager ces supports de cours pour plusieurs raisons :

- les étudiants préfèrent utiliser des versions électroniques des
    documents, et plutôt que laisser trainer des copies pirates
    obsolètes, je préfère directement mettre à disposition les
    versions à jour et originales.

- pour rédiger ces documents, outre mes travaux personnels et les
    lectures d'ouvrages, j'ai puisé dans les documents mis à disposition
    sur le réseau par d'autres enseignants que je ne saurais jamais
    trop remercier. C'est un juste retour des choses que d'offrir à
    mon tour ma modeste contribution, en espérant qu'elle soit utile
    à d'autres.

Si vous utilisez ces supports, que vous les trouvez utiles (que ce soit
juste pour les lire ou pour les adapter) et que vous voulez apporter un
peu de gentillesse dans ce bas monde, sentez-vous libre de m'envoyer un
petit mail à l'adresse pda (at) unistra.fr.


Erreurs, imperfections, coquilles, etc.
---------------------------------------

Si vous notez des erreurs, des inperfections, des coquilles ou n'importe
quoi qui permette d'améliorer ces supports, vous pouvez soit me contacter
par mail à l'adresse ci-dessus, soit utiliser le mécanisme de [bug
tracking de github](../../issues).


Lecture en ligne
----------------

Si vous êtes intéressé-e-s seulement par la lecture de ces supports, vous les
trouverez dans les liens suivants :

| Document | Objet |
| :------: | ----- |
| [manuel.pdf](http://dpt-info.u-strasbg.fr/~pda/manuel.pdf) | notice simplifiée des primitives systèmes et fonctions de librairie |
| [exercices.pdf](http://dpt-info.u-strasbg.fr/~pda/exercices.pdf) | recueil d'exercices |
| [conseils.pdf](http://dpt-info.u-strasbg.fr/~pda/conseils.pdf) | conseils pour réussir TP et projets |
| [cours-se1.pdf](http://dpt-info.u-strasbg.fr/~pda/cours-se1.pdf) | transparents du cours de systèmes d'exploitation de L2S4 (partie 1 : utilisation des primitives systèmes) |
| [cours-se2.pdf](http://dpt-info.u-strasbg.fr/~pda/cours-se2.pdf) | transparents du cours de systèmes d'exploitation de L2S4 (partie 2 : le noyau) |
| [cours-sc.pdf](http://dpt-info.u-strasbg.fr/~pda/cours-sc.pdf) | transparents du cours de systèmes concurrents en L3S5 |


Sources LaTeX
-------------

Si vous êtes intéressé-e-s par les sources de ces supports (pour
les reprendre tels quels ou les adapter à votre propre enseignement)
et si vous respectez les [conditions de la licence CC-BY-NC 4.0](http://creativecommons.org/licenses/by-nc/4.0/deed.fr),
vous trouverez dans ce dépôt tout le nécessaire.

### Structure en répertoires

Les répertoires qui composent ce dépôt sont découpés de telle sorte
qu'ils soient autonomes : vous pouvez juste récupérer le répertoire
qui vous concerne sans vous soucier des autres.

### Prérequis

Pour compiler ces sources, il faut :

- une distribution de LaTeX complète (comme [texlive](https://www.tug.org/texlive/) par exemple), avec notamment les programmes `pdflatex` et `makeindex`
  ainsi que les paquetages LaTeX les plus courants
- les utilitaires Unix classiques, comme `make` (version GNU), `test`,
    `rm`, etc.
- les programmes :
  * `fig2dev` (venant avec [`xfig`](http://www.xfig.org), pour convertir les innombrables fichiers FIG en PDF)
  * [`inkscape`](http://www.inkscape.org) (pour convertir les fichiers SVG en PDF)
  * [`gnuplot`](http://www.gnuplot.info) (version 4.6 ou supérieure, pour le cours de systèmes concurrents notamment)
  * [`pdfjam`](http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic-research/firth/software/pdfjam) (si vous voulez imprimer les transparents en 3 ou 6 pages par page par exemple)

Pour imprimer les transparents en 3 ou 6 pages par page (cibles `print`
des `Makefile`), il faut le programme `pdfjam`.

Note spécifique au cours de système concurrents : certaines données
sont extraites de la CPUDB de Stanford. Une copie des données utilisées
est présente dans le dépôt. Si vous voulez rafraîchir ces données
(ce qui n'est à priori pas nécessaire), le moteur SGBD [PostgreSQL]
(http://www.postgresql.org) sera nécessaire.
