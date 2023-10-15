#-------------------------------------------------------------------------------
# Programa   : poema.py
# Propósito  : Visualizar en pantalla un poema en idioma español.
# Autor      : Octulio Biletán
# Referencias: https://poemas.yavendras.com/a-mis-amigos.htm
#              https://docs.python.org/es/3/library/locale.html
# Notas      : Se utilizó el IDE PyScripter - Windows -
# Creado     : 01/10/2023
# Copyright  : (c) Octulio Biletán 2023
# Licencia   : software libre.
#-------------------------------------------------------------------------------
import os
import locale

# Se define la función main()
def main():
    poema_titulo = "\t\tA mis amigos\n"
    poema_autor = "Alberto Cortéz"

    poema_lineas = ["A mis amigos les adeudo la ternura",
		    "y las palabras de aliento y el abrazo;",
		    "el compartir con todos ellos la factura",
		    "que nos presenta la vida, paso a paso.",
		    "",
		    "A mis amigos les adeudo la paciencia",
		    "de tolerarme las espinas más agudas;",
		    "los arrebatos de humor, la negligencia,",
		    "las vanidades, los temores y las dudas.",
		    "",
		    "Un barco frágil de papel,",
		    "parece a veces la amistad",
		    "pero jamás puede con él",
		    "la más violenta tempestad",
		    "porque ese barco de papel,",
		    "tiene aferrado a su timón",
		    "por capitán y timonel:",
		    "un corazón.",
		    "",
		    "A mis amigos les adeudo algún enfado",
		    "que perturbara sin querer nuestra armonía;",
		    "sabemos todos que no puede ser pecado",
		    "el discutir, alguna vez, por tonterías."
		   ]

    # Ajusta la salida del texto a Argentina/español en el S.O.
    locale.setlocale(locale.LC_ALL, 'spanish_argentina')

    # Borra la pantalla
    os.system("cls")

    # Muestra el título del poema
    print(poema_titulo)

    # Muestra todo el poema
    for linea in poema_lineas:
        print("    ", linea)

    # Muestra el autor del poema
    print("\n\t\tAutor del poema: ", poema_autor)

if __name__ == '__main__':
    main()
