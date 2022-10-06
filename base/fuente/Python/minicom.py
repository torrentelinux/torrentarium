#!/usr/bin/python
# minicom: Mini Intérprete de comandos.
# Octulio Biletán - 09.2022.
# Programa escrito en lenguaje Python, versión 3.x.
# Llamar de la siguiente manera:
#       ./minicom.py
# si Python está instalado en su sistema.
# Es compatible en Linux, Windows y en Cygwin.

import os, sys
import readline

nombre_usuario = os.getlogin()
id_usuario = os.getuid()
print("minicom v1.1 -- Intérprete de comandos")
print("Ingrese '?' para mostrar los comandos admitidos.")
print("Usuario vigente: ", nombre_usuario)
print("ID usuario vigente: ", id_usuario)

cierto = 1
while cierto:
    # Espera comando...
    proceso = input(">> ")

    # Responde al comando ayuda
    if proceso == "?":
      msj_ayuda = "? -- Ayuda de minicom.py\n" \
                  "salir -- Sale de minicom\n" \
                  "Ctrl+C -- Sale de minicom\n" \
                  "Ctrl+D -- Sale de minicom\n" \
                  "Ctrl+L -- Borra la pantalla\n" \
                  "Cualquier comando escrito no reconocido por 'minicom' es enviado al intérprete de comandos del S.O. para su interpretación y ejecución.\n" \
                  "Ejemplos: dir, ls, vdir, help, clear, mc, id, w, pwd, man, etc. etc.\n" \
                  "En Windows+Cygwin: si quiere ejecutar una aplicación en una ventana separada haga lo siguiente:\n" \
                  "cmd /c start <programa.ejecutable>\n" \
                  "por ej.: cmd /c start mspaint\n" \
                  "\nAplicación creada por Octulio Biletán, 09-2022\n" \
                  "Sitio: https://misnubes.000webhostapp.com\n"
      print(msj_ayuda)
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
