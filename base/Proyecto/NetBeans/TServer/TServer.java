// TServer.java
// Eugenio Martínez - Abril de 2022
// Aplicación que escucha y responde peticiones por el puerto 337.
// Las ordenes aceptadas son: ?, hora y salir.
// Lado servidor.
// Sugerencias: usar una aplicación cliente en Android para consultar la hora del servidor.
// https://play.google.com/store/apps/details?id=jp.gr.java_conf.tcp_udp_testtool&hl=es_AR&gl=US

package tserver;

import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Calendar;
import java.util.Locale;

/**
 * Servidor de tiempo.
 * @author Eugenio Martínez
 */
public class TServer {
    /**
    * Constante que identifica el país Argentina, codificación dependiente del S.O.
    */
    public static final String ARGENTINA = "es-AR";
  
    /**
    * Constante que identifica el país Argentina, codificación UTF-8.
    */
    public static final String ARGENTINA_UTF8 = "es-AR.UTF-8";
  
    /**
    * Constante que identifica el país España, codificación dependiente del S.O.
    */
    public static final String ESPAÑA = "es-ES";
  
    /**
    * Constante que identifica el país España, codificación UTF-8.
    */
    public static final String ESPAÑA_UTF8 = "es-ES.UTF-8";

    TServer()
    {
        System.out.println("Iniciando servidor de tiempo...");
        System.out.println("Ordenes aceptadas: ?, hora y salir.");
    }

    /**
    * Establece la codificación regional elegida por el usuario. Por ejemplo <code>mpais = ARGENTINA</code>.
    * @param mpais El nombre del país.
    * @see java.util.Locale#forLanguageTag(String languageTag)
    */
    public static void miLocalidad(String mpais)
    {
      Locale.setDefault(Locale.forLanguageTag(mpais));
    }        
    
    // Salida remota -->> sr
    void comandoSalir(PrintWriter sr)
    {
        sr.println("\r\nOk.\n");
        sr.flush();

        // Hace sonar el timbre predeterminado del sistema
        Toolkit.getDefaultToolkit().beep();

        System.out.println("Tiempo de salida: " + Calendar.getInstance().getTime());
        System.out.println("Saliendo...");
        System.exit(0);
    }
    
    // Conector cliente -->> cc
    // Equipo cliente -->> equipo_cliente
    void comandoHora(Socket cc, PrintWriter equipo_cliente)
    {        
        InetAddress clienteIP;
                  
        // Responde al cliente con el tiempo actual
        equipo_cliente.println("Tiempo actual: " + Calendar.getInstance().getTime());
        equipo_cliente.flush();
 
        // Hace sonar un timbre por el altavoz de la PC servidor
        Toolkit.getDefaultToolkit().beep();
                
        // Obtiene la dir. de internet del equipo cliente
        clienteIP = cc.getInetAddress();
        
        // Informa en la pantalla del servidor los datos del equipo cliente que solicitó la hora
        System.out.println("<Hora>" + " desde: " + clienteIP.getHostAddress() + "<>" + "Nombre equipo: " + clienteIP.getHostName());
        System.out.flush();
    }
    
    // Equipo cliente -->> equipo_cliente
    void comandoAyuda(PrintWriter equipo_cliente)
    {
        equipo_cliente.println("<<Ayuda>>");
        equipo_cliente.println("Comandos aceptados:\r\n"
                + "hora --->> informa la hora actual del servidor\r\n"
                + "salir --->> termina la ejecución del servidor");
        equipo_cliente.flush();
 
        // Hace sonar un timbre por el altavoz de la PC servidor
        Toolkit.getDefaultToolkit().beep();

        System.out.println("Ayuda respondida.");
        System.out.flush();
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if(args.length != 1) 
        {
            System.err.println("Uso: java -jar TServer <puerto>");
            System.exit(1);
        }

        // Establece la zona horaria y los signos de puntuación típico del país.
        miLocalidad(ARGENTINA_UTF8);
	    
        int numPuerto = Integer.parseInt(args[0]);
        TServer servidor_tiempo = new TServer();
        
        try (
            ServerSocket conectorServidor = new ServerSocket(numPuerto);
            Socket conectorCliente = conectorServidor.accept();     
            PrintWriter salidaRemota = new PrintWriter(conectorCliente.getOutputStream(), true);                   
            BufferedReader entradaLocal = new BufferedReader(new InputStreamReader(conectorCliente.getInputStream()));
        ) 
        {
            InetAddress servidorIP;
            String entradaUsuario;
            
            servidorIP = conectorServidor.getInetAddress();
                    
            System.out.println("Tiempo inicial: " + Calendar.getInstance(Locale.ITALY).getTime());
            System.out.println("<Servidor> Dirección IP: " + servidorIP 
                    + "<>" 
                    + "Nº puerto: " + conectorServidor.getLocalPort()
                    + "<>" 
                    + "Nombre: " + servidorIP.getCanonicalHostName());
            System.out.flush();
            
            while((entradaUsuario = entradaLocal.readLine()) != null) 
            {
                salidaRemota.println(entradaUsuario);
                salidaRemota.flush();
                
                // Opción ayuda
                if(entradaUsuario.compareTo("?") == 0)
                {
                    servidor_tiempo.comandoAyuda(salidaRemota);
                }
                
                // Opción salir
                if(entradaUsuario.compareTo("salir") == 0) 
                {
                    servidor_tiempo.comandoSalir(salidaRemota);
                }
                
                // Opción hora
                if(entradaUsuario.compareTo("hora") == 0)
                {                    
                    servidor_tiempo.comandoHora(conectorCliente, salidaRemota);
                }
                
                System.out.println("Mensaje recibido-->> " + entradaUsuario + " [" + entradaUsuario.length() + "]");
                System.out.flush();
            }
            
            System.out.println("\n<<Actividad terminada>>");
            System.out.flush();
        } 
        catch(IOException e) 
        {
            System.err.println("AVISO: Excepción capturada cuando trataba de escuchar por el puerto " + numPuerto + " o porque estaba escuchando.");
            System.err.println(e.getMessage());
        }
        catch(NullPointerException e)
        {
            System.err.println("<ERROR>" + e.getMessage());
        }
    }
}
