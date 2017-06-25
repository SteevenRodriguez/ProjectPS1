INCLUDE=-Iinclude/
LIBS=-Llib/

prueba: lib/*
	gcc $(LIBS) $^ -o bin/$@

liblista.so: obj/*
	gcc -shared  $^ -o lib/liblista.so

pruebaLista.o: src/pruebaLista.c
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

ListaAnterior.o: src/ListaAnterior.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_InsertarFin.o: src/Lista_InsertarFin.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Ultimo.o: src/Lista_Ultimo.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Buscar.o: src/Lista_Buscar.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_InsertarInicio.o: src/Lista_InsertarInicio.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Conteo.o: src/Lista_Conteo.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_vacia.o: src/Lista_vacia.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Primero.o: src/Lista_Primero.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

listainicializar.o: src/listainicializar.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Sacar.o: src/Lista_Sacar.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_InsertarAntes.o: src/Lista_InsertarAntes.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_SacarTodos.o: src/Lista_SacarTodos.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_InsertarDespues.o: src/Lista_InsertarDespues.c 
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@

Lista_Siguiente.o: src/Lista_Siguiente.c
	gcc -fPIC -Wall -c $(INCLUDE) $^ -o obj/$@


.PHONY: clean
clean:
	rm -rf obj/* bin/* lib/*


      


