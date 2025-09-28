// Proyecto: jLogo
// Paquete : Ejemplo01
// Programa: Ejemplo1.java
// Ambiente: Linux, modo consola.

package Ejemplo01;

import jlogo.JLogo;

/**
 *
 * @author Octulio Biletán, Septiembre de 2025.
 */
public class Ejemplo1 {

    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {

        int pasos = 10;
        JLogo tortuga = new JLogo();

        tortuga.borrapantalla();
        tortuga.producto();
        tortuga.mostrar();
        tortuga.detente(2);	// Se detiene por 2 segundos

        tortuga.avance(pasos);	// Se desplaza hacia arriba
        tortuga.mostrar();
        tortuga.detente(2);

        tortuga.derecha();	// Se desplaza hacia la derecha
        tortuga.mostrar();
        tortuga.detente(2);

        tortuga.avance(pasos);
        tortuga.mostrar();
        tortuga.detente(2);

        tortuga.bajar();	// Se desplaza hacia abajo
        tortuga.mostrar();
        tortuga.detente(2);

        tortuga.avance(pasos);
        tortuga.mostrar();
        tortuga.detente(1);

        tortuga.izquierda();	// Se desplaza hacia la izquierda
        tortuga.mostrar();
        tortuga.detente(1);

        tortuga.avance(pasos);
        tortuga.mostrar();
        tortuga.detente(1);

        tortuga.subir();	// Se prepara para subir
        tortuga.mostrar_esquinas();
        tortuga.mostrar();
        tortuga.detente(2);

        tortuga.esconder();
        tortuga.esconder_esquinas();
        tortuga.mostrar();
        tortuga.detente(-499);
    }
}
