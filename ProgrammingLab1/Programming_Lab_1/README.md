# Programming LAB 1

El presente programa tiene por objetivo realizar la suma de N cantidad de 
numeros enteros y se reporta el tiempo de ejecución que tomo realizar dicho
procedimiento expresado en nanosegundos.

## Uso
1. Pasos para ejecutar tests de rendimiento
-  g++ createPerfomanceTestFiles.cpp -o createPerfomanceTestFiles.out
- ./createPerfomanceTestFiles
-  g++ main.cpp -o main
- ./main

2. Pasos para ejecutar con archivo de texto
- g++ main.cpp -o main
- ./main <ruta_al_archivo>
- E.g. ./main ./tests/test-1.txt

## Casos de prueba 
1. ./main ./tests/test-1.txt
Este caso de prueba evalua el correcto cálculo de la suma de números
enteros siendo todos ellos positivos

Expected output:  
Time Elapsed for 10 numbers is: 2641 nanosec  
Sum: 47

2. ./main ./tests/test-2.txt
Este caso de prueba evalua el correcto cálculo de la suma de números
enteros siendo algunos de ellos positivos y otros negativos

Expected output:  
Time Elapsed for 7 numbers is: 1950 nanosec  
Sum: 7  

3. ./main ./tests/test-3.txt
Este caso de prueba evalua el correcto funcionamiento del programa al 
presentarle un archivo vacío y regresando como resultado de la suma: 0

Expected output:  
Time Elapsed for 0 numbers is: 637 nanosec  
Sum: 0 

4. ./main ./tests/test-4.txt
Este caso de prueba revisa el correcto funcionamiento del programa al 
otorgarle como input una dirección hacia un archivo que no existe.
Informando del error mediante una impresión a pantalla.

Expected output:  
Could not open the file - 'tests/test-4.txt'

# Author:
- Brandon Magaña
