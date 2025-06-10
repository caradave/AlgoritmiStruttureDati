# Nome dell'eseguibile
TARGET = es2

# Compilatore
CC = gcc

# Opzioni di compilazione
CFLAGS = -Wall -Wextra -std=c99 -g

# File sorgenti
SRCS = es2.c edge.c grafo.c

# File oggetto (convertendo i .c in .o)
OBJS = $(SRCS:.c=.o)

# Regola principale
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola per compilare i .c in .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)