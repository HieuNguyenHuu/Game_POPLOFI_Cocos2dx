#include "Manager_Enemy.h"

void Manager_Enemy::addSF_Layer(SpriteFrameCache* sf_a, Layer* layer_a)
{
    sf = sf_a;
    layer = layer_a;
}


void Manager_Enemy::addEnemy(std::string a) {
    enemy = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(a));
    enemy->setScale(7);
    enemy->setPosition(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y+ 350));

    layer->addChild(enemy);


    //anihitleft();
}


void Manager_Enemy::update(float dt) {
   /* if(state == "idle"){
        aniidle();
    }
    else if (state == "left"){
        anihitleft();
        state = "idle";
    }
    else if (state == "right"){
        anihitright();
        state = "idle";
    }*/
}

Sprite *Manager_Enemy::getEnemy() {
    return enemy;
}

void Manager_Enemy::anihitmf(std::string a) {
    if (!anihitmfflag) {
        state = "hitmf";
        enemy->stopAllActions();

        auto animation = Manager_Enemy::createAnimation(a, 5, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();

        enemy->runAction(animate);

        anihitmfflag = true;
        aniidleflag = false;
        anihitleftflag = false;
        anihitrightflag = false;
    }
}

void Manager_Enemy::aniidle(std::string a) {
    if (!aniidleflag) {
        enemy->stopAllActions();

        /*auto move1 = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y+ 350));
*/
        auto animation1 = Manager_Enemy::createAnimation1(a, 5, 0.1f, 2);
        auto animate1 = Animate::create(animation1);
        animate1->retain();

        /*uto animation = Manager_Enemy::createAnimation("bg1_enstand", -1, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();

        auto seq =  Sequence::create(move1, animate1, nullptr);*/

        enemy->runAction(animate1);

        //enemy->setSpriteFrame(sf->getSpriteFrameByName("bg1_enstand.png"));

        aniidleflag = true;
        anihitmfflag = false;
        anihitleftflag = false;
        anihitrightflag = false;
    }
}

void Manager_Enemy::anihitleft(std::string a) {
    if(!anihitleftflag){ auto animation = Manager_Enemy::createAnimation(a, 2, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();




        auto move = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x - 150, visibleSize.height/2 + origin.y+ 350));

        auto spawn = Sequence::create( move,animate, nullptr);

        auto move1 = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y+ 350));

        auto animation1 = Manager_Enemy::createAnimation1(a, 5, 0.1f, 2);
        auto animate1 = Animate::create(animation1);
        animate1->retain();

        auto seq =  Sequence::create(spawn, move1, animate1, nullptr);

        enemy->runAction(seq);

        anihitleftflag = true;
        anihitrightflag = false;
        anihitmfflag = false;
        aniidleflag = false;
    }
}

void Manager_Enemy::anihitright(std::string a) {
    if(!anihitrightflag){

        auto animation = Manager_Enemy::createAnimation(a, 2, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();

        auto move = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x + 150, visibleSize.height/2 + origin.y+ 350));

        auto spawn = Sequence::create( move,animate, nullptr);

        auto move1 = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y+ 350));

        auto animation1 = Manager_Enemy::createAnimation1(a, 5, 0.1f, 2);
        auto animate1 = Animate::create(animation1);
        animate1->retain();

        auto seq =  Sequence::create(spawn,move1, animate1, nullptr);

        enemy->runAction(seq);

        anihitrightflag = true;
        anihitleftflag = false;
        anihitmfflag = false;
        aniidleflag = false;
    }
}


Animation* Manager_Enemy::createAnimation(std::string prefixName, int numberofFrame, float delay) {
    Vector<SpriteFrame*> animFrames;
    if (numberofFrame == -1){
        char buffer[30] = { 0 };
        sprintf(buffer, ".png");
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    else {
        for (int i = 0; i <= numberofFrame; i++) {
            char buffer[30] = {0};
            sprintf(buffer, "%d.png", i);
            std::string str = prefixName + buffer;
            auto frame = sf->getSpriteFrameByName(str);
            animFrames.pushBack(frame);
        }
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}
Animation* Manager_Enemy::createAnimation1(std::string prefixName, int numberofFrame, float delay, int numberofBegin) {
    Vector<SpriteFrame*> animFrames;
        for (int i =  numberofBegin; i <= numberofFrame; i++) {
            char buffer[30] = {0};
            sprintf(buffer, "%d.png", i);
            std::string str = prefixName + buffer;
            auto frame = sf->getSpriteFrameByName(str);
            animFrames.pushBack(frame);
        }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}

Manager_Enemy* Manager_Enemy::instances = nullptr;

Manager_Enemy * Manager_Enemy::get_intances()
{
    if (instances == nullptr) {
        instances = new Manager_Enemy();
    }
    return instances;
}

Manager_Enemy::Manager_Enemy() {
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}








