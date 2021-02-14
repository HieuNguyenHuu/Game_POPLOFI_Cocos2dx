#include "MenuScene.h"

Scene * MenuScene::createScene()
{
    return MenuScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool MenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();

    sf = SpriteFrameCache::getInstance();
    sf->addSpriteFramesWithFile(TEXTURE_PLIST, TEXTURE_PNG);

    auto w53 = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_MENU_WAIT_1));
    w53->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    w53->setScale(8);
    this->addChild(w53);

    w51 = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_MENU_WAIT_5));
    w51->setPosition(Vec2(0, visibleSize.height/2 + origin.y));
    w51->setScale(6);
    w51->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    this->addChild(w51);

    auto cbg = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_MENU_TRAIN));
    cbg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 100));
    cbg->setScale(8);
    this->addChild(cbg);
    auto animation = MenuScene::createAnimation(BG_MENU_TRAIN_ANIMATION_7, 7, 0.1f);
    auto animate = Animate::create(animation);
    animate->retain();
    cbg->runAction(RepeatForever::create(animate));


    auto phone = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG_PHONE));
    phone->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y + 800));
    phone->setScale(9);
    this->addChild(phone);
    phone->runAction(MoveTo::create(0.5f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y )));

    //if (phone->getPosition() == Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y )) {
        auto item1label = Label::createWithTTF("choose track", "fonts/pixelcyr.ttf", 64);
        auto item1 = MenuItemLabel::create(item1label, CC_CALLBACK_0(MenuScene::choosetrack, this));

        auto item2label = Label::createWithTTF("setting", "fonts/pixelcyr.ttf", 64);
        auto item2 = MenuItemLabel::create(item2label, CC_CALLBACK_0(MenuScene::choosetrack, this));

        auto menu = Menu::create(item1, item2, NULL);
        menu->setPosition(
                Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(menu, 10);
   // }


    this->scheduleUpdate();

    return true;
}

void MenuScene::choosetrack() {
    log("ct");
}


void MenuScene::update(float dt){

    /*w51->setPositionX(w51->getPositionX() +
                              (SCROLLING_BACKGROUND_SPEED*visibleSize.width));
    w52->setPositionX(w52->getPositionX() +
                              (SCROLLING_BACKGROUND_SPEED*visibleSize.width));

    if (w51->getPositionX() <= -w51->getContentSize().height)
    {
        w51->setPositionX(w52->getPositionX() +
                                  w52->getContentSize().height);
    }

    if (w52->getPositionX() <= -w52->getContentSize().height)
    {
        w52->setPositionX(w51->getPositionX() +
                                  w51->getContentSize().height);
    }*/
    /*w51->setPositionX(w51->getPositionX() -
                              -(SCROLLING_BACKGROUND_SPEED*visibleSize.width));
    /*w52->setPositionX(w52->getPositionX() -(SCROLLING_BACKGROUND_SPEED*visibleSize.width));

    if (w51->getPositionX() <= -w51->getContentSize().height)
    {
        w51->setPositionX(w52->getPositionX() +
                                  w52->getContentSize().height);
    }

    if (w52->getPositionX() <= -w52->getContentSize().height)
    {
        w52->setPositionX(w51->getPositionX() +
                                  w51->getContentSize().height);
    }*/
}



Animation* MenuScene::createAnimation(std::string prefixName, int numberofFrame, float delay) {
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