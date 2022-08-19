# MergeSort

El presente programa tiene por objetivo realizar el ordenamiento de un arreglo de tamaño 
N de números enteros siendo N >= 1 utilizando el algoritmo de ordenamiento MergeSort cuya
complejidad temporal en promedio es de O(n log(n)). 

## Uso
1. Compilar archivo main.cpp y ejecutar
-  g++ main.cpp -o mergeSort
- ./mergeSort

2. Ejecutar con archivo de texto como entrada
- g++ main.cpp -o mamergeSortin
- ./mergeSort < ruta_al_archivo
- ./mergeSort  < ./tests/test-1.txt

## Casos de prueba 
1. ./mergeSort ./tests/test-1.txt
Este caso de prueba evalua el correcto ordenamiento del arreglo de números 
cuando estos originalmente ya se encuentran ordenados.  
Salida esperada:
```
Vector Original: 
2,4,6,8,10
Vector Ordenado: 
2,4,6,8,10
```
2. ./mergeSort ./tests/test-2.txt
Este caso de prueba evalua el correcto ordenamiento del arreglo cuando originalmente
se encuentra desordenado de manera aleatoria.
```
Vector Original: 
8,5,2,5,-6,1
Vector Ordenado: 
-6,1,2,5,5,8
```

3. ./mergeSort ./tests/test-3.txt
Este caso de prueba evalua el comportamiento del algoritmo cuando los elementos 
del arreglo original se encuentran ordenados de manera descendente.
Salida esperada:
```
Vector Original: 
9,7,5,3,1
Vector Ordenado: 
1,3,5,7,9
```

4. /mergeSort ./test/test-4,txt
Este caso de prueba evalua el correcto comportamiento del algoritmo cuando se le 
presenta un arreglo de 1 elemento.  
Salida esperada:
```
Vector Original: 
8
Vector Ordenado: 
8
```

5. ./mergeSort ./tests/test-3.txt
Este caso de prueba evalua el comportamiento del programa cuando se 
le otorga un valor N igual a 0.  
Salida esperada:
```
Empty vector
``` 

6. ./mergeSort ./tests/test-3.txt
Este caso de prueba evalua el comportamiento del programa cuando se 
le otorga un valor N menor a 0.  
Salida esperada:
```
Vector length error.
Cannot create vector of length < 0.
```

# Author:
- Brandon Magaña