// EcoCliente.java
// Cliente eco que envía peticiones ingresadas por teclado y abre una conexión IP/equipo más el puerto nº 7.

/*
Referencias:
https://docs.oracle.com/javase/tutorial/networking/sockets/readingWriting.html
https://docs.oracle.com/javase/tutorial/displayCode.html?code=https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoClient.java
https://docs.oracle.com/javase/tutorial/displayCode.html?code=https://docs.oracle.com/javase/tutorial/networking/sockets/examples/EchoServer.java
https://datatracker.ietf.org/doc/html/rfc862
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

public class EcoCliente 
{
    public static void main(String[] args) throws IOException 
    {
            int numPuerto;
            String nombreEquipo;
        
        if (args.length != 2) 
        {
            System.err.println("Uso: java EcoCliente <equipo> <puerto>");
            System.out.println("Haciendo ajuste hacia 'localhost', puerto 7...");
            
            nombreEquipo = "localhost";
            numPuerto = 7;
        }
        else
        {
            nombreEquipo = args[0];
            numPuerto = Integer.parseInt(args[1]);
        }
        
        System.out.println("Iniciando cliente EcoBeep...");
        System.out.println("Ordenes: beep y exit.");
        System.out.println("Ingrese un texto cualquiera y presione [Intro]");
        System.out.println("Presione [Ctrl]+[C] para terminar la comunicación con el servidor.");
        
        try (
            Socket conectorEcho = new Socket(nombreEquipo, numPuerto);
            PrintWriter salidaRemota = new PrintWriter(conectorEcho.getOutputStream(), true);
            BufferedReader entradaRemota = new BufferedReader(new InputStreamReader(conectorEcho.getInputStream()));
            BufferedReader entradaLocal = new BufferedReader(new InputStreamReader(System.in))
        ) {
            String entradaUsuario;

            while ((entradaUsuario = entradaLocal.readLine()) != null) 
            {
                salidaRemota.println(entradaUsuario);
                salidaRemota.flush();
                
                System.out.println("echo: " + entradaRemota.readLine());
            }
        } 
        catch (UnknownHostException e) 
        {
            System.err.println("AVISO: Equipo no reconocido/identificado correctamente " + nombreEquipo);
            System.exit(1);
        } 
        catch (IOException e) 
        {
            System.err.println("AVISO: La conexión de E/S no se pudo establecer con " + nombreEquipo);
            System.err.println(e.getMessage());
            
            System.exit(1);
        } 
    }
}
