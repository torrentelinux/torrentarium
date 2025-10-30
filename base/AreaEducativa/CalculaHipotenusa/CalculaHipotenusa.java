// CalculaHipotenusa.java

/**
 * Programa para calcular la hipotenusa de un triángulo rectángulo utilizando el
 * teorema de Pitágoras. Fórmula: hipotenusa = √(cateto1² + cateto2²)
 *
 * @author Octulio Biletán
 */
public class CalculaHipotenusa {

    public static void main(String[] args) {
        TrianguloRectangulo triangulo = new TrianguloRectangulo();

        triangulo.titular("Bienvenido al programa 'Cálculo de la Hipotenusa' de un triángulo rectángulo");

        triangulo.muestraResultado(
                triangulo.hipotenusa(
                        triangulo.solicitaCateto("Ingresa el valor del 1º cateto (X)"),
                        triangulo.solicitaCateto("Ingresa el valor del 2º cateto (Y)")
                )
        );

        triangulo.graficar();
    }
}
