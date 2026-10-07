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
Cada fitxer tN.txt simula la interaccio d'un usuari amb el programa (conte
tot el que l'usuari escriuria pel teclat) i te la seva sortida esperada a
tN_out.txt. Els fitxers proves_*.csv son CSV petits fets per nosaltres amb
el mateix format que el del professor (capçalera + 33 columnes, separador
coma i camps entre cometes), pensats per provar casos concrets que el
fitxer real no prova o que costa trobar-hi.

Hem seguit la idea de provar primer l'escenari normal (t1 i t2) i despres
escenaris poc habituals pero possibles (t3, t4 i t5).

t1.txt - ESCENARI NORMAL AMB EL FITXER CURT DEL PROFESSOR
  Fitxer: /u/prof/dfiguls/Public/establimentsCurt.csv (225 files)
  Que fa:
    - 01: llegeix el fitxer (ha de dir 225 linies).
    - 02 amb les comarques 13 (Barcelones), 36 (Tarragones) i 21 (Maresme):
      son comarques amb molts municipis, aixi es veu que surten ordenats
      pel nom i amb el nombre correcte d'establiments.
    - 02 amb la comarca 1 (Alt Camp): existeix pero al fitxer curt no te cap
      establiment, aixi que nomes ha de sortir la capçalera.
    - 03 amb 080193 (Barcelona, 19 establiments, en l'ordre del fitxer) i
      081635 (Pineda de Mar, que te un numero de carrer "016 B" que ja te
      5 caracters i no s'ha d'omplir amb zeros).
    - 04 amb totes les comarques del fitxer curt.
  Per que: comprova que el funcionament basic es correcte amb dades
  reals, amb consultes diferents de les del joc de proves del professor.

t2.txt - ESCENARI NORMAL AMB EL FITXER GRAN DEL PROFESSOR
  Fitxer: /u/prof/dfiguls/Public/establimentsLlarg.csv (112714 files)
  Que fa:
    - 01: ha de dir 112714 linies i fer-ho rapid (comprova que la lectura
      i l'estructura aguanten el volum real de dades).
    - 02 amb les comarques 43 (Llucanes) i 27 (Pla d'Urgell): totes dues
      tenen dos municipis empatats amb el maxim (Orista i Perafita amb 17;
      Ivars d'Urgell i Mollerussa amb 7). A la 02 surten tots dos.
    - 02 amb la comarca 5 (Alta Ribagorca), que nomes te 3 municipis.
    - 03 amb 080446 (Capellades) i 430770 (Mas de Barberans): municipis de
      6 establiments amb numeros de carrer com "s/n" o "Parcela 39" (no
      comencen per digit i no s'omplen amb zeros).
    - 04 amb les 43 comarques: a les comarques amb empat ha de sortir el
      municipi que arriba primer al maxim llegint el fitxer (Perafita i
      Mollerussa), igual que a la sortida del professor.
  Per que: es l'escenari real de la practica, i el que posa a prova
  l'eficiencia de l'estructura.

t3.txt - SENSE DADES: CONSULTES AMB L'ESTRUCTURA BUIDA
  Fitxers: no_existeix.csv (no existeix) i proves_buit.csv (nomes capçalera)
  Que fa:
    - 02, 03 i 04 ABANS de llegir cap fitxer: el vector de comarques encara
      es buit; el programa no pot accedir fora del vector ni petar.
    - Opcio 07, que no existeix: no ha de mostrar res per cout (el missatge
      d'error va per cerr) i el programa ha de continuar.
    - 01 amb un fitxer que no existeix: ha de dir 0 linies.
    - 01 amb un fitxer que nomes te la capçalera: tambe 0 linies (la
      capçalera no compta com a dada).
    - 02, 03 i 04 despres de cada lectura buida: no ha de sortir cap
      resultat, nomes les capçaleres.
  Per que: son les situacions on es mes facil que el programa peti
  (accedir a posicions que no existeixen, llegir un fitxer que no s'obre).

t4.txt - FORMAT DEL CSV I CASOS LIMIT DE DADES
  Fitxers: proves_format.csv (5 establiments i una linia buida) i
           proves_un.csv (un sol establiment)
  Que fa amb proves_format.csv:
    - Camps amb comes dins de les cometes ("Hotel Mar, Sol" i el municipi
      "Escala, l'"): han de llegir-se com un sol camp.
    - Places i estances buides: han de sortir com a 0.
    - Places i estances amb punt de milers ("1.713", "2.000"): han de
      sortir com 1713 i 2000.
    - Numeros de carrer de tots els tipus: "7" -> 00007, "1B" -> 0001B,
      "52BIS" i "12-14" (5 caracters, es queden igual), "S/N" (no comença
      per digit, es queda igual).
    - Una linia buida enmig del fitxer: s'ha de descartar i no comptar
      (ha de dir 5 linies, no 6).
    - Codis fora de rang: comarques 0, 44 i 99 i municipi 999999. No ha de
      sortir cap resultat ni petar (el codi 44 i el 99 queden fora del
      vector de comarques).
  Que fa amb proves_un.csv:
    - El cas minim amb dades: una comarca, un municipi i un establiment.
      La 02, la 03 i la 04 han de mostrar exactament aquest establiment.
    - Una 02 d'una comarca que estava al fitxer anterior (la 2): ja no hi
      ha de ser.
  Per que: comprova que la lectura del CSV i la conversio de numeros son
  correctes en els casos dificils del format.

t5.txt - ORDENACIO, EMPATS I RECARREGAR DADES
  Fitxers: proves_ordre.csv (17 establiments barrejats) i proves_format.csv
  Que fa amb proves_ordre.csv:
    - 02 amb la comarca 21: els municipis surten ordenats per nom, no pel
      codi ni per l'ordre del fitxer. "Orrius" (amb accent) va al final.
    - 03 amb 080193 i 081635: els establiments surten en l'ordre del
      fitxer, encara que estiguin barrejats amb els d'altres municipis.
    - El municipi 080193 apareix com "Barcelona" i despres com "BARCELONA":
      s'ha de quedar el nom de la primera aparicio.
    - 04 amb empat dins d'una comarca: Pineda de Mar i Calella tenen 3, pero
      Pineda hi arriba primer en el fitxer, aixi que guanya Pineda (encara
      que Calella vagi abans per ordre alfabetic). Igual a Tarragones:
      guanya Vila-seca i no Salou.
    - 04 amb empat entre comarques: Barcelona i Pineda de Mar tenen 3; es
      mostren ordenats pel nom del municipi.
  Que fa despres:
    - Llegeix proves_format.csv: les dades de proves_ordre.csv han de
      desapareixer (la 04 i la 02 de la comarca 21 ja no les mostren).
    - Torna a llegir el MATEIX fitxer: no s'han de duplicar els
      establiments (l'Escala ha de seguir tenint 3, no 6).
    - La mateixa consulta 02 dues vegades seguides: ha de donar el mateix
      (les consultes no modifiquen les dades).
  Per que: comprova els criteris d'ordenacio i desempat de l'enunciat i
  que llegir dades substitueix les anteriors.

3. ALTRES COMENTARIS
--------------------
- El separador del CSV es la coma (no el punt i coma), amb tots els camps
  entre cometes. Fem servir tokens() d'eines.h amb cometes = true.
- Els numeros (codi de comarca, places, estances) es converteixen sense
  stoi, ignorant qualsevol caracter que no sigui un digit: aixi un camp buit
  val 0 i "1.713" val 1713.
