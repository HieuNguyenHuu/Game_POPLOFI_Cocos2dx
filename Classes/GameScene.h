#pragma once

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "Definition.h"

#include "Manager_Background.h"

#include "Manager_Character.h"
#include "Manager_Enemy.h"
#include "Manager_Ball.h"

#include "Export.h"
#include "AudioEngine.h"

#include "ActionShake.h"

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
using namespace CocosDenshion;

USING_NS_CC;

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void update(float dt);

	void upbeat(float dt);

    int randomValueBetween(int low, int high);

    //Animation *createAnimation(std::string prefixName, int numberofFrame, float delay);

private:

	Size visibleSize;
	Vec2 origin;

	float secperbeat;

	Layer* gamelayer;
	SpriteFrameCache *  sf_character;

	std::string state = "playgame";

    bool collisionenemyandball = false;
    bool collisioncharacterandball = false;

    bool leftc = false;
    bool rightc = false;

    bool lefte = false;
    bool righte = false;

    bool checkc= false;
    bool checke= false;

    bool dd = false;

    bool hithit = false;

    bool w = false;

	Animation* animation;

};
#endif // __GAME_SCENE_H__
