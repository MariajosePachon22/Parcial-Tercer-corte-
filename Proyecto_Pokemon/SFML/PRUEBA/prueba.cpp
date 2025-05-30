#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
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
    string imagen;
    Ataque ataque1;
    Ataque ataque2;
    Ataque ataque3;
    Ataque ataque4;

    Pokemon(string n, int v,Ataque a1, Ataque a2, Ataque a3, Ataque a4,string img)
        : nombre(n), vida(v), ataque1(a1), ataque2(a2), ataque3(a3), ataque4(a4), imagen(img) {}

    void mostrarEstado() {
        cout << nombre << " - Vida: " << vida << endl;
    }
    bool estaVivo() {
        return vida > 0;
    }
    void usarAtaque(int opcion, Pokemon &oponente){
    }
    void recibirDaño(int cantidad) {
        vida -= cantidad;
        if (vida < 0) vida = 0;
    }

};

int mostrarMenu(Pokemon &poke) {
    int opcion;
    cout << "\nTurno de " << poke.nombre << ". Elige un ataque:\n";
    cout << "1. " << poke.ataque1.nombre << "\n";
    cout << "2. " << poke.ataque2.nombre << "\n";
    cout << "3. " << poke.ataque3.nombre << "\n";
    cout << "4. " << poke.ataque4.nombre << "\n";
    cout << "Opción: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
        cout << "Opción inválida. Intenta de nuevo: ";
        cin >> opcion;
    }
    return opcion;
}

// ✅ Lista de Pokémon
vector<Pokemon> crearPokemones() {
    return {
        Pokemon("a. Charmander/Fuego", 150, Ataque("Arañazo", 15), Ataque("Ascuas", 15), Ataque("Cuchillada", 20), Ataque("Pantalla de humo", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Charmander.png"),
        Pokemon("b. Shellder/Agua", 150, Ataque("Tenaza", 15), Ataque("Rayo aurora", 20), Ataque("Placaje", 25), Ataque("Aguante", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Shellder.png"),
        Pokemon("c. Bulbasaur/Planta", 150, Ataque("Látigo Cepa", 10), Ataque("Hoja Afilada", 15), Ataque("Golpe cabeza", 15), Ataque("Tóxico", 20),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Bulbasaur.png"),
        Pokemon("d. Pikachu/Electrico", 150, Ataque("Rayo", 15), Ataque("Impactrueno", 15), Ataque("Cola de hierro", 30), Ataque("Trueno", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Pikachu.png"),
        Pokemon("e. Mewtwo/Psiquico", 150, Ataque("Psicocorte", 25), Ataque("Puño dinámico", 15), Ataque("Amnesia", 25), Ataque("Confusión", 15),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\mewtwo.png"),
        Pokemon("f. Hitmonlee/Lucha", 150, Ataque("Patada baja", 10), Ataque("Meditación", 15), Ataque("Megapatada", 20), Ataque("Amago", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Hitmonlee.png"),
        Pokemon("g. Haunter/Fantasma", 150, Ataque("Bola Sombra", 10), Ataque("Lengüetazo", 15), Ataque("Rencor", 5), Ataque("Tinieblas", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\Haunter.png"),
        Pokemon("h. Dragonite/Dragon", 150, Ataque("Ataque Ala", 15), Ataque("Ciclón", 10), Ataque("Furia Dragón", 25), Ataque("Enfado", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\dragonite.png"),
        Pokemon("i. Hippopotas/Tierra", 150, Ataque("Mordisco", 10), Ataque("Fisura", 15), Ataque("Triturar", 15), Ataque("Excavar", 10),
        "C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagenespoke\\hippopotas.png"),
        /*Pokemon("j. Jirachi/Acero", 150, Ataque("Rapidez", 20), Ataque("Cabezazo Zen", 15), Ataque("Confusión", 25), Ataque("Rayo carga", 10)),
        Pokemon("k. Cubchoo/Hielo", 150, Ataque("Viento Hielo", 20), Ataque("Encanto", 15), Ataque("Granizo", 10), Ataque("Ventisca", 15)),
        Pokemon("l. Ekans/Veneno", 150, Ataque("Picotazo Ven", 20), Ataque("Bomba Lodo", 15), Ataque("Deslumbrar", 10), Ataque("Ácido", 15)),
        Pokemon("m. Tornadus/Volador", 150, Ataque("Golpe", 10), Ataque("Aire Afilado", 25), Ataque("Pulso Umbrío", 15), Ataque("Triturar", 15)),
        Pokemon("n. Umbreon/Siniestro", 150, Ataque("Ojitos Tiernos", 20), Ataque("Chirridos", 15), Ataque("Finta", 10), Ataque("Placaje", 10)),
        Pokemon("o. Scyther/Bicho", 150, Ataque("Corte Furia", 15), Ataque("Tijeras X", 10), Ataque("Tajo Aéreo", 15), Ataque("Foco energía", 10)),
        Pokemon("p. Alcremie/Hada", 150, Ataque("Aromaterapia", 15), Ataque("Encanto", 10), Ataque("Zona Mágica", 20), Ataque("Carantoña", 15)),
        Pokemon("q. Jigglypuff/Normal", 150, Ataque("Beso", 15), Ataque("Brillo Mágico", 15), Ataque("Chispas", 20), Ataque("Golpe Cuerpo", 10)),
        Pokemon("r. Diancie/Roca", 150, Ataque("Roca Afilada", 25), Ataque("Fuerza Lunar", 20), Ataque("Lanza Roca", 10), Ataque("Placaje", 15)),*/
    };
}


// ✅ Selección de Pokémon para el jugador
Pokemon elegirPokemonJugador(vector<Pokemon> &pokemones) {
    cout << "Elige tu Pokémon:\n";
    for (size_t i = 0; i < pokemones.size(); ++i) {
        cout << i + 1 << ". " << pokemones[i].nombre << endl;
    }
    int eleccion;
    cout << "Número: ";
    cin >> eleccion;
    while (eleccion < 1 || eleccion > (int)pokemones.size()) {
        cout << "Opción inválida. Intenta de nuevo: ";
        cin >> eleccion;
    }
    return pokemones[eleccion - 1];
}

int main() {
     //Se crea una ventana
   RenderWindow renderWindow(VideoMode({1000,900}),"Batalla Pokemon");
    //se carga un sprite
   Texture texture;
    if(!texture.loadFromFile("C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagen\\fondopoke2.png")){
        system("echo No se pudo cargar la texture&&pause");
        return EXIT_FAILURE;
    }
    Vector2u texturesize = texture.getSize();
    sf::IntRect rectSourceSprite ({{0, 0}, {800, 600}});// ← Esto debería ser válido
    
    Sprite sprite1(texture, rectSourceSprite);
    sprite1.setPosition({100.f, 25.f});//{x,y}

        Texture texture2;
    if(!texture2.loadFromFile("C:\\Users\\USUARIO\\Desktop\\PARCIAL\\imagen\\fondopoke2.png")){
        system("echo No se pudo cargar la batalla&&pause");
        return EXIT_FAILURE;
    }
   
    Vector2u texture2size = texture2.getSize();
    sf::IntRect rectSourceSprite2 ({{0, 0}, {770, 400}});// ← Esto debería ser válido
    
    Sprite sprite2(texture2, rectSourceSprite2);
    sprite2.setPosition({100.f, 25.f});//{x,y}

    Font font;
    if(!font.openFromFile("C:\\Users\\USUARIO\\Desktop\\PARCIAL\\Texto\\CoffeCake.ttf")){
        system("echo No se pudo cargar la font&&pause");
        return EXIT_FAILURE;
    }
    Text text1 (font, "Bienvenido al Combate Pokemon", 50);
    text1.setPosition({50.f, 25.f});
    Text text2 (font, "Selecciona el modo de juego:", 30);
    text2.setPosition({50.f,80.f});
    Text text3 (font, "1. Un jugador (contra la CPU)", 18);
    text3.setPosition({50.f, 120.f});
    Text text4 (font, "2. Dos jugadores", 18);
    text4.setPosition({50.f, 160.f});
    Text text5 (font, "Selecciona el Pokemon", 40);
    text5.setPosition({50.f, 25.f});
    int modo=0;
    int poke=-1;
    srand(time(0));
    vector<Pokemon> pokemones = crearPokemones();
    int d=rand() % pokemones.size();

    while (renderWindow.isOpen()){
        while (const std::optional event = renderWindow.pollEvent()){
            // Close window: exit
            if (event->is<sf::Event::Closed>()){
                renderWindow.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    renderWindow.close();
                if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
                    modo=1;
                if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
                    modo=2;
                if (keyPressed->scancode == sf::Keyboard::Scancode::A)
                    poke=0;
                if (keyPressed->scancode == sf::Keyboard::Scancode::B)
                    poke=1;
                if (keyPressed->scancode == sf::Keyboard::Scancode::C)
                    poke=2;
                if (keyPressed->scancode == sf::Keyboard::Scancode::D)
                    poke=3;
                if (keyPressed->scancode == sf::Keyboard::Scancode::E)
                    poke=4;
                if (keyPressed->scancode == sf::Keyboard::Scancode::F)
                    poke=5;      
                if (keyPressed->scancode == sf::Keyboard::Scancode::G)
                    poke=6;    
                if (keyPressed->scancode == sf::Keyboard::Scancode::H)
                    poke=7;      
                if (keyPressed->scancode == sf::Keyboard::Scancode::I)
                    poke=8;                                                                
            }
        }
       sprite1.setTextureRect(rectSourceSprite);


        // Clear screen
        renderWindow.clear();
        if(modo==0){
            // Draw the sprite
            renderWindow.draw(sprite1);

            // Draw the string
            renderWindow.draw(text1); 
            renderWindow.draw(text2); 
            renderWindow.draw(text3); 
            renderWindow.draw(text4); 
        }
        else if(modo==1){
            renderWindow.draw(text5);
            for (size_t i = 0; i < pokemones.size(); ++i) {
                Text textos (font,pokemones[i].nombre,30);
                textos.setPosition({50.f, (i+2)*40.f});
                renderWindow.draw(textos);
            } 
            sprite2.setTextureRect(rectSourceSprite2);
            if(poke != -1){                
                renderWindow.clear(sf::Color::Black);
                renderWindow.draw(sprite2);
                Texture texture3;
                if(!texture3.loadFromFile(pokemones[poke].imagen)){
                    system("echo No se pudo cargar la textura&&pause");
                    return EXIT_FAILURE;
                }
   
                Vector2u texture3size = texture3.getSize();
                sf::IntRect rectSourceSprite3 ({{0, 0}, {200, 300}});// ← Esto debería ser válido
                
                Sprite sprite3(texture3, rectSourceSprite3);
                sprite3.setPosition({100.f, 30.f});//{x,y}              
                
                Texture texture4;
                if(!texture4.loadFromFile(pokemones[d].imagen)){
                    system("echo No se pudo cargar la textura&&pause");
                    return EXIT_FAILURE;
                }
   
                Vector2u texture4size = texture4.getSize();
                sf::IntRect rectSourceSprite4 ({{0, 0}, {200, 300}});// ← Esto debería ser válido
                
                Sprite sprite4(texture4, rectSourceSprite4);
                sprite4.setPosition({300.f, 30.f});//{x,y}

                renderWindow.draw(sprite3);
                renderWindow.draw(sprite4);
            }
        
        }
        else if(modo==2){

        }
        // Update the window
        renderWindow.display();
    }

    return 0;
}
