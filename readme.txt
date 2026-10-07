EDA - Exercici 1: Vector i list
NOM COGNOMS (u1XXXXXXX)

1. QUE FA EL PROGRAMA
---------------------
Llegeix el fitxer CSV d'establiments turistics de Catalunya i el guarda en
una estructura feta nomes amb vector i list:

  Establiments
    vector<Comarca>        indexat pel codi de comarca (acces O(1))
      vector<Municipi>     ordenat per codi IDESCAT (cerca dicotomica O(log M))
        list<Establiment>  en l'ordre del fitxer (afegir al final O(1))

De cada fila nomes es guarden els camps que fan servir les consultes:
retol, nom de la via, numero, numero d'inscripcio, places i estances.

Opcions del menu (el menu surt per cerr; per cout nomes surt el resultat):
  01  llegir dades del CSV indicat
  02  municipis d'una comarca amb el nombre d'establiments
  03  establiments d'un municipi
  04  per cada comarca, el municipi amb mes establiments
  0   acabar

Execucio d'un joc de proves (nomes es compara cout; cerr va a /dev/null):
  ./e1 < t1.txt 1> t1_out_meu.txt 2>/dev/null
  diff t1_out.txt t1_out_meu.txt

2. JOC DE PROVES
----------------
Cada fitxer tN.txt simula una interaccio d'un usuari amb el programa i te
la seva sortida esperada a tN_out.txt. Els fitxers proves_*.csv son CSV
petits fets per nosaltres, amb el mateix format (33 columnes) que el fitxer
del professor.

t1.txt - Sense dades
  Consulta 02 abans de llegir res, lectura d'un fitxer que no existeix
  (ha de dir 0 linies), consultes 02, 03 i 04 sense dades i una opcio
  incorrecta (07). Objectiu: que el programa no peti amb l'estructura buida.

t2.txt - Format del CSV (proves_format.csv)
  - camps amb comes dins de les cometes ("Hotel Mar, Sol", "Escala, l'")
  - places i estances buides (han de sortir com a 0)
  - places i estances amb punt de milers ("1.713" -> 1713)
  - numeros de carrer de tot tipus: "7" -> 00007, "1B" -> 0001B,
    "52BIS", "12-14", "S/N"
  - una linia buida enmig del fitxer (s'ha de descartar i no comptar)

t3.txt - Ordenacio i empats (proves_ordre.csv)
  - 02: els municipis surten ordenats per nom, no per codi ni per ordre
    del fitxer (inclou un nom amb accent, "Orrius", que va al final)
  - 03: els establiments surten en l'ordre del fitxer encara que estiguin
    barrejats amb els d'altres municipis
  - 04: empat dins d'una comarca (Pineda de Mar i Calella amb 3; guanya
    el que hi arriba primer en el fitxer, igual que a la sortida del
    professor) i empat entre comarques (Barcelona i Pineda de Mar amb 3,
    s'ordenen per nom del municipi)
  - un mateix codi de municipi escrit de dues maneres ("Barcelona" i
    "BARCELONA"): es queda el nom de la primera aparicio

t4.txt - Recarregar dades i codis fora de rang
  Llegeix proves_format.csv i despres proves_ordre.csv: les dades del
  primer fitxer han de desapareixer. Consulta comarques 0, 43, 44 i 99 i
  un municipi inexistent: no ha de sortir cap resultat ni petar.

t5.txt - Fitxer real del professor (establimentsCurt.csv)
  Consultes diferents de les del joc de proves del professor: comarques
  13, 36 i 21 (molts municipis), comarca 1 (no te establiments al fitxer
  curt), municipis 080193 (Barcelona, 19 establiments) i 081635, i la 04.
  Fa servir el cami de bas.udg.edu /u/prof/dfiguls/Public/; per executar-lo
  en un altre ordinador cal canviar el cami.

t6.txt - Escenari normal amb el fitxer gran (establimentsLlarg.csv)
  112714 linies. Comarques 43 (Lluçanès) i 27 (Pla d'Urgell), que tenen
  empats al maxim (Oristà/Perafita i Ivars d'Urgell/Mollerussa), comarca 5
  (nomes 3 municipis), dos municipis de 6 establiments (inclou numeros com
  "s/n" i "Parcela 39") i la 04 amb les 43 comarques.
  Fa servir el cami de bas.udg.edu.

t7.txt - Fitxer amb nomes la capçalera (proves_buit.csv)
  Ha de dir 0 linies i les consultes 02, 03 i 04 no han de mostrar res.

t8.txt - Fitxer amb un sol establiment (proves_un.csv)
  Cas minim amb dades: una comarca, un municipi i un establiment.
  Una consulta d'una comarca que no hi es no ha de mostrar res.

t9.txt - Consultes repetides i en un ordre poc habitual
  04 abans de llegir dades, llegir dues vegades el mateix fitxer (no s'han
  de duplicar els establiments: Escala, l' ha de seguir tenint 3) i la
  mateixa consulta 02 dues vegades seguides.

3. ALTRES COMENTARIS
--------------------
- El separador del CSV es la coma (no el punt i coma), amb tots els camps
  entre cometes. Fem servir tokens() d'eines.h amb cometes = true.
- Els numeros (codi de comarca, places, estances) es converteixen sense
  stoi, ignorant qualsevol caracter que no sigui un digit: aixi un camp buit
  val 0 i "1.713" val 1713.
