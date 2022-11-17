# Tries

El presente programa tiene como objetivo ilustrar una implementación de la estructura de datos Trie.  Donde el usuario ingresa un número M de palabras que contendrá el Trie seguido de esas M palabras,  posterior a ello el usuario ingresa un número N que serán las palabras a buscar dentro del árbol.  
**NOTA: Todas las palabras son almacenadas en minúscula**

## Uso
1. Compilar archivo main.cpp y ejecutar
-  g++ main.cpp -o tries
- ./tries

2. Ejecutar con archivo de texto como entrada
- g++ main.cpp -o tries
- ./tries < ruta_al_archivo
- ./tries  < ./tests/test-1.txt

## Casos de prueba 
1. ./tries ./tests/test-1.txt
Este caso de prueba evalua el correcto comportamiento del recorrido del Trie, así como la búsqueda de pabalabras cuando se ingresan palabras únicas en minúscula.

Salida esperada:
```
Trie DFS:
@
c
o
l
o
r
g
i
s
l
a
p
t
o
p
m
o
u
s
e
Resultado de busqueda:
color True
escritorio False
```
2. ./tries ./tests/test-2.txt
Este caso de prueba evalua el correcto comportamiento del recorrido del Trie, así como la búsqueda de pabalabras cuando se ingresan palabras que comparten prefijos.

Salida esperada:
```
Trie DFS:
@
b
i
b
l
i
o
t
e
c
a
r
i
o
Resultado de busqueda:
biblioteca True
```

3. ./tries ./tests/test-3.txt
Este caso de prueba evalua el correcto comportamiento del recorrido del Trie, así como la búsqueda de pabalabras cuando se ingresan palabras repetidas.

Salida esperada:
```
Trie DFS:
@
c
a
m
i
s
a
Resultado de busqueda:
pantalon False
```

4. ./tries ./tests/test-3.txt
Este caso de prueba evalua el correcto comportamiento del recorrido del Trie, así como la búsqueda de pabalabras cuando se ingresan palabras con letras mayúscula y minúsculas de manera intercalada.

Salida esperada:
```
Trie DFS:
@
e
s
p
a
c
i
o
t
r
e
l
l
a
p
l
a
n
e
t
a
u
t
o
n
Resultado de busqueda:
estrella True
pluton True
```

# Autores:
- Brandon Magaña
- Santiago González de Cosío