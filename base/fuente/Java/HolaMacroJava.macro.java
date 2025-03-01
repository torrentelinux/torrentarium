// Programa: HolaMacroJava.macro.java
// Autor: Octulio Biletán * Marzo de 2025
// Descripción: Uso de macros en el lenguaje Java.
// Referencias: consultar y leer en este enlace
// 	https://stackoverflow.com/questions/6525059/can-i-have-macros-in-java-source-files
// Observac.: cpp es el preprocesador de macros para el lenguaje C/C++.
//            consultar man cpp y cpp --help
// Comandos a ejecutar desde la línea de órdenes:
//	cpp -P HolaMacroJava.macro.java HolaMacroJava.java
//	javac HolaMacroJava.java
//	java HolaMacroJava
//	jar --create --main-class=HolaMacroJava --file HolaMacroJava.jar HolaMacroJava.class
//	java -jar HolaMacroJava.jar
//

#define APLICACION	"Aplicación HolaMacroJava, "
#define VERSION		"Ver. 1.03.2025"
#define SALUDOS		"Hola a todos desde Java..."
#define puts		System.out.println

class HolaMacroJava
{
	public static void main(String args[])
	{
		puts(APLICACION+VERSION);
		puts(SALUDOS);
	}
}
