# Makefile para compilar y crear 'hello' en Linux.
#
# Variables del compilador y opciones.
compiler = gm2
flags       = -g -flibs=m2pim,m2iso,m2cor
source    = hello.mod
output    = hello

# Regla por defecto: compila el programa
all: $(output)

$(output): $(source)
	@echo "Iniciando compilación..."
	$(compiler) $(flags) $(source) -o $(output)
	@echo "Compilación finalizada."

# Regla para ejecutar el programa directamente
run: $(output)
	./$(output)

# Regla para limpiar los archivos generados
clean:
	rm -f $(output)
