// TServer.java
// Eugenio Martínez - Abril de 2022
// Aplicación que escucha y responde peticiones por el puerto TCP 337.
// Las órdenes aceptadas son: ?, hora, salir y fin.
// Lado servidor. Utiliza conexiones bloqueantes.
// Sugerencias: usar una aplicación cliente en Android para consultar la hora del servidor.
// https://play.google.com/store/apps/details?id=jp.gr.java_conf.tcp_udp_testtool&hl=es_AR&gl=US
// Referencias:
// https://www.delftstack.com/es/howto/java/how-to-get-the-current-date-time-in-java/
// https://examples.javacodegeeks.com/core-java/net/networkinterface/java-net-networkinterface-example/
// https://www.demo2s.com/java/java-creating-a-tcp-server-socket.html

package tserver;

import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Locale;
import java.util.logging.Level;
import java.util.logging.Logger;

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
        System.out.println("Ordenes aceptadas: ?, fin, hora y salir.");
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

    void listarAdaptadoresRedes() throws SocketException
    {
        // NetworkInterface implements a static method that returns all the interfaces on the PC,
        // which we add on a list in order to iterate over them.
        ArrayList<NetworkInterface> interfaces = Collections.list(NetworkInterface.getNetworkInterfaces());
                 
        System.out.println("\n< Tarjetas de redes activas >");

        for(NetworkInterface iface : interfaces) 
        {
            // Due to the amount of the interfaces, we will only print info
            // about the interfaces that are actually online.
            if(iface.isUp()) 
            {
                // Display name
                System.out.println("  * Nombre del dispositivo: " + iface.getDisplayName());
                         
                System.out.println("    [] Direcciones de la tarjeta de red: ");
            
                // Interface addresses of the network interface
                iface.getInterfaceAddresses().forEach(addr -> {
                    System.out.println("\t" + addr.getAddress().toString());
                });
                
                System.out.println();
            }
        } // fin de for()
    }

    // Conector cliente -->> cc
    // Salida remota -->> sr
    void comandoSalir(Socket cc, PrintWriter sr)
    {
        sr.println("\r\nOk.\n");
        sr.flush();

        // Hace sonar el timbre predeterminado del sistema
        Toolkit.getDefaultToolkit().beep();

        System.out.println("Tiempo de salida: " + Calendar.getInstance().getTime());
        System.out.println("Saliendo cliente...");
        
        // Cierra la conexión con el cliente
        try {
            sr.close();
            cc.close();
        } catch (IOException ex) {
            Logger.getLogger(TServer.class.getName()).log(Level.SEVERE, null, ex);
        }
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
        equipo_cliente.println("<<Ayuda>>\r\n"
                + "Comandos aceptados:\r\n"
                + "fin ----->> finaliza la comunicación el servidor\r\n"
                + "hora ---->> informa la hora actual del servidor\r\n"
                + "salir --->> cierra la conexión con el cliente"
                );
        equipo_cliente.flush();
 
        // Hace sonar un timbre por el altavoz de la PC servidor
        Toolkit.getDefaultToolkit().beep();

        System.out.println("Ayuda respondida.");
        System.out.flush();
    }

    /**
     * @param args Los argumentos que vienen de la línea de comandos.
     */
    public static void main(String[] args) 
    {
        System.out.println("Servidor de tiempo");
    
        if(args.length != 1) 
        {
            System.err.println("Uso: java -jar TServer <puerto>");
            System.exit(1);
        }

        // Establece la zona horaria y los signos de puntuación típico del país.
        miLocalidad(ARGENTINA_UTF8);

        int numPuerto = Integer.parseInt(args[0]);
        TServer servidor_tiempo = new TServer();
        Socket conectorEstado = null;

        try 
        {
            // Muestra la lista de tarjetas de redes que posee la computadora
            servidor_tiempo.listarAdaptadoresRedes();
            
        } 
        catch(SocketException ex) 
        {
            Logger.getLogger(TServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(true)
        {
            
            try(
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

                // Espera comando...
                while((entradaUsuario = entradaLocal.readLine()) != null)
                {
                    // ---Hace echo hacia el usuario conectado
                    salidaRemota.println(entradaUsuario);
                    salidaRemota.flush();
                    // ---
                    
                    // Opción ayuda
                    if(entradaUsuario.compareTo("?") == 0)
                    {
                        servidor_tiempo.comandoAyuda(salidaRemota);
                    }
                    
                    // Opción fin
                    if(entradaUsuario.compareTo("fin") == 0)
                    {
                        System.out.println("Fin.");
                        System.out.flush();
                        System.exit(0);
                    }
                
                    // Opción salir
                    if(entradaUsuario.compareTo("salir") == 0) 
                    {
                        servidor_tiempo.comandoSalir(conectorCliente, salidaRemota);
                        conectorEstado = conectorCliente;
                    }
                
                    // Opción hora
                    if(entradaUsuario.compareTo("hora") == 0)
                    {
                        servidor_tiempo.comandoHora(conectorCliente, salidaRemota);
                        conectorEstado = conectorCliente;
                    }

                    if(entradaUsuario.length() == 0)
                    {
                      System.out.println("El servidor le sugiere al cliente solicitar ayuda.");
                      System.out.flush();
                      
                      salidaRemota.println("Envíe comando ayuda: ?");
                      salidaRemota.flush();
                    }
                    else
                    {
                        System.out.println("Mensaje recibido-->> " + entradaUsuario + " [" + entradaUsuario.length() + "]");
                        System.out.flush();
                    }
                }  // Fin while() - comandos -
            
                System.out.println("\n<<Actividad terminada>>");
                System.out.flush();
            }
            catch(IOException e) 
            {
                if(conectorEstado.isClosed())
                    System.out.println("Conexión cerrada con el cliente.");
                else
                {    
                    System.err.println("AVISO: Excepción capturada cuando trataba de escuchar por el puerto " + numPuerto + " o porque estaba escuchando.");
                    System.err.println(e.getMessage());
                }
            }
            catch(NullPointerException e)
            {
                System.err.println("<ERROR>" + e.getMessage());
            }
            
        }  // Fin while()
    }  // Fin de main()
}
