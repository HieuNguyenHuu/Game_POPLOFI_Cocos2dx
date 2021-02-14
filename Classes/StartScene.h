#pragma once

#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "Definition.h"
#include "ActionShake.h"
#include "MenuScene.h"
#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
using namespace CocosDenshion;

USING_NS_CC;

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(StartScene);

    Animation* createAnimation(std::string prefixName, int numberofFrame, float delay) ;

    void update(float dt);

private:

    Size visibleSize;
    Vec2 origin;
    SpriteFrameCache* sf;
    Animation* animation;

    Sprite *  trainright;
    Sprite *  trainleft;

    Sprite * gamelogo;
    Label* text;

    Sprite * character;

    bool check = false;
};
#endif // __START_SCENE_H__