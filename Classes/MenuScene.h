#pragma once

#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "Definition.h"
#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
using namespace CocosDenshion;

USING_NS_CC;

class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MenuScene);

    void update(float dt);

    void choosetrack();

    Animation* createAnimation(std::string prefixName, int numberofFrame, float delay);
private:
    Size visibleSize;
    Vec2 origin;
    SpriteFrameCache* sf;
    Animation* animation;

    Sprite * w51;
    Sprite * w52;

};
#endif // __MENU_SCENE_H__