// EcoServidor.java
// Servidor eco que escucha y responde peticiones por el puerto nº 7.

/*
Referencias:
https://docs.oracle.com/javase/tutorial/networking/sockets/readingWriting.html
https://docs.oracle.com/javase/tutorial/displayCode.html?code=https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoClient.java
https://docs.oracle.com/javase/tutorial/displayCode.html?code=https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoServer.java
https://datatracker.ietf.org/doc/html/rfc862
*/

import java.awt.Toolkit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.ServerSocket;
import java.net.Socket;

import java.util.Calendar;

public class EcoServidor 
{
    public static void main(String[] args) throws IOException 
    {
        if (args.length != 1) 
        {
            System.err.println("Uso: java EcoServidor <puerto>");
            System.exit(1);
        }
	    
        int numPuerto = Integer.parseInt(args[0]);
        
        System.out.println("Iniciando servidor EcoBeep...");
        System.out.println("Ordenes aceptadas: beep y exit.");
        
        try (
            ServerSocket conectorServidor = new ServerSocket(numPuerto);
            Socket conectorCliente = conectorServidor.accept();     
            PrintWriter salidaRemota = new PrintWriter(conectorCliente.getOutputStream(), true);                   
            BufferedReader entradaLocal = new BufferedReader(new InputStreamReader(conectorCliente.getInputStream()));
        ) 
        {
            String entradaUsuario;

            System.out.println("Tiempo: " + Calendar.getInstance().getTime());
            System.out.println("Dirección: " + conectorServidor.getLocalSocketAddress());
            
            while ((entradaUsuario = entradaLocal.readLine()) != null) 
            {
                salidaRemota.println(entradaUsuario);
                salidaRemota.flush();
                
                if(entradaUsuario.compareTo("exit") == 0) 
                {
                    salidaRemota.println("\nOk.\n");
                    salidaRemota.flush();

                    System.out.println("Tiempo: " + Calendar.getInstance().getTime());
                    System.out.println("\nSaliendo...");
                    System.exit(0);
                }
                
                if(entradaUsuario.compareTo("beep") == 0)
                {                    
                  System.out.print("\u0007");
                  System.out.flush();
                  
                  Toolkit.getDefaultToolkit().beep();
                  System.out.println("Timbre");
                }
            }
        } 
        catch (IOException e) 
        {
            System.out.println("AVISO: Excepción capturada cuando trataba de escuchar por el puerto " + numPuerto + " o porque estaba escuchando.");
            System.out.println(e.getMessage());
        }
    }
}
