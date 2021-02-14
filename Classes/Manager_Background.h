#pragma once


#ifndef __MANAGER_BACKGROUND_H__
#define __MANAGER_BACKGROUND_H__


#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

class Manager_Background
{
public:

    Manager_Background();

    void addSF_Layer(SpriteFrameCache* sf, Layer * layer);

    void addBackground();

    void addParticle();

    void addTable();

    void update(float dt);

    static Manager_Background* get_intances();

    Animation *createAnimation(std::string prefixName, int numberofFrame, float delay);

private:
    static Manager_Background* instances;

    Layer *layer;

    SpriteFrameCache* sf;

    ParticleSystemQuad* particleSystem;

    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

    Animation* animation;


    bool ptscheck = false;

    Sprite * background;

    Sprite * objbg;

    Sprite * table;



};
#endif
