# Nome do programa
TARGET = vina++

# Diretórios
SRCDIR = src
LIBDIR = libs
OBJDIR = objects

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -I$(LIBDIR)

# Arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Regra principal
all: $(TARGET)

# Regra de compilação dos objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de ligação
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o bin/$@

# Regra para criar o diretório bin, se não existir
$(shell mkdir -p bin)

# Regra para limpar arquivos gerados
clean:
	rm -f $(OBJDIR)/*.o bin/$(TARGET)
