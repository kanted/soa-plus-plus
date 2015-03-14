# soa-plus-plus
2010/2011

Cosimo Sacco <cosimosacco@gmail.com>
Davide Silvestri <davidesil.web@gmail.com>

Compilazione:
-------------
Eseguire lo script soa-plus-plus-test.sh.
Lo script effettua il download dei sorgenti dal repository Google Code
ed effettua la compilazione, indicando quali eseguibili sono stati prodotti.
Lo script è anche disponibile all' indirizzo
http://soa-plus-plus.googlecode.com/files/soa-plus-plus-test.sh

Esecuzione:
-----------
Per effettuare il test è necessario seguire i seguenti step:
1) avviare il Service Registry (soa-plus-plus/Test/Servers/registry)
   sull' indirizzo 127.0.0.1:4000 (in modo da poter utilizzare un
   semplice script di avvio per i client senza dover specificare,
   per ciascuno, l' indirizzo del Registry).
2) avviare i Service Provider 
   (soa-plus-plus/Test/Servers/horizontalFlipServer,
    soa-plus-plus/Test/Servers/rotateImageServer,
    soa-plus-plus/Test/Servers/imageRegisterServer)
3) avviare i client eseguendo lo script soa-plus-plus/Test/Client/clientsStart.sh

