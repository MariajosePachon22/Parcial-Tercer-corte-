from datetime import datetime, timedelta

VACIO = 'O'
OCUPADO = 'X'
CAMINO = '-'
ENTRADA = 'E'
SALIDA = 'S'
VALOR_POR_MINUTO = 100

parqueadero = [
    [ENTRADA, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [VACIO, VACIO, CAMINO, VACIO, VACIO, VACIO, CAMINO, VACIO, VACIO, CAMINO],
    [SALIDA, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO, CAMINO],
]

vehiculos = {}

letras = "ABCDEFG"
columnas_validas = [0, 1, 3, 4, 5, 7, 8]

# Mostrar estado del parqueadero
def mostrar_parqueadero():
    print("\nEstado del parqueadero:\n")
    for i in range(len(parqueadero)):
        fila_str = ""
        for j in range(len(parqueadero[0])):
            celda = parqueadero[i][j]
            if i == 0 or i == 8:
                fila_str += f"{celda}   " if celda in [ENTRADA, SALIDA] else "-   "
            elif j not in columnas_validas:
                fila_str += "-   "
            else:
                letra = letras[i - 1]
                num = columnas_validas.index(j) + 1
                if celda == VACIO:
                    fila_str += f"{letra}{num} "
                elif celda == OCUPADO:
                    fila_str += "XX "
                else:
                    fila_str += "-   "
        print(fila_str.strip())
    print()

def convertir_codigo_a_posicion(codigo):
    if len(codigo) < 2:
        return None
    letra = codigo[0].upper()
    numero = codigo[1:]
    if letra not in letras or not numero.isdigit():
        return None
    fila = letras.index(letra) + 1
    try:
        col = columnas_validas[int(numero) - 1]
    except:
        return None
    return (fila, col)

def pedir_hora(tipo, fecha_base=None):
    try:
        hora = int(input(f"Ingresa la hora de {tipo} (1 a 12): "))
        minuto = int(input("Ingresa los minutos (0 a 59): "))
        am_pm = input("¿Es AM o PM?: ").strip().upper()

        if am_pm == "PM" and hora != 12:
            hora += 12
        elif am_pm == "AM" and hora == 12:
            hora = 0

        hoy = datetime.now()
        base = fecha_base if fecha_base else hoy
        fecha_resultado = base.replace(hour=hora, minute=minuto, second=0, microsecond=0)

        if tipo == "salida" and fecha_base and fecha_resultado < fecha_base:
            fecha_resultado += timedelta(days=1)

        return fecha_resultado
    except:
        print("Hora no válida.")
        return None

def ingresar_carro():
    placa = input("Ingresa la placa del carro: ").upper()
    if placa in vehiculos:
        print("Ese carro ya está registrado.")
        return

    hora_entrada = pedir_hora("entrada")
    if not hora_entrada:
        return

    codigo = input("Ingresa la posición:").upper()
    pos = convertir_codigo_a_posicion(codigo)
    if not pos:
        print("Posición inválida.")
        return

    fila, col = pos
    if parqueadero[fila][col] != VACIO:
        print("Ese espacio no está disponible.")
        return

    parqueadero[fila][col] = OCUPADO
    vehiculos[placa] = {"hora_entrada": hora_entrada, "posicion": (fila, col)}
    print("Carro registrado exitosamente.")

def sacar_carro():
    placa = input("Ingresa la placa del carro a retirar: ").upper()
    if placa not in vehiculos:
        print("Ese carro no está registrado.")
        return

    datos = vehiculos[placa]
    hora_salida = pedir_hora("salida", datos["hora_entrada"])
    if not hora_salida:
        return

    tiempo = hora_salida - datos["hora_entrada"]
    minutos = int(tiempo.total_seconds() // 60)
    costo = minutos * VALOR_POR_MINUTO

    print(f"Tiempo estacionado: {minutos} minutos")
    print(f"Total a pagar: ${costo}")

    fila, col = datos["posicion"]
    parqueadero[fila][col] = VACIO
    del vehiculos[placa]
    print("Carro retirado del parqueadero.")

def menu():
    while True:
        mostrar_parqueadero()
        print("\n1. Ingresar vehículo")
        print("2. Sacar vehículo")
        print("3. Salir")
        op = input("Elige una opción: ")
        if op == "1":
            ingresar_carro()
        elif op == "2":
            sacar_carro()
        elif op == "3":
            print("¡Hasta luego!")
            break
        else:
            print("Opción inválida.")

menu()
