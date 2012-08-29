#include "MonsterAttackEvent.h"
#include "GameController.h"
#include "UserInterface.h"
#include "Player.h"
#include "Monster.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include <sstream>

MonsterAttackEvent::MonsterAttackEvent(GameController *game,
                                       UserInterface *gui,
                                       Player *player, Monster *monster) {
    this->game = game;
    this->gui = gui;
    this->player = player;
    this->monster = monster;

    this->executed = false;
}

MonsterAttackEvent::~MonsterAttackEvent() {

}

bool MonsterAttackEvent::hasFinished() {
    return executed;
}

bool MonsterAttackEvent::isBlocking() {
    return true;
}

void MonsterAttackEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    audioSystem->playSound("AttackName", 0);

    AttackFeedback feedback = monster->attack(player);

    AttackAnimationEvent *nameEvent = new AttackAnimationEvent();

    std::stringstream textMonster;
    textMonster << feedback.result.attackName;

    Vector textPosition =
        monster->getWorldPosition(0.0);
    textPosition =
        textPosition.translate(Vector(0.0, 1.15 * MONSTER_SIZE, 0.0));

    Animation *animation =
        new TextAnimation(textPosition,
                          textMonster.str(),
                          ALIGN_CENTER,
                          true);
    nameEvent->addAnimation(animation);
    gui->attachAnimation(animation);

    Event *event = new SetTooltipVisibilityEvent(gui, true, true);
    game->queueFrontEvent(event);

    event = new PlayerDamageEvent(game, gui, player, feedback);
    game->queueFrontEvent(event);
    
    game->queueFrontEvent(nameEvent);

    event = new SetTooltipVisibilityEvent(gui, false, true);
    game->queueFrontEvent(event);

    executed = true;
}

void MonsterAttackEvent::update(double dt) {

}

bool MonsterAttackEvent::wasExecuted() {
    return executed;
}
