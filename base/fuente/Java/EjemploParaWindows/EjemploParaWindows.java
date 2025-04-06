// EjemploParaWindows - Java/JNA
// Octulio Biletán - Abril de 2025.
// Referencias: https://en.wikipedia.org/wiki/Java_Native_Access
//

package ejemploparawindows;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

/**
 * Clase Ejemplo para Windows que invoca a Java/JNA.
 * @author Octulio Biletán
 */
public class EjemploParaWindows
{
    /**
     * Clase Stdlib.
     */
    public interface Stdlib extends Library
    {
        public int putenv(String strvar);
        public int _putenv(String strvar);
        public int system(String comando);
    }

    /**
     * Clase Stdio.
     */
    public interface Stdio extends Library
    {
        public int printf(String format, Object... args);
        public int puts(String s);
        public int _flushall();
    }

    /**
     * Conjunto de funciones de la librería <conio.h> del compilador Embarcadero C++ Builder.
     */
    public interface Conio extends Library
    {
        public void clrscr();
        public int getch();
    }

    /**
     * Librería Embarcadero RAD Studio C++ RTL, ver. 11.3, Alexandria, Feb. 2023.
     */
    public class Embarcadero
    {
        /**
         * Embarcadero RAD Studio C++ RTL, ver. 11.3, Alexandria, Feb. 2023.<br>
         * --> cc64280.dll <-- <br>
         * https://docwiki.embarcadero.com/RADStudio/Alexandria/en/11_Alexandria_-_Release_3
         *
         */
        public static final String CC64_LIBRARY_NAME = "cc64280";
    }

    /**
     * @param args Argumentos.
     */
    public static void main(String[] args)
    {
        String []nombreSO = {"Mac", "Linux", "Windows", "Solaris", "Otro", "¿?"};
        @SuppressWarnings("UnusedAssignment")
        Stdlib stdlib = null;
        @SuppressWarnings("UnusedAssignment")
        Stdio stdio = null;
        @SuppressWarnings("UnusedAssignment")
        Conio conio = null;

        try
        {
            // Se vincula en tiempo de ejecución con la librería de 'C' del S.O. anfitrión
            stdlib = (Stdlib)Native.load(Platform.C_LIBRARY_NAME, Stdlib.class);
            stdio = (Stdio)Native.load(Platform.C_LIBRARY_NAME, Stdio.class);

            // Y esta con la librería de Embarcadero RAD Studio
            conio = (Conio)Native.load(Embarcadero.CC64_LIBRARY_NAME, Conio.class);
        }
        catch(UnsatisfiedLinkError lnkError)
        {
            System.err.println("[Error] " + lnkError.getMessage());
            System.exit(1);
        }

        // Borra la pantalla
        conio.clrscr();

        Native.main(args);
        System.out.println("Codificación: " + Native.getDefaultStringEncoding());
        System.out.println("Tipo de S.O.: "+ nombreSO[ Platform.getOSType() ] + "," + Platform.ARCH);
        System.out.println("Nombre de la librería 'C': " + Platform.C_LIBRARY_NAME);
        System.out.println("Nombre de la librería matemática: " + Platform.MATH_LIBRARY_NAME);
        System.out.println("Nombre de la librería Embarcadero RAD Studio: " + Embarcadero.CC64_LIBRARY_NAME);
        System.out.println("Prefijo del S.O.: " + Platform.RESOURCE_PREFIX);

        stdio.puts("____________________");
        stdio._flushall();

        stdio.printf("Ejemplo de llamadas %s en Java.\n", nombreSO[ Platform.getOSType() ]);
        stdio._flushall();

        // Define una variable de entorno
        System.out.println("putenv: " + stdlib._putenv("Navegador=1"));

        // Examina la var. de entorno desde la shell del S.O.
        System.out.println("system: " + stdlib.system("set|find \"Navegador\""));

        stdio.printf("Navegador: %s\n", System.getenv("Navegador"));
        stdio._flushall();

        stdio.puts("Presione una tecla cualquiera para terminar...");
        stdio._flushall();

        conio.getch();
    }
}
