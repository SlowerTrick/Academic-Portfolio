CASOS_DIR = Casos_de_teste

#O arquivo que é pra ser descompactado deve terminar com .comp
#Verificar se você está colocando o arquivo certo para compactar/descompactar.
#Ex: compactar (input.txt) / descompactar (input.txt.comp)

# Arquivos fonte
SRC_ALL = $(wildcard *.c)
SRC_COMPACTA = $(filter-out descompacta.c, $(SRC_ALL))
SRC_DESCOMPACTA = $(filter-out compacta.c, $(SRC_ALL))

# Binários
BIN_COMPACTA = compacta
BIN_DESCOMPACTA = descompacta

# Compila sem o descompacta.c
$(BIN_COMPACTA): $(SRC_COMPACTA)
	gcc $^ -o $@

# Compila sem o compacta.c
$(BIN_DESCOMPACTA): $(SRC_DESCOMPACTA)
	gcc $^ -o $@

all:
	clear

prog:
	gcc *.c -o test -g
	touch teste_saida.txt
	./test > teste_saida.txt

valgrind:
	gcc -g *.c
	valgrind --leak-check=full ./a.out

clean:
	rm -f $(BIN_COMPACTA) $(BIN_DESCOMPACTA) test a.out
	find $(CASOS_DIR) -type f -name '*.comp' -delete

run-test:
	@if [ -z "$(T)" ]; then \
		echo "Erro: informe o número do teste com T=número (ex: make run-test T=2)"; \
		exit 1; \
	fi; \
	TEST_DIR="$(CASOS_DIR)/test$(T)"; \
	INPUT_FILE=$$(find "$$TEST_DIR" -maxdepth 1 -type f \
		\( -name '*.txt' -o -name '*.png' -o -name '*.jpg' -o -name '*.bin' \
		   -name '*.dat' -o -name '*.json' -o -name '*.csv' -o -name '*.bmp' \
		   -o -name '*.gif' -o -name '*.wav' \) | head -n1); \
	if [ -z "$$INPUT_FILE" ]; then \
		echo "Erro: nenhum arquivo de entrada encontrado em $$TEST_DIR"; \
		exit 1; \
	fi; \
	echo "============================="; \
	echo "Rodando teste: $$TEST_DIR"; \
	echo "Arquivo de entrada: $$INPUT_FILE"; \
	$(MAKE) $(BIN_COMPACTA) >/dev/null; \
	./$(BIN_COMPACTA) "$$INPUT_FILE"; \
	$(MAKE) $(BIN_DESCOMPACTA) >/dev/null; \
	./$(BIN_DESCOMPACTA) "$$INPUT_FILE.comp"; \
	echo "============================="

run-all-tests:
	@for dir in $(CASOS_DIR)/test* ; do \
		INPUT_FILE=$$(find "$$dir" -maxdepth 1 -type f \
			\( -name '*.txt' -o -name '*.png' -o -name '*.jpg' -o -name '*.bin' \
			   -name '*.dat' -o -name '*.json' -o -name '*.csv' -o -name '*.bmp' \
			   -o -name '*.gif' -o -name '*.wav' \) | head -n1); \
		if [ -z "$$INPUT_FILE" ]; then \
			echo "Ignorando $$dir (nenhum arquivo válido encontrado)"; \
			continue; \
		fi; \
		echo "============================="; \
		echo "Rodando teste: $$dir"; \
		echo "Arquivo de entrada: $$INPUT_FILE"; \
		$(MAKE) $(BIN_COMPACTA) >/dev/null; \
		./$(BIN_COMPACTA) "$$INPUT_FILE"; \
		$(MAKE) $(BIN_DESCOMPACTA) >/dev/null; \
		./$(BIN_DESCOMPACTA) "$$INPUT_FILE.comp"; \
		echo "============================="; \
	done