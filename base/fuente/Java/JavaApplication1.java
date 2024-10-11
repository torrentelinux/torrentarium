// Ciclo infinito

package javaapplication1;

/**
 *
 * @author euxeniu
 */
public class JavaApplication1 
{
        static boolean cycle;
     
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        do 
        {
            print("ciclando...");
        } while(repeat(cycle));
    }
    
    private static void print(String ciclando) 
    {
        System.out.println(ciclando);
    }

    private static boolean repeat(boolean continuar) 
    {
        return (continuar = !continuar);
    }
}
