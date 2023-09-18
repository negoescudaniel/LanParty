ROMANA
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

ENGLISH    
I have written this code to solve the assignment from the address https://ocw.cs.pub.ro/courses/sda-ab/tema1 received within the PA (Algorithm Design) course.

For solving task 1, I decided to read the data from the files "d.in" character by character. Additionally, each team node included a dynamically allocated vector of "player" structures.

For solving task 2, I calculated the score by iterating through the player vector of each team, computing the arithmetic mean of the scores of these players. I determined "n" - the number
of teams that should remain in the list, and I removed the necessary number of teams by calculating the minimum scores of Nr. OF TEAMS - N (+1) times.

For task 3, I implemented two stacks, one for winners and one for losers, along with a queue. Each node in a stack stores the name of a team. Each node in the queue holds the names of
two teams that are scheduled to play together. For the teams in a queue node, I searched in the list, calculated their scores, and based on the scores, added them to the stacks. 
The teams in the Winners stack will form the next queue for the next round of matches, and their names are displayed alongside their scores after the match is finished, each with 
an additional point. The teams in the Losers stack are removed from the initial list. And so on.
When only 8 teams remain in the competition, their data will be saved in a second list.

For task 4, the elements from the previously created list are added and inserted into a Binary Search Tree (BST), taking scores into account. To display the teams in descending order 
based on scores, the tree is traversed in Inorder (Left-Root-Right) fashion.

For task 5, I decided to insert the elements into an AVL tree directly in descending order, as they were displayed in the previous subtask. To achieve this, I created a function that
adds the names of the 8 teams to a word array in the order displayed in task 4. Thus, the tree always added elements to the left subtree, and balancing was achieved only through right 
rotations. Considering that the tree has only 8 nodes and is balanced, this means that on level 2 of the tree, there are always 4 elements, specifically the elements at addresses:
AVLroot->right->right
AVLroot->right->left
AVLroot->left->left
AVLroot->left->right