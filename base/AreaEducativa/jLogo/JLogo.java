// Proyecto: jLogo
// Paquete : jlogo
// Librería: JLogo.java
// Versión : 1.0
// Ambiente: Linux, modo consola.

/*
  Movimientos de la tortuga sobre la pantalla de textos
			      subir (norte)
				^
				|
				|
izquierda (oeste)---------------*---------------derecha (este)
				|
				|
				v
			      bajar (sur)
 */
package jlogo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
    A implementar:
        bordes(mostrar)
	bordes(esconder)
        trazador(arriba) ---> sube el lápiz
        trazador(abajo)  ---> baja el lápiz
*/
/**
 *
 * @author Octulio Biletán, Septiembre de 2025.
 */
public class JLogo {

    int columnas;   // eje Y
    int lineas;     // eje X
    int col_actual;
    int linea_actual;
    String direccion;		// norte, sur, este, oeste
    private final String tortuga_version;
    private final String tortuga_fproduc;
    private char tortuga_figura;
    private final char tortuga_traza;
    private final char piso_figura;
    private final char _pantalla[][];

    public JLogo() {
        columnas = 123;     // 80, 124, 123
        lineas = 33;        // 25, 36, 34
        col_actual = 0;
        linea_actual = 0;
	tortuga_version = "1.0";
	tortuga_fproduc = "28-09-2025";
        _pantalla = new char[lineas][columnas];
        tortuga_figura = 'ᐃ';  // es la apariencia visual que tiene la tortuga
        tortuga_traza = '·';   // es la traza que deja la tortuga cuando avanza
        piso_figura = ' ';     // es la superficie de escritura/dibujo

        limpiar();
        direccion = "norte";    // Se desplazará hacia arriba

        col_actual = (columnas / 2) - 1;
        linea_actual = (lineas / 2) - 1;
        _pantalla[linea_actual][col_actual] = tortuga_figura;  // Coloca la tortuga en el centro de la pantalla
    }

    public void borrapantalla() {
        System.out.print("\033[2J\033[1;1f");
    }

    public void esconder() {
        _pantalla[linea_actual][col_actual] = tortuga_traza;
    }

    public void detente(int lapso) throws InterruptedException {
        if (lapso == 0) {
            return;
        }

        if (lapso > 0) {
            Thread.sleep(lapso * 1000);  // convierte a milisegundos
        } else {
            lapso = lapso * (-1);  // convierte a valor positivo el lapso de tiempo
            Thread.sleep(lapso);
        }
    }

    private void limpiar() {
        for (int x = 0; x < lineas; x++) {
            for (int y = 0; y < columnas; y++) {
                _pantalla[x][y] = piso_figura;
            }
        }
    }

    public void mostrar() {
        for (int x = 0; x < lineas; x++) {
            for (int y = 0; y < columnas; y++) {
                System.out.print(_pantalla[x][y]);
            }

            System.out.println();
        }
    }

    public void mostrar_esquinas() {
        _pantalla[0][0] = '·';
        _pantalla[0][columnas - 1] = '·';
        _pantalla[lineas - 1][0] = '·';
        _pantalla[lineas - 1][columnas - 1] = '·';
    }

    public void esconder_esquinas() {
        _pantalla[0][0] = piso_figura;
        _pantalla[0][columnas - 1] = piso_figura;
        _pantalla[lineas - 1][0] = piso_figura;
        _pantalla[lineas - 1][columnas - 1] = piso_figura;
    }

    public void avance(int pasos) {
        switch (direccion) {
            // Se desplaza hacia arriba
            case "norte" -> {
                int sube = linea_actual - 1;
                int ln = 0;     // nro de línea

                _pantalla[linea_actual][col_actual] = tortuga_traza;

                while (ln < pasos) {
                    _pantalla[sube][col_actual] = tortuga_traza;
                    sube--;
                    ln++;
                }

                linea_actual = sube;
                _pantalla[linea_actual][col_actual] = tortuga_figura;
            }

            // Se desplaza hacia abajo
            case "sur" -> {
                int baja = linea_actual + 1;
                int ln = 0;     // nro de línea

                _pantalla[linea_actual][col_actual] = tortuga_traza;
                while (ln < pasos) {
                    _pantalla[baja][col_actual] = tortuga_traza;
                    baja++;
                    ln++;
                }

                linea_actual = baja;
                _pantalla[linea_actual][col_actual] = tortuga_figura;
            }

            // Se desplaza hacia la derecha
            case "este" -> {
                int desplazaX = col_actual + 1;
                int cn = 0;     // nro de columna

                _pantalla[linea_actual][col_actual] = tortuga_traza;
                while (cn < pasos) {
                    _pantalla[linea_actual][desplazaX] = tortuga_traza;
                    desplazaX++;
                    cn++;
                }

                col_actual = desplazaX;
                _pantalla[linea_actual][col_actual] = tortuga_figura;
            }

            // Se desplaza por el eje X hacia la izquierda
            case "oeste" -> {
                int desplazaXizq = col_actual - 1;
                int cn = 0;     // nro de columna

                _pantalla[linea_actual][col_actual] = tortuga_traza;
                while (cn < pasos) {
                    _pantalla[linea_actual][desplazaXizq] = tortuga_traza;
                    desplazaXizq--;
                    cn++;
                }

                col_actual = desplazaXizq;
                _pantalla[linea_actual][col_actual] = tortuga_figura;
            }

            default ->
                throw new AssertionError();
        }
    }

    public void derecha() {
        direccion = "este";
        tortuga_figura = 'ᐅ';
        _pantalla[linea_actual][col_actual] = tortuga_figura;
    }

    public void izquierda() {
        direccion = "oeste";
        tortuga_figura = 'ᐊ';
        _pantalla[linea_actual][col_actual] = tortuga_figura;
    }

    public void subir() {
        direccion = "norte";
        tortuga_figura = 'ᐃ';
        _pantalla[linea_actual][col_actual] = tortuga_figura;
    }

    public void bajar() {
        direccion = "sur";
        tortuga_figura = 'ᐁ';
        _pantalla[linea_actual][col_actual] = tortuga_figura;
    }

    // En desarrollo, falta completar.
    // Valores admitidos para 'grd':
    // 0º, 90º, 180º, 270º, 360º
    private void girar(int grd) {
        switch (grd) {
            case 0 ->
                direccion = "este";
            case 90 ->
                direccion = "norte";
            case 180 ->
                direccion = "oeste";
            case 270 ->
                direccion = "sur";
            case 360 ->
                direccion = "este";
            default ->
                throw new AssertionError();
        }
    }

    public void producto() {
        String texto = "Librería jLogo, versión " + tortuga_version + " " + tortuga_fproduc;
        char resultado[] = texto.toCharArray();

        for (int i = 0; i < resultado.length; i++) {
            _pantalla[1][i + 1] = resultado[i];
        }
    }

    public static class tecla {

        static int teclado;

        public tecla() {
            teclado = 0;
        }

        public static void lee() {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

            try {
                teclado = reader.read();

            } catch (IOException ex) {
                Logger.getLogger(JLogo.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JLogo tortuga = new JLogo();

        tortuga.borrapantalla();
        tortuga.mostrar();
        JLogo.tecla.lee();
    }
}
