#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#pragma once

#include <memory>
#include <functional>
#include "../common.h"
#include "../localisation/StringIds.h"
#include "../peep/Peep.h"

enum PARK_AWARD
{
    PARK_AWARD_MOST_UNTIDY,
    PARK_AWARD_MOST_TIDY,
    PARK_AWARD_BEST_ROLLERCOASTERS,
    PARK_AWARD_BEST_VALUE,
    PARK_AWARD_MOST_BEAUTIFUL,
    PARK_AWARD_WORST_VALUE,
    PARK_AWARD_SAFEST,
    PARK_AWARD_BEST_STAFF,
    PARK_AWARD_BEST_FOOD,
    PARK_AWARD_WORST_FOOD,
    PARK_AWARD_BEST_RESTROOMS,
    PARK_AWARD_MOST_DISAPPOINTING,
    PARK_AWARD_BEST_WATER_RIDES,
    PARK_AWARD_BEST_CUSTOM_DESIGNED_RIDES,
    PARK_AWARD_MOST_DAZZLING_RIDE_COLOURS,
    PARK_AWARD_MOST_CONFUSING_LAYOUT,
    PARK_AWARD_BEST_GENTLE_RIDES,
    PARK_AWARD_COUNT
};

struct AwardGrant
{
    uint16 Time;
    uint16 Type;
};

class Award
{
public:
    virtual ~Award() = default;
    virtual bool positive() const = 0;
    virtual bool deserved() const = 0;
    virtual PARK_AWARD type() const = 0;
    virtual rct_string_id string() const = 0;
};

class AwardManager
{
public:
    AwardManager(
        std::function<bool ()> park_is_open,
        std::function<void (Award* award)> on_award_granted,
        std::function<void ()> on_award_revoked
    );

    void update();
    void reset();

    std::vector<Award> current_awards() const;
private:
    std::function<void (Award* award)> on_award_granted_;
    std::function<void ()> on_award_revoked_;
    std::vector<Award*> awards_;
};

#define MAX_AWARDS 4

extern AwardGrant gCurrentAwards[MAX_AWARDS];

bool award_is_positive(sint32 type);
void award_reset();
void award_update_all();
