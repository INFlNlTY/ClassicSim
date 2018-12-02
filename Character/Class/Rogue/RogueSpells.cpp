#include "RogueSpells.h"

#include "AdrenalineRush.h"
#include "Backstab.h"
#include "BladeFlurry.h"
#include "Eviscerate.h"
#include "MainhandAttack.h"
#include "OffhandAttackRogue.h"
#include "OffhandMeleeHit.h"
#include "Rogue.h"
#include "SinisterStrike.h"
#include "SliceAndDice.h"

RogueSpells::RogueSpells(Rogue* rogue) :
    Spells(rogue),
    rogue(rogue)
{
    this->mh_attack = new MainhandAttack(rogue);
    this->oh_attack = new OffhandAttackRogue(rogue);
    this->adrenaline_rush = new AdrenalineRush(rogue);
    this->blade_flurry = new BladeFlurry(rogue);
    this->backstab = new Backstab(rogue);
    this->eviscerate = new Eviscerate(rogue);
    this->sinister_strike = new SinisterStrike(rogue);
    this->slice_and_dice = new SliceAndDice(rogue);

    spells.append(mh_attack);
    spells.append(oh_attack);
    spells.append(adrenaline_rush);
    spells.append(blade_flurry);
    spells.append(backstab);
    spells.append(eviscerate);
    spells.append(sinister_strike);
    spells.append(slice_and_dice);
}

RogueSpells::~RogueSpells() = default;

void RogueSpells::oh_auto_attack(const int iteration) {
    if (!oh_attack->attack_is_valid(iteration))
        return;

    if (!pchar->is_melee_attacking())
        return;

    oh_attack->perform();

    add_next_oh_attack();
}

void RogueSpells::add_next_oh_attack() {
    auto* new_event = new OffhandMeleeHit(this, oh_attack->get_next_expected_use(), oh_attack->get_next_iteration());
    rogue->get_engine()->add_event(new_event);
}

OffhandAttack* RogueSpells::get_oh_attack() const {
    return oh_attack;
}

AdrenalineRush* RogueSpells::get_adrenaline_rush() const {
    return this->adrenaline_rush;
}

Backstab* RogueSpells::get_backstab() const {
    return this->backstab;
}

BladeFlurry* RogueSpells::get_blade_flurry() const {
    return this->blade_flurry;
}

Eviscerate* RogueSpells::get_eviscerate() const {
    return this->eviscerate;
}

SinisterStrike* RogueSpells::get_sinister_strike() const {
    return this->sinister_strike;
}

SliceAndDice* RogueSpells::get_slice_and_dice() const {
    return this->slice_and_dice;
}
