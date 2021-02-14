#pragma once

#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"
#include "Definition.h"
#include "Manager_Character.h"
#include "Manager_Enemy.h"

USING_NS_CC;

class Manager_Ball
{
public:

    Manager_Ball();

    void addSF_Layer(SpriteFrameCache* sf, Layer * layer);

    void update(float dt);

    void addBall();

    Sprite* getBall();

    static Manager_Ball* get_intances();

    Animation *createAnimation(std::string prefixName, int numberofFrame, float delay);
private:
    static Manager_Ball* instances;

    Layer *layer;

    SpriteFrameCache* sf;

    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

    Animation* animation;

    Sprite * ball;

    bool moveballflag = false;

};
#endif
