gungnir.so: netsoc.c gungnir.h
	gcc -o gungnir.so -fPIC -shared -Wall netsoc.c
install:gungnir.so
	sudo cp gungnir.so /usr/local/lib/libgungnir.so
	sudo ldconfig
	sudo cp gungnir.h /usr/local/include/gungnir.h
uninstall:
	sudo rm /usr/local/lib/libgungnir.so
	sudo rm /usr/local/include gungnir.h
