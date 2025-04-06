// EjemploParaLinux - Java/JNA
// Referencias: https://en.wikipedia.org/wiki/Java_Native_Access
//

package ejemploparalinux;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

/**
 * Ejemplo de llamadas al S.O. desde Linux mediante Java/JNA.
 * @author Octulio Biletán
 */
public class EjemploParaLinux
{
    /**
     * Clase Stdlib.<br>
     * Consultar 'man 0p stdlib'.
     */
    public interface Stdlib extends Library
    {
        /**
         * Consultar 'man 3p putenv'.
         * @param strvar
         * @return
         */
        public int putenv(String strvar);
            
        /**
         * Consultar 'man 3p system'.
         * @param comando
         * @return
         */
        public int system(String comando);
    }

    /**
     * @param args Argumentos.
     */
    public static void main(String[] args)
    {
        String []nombreSO = {"Mac","Linux","Windows","Solaris","Otro","¿?"};
        Stdlib oslinux;

        // Se vincula en tiempo de ejecución con la librería de 'C' del S.O. Linux
        oslinux = (Stdlib)Native.load(Platform.C_LIBRARY_NAME, Stdlib.class);

        // Suena un bip en el parlante de la PC, borra la pantalla y coloca el
        // cursor en la posición 1,1 de la pantalla.
        System.out.print("\007\033[2J\033[H");

        Native.main(args);
        System.out.println("Codificación: " + Native.getDefaultStringEncoding());
        System.out.println("Tipo de S.O.: "+ nombreSO[ Platform.getOSType() ] + "," + Platform.ARCH);
        System.out.println("Nombre de la librería 'C': " + Platform.C_LIBRARY_NAME);
        System.out.println("Nombre de la librería matemática: " + Platform.MATH_LIBRARY_NAME);
        System.out.println("Prefijo del S.O.: " + Platform.RESOURCE_PREFIX);
        System.out.println("___________________");

        System.out.println("Ejemplo de llamadas " + nombreSO[ Platform.getOSType() ] + " en Java.");

        // Define una variable de entorno
        System.out.println("Define la var. de entorno 'Navegador'");
        System.out.println("putenv: " + (oslinux.putenv("Navegador=1") == 0 ? "Ok" : "Error" ) );

        // Examina la var. de entorno desde la shell del S.O.
        System.out.println("system: " + (oslinux.system("export|grep Navegador") == 0 ? "Ok" : "Error") );
        System.out.println("Tarea concluida.");
    }
}
