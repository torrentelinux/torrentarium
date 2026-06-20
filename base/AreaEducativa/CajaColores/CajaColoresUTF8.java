/*
    Programa : CajaColoresUTF8.java
    Autor    : Octulio Biletán · Junio de 2026.
    Propósito: Dibuja un marco con líneas dobles amarillas en la ventana de comandos/Windows.
	       Utiliza caracteres UTF-8.
    Compilar: javac CajaColoresUTF8.java
    Ejecutar: chcp 65001   (cambio de codificación a UTF-8)
    Ejecutar: java -cp . CajaColoresUTF8
    Construye: jar -cvfe CajaColoresUTF8.jar CajaColoresUTF8 CajaColoresUTF8.class
    Ejecutar: java -jar CajaColoresUTF8.jar

    Consulta efectuada en microsoft copilot:
    'en java, cómo se puede "dibujar" un área rectangular en cmd con líneas horizontales, verticales y las esquinas?'
    https://copilot.microsoft.com/shares/K6G7uWDxToqTHuKahq26E

    Licencia: Software Libre.
*/

/**
 * Clase principal del programa <code>CajaColoresUTF8.java</code>.
 * @author Euxeniu Martínez
 * @version 1.6.2026
 */
public class CajaColoresUTF8
{

    /**
     * Entrada principal al programa <code>CajaColoresUTF8</code>.
     * @param args Sin uso.
     * @throws Exception Lanza una excepción en caso de encontrar algún error en tiempo de ejecución.
     */
    public static void main(String[] args) throws Exception
    {
        // Configura la salida estándar en UTF-8
        System.setOut(new java.io.PrintStream(System.out, true, "UTF-8"));
        System.out.println("Codificación de caracteres activa: " + System.out.charset().displayName());
        System.out.println();
        
        // Ancho del marco
        int ancho = 24;

        // Altura del marco
        int alto = 12;

        // Códigos de escape ANSI para poner colores a los caracteres
        final String AMARILLO = "\u001B[33m";
        final String AZUL = "\u001B[34m";
        final String RESET = "\u001B[0m";

        for (int fila = 0; fila < alto; fila++)
        {
            for (int col = 0; col < ancho; col++)
            {
                if (fila == 0 && col == 0)
                {
                    // Pone la esquina sup. izq.
                    System.out.print(AMARILLO + "╔" + RESET);
                }
                else
                  if (fila == 0 && col == ancho - 1)
                  {
                    // Pone la esquina sup. der.
                    System.out.print(AMARILLO + "╗" + RESET);
                  }
                  else
                    if (fila == alto - 1 && col == 0)
                    {
                      // Pone la esquina inf. izq.
                      System.out.print(AMARILLO + "╚" + RESET);
                    }
                    else
                      if (fila == alto - 1 && col == ancho - 1)
                      {
                        // Pone la esquina inf. der.
                        System.out.print(AMARILLO + "╝" + RESET);
                      }
                      else
                        if (fila == 0 || fila == alto - 1)
                        {
                          // Pone una doble linea horiz.
                          System.out.print(AMARILLO + "═" + RESET);
                        }
                        else
                          if (col == 0 || col == ancho - 1)
                          {
                            // Pone una doble línea vert.
                            System.out.print(AMARILLO + "║" + RESET);
                          }
                          else
                          {
                            // Pone en el interior un patrón azul
                            System.out.print(AZUL + "▒" + RESET);
                          }
            }  // fin for()
            System.out.println();
        }  // fin for()
    }
}
