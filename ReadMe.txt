Am scris acest cod pentru rezolvarea temei de la adresa https://ocw.cs.pub.ro/courses/sda-ab/tema1 primite in cadrul cursului PA(Proiectarea Algoritmilor).

Pentru rezolvarea cerintei 1 am decis sa citesc datele din fisirele d.in caracter cu caracter. De asemenea fiecare nod echipa a cuprins un vector alocat dinamic de structuri "player".

Pentru rezolvarea cerintei 2 am calculat scorul patrcurgand pentru fiecare echipa vectorul cu jucatori, facand media aritmetica a scorurilor acestor jucatori. Am determinat  n - numarul 
de echipe ce trebuie sa ramana in lista si le am eliminat numarul necesar de echipe calculand minimul scorurilor de Nr.DE ECHIPE - N (+1) ori. 

La cerinta 3 am implementat doua stive una pentru invinsi si una pentru pierzatori si o coada. In nodul unei stive se salveaza cate un nume de echipa. In nodul cozii se retin numele a doua
echipe care urmeaza sa aiba un meci in preuna. Pentru echipele dintr-un nod al cozii le caut in lista, le calculez scorul. In functie de scor ele sunt adaugate in stive. Echipele din stiva
de Castigatori vor urma sa creeze urmatoarea coada pentru urmatoarea runda de meciuri si numele lor sunt afisate alaturi de scorul acestora dupa finalizarea meciului, respectiv cu un punct
in plus. Echipele din stiva de invinsi se vor sterge din lista initiala.Si asa mai departe.
Cand vor mai ramane 8 echipe in concurs datele lor vor fi salvate intr - o a doua lista.

La cerinta 4 se adauga elemantele din lista anterior creata si se insereza intr-un BinarySearchTree, tinand cont de scor. Pentru a afisa echipele in ordine descrescatoare in functie de
scoruri, arborele se va parcurge in inordine (DRS).

La cerinta 5 am decis sa introduc elementele in AVL direct in ordine descrescatoare, precum au fost afisate la subpunctul anterior. Pentru a face asta am creat o functie care adauga
intr-un vector de cuvinte numele celor 8 echipe in ordinea afisata la cerinta 4. Astfel in arbore mereu se adaugau elemente in subarborele stang, iar balansarea acestuia se face doar din
rotatii la dreapta. Avand in vedere ca arborele are doar 8 noduri si ca este balansat, inseamna ca pe nivelul 2 al acestuia exista mereu 4 elemente respectiv elementele de la adresele
	AVLroot->right->right
	AVLroot->right->left
	AVLroot->left->left
	AVLroot->left->right    