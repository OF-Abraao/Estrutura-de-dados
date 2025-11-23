# Makefile - projeto em pt-br
# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -O2 -Iinclude -Wall -Wextra

# Diretórios do projeto
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/tp2.out

# Encontra todos os arquivos .cpp e gera lista de objetos
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean dirs

# Alvo principal: cria diretórios e compila o programa
all: dirs $(TARGET)

# Cria os diretórios necessários se não existirem
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Linka todos os objetos para criar o executável final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila cada arquivo .cpp em um arquivo .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa todos os arquivos gerados na compilação
clean:
	rm -rf $(OBJDIR) $(BINDIR)
