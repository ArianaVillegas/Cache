# Análisis de complejidad

| Estructura | Operación | Complejidad |
| :--: | :--: | :--: |
| unordered_map | [] | O(1) |
| unordered_map | find | O(1) |
| unordered_map | end | O(1) |
| unordered_map | erase(itr) | O(1) |
| list | size | O(1) |
| list | begin | O(1) |
| list | end | O(1) |
| list | front | O(1) |
| list | back | O(1) |
| list | push_front | O(1) |
| list | pop_front | O(1) |
| list | push_back | O(1) |
| list | pop_back | O(1) |

## Espacio

El espacio es constante porque la estructura tiene un tamaño máximo que se define al momento de crearla.

## Complejidad

* InsertKeyValuePair: Para esta función, hay dos casos,
   - El key ya esta en la estructura: Primero se usa un hash para acceder al iterador que tiene el par de key/value en la lista ([]). Luego se usa el iterador para cambiar el valor en la lista, las operaciones anteriores son constantes por lo cual este caso es O(1).
   - El key no esta en la estructuras:
      - Si la estructura esta llena eliminamos el ultimo elemento de la lista, y con la key de la lista tambien lo elminamos en el hash. O(1)
      - Se añade el nuevo key/value al inicio de la lista (push_front), luego guardamos este valor en el hash ([]), para acceder a el usamos (front), e insertar el par al hash ([]). O(1)
* GetValueFromKey: Dos casos
   - Si el key no esta en el hash, retornamos nullopt. O(1)
   - Si el key esta, lo eliminamos de la posicion en que esta (erase), y lo insertamos al inicio de la lista (push_front), y actualizamos el valor en el hash ([]). Finalmente retornamos el valor del key/value pair. O(1)
* GetMostRecentKey: Accedemos al primer par de la lista y tomamos el value (front). O(1)

# Tabla de comparación de tiempos

| Tamaño | LRU | FIFO | LIFO |
| :--: | :--: | :--: | :--: |
| 10000 | 0.016224 | 0.015059 | 0.014854 |
| 100000 | 0.113235 | 0.105974 | 0.094090 |
| 1000000 | 1.25813 | 0.87822 | 0.89499 |
| 10000000 | 10.0824 | 9.81382 | 10.2575 |
| 100000000 | 123.058 | 119.257 | 113.550 |