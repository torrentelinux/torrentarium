// EjemploParaWindows - Java/JNA
// Octulio Biletán - Abril de 2025.
// En este programa se expone cómo debería
// efectuarse las llamadas a funciones escritas en lenguaje 'C' que el S.O.
// posee para cualquier aplicación ejecutable.
// Para lograr todo esto en Java se recurre a la librería JNA.
// Referencias: https://en.wikipedia.org/wiki/Java_Native_Access
// ----------------------------------------------------------

package ejemploparawindows;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

/**
 * Clase Ejemplo para Windows que invoca a Java/JNA.<br>
 * @author Octulio Biletán
 * @version 1.0
 */
public class EjemploParaWindows
{
    /**
     * Clase Stdlib.<br>
     * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/c-run-time-library-reference?view=msvc-170
     */
    public interface Stdlib extends Library
    {
        public int putenv(String strvar);

        /**
         * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/putenv-wputenv?view=msvc-170
         * @param strvar
         * @return
         */
        public int _putenv(String strvar);

        /**
         * Consultar: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/system-wsystem?view=msvc-170
         * @param comando
         * @return
         */
        public int system(String comando);
    }

    /**
     * Clase Stdio.<br>
     * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/c-run-time-library-reference?view=msvc-170
     */
    public interface Stdio extends Library
    {
        /**
         * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l?view=msvc-170
         * @param format
         * @param args
         * @return
         */
        public int printf(String format, Object... args);

        /**
         * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/puts-putws?view=msvc-170
         * @param s
         * @return
         */
        public int puts(String s);

        /**
         * Consultar en: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/flushall?view=msvc-170
         * @return
         */
        public int _flushall();
    }

    /**
     * Conjunto de funciones de la librería <conio.h> del compilador Embarcadero C++ Builder.<br>
     * Consultar en: https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Conio.h_Index
     */
    public interface Conio extends Library
    {
        /**
         * Consultar en: https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Clrscr
         */
        public void clrscr();

        /**
         * Consultar en: https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Getch
         * @return
         */
        public int getch();
    }

    /**
     * Librería Embarcadero RAD Studio C++ RTL, ver. 11.3, Alexandria, Feb. 2023.<br>
     * Instale en Windows la librería 'cc64280.dll' y guarde la misma en el directorio c:\Windows\System32. <br>
     * Consultar en: https://docwiki.embarcadero.com/RADStudio/Alexandria/en/11_Alexandria_-_Release_3
     */
    public class Embarcadero
    {
        /**
         * Embarcadero RAD Studio C++ RTL, ver. 11.3, Alexandria, Feb. 2023.<br>
         * --> cc64280.dll <-- <br>
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
