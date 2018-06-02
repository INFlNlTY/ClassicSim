
#include "ExtraAttackOnNextSwingBuff.h"
#include "Character.h"
#include "Buffs.h"
#include "Procs.h"
#include "ExtraAttackInstantProc.h"

ExtraAttackOnNextSwingBuff::ExtraAttackOnNextSwingBuff(Character* pchar,
                                                       ExtraAttackInstantProc* extra_attack,
                                                       const int num_attacks):
    Buff(pchar, "ExtraAttackOnSwing", 300, num_attacks),
    extra_attack(extra_attack)
{}

void ExtraAttackOnNextSwingBuff::buff_effect_when_applied() {
    pchar->get_procs()->add_proc_effect(extra_attack);
}

void ExtraAttackOnNextSwingBuff::buff_effect_when_removed() {
    pchar->get_procs()->remove_proc_effect(extra_attack);
}