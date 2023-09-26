# PATRONES 2

# patron1, patron2
# - Especifican un rango de registros
# - patron1 (patron de inicio), patron2 (patron de fin)
# - Cuando un registro concuerda con patron1 comienzan a chequearse
# los siguientes registros contra patron2, luego realiza la misma tarea desde el principio

# awk '$1 == "17/05/2005", $2 == "20/06/2005"'

# BEGIN END
# - Son patrones especiale, no se utilizan como filtro
# - Brindar la posibilidad de realizar tareas antes y despues de procesar la entrada
# - Tanto BEGIN como END se ejecutan solo una vez
# - No pueden ser usados en rangos o con operadores booleanos
# - deben estar acompañados por accion(es) pues no ecisten acciones por defecto para estas reglas

# null
# - Especifican cualquier secuencia de caracteres, es decir, todos los registros
# concuerdan con este