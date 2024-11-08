// rdp.java
// diagrama de flujo: resolución de problemas.
// resolución 'inteligente' de los problemas.
// programación divertida en la consola de windows.
// codificador: edmund muslok (em).
// referencias...
// https://github.com/torrentelinux/torrentarium/blob/master/base/fuente/CPP/rdp.cpp

package rdp;

import java.io.PrintStream;
import javax.swing.JOptionPane;

/**
 * @author Edmund Muslok
 */
public class Rdp 
{
    private enum rsp { NO, SI };
    private rsp rsp1;
    
    public Rdp() 
    {
        // <sin código>
    }
    
    public rsp pregunta(String msj)
    {
        int responde;
        
        msj = msj.replace('¿', ' ');
        msj = msj.replace('?', ' ');
        
        String texto = "¿" + msj + "?";

        responde = JOptionPane.showConfirmDialog(null, texto, "Rdp", JOptionPane.YES_NO_OPTION);
        if(responde == 0)
            rsp1 = rsp.SI;
        else
            rsp1 = rsp.NO;
        
        return rsp1;
    }

    public void mostrarMensaje(String msj)
    {
        JOptionPane.showMessageDialog(null, msj, "Rdp", JOptionPane.OK_OPTION|JOptionPane.INFORMATION_MESSAGE);
    }
    
    /**
     * @param args argumentos de entrada.
     */
    public static void main(String[] args) 
    {
        boolean pase = false;
        rsp responde;
        PrintStream pantalla = System.out;
        Rdp problema = new Rdp();
        
        pantalla.println("Programa rdp.jar");
        pantalla.println("Resolución de problemas.\n");

        responde = problema.pregunta("Funciona la porquería");
        pantalla.println(responde);
        
        if(responde == rsp.SI)
            problema.mostrarMensaje("No ¡ jodas !");
        else
        {
            responde = problema.pregunta("Trataste de arreglarlo");
            pantalla.println(responde);
            
            // 1º ciclo
            while(true)
            {    
                if(responde == rsp.SI)
                {
                    if(pase == false)
                    {    
                        responde = problema.pregunta("Lo sabe alguien más");
                        pantalla.println(responde);
                    }
                    
                    // para salir del quilombo tenés que culpar a alguien...
                    if(responde == rsp.SI)
                    {
                        // 2º ciclo
                        while(true)
                        {    
                            problema.mostrarMensaje("¡ Cagaste !");
                    
                            responde = problema.pregunta("Podés culpar a otro");
                            pantalla.println(responde);
                    
                            if(responde == rsp.SI)
                                break;  // sale del 2º ciclo
                    
                        }  // fin while()
                        
                        break;  // sale del 1º ciclo
                    }
                    else
                    {
                        problema.mostrarMensaje("Hacete el boludo...");
                        break;  // sale del 1º ciclo
                    }
                }
                else
                {
                    responde = problema.pregunta("Te pueden cagar a pedos");
                    pantalla.println(responde);
                
                    if(responde == rsp.SI)
                    {
                        pase = true;
                    }
                    else
                    {
                        problema.mostrarMensaje("Tiralo a la mierda...");
                        break;  // sale del 1º ciclo
                    }
                }
            }  // fin while()
        }
        
        problema.mostrarMensaje("*** Problema resuelto ***");
    }
}
