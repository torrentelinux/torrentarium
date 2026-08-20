// ValidaCorreo.java --- Octulio Biletán --- Marzo de 2020.
// Valida una dirección de correo electrónico que tiene la forma:
// caso 1: <caracteres>@<caracteres>.<caracteres>
// Es decir si está correctamente escrito.
// Correcto: lala@lala.com
// Incorrecto: lalalalacom ; lala@lala.com1
// -------------
// Alternativa 1: Pattern.compile("([a-z0-9]+(\\.?[a-z0-9])*)+@(([a-z]+)\\.([a-z]+))+");
// Alternativa 2: Pattern composicion = Pattern.compile("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");
// ------------
// Ejecutar: java ValidaCorreo.java
// Referencias: Consulta en: https://lagrowthmachine.com/es/que-es-una-direccion-de-correo-electronico-valida-reglas-formato-explicadas/
// Actualizado: Agosto de 2026.
// ------------

// Variante: validacorreo
package ValidaCorreo;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ValidaCorreo
{
    public static void main(String[] args)
    {
        boolean ayuda = false;
        boolean sugerencia = false;
        String texto;
        Pattern composicion = Pattern.compile("^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$");

        IO.println("'ValidaCorreo.java' valida la dirección de correo electrónico.\n");
        if(args.length > 0)
        {
            texto = args[0];
            if(texto.indexOf('@') > 65)
            {
                IO.println("ERROR: el nombre de la cuenta del correo electrónico supera los 64 caracteres permitidos.");
                sugerencia = true;
            }

            if(texto.length() > 320)
            {
                IO.println("ERROR: la longitud del texto a validar supera los 320 caracteres permitidos.");
                sugerencia = true;
            }

            if(sugerencia)
            {
                IO.println("Longitud del texto ingresado: " + texto.length());
                IO.println("El formato debe ser:");
                IO.println("\t- 64 caracteres@255 caracteres");
                IO.println("No se admiten las vocales acentuadas y ñ/Ñ.");
                IO.println("Formas admitidas:");
                IO.println("\t- servicios@empresa.com");
                IO.println("\t- servicios@192.168.1.1");
                System.exit(1);
            }
        }
        else
        {
            // La dirección de correo electrónico a validar.
            texto = "consultas@google.com";
            ayuda = true;
        }

        // Examina el contenido de 'texto'
        Matcher validador = composicion.matcher(texto);

        // Muestra 'sí' si e-mail está correctamente escrito sino 'no'
        IO.println("Correo electrónico validado: " + texto);
        IO.println("¿Es válido?: " + (validador.find() == true ? "sí" : "no"));

        if (ayuda)
        {
            String textoAyuda = """
                                Ayuda
                                Puede agregar su correo electr\u00f3nico que quiere validar, por ejemplo ejecute:
                                java ValidaCorreo.java xyz@abc.com
                                Dominios de internet admitidos: .com, .net, .org, .edu, gov, .gob, .mil, .xyz, .io""";
            IO.println(textoAyuda);
        }
    }
}
