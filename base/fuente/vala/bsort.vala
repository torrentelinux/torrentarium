// bsort.vala
// Octulio Biletán - Enero de 2021.
//
// Compilar el programa fuente en Linux:
// valac -v --main=comienzo bsort.vala
//
// Ejecutar el programa:
// ./bsort
//
// Referencias: leer en los siguientes docus.
// https://users.cs.duke.edu/~ola/bubble/bubble.pdf
// https://users.cs.duke.edu/~ola/bubble/bubble.html

// Lleva la cuenta de intercambios efectuados
ulong intercambios = 0;

// Intercambia dos valores numéricos en un mismo vector
void Swap(int[] v, int a0, int a1)
{
    int _x = v[a0];
    v[a0] = v[a1];
    v[a1] = _x;
    
    intercambios++;
}

// El algoritmo del método de ordenamiento de la burbuja
void BubbleSort(int[] a, int n)
{
    for(int j = n - 1; j > 0; j--)
      for(int k = 0; k < j; k++)
        if(a[k + 1] < a[k])
          Swap(a, k, k + 1);
}

// Mi función de entrada
void comienzo()
{
	// vector con valores numéricos desordenados
	int vector[] = { 33, 0, 99, -1, -62, 19, 8, 101, 10, 33, 31 };

    print("Método de ordenamiento por intercambio de datos en un vector numérico (bubble sort).\n");
    print("\n--Vector desordenado--\n");

    // Muestra los datos del vector usando un puntero a vector
    for(int *secuencia = vector; secuencia < &vector[vector.length]; secuencia++)
      stdout.printf("%d ", *secuencia);

    print("\n");

    // Ordena el vector de menor a mayor
    BubbleSort(vector, vector.length);

    print("--Vector ordenado--\n");

    // Muestra los datos del vector usando un puntero a vector
    for(int *secuencia = vector; secuencia < &vector[vector.length]; secuencia++)
      stdout.printf("%d ", *secuencia);

    stdout.printf("\n\nCantidad de intercambios realizados: %lu\n", intercambios);

    print("Estado inicial del vector: ");
    if(intercambios < (vector.length / 2))
      print("Parcialmente desordenado.\n");
    else
      if(intercambios >= (vector.length/2) && intercambios <= vector.length)
        print("Desordenado.\n");
      else
        print("Muy desordenado.\n");

    print("\n");
}
