#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ataque {
public:
	string nombre;
	int daño;

	Ataque(string n, int d) : nombre(n), daño(d) {}
};

class Pokemon {
public:
	string nombre;
	int vida;
	Ataque ataque1;
	Ataque ataque2;
	Ataque ataque3;
	Ataque ataque4;
	
	Pokemon(string n, int v, Ataque a1, Ataque a2, Ataque a3, Ataque a4)
		: nombre(n), vida(v), ataque1(a1), ataque2(a2), ataque3 (a3), ataque4 (a4) {}

	bool estaVivo() {
		return vida > 0;
	}

	void recibirDaño(int cantidad) {
		vida -= cantidad;
		if (vida < 0) vida = 0;
	}

	void mostrarEstado() {
		cout << nombre << " - Vida: " << vida << endl;
	}

	void usarAtaque(int opcion, Pokemon & oponente) {
		Ataque ataqueSeleccionado = ataque1;
		switch (opcion) {
        case 1: ataqueSeleccionado = ataque1; break;
        case 2: ataqueSeleccionado = ataque2; break;
        case 3: ataqueSeleccionado = ataque3; break;
        case 4: ataqueSeleccionado = ataque4; break;
		}
		cout << nombre << " usa " << ataqueSeleccionado.nombre << "!" << endl;
		oponente.recibirDaño(ataqueSeleccionado.daño);
		cout << oponente.nombre << " recibe " << ataqueSeleccionado.daño << " de daño.\n";
	}
};

int mostrarMenu(Pokemon &poke) {
	int opcion;
	cout << "\nTurno de " << poke.nombre << ". Elige un ataque:\n";
	cout << "1. " << poke.ataque1.nombre << "\n";
	cout << "2. " << poke.ataque2.nombre << "\n";
	cout << "3. " << poke.ataque3.nombre << "\n";
	cout << "4. " << poke.ataque4.nombre << "\n";
	cout << "Opcion: ";
	cin >> opcion;
	while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) {
		cout << "Opción invalida. Intenta de nuevo: ";
		cin >> opcion;
	}
	return opcion;
}

// Generar los 18 Pokemones con nombres, ataques y tipos diferentes
vector<Pokemon> crearPokemones() {
	return {
		Pokemon("Charmander/Fuego", 150, Ataque("Arañazo", 15), Ataque("Ascuas", 15),Ataque("Cuchillada", 20),Ataque("Pantalla de humo", 10)),// Fuego
	    Pokemon("Shellder/Agua", 150, Ataque("Tenaza", 15), Ataque("Rayo aurora", 20),Ataque("Plcaje", 25),Ataque("Aguante", 10)),// Agua
		Pokemon("Bulbasaur/Planta", 150, Ataque("Latigo Cepa", 10), Ataque("Hoja Afilada", 15),Ataque("Golpe cabeza", 15),Ataque("Toxico", 20)),// Planta
		Pokemon("Pikachu/Electrico", 150, Ataque("Rayo", 15), Ataque("Impactrueno", 15),Ataque("Cola de hierro", 30),Ataque("Trueno", 10)),// Eléctrico
		Pokemon("Mewtwo/Psiquico", 150, Ataque("Psicocorte", 25), Ataque("Puño dinamico", 15),Ataque("Amnesia", 25),Ataque("Confusion", 15)),// Psiquico
		Pokemon("Hitmonlee/Lucha", 150, Ataque("Patada baja", 10), Ataque("Meditacion ", 15),Ataque("Megapatada", 20),Ataque("Amago", 10)),// Lucha
		Pokemon("Haunter/Fantasma", 150, Ataque("Bola Sombra", 10), Ataque("Lengüetazo", 15),Ataque("Rencor", 5),Ataque("Tinieblas", 10)),// Fantasma
		Pokemon("Dragonite/Dragon", 150, Ataque("Ataque Ala", 15), Ataque("Ciclón", 10),Ataque("Furia Dragon", 25),Ataque("Enfado", 10)),// Dragon
		Pokemon("Hippopotas/Tierra", 150, Ataque("Mordisco", 10), Ataque("Fisura", 15), Ataque("Triturar", 15),Ataque("Excavar", 10)),// Tierra
		Pokemon("Jirachi/Acero", 150, Ataque("Rapidez", 20), Ataque("Cabezazo Zen", 15),Ataque("Confusion", 25),Ataque("Rayo carga",10)),// Acero
		Pokemon("Cubchoo/Hielo", 150, Ataque("Viento Hielo", 20), Ataque("Encanto", 15),Ataque("Granizo", 10),Ataque("Ventisca", 15)),// Hielo
		Pokemon("Ekans/Veneno", 150, Ataque("Picotazo Ven", 20), Ataque("Bomba Lodo", 15),Ataque("Deslumbrar", 10),Ataque("Ácido", 15)),// Veneno
		Pokemon("Tornadus/Volador", 150, Ataque("Golpe", 10), Ataque("Aire Afilado", 25),Ataque("Pulso Umbrio", 15),Ataque("Triturar", 15)),// Volador
		Pokemon("Umbreon/Siniestro", 150, Ataque("Ojitos Tierno", 20), Ataque("Chirridos", 15),Ataque("Finta", 10),Ataque("Placaje", 10)),// Siniestro
		Pokemon("Scyther/Bicho", 150, Ataque("Corte Furia", 15), Ataque("Tijeras X", 10),Ataque("Tajo Aereo", 15),Ataque("Foco energia", 10)),// Bicho
		Pokemon("Alcremie/Hada", 150, Ataque("Aromaterapia", 15), Ataque("Encanto", 10),Ataque("Zona Magica", 20),Ataque("Carantoña", 15)), // Hada
		Pokemon("Jigglypuff/Normal", 150, Ataque("Beso", 15), Ataque("Brillo Magico", 15),Ataque("Chispas", 20),Ataque("Golpe Cuerpo", 10)),// Normal
		Pokemon("Diancie/Roca", 150, Ataque("Roca Afilada", 25), Ataque("Fuerza Lunar", 20),Ataque("Lanza Roca", 10),Ataque("Placaje", 15)), //Roca
	};
}

// Selección de Pokemon para un jugador humano
Pokemon elegirPokemonJugador(vector<Pokemon> &pokemones) {
	cout << "Elige tu Pokemon:\n";
	for (size_t i = 0; i < pokemones.size(); ++i) {
		cout << i + 1 << ". " << pokemones[i].nombre << endl;
	}
	int eleccion;
	cout << "Numero: ";
	cin >> eleccion;
	while (eleccion < 1 || eleccion > (int)pokemones.size()) {
		cout << "Opcion invalida. Intenta de nuevo: ";
		cin >> eleccion;
	}
	return pokemones[eleccion - 1];
}

int main() {
	srand(time(0));
	vector<Pokemon> pokemones = crearPokemones();

	cout << "¡Bienvenido al Combate Pokemon!\n";
	cout << "Selecciona el modo de juego:\n";
	cout << "1. Un jugador (contra un Bot)\n";
	cout << "2. Dos jugadores\n";
	cout << "Opcion: ";
	int modo;
	cin >> modo;

	Pokemon jugador1 = elegirPokemonJugador(pokemones);
    Pokemon jugador2 = (modo == 2)
        ? elegirPokemonJugador(pokemones)
        : pokemones[rand() % pokemones.size()];

	cout << "\nB!Combate entre " << jugador1.nombre << " y " << jugador2.nombre << "!\n";
    cout << "----------------------------------\n";
	// Combate por turnos
	bool turnoJugador1 = true;
	while (jugador1.estaVivo() && jugador2.estaVivo()) {
		jugador1.mostrarEstado();
		jugador2.mostrarEstado();

		if (turnoJugador1) {
			int eleccion = mostrarMenu(jugador1);
			jugador1.usarAtaque(eleccion, jugador2);
		} else {
			if (modo == 2) {
				int eleccion = mostrarMenu(jugador2);
				jugador2.usarAtaque(eleccion, jugador1);
			} else {
				int eleccionCpu = rand() % 4 + 1;
                Ataque ataqueBot("Desconocido", 0);  // inicialización válida

                    switch (eleccionCpu) {
	                case 1: ataqueBot = jugador2.ataque1; break;
	                case 2: ataqueBot = jugador2.ataque2; break;
	                case 3: ataqueBot = jugador2.ataque3; break;
	                case 4: ataqueBot = jugador2.ataque4; break;
}
cout << "----------------------------------\n";
cout << jugador2.nombre << " (BOT) ha elegido el ataque: " << ataqueBot.nombre << endl;
jugador2.usarAtaque(eleccionCpu, jugador1);

			}
		}

		turnoJugador1 = !turnoJugador1;
		cout << "----------------------------------\n";
	}

	if (jugador1.estaVivo()) {
		cout << "\nB!" << jugador1.nombre << " gana el combate!\n";
	} else {
		cout << "\nB!" << jugador2.nombre << " gana el combate!\n";
	}

	return 0;
}