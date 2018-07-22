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

#include <functional>
#include <memory>
#include "../config/Config.h"
#include "../interface/Window.h"
#include "../localisation/StringIds.h"
#include "../peep/Peep.h"
#include "../scenario/Scenario.h"
#include "../world/Park.h"
#include "Award.h"
#include "AwardManager.h"
#include "NewsItem.h"

AwardGrant gCurrentAwards[MAX_AWARDS];

#define NEGATIVE 0
#define POSITIVE 1

static constexpr const uint8 AwardPositiveMap[] =
{
    NEGATIVE, // PARK_AWARD_MOST_UNTIDY
    POSITIVE, // PARK_AWARD_MOST_TIDY
    POSITIVE, // PARK_AWARD_BEST_ROLLERCOASTERS
    POSITIVE, // PARK_AWARD_BEST_VALUE
    POSITIVE, // PARK_AWARD_MOST_BEAUTIFUL
    NEGATIVE, // PARK_AWARD_WORST_VALUE
    POSITIVE, // PARK_AWARD_SAFEST
    POSITIVE, // PARK_AWARD_BEST_STAFF
    POSITIVE, // PARK_AWARD_BEST_FOOD
    NEGATIVE, // PARK_AWARD_WORST_FOOD
    POSITIVE, // PARK_AWARD_BEST_RESTROOMS
    NEGATIVE, // PARK_AWARD_MOST_DISAPPOINTING
    POSITIVE, // PARK_AWARD_BEST_WATER_RIDES
    POSITIVE, // PARK_AWARD_BEST_CUSTOM_DESIGNED_RIDES
    POSITIVE, // PARK_AWARD_MOST_DAZZLING_RIDE_COLOURS
    NEGATIVE, // PARK_AWARD_MOST_CONFUSING_LAYOUT
    POSITIVE, // PARK_AWARD_BEST_GENTLE_RIDES
};

static constexpr const rct_string_id AwardNewsStrings[] =
{
    STR_NEWS_ITEM_AWARD_MOST_UNTIDY,
    STR_NEWS_ITEM_MOST_TIDY,
    STR_NEWS_ITEM_BEST_ROLLERCOASTERS,
    STR_NEWS_ITEM_BEST_VALUE,
    STR_NEWS_ITEM_MOST_BEAUTIFUL,
    STR_NEWS_ITEM_WORST_VALUE,
    STR_NEWS_ITEM_SAFEST,
    STR_NEWS_ITEM_BEST_STAFF,
    STR_NEWS_ITEM_BEST_FOOD,
    STR_NEWS_ITEM_WORST_FOOD,
    STR_NEWS_ITEM_BEST_RESTROOMS,
    STR_NEWS_ITEM_MOST_DISAPPOINTING,
    STR_NEWS_ITEM_BEST_WATER_RIDES,
    STR_NEWS_ITEM_BEST_CUSTOM_DESIGNED_RIDES,
    STR_NEWS_ITEM_MOST_DAZZLING_RIDE_COLOURS,
    STR_NEWS_ITEM_MOST_CONFUSING_LAYOUT,
    STR_NEWS_ITEM_BEST_GENTLE_RIDES,
};

bool award_is_positive(sint32 type)
{
    return AwardPositiveMap[type];
}

std::unique_ptr<AwardManager> award_manager = std::make_unique<AwardManager>(
    [] { return gParkFlags & PARK_FLAGS_PARK_OPEN; },
    [] (const Award& award) {
        if (gConfigNotifications.park_award)
        {
            news_item_add_to_queue(NEWS_ITEM_AWARD, award.string(), 0);
        }
        window_invalidate_by_class(WC_PARK_INFORMATION);
    },
    [] {
        window_invalidate_by_class(WC_PARK_INFORMATION);
    }
);

void award_reset()
{
    award_manager->reset();
}

void award_update_all()
{
    award_manager->update();
}
