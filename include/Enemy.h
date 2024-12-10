#ifndef ENEMY_H
#define ENEMY_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Enemy : public Drawable
{
    private:
        Sprite sprite;
        bool active;
        float vel;
        int life;
        int dist;
        void Movement(Vector2f);
        void Aim(Vector2f);
    public:
        Enemy(Vector2f, Texture&);
        void Update(Vector2f, int);
        Vector2f GetPosition();
        void TakeLife();
        int ConsultLife();
        virtual void draw(RenderTarget&,RenderStates) const;

};

#endif // ENEMY_H
