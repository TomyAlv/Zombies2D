// main_debug.cpp
#include "tau.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
//#include <SFML/Graphics.hpp>

using namespace sf;

// Entrada principal de TAU
TAU_MAIN()

TEST(Bullet, ConstructorYMetodos)
{
    Texture texture;
    texture.create(10, 10); // Textura ficticia para pruebas
    Bullet bullet(Vector2f(0, 0), Vector2f(1, 0), 0, texture);

    CHECK(bullet.GetPosition() == Vector2f(0, 0));

    bullet.Update();
    CHECK(bullet.GetPosition() == Vector2f(10, 0));
}

