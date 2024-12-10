# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = main.c conta.c usuario.c

# Gerar uma lista de arquivos objeto (.o) com base nos fontes (.c)
OBJS = $(SRCS:.c=.o)

# Flags do compilador
CC = gcc
CFLAGS = -Wall -Wextra -g

# Regra padrão: compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar cada arquivo .c em .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(OBJS) $(TARGET)

# Garante que "make clean" seja sempre executado corretamente
.PHONY: clean
