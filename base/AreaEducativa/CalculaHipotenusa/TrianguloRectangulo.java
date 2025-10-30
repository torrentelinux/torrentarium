// TrianguloRectangulo.java

import java.util.Locale;
import java.util.Scanner;

/**
 *
 * @author Octulio Biletán
 */
class TrianguloRectangulo {

    double X;
    double Y;
    double H;

    public TrianguloRectangulo() {
        X = 0.0;
        Y = 0.0;
        H = 0.0;
    }

    // Dato a solicitar por teclado
    double solicitaCateto(String msj) {
        double cateto;

        // Crea el objeto Scanner para leer datos desde teclado
        Scanner teclado = new Scanner(System.in);

        System.out.print(msj + ": ");
        cateto = teclado.nextDouble();

        if (X == 0.0) {
            X = cateto;
        } else {
            if (Y == 0.0) {
                Y = cateto;
            }
        }

        return cateto;
    }

    // Calcula la hipotenusa utilizando la fórmula del Teorema de Pitágoras
    double hipotenusa(double cateto1, double cateto2) {
        X = cateto1;
        Y = cateto2;
        H = Math.sqrt(Math.pow(cateto1, 2) + Math.pow(cateto2, 2));
        return H;
    }

    // Muestra el resultado en la pantalla
    void muestraResultado(double diagonal) {
        System.out.printf(Locale.FRENCH, "La Hipotenusa es: %.2f\n", diagonal);
    }

    void titular(String msj) {
        System.out.print("\t<");
        System.out.print(msj);
        System.out.println(">\n");
    }

    void graficar() {
        System.out.println("\nRepresentación gráfica del triángulo rectángulo\n");

        System.out.println("^ ·");
        System.out.println("| | \\");
        System.out.println("| |  \\");
        System.out.println("Y |   \\  Hipotenusa");
        System.out.println("| |    \\");
        System.out.println("| |     \\");
        System.out.println("V ·------·");
        System.out.println("  <-- X -->");

        System.out.println("\nX=" + X);
        System.out.println("Y=" + Y);
        System.out.println("Hipotenusa=" + H);
    }
}
