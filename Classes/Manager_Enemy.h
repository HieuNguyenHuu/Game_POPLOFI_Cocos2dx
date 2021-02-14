#pragma once

#ifndef __MANAGER_ENEMY_H__
#define __MANAGER_ENEMY_H__

#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

class Manager_Enemy
{
public:

   Manager_Enemy();

    void addSF_Layer(SpriteFrameCache* sf, Layer * layer);

    void addEnemy(std::string a);

    void update(float dt);

    Sprite* getEnemy();

    void anihitmf(std::string a);

    void anihitleft(std::string a);

    void anihitright(std::string a);

    void aniidle(std::string a);

    static Manager_Enemy* get_intances();

    Animation *createAnimation(std::string prefixName, int numberofFrame, float delay);

    Animation* createAnimation1(std::string prefixName, int numberofFrame, float delay, int numberofBegin);

    std::string state = "idle";


private:

    bool anihitleftflag = false;

    bool anihitrightflag = false;

    bool anihitmfflag = false;

    bool aniidleflag = false;

    static Manager_Enemy* instances;

    Layer *layer;

    SpriteFrameCache* sf;

    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

    Animation* animation;

    Sprite * enemy;



};
#endif
