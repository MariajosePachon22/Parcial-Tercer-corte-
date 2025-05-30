# Proyecto Parqueadero

# Desarrollo Innovador 1: Cálculo de cobro por minutos usando entrada/salida con AM/PM

# ¿Para qué se implementó?
Para simular una experiencia realista en el ingreso y salida de vehículos, considerando formatos de tiempo comunes (AM/PM).
(El usuario pondra la hora como está acostumbrado (ej. 3:30 PM)).

# ¿Por qué se consideró necesario?
Porque facilita el uso del sistema, además de permitir calcular con precisión el valor a pagar según la permanencia.
(El programa pregunta si es AM o PM, convierte eso a una hora interna y calcula cuánto tiempo estuvo el carro).

# ¿Cómo se llevó a cabo su implementación?
Mediante la función `pedir_hora`, que convierte la hora introducida manualmente en un objeto `datetime`, usando reglas de conversión de AM/PM. Luego se calcula la diferencia de tiempo y se multiplica por el valor por minuto.



# Desarrollo Innovador 2: Conversión de códigos como 'C4' a coordenadas

# ¿Para qué se implementó?
Para permitir a los usuarios identificar y seleccionar espacios disponibles de forma simple.

# ¿Por qué se consideró necesario?
Porque mejora la experiencia de usuario al usar identificadores legibles en lugar de coordenadas de matriz.
(Es más claro usar una letra y número que contar filas y columnas)

### ¿Cómo se llevó a cabo su implementación?
La función `convertir_codigo_a_posicion` convierte un código como 'A1' en índices de fila y columna válidos para el sistema, siendo una posicion valida del parqueadero 



# Desarrollo Innovador 3: Visualización clara del parqueadero

# ¿Para qué se implementó?
Para permitir una visualización fácil y rápida del estado del parqueadero.

# ¿Por qué se consideró necesario?
Ayuda a identificar visualmente los espacios disponibles, ocupados y zonas de tránsito.

# ¿Cómo se llevó a cabo su implementación?
Con la función `mostrar_parqueadero`, que imprime el parqueadero respetando una convención clara de símbolos y posiciones codificadas.

