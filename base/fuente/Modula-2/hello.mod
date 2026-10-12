(* Programa hello.mod en Modula-2 *)
(* Compilar en Linux: gm2 -g -flibs=m2pim,m2iso,m2cor hello.mod -o hello *)
(* Fecha: sábado, 10 de octubre de 2026 *)

MODULE hello;
FROM StrIO IMPORT WriteString, WriteLn;
FROM StdIO IMPORT Read;
FROM NumberIO IMPORT WriteInt;
FROM libHello IMPORT system; (* libHello.system() *)

VAR
   status: INTEGER; (* Almacena el código devuelto por system() *)
   ch: CHAR;
BEGIN
   status := system('clear');  (* Borra la pantalla totalmente *)

   WriteString('¡Hola mundo!'); WriteLn;
   WriteString('status='); WriteInt(status, 0);
   WriteLn;

   Read(ch)  (* Efectúa una pausa hasta que que se presione tecla Intro. *)
END hello.
