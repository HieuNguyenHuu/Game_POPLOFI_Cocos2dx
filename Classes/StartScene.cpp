#include "StartScene.h"

Scene * StartScene::createScene()
{
    return StartScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool StartScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_BG, false);

    sf = SpriteFrameCache::getInstance();
    sf->addSpriteFramesWithFile(TEXTURE_PLIST, TEXTURE_PNG);

    auto bg = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START));
    bg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    bg->setScale(8);
    this->addChild(bg);

    trainright = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_OBJECT_TRAINRIGHT));
    trainright->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    trainright->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height/2 + origin.y));
    trainright->setScale(8);
    this->addChild(trainright);


    character = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_CHARACTER_SIT));
    character->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    character->setScale(8);
    this->addChild(character);
    auto animation = StartScene::createAnimation(BG_START_CHARACTER_SITTEXT_ANIMATION_6, 6, 0.2f);
    auto animate = Animate::create(animation);
    animate->retain();
    character->runAction(RepeatForever::create(animate));


    trainleft = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_OBJECT_TRAINLEFT));
    trainleft->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    trainleft->setPosition(Vec2(0, visibleSize.height/2 + origin.y));
    trainleft->setScale(8);
    this->addChild(trainleft);

    auto signbadel = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_OBJECT_SIGNPOST));
    signbadel->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 400));
    signbadel->setScale(8);
    this->addChild(signbadel);


    auto signsign = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_OBJECT_SIGNSIGN));
    signsign->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 350));
    signsign->setScale(8);
    this->addChild( signsign);
    auto animation1 = StartScene::createAnimation(BG_START_OBJECT_SIGNSIGN_ANIMATION_5, 5, 0.5f);
    auto animate1 = Animate::create(animation1);
    animate1->retain();
    signsign->runAction(RepeatForever::create(animate1));


    gamelogo = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_LOGO));
    gamelogo->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 900));
    gamelogo->setScale(2.8);
    this->addChild(gamelogo);
    gamelogo->runAction(MoveTo::create(0.5f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 180)));

    text = Label::createWithTTF("click to continue . . .", "fonts/pixelcyr.ttf", 64);
    text->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 470));
    this->addChild(text);


    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = [&](Touch* touch, Event* event){

        /*float duration = 0.8f;
        float speed = 6.0f;
        float magnitude = 2.f;
        trainleft->runAction(RepeatForever::create(ActionShake::create(duration,speed,magnitude)));*/

        text->runAction(MoveTo::create(0.4f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 600)));
        gamelogo->runAction(MoveTo::create(0.4f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 900)));

        return true;
    };

    listener->onTouchMoved = [&](Touch* touch, Event* event){

    };
    listener->onTouchEnded = [&](Touch* touch, Event* event){

        auto dtime = DelayTime::create(0.5f);

        auto lightroom = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_START_OBJECT_DOORLIGHT));
        lightroom->setScale(8);
        lightroom->setPosition(500, character->getPosition().y-20);
        this->addChild(lightroom);
        auto animation = StartScene::createAnimation(BG_START_OBJECT_DOORLIGHT_ANIMATION_13, 13, 0.2f);
        auto animate = Animate::create(animation);
        animate->retain();
        lightroom->runAction( RepeatForever::create(animate));

        character->stopAllActions();
        auto animation1 = StartScene::createAnimation(BG_START_CHARACTER_BOTRUNLEFT_ANIMATION_7, 0, 0.2f);
        auto animate1 = Animate::create(animation1);
        animate1->retain();
        character->stopAllActions();
        auto animation2 = StartScene::createAnimation(BG_START_CHARACTER_BOTRUNLEFT_ANIMATION_7, 7, 0.2f);
        auto animate2 = Animate::create(animation2);
        animate2->retain();
        character->runAction(Sequence::create(dtime, animate1, Spawn::create(MoveTo::create(1.8f, Vec2(200, character->getPosition().y -20))
                ,animate2, nullptr), nullptr));

        check = true;
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();

    return true;
}

void StartScene::update(float dt){
    if (check){
        if(character->getPosition().x == 200){
            check = false;
            Scene* scene = MenuScene::createScene();
            auto transition = TransitionSlideInL::create(SCENE_TRANSITION_TIME, scene);
            Director::getInstance()->replaceScene(transition);
        }
    }
}


Animation* StartScene::createAnimation(std::string prefixName, int numberofFrame, float delay) {
    Vector<SpriteFrame*> animFrames;
    for (int i = 0; i <= numberofFrame; i++) {
        char buffer[30] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}