// Módulo   : HTML.java
// Autor    : Eugenio Martínez - Nov. de 2021
// Propósito: Define la clase HTML. 
//            Mediante esta clase se puede construir dinámicamente una página de texto con formato HTML.
// Referencias: https://es.wikipedia.org/wiki/HTML
// __________________________________________________________________________

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServletResponse;

/**
 * La clase {@code HTML}  permite manipular las etiquetas del lenguaje HTML a través de métodos.<br>
 * Los métodos definidos son:<br>
 * <blockquote><pre>
 * HTML(HttpServletResponse r) - constructor de la clase.
 * openHtml() y closeHtml()
 * openHead() y closeHead()
 * openBody() y closeBody()
 * setGenerator(String g)
 * setAuthor(String a)
 * setDescription(String d)
 * putHorizontalLine(String hl)
 * putTitle(String t)
 * putText(String t)
 * putTextBr(String t)
 * putTextColor(String bg, String fg, String t)
 * String alignCenter(String c)
 * String bold(String b)
 * String underline(String u)
 * String italic(String i)
 * putTitle1(String t)
 * </pre></blockquote>
 * <b>Uso simple:</b><br>
 * <blockquote><pre>
 * HTML html = new HTML(responde);
 * html.openHtml();
 * html.putTitle("HTML");
 * html.openBody();
 * html.putText("¡Esto es HTML!");
 * html.closeBody();
 * html.closeHtml();</pre></blockquote>
 * @author Eugenio Martínez
 * @see    javax.servlet.http.HttpServlet
 * @version 1.0
 * @since  JDK1.8
 */
public final class HTML
{
    private PrintWriter hoja;

    HTML(HttpServletResponse r) throws IOException
    {
        hoja = r.getWriter();

        // Establece como respuesta el tipo de contenido texto/html
        r.setContentType("text/html");

        // La codificación del texto es UTF-8
        r.setCharacterEncoding("UTF-8");
    }

    void openHtml()
    {
        // Pone la declaración del tipo de documento (DTD)
        hoja.println("<!DOCTYPE HTML>");

        // Empieza la página HTML
        hoja.println("<html>");
    }

    void closeHtml()
    {
        // Termina la página HTML
        hoja.println("</html>");
    }

    void openHead()
    {
        hoja.println("<head>");
        hoja.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">");
    }

    void closeHead()
    {
        hoja.println("</head>");
    }

    void openBody()
    {
        hoja.println("<body>");
    }

    void closeBody()
    {
        hoja.println("</body>");
    }

    // Identifica el generador de la página html a través de la etiqueta 'meta'
    // Usar dentro del bloque '<head>'
    void setGenerator(String g)
    {
        hoja.print("<meta name=\"generator\" content=\"");
        hoja.print(g);
        hoja.println("\">");
    }

    // Identifica el autor de la página html a través de la etiqueta 'meta'
    // Usar dentro del bloque '<head>'
    void setAuthor(String a)
    {
        hoja.print("<meta name=\"author\" content=\"");
        hoja.print(a);
        hoja.println("\">");
    }

    // Define la descripción de la página html a través de la etiqueta 'meta'
    // Usar dentro del bloque '<head>'
    void setDescription(String d)
    {
        hoja.print("<meta name=\"description\" content=\"");
        hoja.print(d);
        hoja.println("\">");
    }

    void putTitle(String t)
    {
        hoja.println("<title>" + t + "</title>");
    }

    // Pone color de fondo 'bg' y color de frente 'fg' sobre el texto 't'
    void putTextColor(String bg, String fg, String t)
    {
        hoja.print("<span style=\"background-color: ");
        hoja.print(bg);
        hoja.print("; color: ");
        hoja.print(fg);
        hoja.print(";\">");
        hoja.print(t);
        hoja.print("</span>");
    }

    void putTextBr(String t)
    {
        if(t.isEmpty())
          hoja.println("<br>");
        else
          hoja.println(t + "<br>");
    }

    void putText(String t)
    {
        hoja.print(t);
    }

    // El texto 'c' va acompañado del atributo 'align=center'.
    // Ajuste del texto centrado en la hoja.
    String alignCenter(String c)
    {
        return "align=center^" + c;
    }

    // Se coloca al texto 'b' en negrita.
    // Devuelve el texto en negrita.
    String bold(String b)
    {
        return "<b>" + b + "</b>";
    }

    // Se coloca subrayado a texto 'u'.
    // Devuelve el texto subrayado.
    String underline(String u)
    {
        return "<u>" + u + "</u>";
    }

    // Se coloca el estilo cursiva a texto 'i'.
    // Devuelve el texto en itálica.
    String italic(String i)
    {
        return "<i>" + i + "</i>";
    }

    // Pone texto 't' a 1º Nivel de encabezamento (Heading level 1)
    // --Título muy grande--
    void putTitle1(String t)
    {
        int pos;

        hoja.print("<h1");
        pos = t.indexOf('^');
        if(pos != -1)
        {
          hoja.print(" " + t.substring(0, pos) + ">");
          hoja.print(t.substring(pos+1));
          hoja.println("</h1><br>");
        }
        else
        {
            hoja.print(">" + t);
            hoja.println("</h1><br>");
        }
    }

    // Pone una línea horizontal de longitud 'hl'.
    // La longitud puede ser entre 1 y 100 inclusive.
    // El grosor de la línea es siempre constante.
    void putHorizontalLine(String hl)
    {
        Integer valor = new Integer(hl);
        String ancho;

        if(hl.isEmpty())
            ancho = "100";
        else
            ancho = hl;

        if(valor < 1 || valor > 100)
            ancho = "100";

        hoja.print("<hr width=\"");
        hoja.print(ancho);

        // El valor 'hl' es porcentual y el grosor es 1.
        hoja.print("%\" size=\"1\">");
    }
}
