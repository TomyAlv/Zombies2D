#include "Enemy.h"

Enemy::Enemy(Vector2f pos, Texture &texture){
    sprite.setTexture(texture);
    sprite.setScale(0.35,0.35);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(pos);
    vel=1.5;
    life=100;
    active=false;
}

void Enemy::Update(Vector2f posPlayer,int dista){
    dist=dista;
    Movement(posPlayer);
    Aim(posPlayer);
}

void Enemy::Movement(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    Vector2f dirNorm = Vector2f(dir.x/sqrt(pow(dir.x,2)+pow(dir.y,2)),dir.y/sqrt(pow(dir.x,2)+pow(dir.y,2)));
    if(abs(dir.x)+abs(dir.y)<=dist||active) sprite.move(dirNorm.x*vel,dirNorm.y*vel);
}

void Enemy::Aim(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    if(abs(dir.x)+abs(dir.y)<=dist||active) sprite.setRotation(atan2(posPlayer.y-sprite.getPosition().y,posPlayer.x-sprite.getPosition().x)*180/3.14159265f);
}

void Enemy::TakeLife(){
    life-=20;
    active=true;
}

int Enemy::ConsultLife(){
    return life;
}
Vector2f Enemy::GetPosition(){
    return sprite.getPosition();
}

void Enemy::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite,rs);
}
