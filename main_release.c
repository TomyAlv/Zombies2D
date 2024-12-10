#include "Game.h"
#include "Test.h" // Incluir el archivo de pruebas
#include "tau.h"

//TAU_MAIN()

int main() {
    // Ejecutar las pruebas
    tauRunTests();

    // Ejecutar el juego
    Game game(1000, 650, "Zombies 2D");
    game.run();

    return 0;
}
*/
