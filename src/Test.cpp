#include "tau.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

TAU_MAIN()

TEST(Bullet, ConstructorYMetodos)
{
    Texture texture;
    texture.create(10, 10);
    Bullet bullet(Vector2f(0, 0), Vector2f(1, 0), 0, texture);

    CHECK(bullet.GetPosition() == Vector2f(0, 0));

    bullet.Update();
    CHECK(bullet.GetPosition() == Vector2f(10, 0));
}

TEST(Enemy, ConstructorYMetodos)
{
    Texture texture;
    texture.create(10, 10);
    Enemy enemy(Vector2f(100, 100), texture);

    CHECK(enemy.GetPosition() == Vector2f(100, 100));

    enemy.Update(Vector2f(110, 110), 20);
    CHECK(enemy.GetPosition() != Vector2f(100, 100));

    int initialLife = enemy.ConsultLife();
    enemy.TakeLife();
    CHECK(enemy.ConsultLife() == initialLife - 20);
}

TEST(Player, ConstructorYDisparo)
{
    Texture texture;
    texture.create(250, 250);
    Player player(texture);

    CHECK(player.GetPosition() == Vector2f(0, 0));

    RenderWindow window(VideoMode(800, 600), "Test Window");
    auto shoot = player.AnswerShoot(window);
    CHECK(!shoot.first);
}


TEST(Game, Inicializacion)
{
    Game game(800, 600, "Test Game");

    CHECK(game.getScore() == 0);
}


TEST(Game, Puntaje)
{
    Game game(800, 600, "Test Game");
    CHECK(game.getScore() == 0);

    game.setScore(100);
    CHECK(game.getScore() == 100);
}

TEST(Game, Excepciones)
{
    try {
        throw "Excepcion de prueba";
        CHECK(false);
    } catch (const char* e) {
        CHECK(std::string(e) == "Excepcion de prueba");
    }
}
