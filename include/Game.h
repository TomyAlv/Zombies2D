#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "UISounds.h"

using namespace sf;
using namespace std;

class Game {
public:
    Game(int width, int height, const string& title);
        int getScore() const {
        return score;
    }

    void setScore(int newScore) {
        score = newScore;
    }
    ~Game();

    void run();

private:
    void processEvents();
    void update();
    void render();

    RenderWindow window;
    View view;
    Texture playerTexture;
    Texture enemieTexture;
    Texture bulletTexture;
    Texture bloodTexture;
    Texture backgroundTexture;
    Sprite background;

    UISounds uisounds;
    Player player;
    vector<Enemy> enemies;
    vector<Bullet> bulletsPlayer;
    vector<pair<Sprite, float>> bloodEnemies;
    Vector2f bulletPosition;
    Vector2f playerPos;
    Vector2f enemiePos;
    bool live;
    int dist;
    int score;
};

#endif // GAME_H
