#!/usr/bin/python
# minicom: Mini Intérprete de comandos.
# Octulio Biletán - 09.2022.
# Programa escrito en lenguaje Python, versión 3.x.
# Llamar de la siguiente manera:
#       ./minicom.py
# si Python está instalado en su sistema.
# Es compatible en Linux, Windows y en Cygwin.
# Instalar desde la consola de Windows: python -m pip install pyreadline3
#
# Actualizado a Python 3.14.2, Enero de 2026.
#

import os, sys
import readline

nombre_usuario = os.getlogin()
# id_usuario = os.getuid()
dir_vigente = os.getcwd()

print("minicom v1.1.2026 -- Intérprete de comandos")
print("Ingrese '?' para mostrar los comandos admitidos.")
print("Usuario vigente: ", nombre_usuario)
# print("Usuario ID: ", id_usuario)
print("Dir. usuario vigente: ", dir_vigente)

cierto = 1
while cierto:
    # Espera comando...
    proceso = input(">> ")

    # Responde al comando ayuda
    if proceso == "?":
      print("? -- Ayuda de minicom.py")
      print("salir -- Sale de minicom")
      print("Ctrl+C -- Sale de minicom")
      print("Ctrl+D -- Sale de minicom")
      print("Ctrl+L -- Borra la pantalla")
      print("Cualquier comando escrito no reconocido por 'minicom' es enviado al intérprete de comandos del S.O. para su interpretación y ejecución.")
      print("Ejemplos: dir, ls, vdir, help, clear, mc, id, w, pwd, man, etc. etc.")
      print("En Windows: si quiere ejecutar una aplicación en una ventana separada haga lo siguiente:")
      print("cmd /c start <programa.ejecutable>")
      print("por ej.: cmd /c start mspaint")
      print("\nAplicación creada por Octulio Biletán, 09-2022, actualizado 01-2026.")
      print("Sitio: https://github.com/torrentelinux/torrentarium/")
      continue

    # Responde al comando salir
    if proceso == "salir":
      print("Terminado.")
      sys.exit(0)
      
    # Ejecuta comando externo
    status = os.system(proceso)
    print("status=", status)

    # Limpia las variables
    proceso = ""
    status=0

#
# Fin de la aplicación
#
