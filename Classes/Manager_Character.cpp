#include "Manager_Character.h"

void Manager_Character::addSF_Layer(SpriteFrameCache* sf_a, Layer* layer_a)
{
    sf = sf_a;
    layer = layer_a;
}


void Manager_Character::addCharacter() {
    character = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(CHARACTER_STAND));
    character->setScale(7);
    character->setPosition(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300));

    layer->addChild(character);

    //aniidle();
}


void Manager_Character::update(float dt) {

}

Sprite *Manager_Character::getCharacter() {
    return character;
}

void Manager_Character::anihitmf() {
    if (!anihitmfflag){
        character->stopAllActions();

        auto animation = Manager_Character::createAnimation("sPlayerBotHitLeft_", 5, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();
        auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
        auto animatesss = Animate::create(animationsss);
        animatesss->retain();

        auto seq = Sequence::create(animate, animatesss, nullptr);

        character->runAction(seq);

        anihitmfflag = true;
        aniidleflag = false;
        anihitleftflag = false;
        anihitrightflag = false;
    }
}

void Manager_Character::aniidle() {
    if (!aniidleflag) {
        state = "idle";

        log("cc state = idle");
        //character->stopAllActions();

       /*auto animation1 = Manager_Character::createAnimation3("sPlayerBotHitLeft_", 5, 0.1f, 2);
        auto animate1 = Animate::create(animation1);
        animate1->retain();*/

        //auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
        //auto animatesss = Animate::create(animationsss);
        //animatesss->retain();

        /*uto animation = Manager_Enemy::createAnimation("bg1_enstand", -1, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();*/



        //character->runAction(animatesss);
       /* character->stopAllActions();

        auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
        auto animatesss = Animate::create(animationsss);
        animatesss->retain();

        auto moves = MoveTo::create(60.0f / MUSIC1_BPM / 2 ,(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300)));

       auto spaw1 = Sequence::create( moves, animatesss, nullptr);

       character->runAction(spaw1);*/

        aniidleflag = true;
        anihitmfflag = false;
        anihitleftflag = false;
        anihitrightflag = false;
    }
}

void Manager_Character::anihitright() {
   if (!anihitrightflag) {
       state = "right";

       auto animation = Manager_Character::createAnimation("sPlayerBotHitLeft_", 2, 0.1f);
       auto animate = Animate::create(animation);
       animate->retain();

       auto move = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x + 200, visibleSize.height/2 + origin.y-300));

       auto spawn = Sequence::create( move,animate, nullptr);

       auto move1 = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y -300));

       auto animation1 = Manager_Character::createAnimation3("sPlayerBotHitLeft_", 4, 0.1f, 2);
       auto animate1 = Animate::create(animation1);
       animate1->retain();
       auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
       auto animatesss = Animate::create(animationsss);
       animatesss->retain();

       auto seq =  Sequence::create(spawn, move1, animate1, animatesss, nullptr);

       character->runAction(seq);

       anihitleftflag =false;
       anihitrightflag = true;
       anihitmfflag = false;
       aniidleflag = false;

       /* character->stopAllActions();

        auto animation = Manager_Character::createAnimation1("sPlayerBotHitRight_", 5, 0.1f, 2);
        auto animate = Animate::create(animation);
        animate->retain();

        auto move = MoveTo::create(60.0f / MUSIC1_BPM /8  ,(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300) + Vec2(200,0)));

        auto spaw = Spawn::create(move, animate, nullptr);

       auto animation1 = Manager_Character::createAnimation1("sPlayerBotHitRight_", 2, 0.1f, 0);
       auto animate1 = Animate::create(animation1);
       animate1->retain();

       auto seq = Sequence::create(spaw, animate1, nullptr);

       auto animation2 = Manager_Character::createAnimation2("sPlayerBotHitRight_", 5, 0.1f, 2);
       auto animate2 = Animate::create(animation2);
       animate2->retain();

       auto seq1 = Sequence::create(seq, animate2, nullptr);

       auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
       auto animatesss = Animate::create(animationsss);
       animatesss->retain();

       auto moves = MoveTo::create(60.0f / MUSIC1_BPM /8 ,(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300)));

       auto spaw1 = Sequence::create(seq1, moves, animatesss, nullptr);

       character->runAction(spaw1);


        anihitrightflag = true;
        anihitleftflag = false;
       anihitmfflag = false;
       //aniidleflag = false;*/
   }
}

void Manager_Character::anihitleft() {
    if (!anihitleftflag) {
        state = "left";
        auto animation = Manager_Character::createAnimation("sPlayerBotHitRight_", 2, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();

        auto move = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x - 200, visibleSize.height/2 + origin.y-300));

        auto spawn = Sequence::create( move,animate, nullptr);

        auto move1 = MoveTo::create(0.1f, Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y-300));

        auto animation1 = Manager_Character::createAnimation3("sPlayerBotHitRight_", 4, 0.1f, 2);
        auto animate1 = Animate::create(animation1);
        animate1->retain();
        auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
        auto animatesss = Animate::create(animationsss);
        animatesss->retain();

        auto seq =  Sequence::create(spawn, move1, animate1, animatesss, nullptr);

        character->runAction(seq);

        anihitleftflag = true;
        anihitrightflag = false;
        anihitmfflag = false;
        aniidleflag = false;

       /* character->stopAllActions();

        auto animation = Manager_Character::createAnimation1("sPlayerBotHitLeft_", 5, 0.1f, 2);
        auto animate = Animate::create(animation);
        animate->retain();

        auto move = MoveTo::create(60.0f / MUSIC1_BPM /8 ,(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300) - Vec2(200,0)));

        auto spaw = Spawn::create(move, animate, nullptr);

        auto animation1 = Manager_Character::createAnimation1("sPlayerBotHitLeft_", 2, 0.1f, 0);
        auto animate1 = Animate::create(animation1);
        animate1->retain();

        auto seq = Sequence::create(spaw, animate1, nullptr);

        auto animation2 = Manager_Character::createAnimation2("sPlayerBotHitLeft_", 5, 0.1f, 2);
        auto animate2 = Animate::create(animation2);
        animate2->retain();

        auto seq1 = Sequence::create(seq, animate2, nullptr);

        auto animationsss = Manager_Character::createAnimation("sPlayerBotStand_", 0, 0.1f);
        auto animatesss = Animate::create(animationsss);
        animatesss->retain();

        auto moves = MoveTo::create(60.0f / MUSIC1_BPM / 8 ,(Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300)));

        auto spaw1 = Sequence::create(seq1, moves, animatesss, nullptr);

        character->runAction(spaw1);



         anihitleftflag = true;
        anihitrightflag = false;
        anihitmfflag = false;
       // aniidleflag = false;*/
    }
}


Animation* Manager_Character::createAnimation(std::string prefixName, int numberofFrame, float delay) {
    Vector<SpriteFrame*> animFrames;
    for (int i = 0; i <= numberofFrame; i++) {
        char buffer[30] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        if((str == "sPlayerBotHitRight_0.png") || (str == "sPlayerBotHitLeft_0.png")){
            hit = true;
            log("cc hit");
        }
        else hit = false;
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}
Animation* Manager_Character::createAnimation1(std::string prefixName, int numberofFrame, float delay, int d) {
    Vector<SpriteFrame*> animFrames;
    for (int i = numberofFrame; i  >= d; i--) {
        char buffer[30] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}

Animation* Manager_Character::createAnimation3(std::string prefixName, int numberofFrame, float delay, int numberofBegin) {
    Vector<SpriteFrame*> animFrames;
    for (int i =  numberofBegin; i <= numberofFrame; i++) {
        char buffer[30] = {0};
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
        if((str == "sPlayerBotHitRight_0.png") || (str == "sPlayerBotHitLeft_0.png")){
            hit = true;
            log("cc hit");
        }
        else hit = false;
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}

Animation* Manager_Character::createAnimation2(std::string prefixName, int numberofFrame, float delay, int d) {
    Vector<SpriteFrame*> animFrames;
    for (int i = d; i  <= numberofFrame; i++) {
        char buffer[30] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}

Manager_Character* Manager_Character::instances = nullptr;

Manager_Character * Manager_Character::get_intances()
{
    if (instances == nullptr) {
        instances = new Manager_Character();
    }
    return instances;
}

Manager_Character::Manager_Character() {
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}









