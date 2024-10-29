// Mesas_y_sillas.java
// Versión 2.0

package mesas_y_sillas;

// https://fusesource.github.io/jansi/

import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;
import org.fusesource.jansi.*;
import static org.fusesource.jansi.Ansi.ansi;

/* Para la E/S de archivos
import java.io.FileReader;
import java.io.FileWriter;
*/

/**
 *
 * @author operador
 */
public class Mesas_y_sillas {
    public String []silla;
    public String [][]mesa;

    public int mesaFilas;
    public int mesaCols;

    public Mesas_y_sillas()
    {
        mesaFilas = 3;
        mesaCols = 10;

        silla = new String[mesaCols];              // vector para 10 elementos
        mesa = new String[mesaFilas][mesaCols];    // matriz 3 x 10 elementos
    }

    public Mesas_y_sillas(int nsillas)
    {
        mesaFilas = 3;
        mesaCols = nsillas;

        silla = new String[nsillas];
        mesa = new String[mesaFilas][mesaCols];

        for(int i = 0; i < mesaFilas; i++)
          for(int j = 0; j < mesaCols; j++)
            mesa[i][j] = "v";  // indicador de vacio
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
            int cantidad_sillas;
            PrintStream consola = System.out;
            InputStream entrada = System.in;
            Scanner teclado = new Scanner(entrada);
            Mesas_y_sillas mesa1;

        AnsiConsole.systemInstall();

        // Borra toda la pantalla
        AnsiConsole.out().print(ansi().eraseScreen().cursor(1, 1));

        // Pone color verde intenso al texto
        AnsiConsole.out().println(ansi().fgBrightGreen().a("Mesas y sillas - ejercicio -"));
        AnsiConsole.out().print(ansi().fgDefault());

        // Pregunta por la cantidad de sillas que acompaña a la mesa
        consola.print("¿Cuántas sillas? (entre 1 y 10)> ");
        cantidad_sillas = Integer.parseInt(teclado.nextLine());

        if(cantidad_sillas < 1 || cantidad_sillas > 10)
        {
          cantidad_sillas = 10;
          AnsiConsole.out().println(ansi().fgBrightRed().a("Error: cantidad incorrecta, reajustado a ").a(cantidad_sillas));
          AnsiConsole.out().print(ansi().fgDefault());
        }

        mesa1 = new Mesas_y_sillas(cantidad_sillas);

        // Lee desde teclado los nombres de cada participante
        for(int n = 0; n < cantidad_sillas; n++)
        {
          consola.print("Nombre del participante(" + n + "): ");
          mesa1.silla[n] = teclado.nextLine();
        }

        // Carga la 1º fila de la matriz 'mesa' con el vector 'silla'
        for(int i = 0; i < mesa1.silla.length; i++)
          mesa1.mesa[0][i] = mesa1.silla[i];

        consola.println();
        consola.printf("Capacidad máxima de mesa[][]: %d\n", (mesa1.mesa.length * mesa1.mesa[0].length));
        consola.printf("Capacidad máxima de sillas[]: %d\n", mesa1.silla.length);

        // Pone color verde intenso al texto
        AnsiConsole.out().println(ansi().fgBrightGreen().a("Contenido de la mesa 1"));
        AnsiConsole.out().print(ansi().fgDefault());

        for(int i = 0; i < mesa1.mesaFilas; i++)
        {
          for(int j = 0; j < mesa1.mesaCols; j++)
            consola.print(mesa1.mesa[i][j] + " ");

          consola.println();
        }

        AnsiConsole.systemUninstall();
    }
}
