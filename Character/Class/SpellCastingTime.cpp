
#include "SpellCastingTime.h"
#include "CastComplete.h"

SpellCastingTime::SpellCastingTime(const QString& name,
                                   Character* pchar,
                                   bool restricted_by_gcd,
                                   double cooldown,
                                   int resource_cost,
                                   int casting_time) :
    Spell(name, pchar, restricted_by_gcd, cooldown, resource_cost),
    casting_time_ms(casting_time),
    cast_in_progress(false)
{}

void SpellCastingTime::start_cast() {
    auto* new_event = new CastComplete(this, engine->get_current_priority() + get_cast_time());
    this->engine->add_event(new_event);
    cast_in_progress = true;
}

void SpellCastingTime::complete_cast() {
    cast_in_progress = false;
    complete_cast_effect();
}

double SpellCastingTime::get_cast_time() const {
    return double(casting_time_ms) / 1000;
}

bool SpellCastingTime::is_ready_spell_specific() const {
    return !cast_in_progress;
}
