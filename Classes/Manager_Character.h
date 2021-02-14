#pragma once

#ifndef __MANAGER_CHARACTER_H__
#define __MANAGER_CHARACTER_H__

#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

class Manager_Character
{
public:

    Manager_Character();

    void addSF_Layer(SpriteFrameCache* sf, Layer * layer);

    void addCharacter();

    void update(float dt);

    Sprite *getCharacter();

    void anihitmf();

    void aniidle();

    void anihitright();

    void anihitleft();

    static Manager_Character* get_intances();

    Animation *createAnimation(std::string prefixName, int numberofFrame, float delay);

    Animation *createAnimation1(std::string prefixName, int numberofFrame, float delay, int d);

    Animation* createAnimation2(std::string prefixName, int numberofFrame, float delay, int d) ;

    Animation* createAnimation3(std::string prefixName, int numberofFrame, float delay, int numberofBegin) ;

    std::string state = "hitmf";

    std::string character_sf_name;

    bool hit = false;

private:

    bool anihitmfflag = false;

    bool aniidleflag = false;

    bool anihitrightflag = false;

    bool anihitleftflag = false;

    static Manager_Character* instances;

    Layer *layer;

    SpriteFrameCache* sf;

    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

    Animation* animation;

    Sprite * character;

};
#endif
