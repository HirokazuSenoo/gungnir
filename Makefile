gungnir.so: netsoc.o consoc.o gungnir.h
	gcc -o gungnir.so -fPIC -shared -Wall netsoc.o consoc.o
netsoc.o: netsoc.c gungnir.h
	gcc -c -fPIC -Wall netsoc.c
consoc.o: consoc.c
	gcc -c -fPIC -Wall consoc.c
header:gungnir.h
	cp gungnir.h /usr/local/include/gungnir.h
install:gungnir.so gungnir.h
	sudo cp gungnir.so /usr/local/lib/libgungnir.so
	sudo ldconfig
	sudo cp gungnir.h /usr/local/include/gungnir.h
uninstall:
	sudo rm /usr/local/lib/libgungnir.so
	sudo rm /usr/local/include gungnir.h
sample:./sample/client.c ./sample/serv.c Makefile
	gcc -o client ./sample/client.c -lgungnir
	gcc -o serv ./sample/serv.c -lgungnir
clean: *.o
	rm *.o
