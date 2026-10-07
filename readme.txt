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
escenaris poc habituals pero possibles (t3 i t4).

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

t4.txt - CAS MINIM: UN SOL ESTABLIMENT
  Fitxer: proves_un.csv (capçalera + una sola fila)
  Que fa:
    - 01: ha de dir 1 linia.
    - 02 amb la comarca 39 (Aran): ha de sortir un sol municipi, Naut Aran,
      amb 1 establiment.
    - 03 amb 259130 (Naut Aran): ha de sortir exactament l'establiment del
      fitxer, amb el numero de carrer "4" omplert amb zeros (00004) i les
      places i estances correctes.
    - 02 amb la comarca 2: es un codi valid pero no te cap dada en aquest
      fitxer, aixi que nomes ha de sortir la capçalera.
    - 04: una sola comarca amb un sol municipi.
  Per que: es el cas mes petit amb dades. Comprova que l'estructura
  funciona quan cada nivell (comarca, municipi i llista d'establiments)
  te un sol element, i que el maxim de la 04 es calcula be quan nomes hi
  ha un candidat.

3. ALTRES COMENTARIS
--------------------
- El separador del CSV es la coma (no el punt i coma), amb tots els camps
  entre cometes. Fem servir tokens() d'eines.h amb cometes = true.
- Els numeros (codi de comarca, places, estances) es converteixen sense
  stoi, ignorant qualsevol caracter que no sigui un digit: aixi un camp buit
  val 0 i "1.713" val 1713.
