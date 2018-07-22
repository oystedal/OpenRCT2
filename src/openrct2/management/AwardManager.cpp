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

#include "AwardManager.h"
#include "../peep/Peep.h"
#include "../scenario/Scenario.h"
#include "../world/Park.h"
#include "Award.h"
#include "NewsItem.h"
#include "UntidyAward.h"

namespace
{

auto available_award_index()
{
   return std::find_if(
        std::begin(gCurrentAwards), std::end(gCurrentAwards),
        [] (const auto& entry) {
            return entry.Time == 0;
        }
    );
}

bool award_is_active(PARK_AWARD award)
{
   return std::find_if(
        std::cbegin(gCurrentAwards), std::cend(gCurrentAwards),
        [&award] (const auto& entry) {
            return entry.Time != 0 && entry.Type == award;
        }
    ) != std::cend(gCurrentAwards);
}

}

AwardManager::AwardManager(
    std::function<bool ()> park_is_open,
    std::function<void (const Award& award)> on_award_granted,
    std::function<void ()> on_award_revoked)
    : on_award_granted_(on_award_granted)
    , on_award_revoked_(on_award_revoked)
{
    constexpr auto len = 1U;
    awards_.reserve(len);

    awards_.push_back(
        std::make_unique<UntidyAward>(
            [] (PARK_AWARD award) {
                for (std::size_t i = 0; i < MAX_AWARDS; i++)
                {
                    return gCurrentAwards[i].Time != 0 && gCurrentAwards[i].Type == award;
                }
                return false;
            },
            [] { return gNumGuestsInPark; },
            [] (auto f) {
                uint16 spriteIndex;
                rct_peep * peep;
                FOR_ALL_GUESTS(spriteIndex, peep)
                {
                    f(peep);
                }
            }
        )
    );
}

void AwardManager::reset()
{
    std::for_each(
        std::begin(gCurrentAwards), std::end(gCurrentAwards),
        [this] (auto& award) {
            award.Time = 0;
            award.Type = 0;
        }
    );
}

void AwardManager::update()
{
    if (!park_is_open())
        return;

    if (auto available_award_slot = available_award_index(); available_award_slot != std::end(gCurrentAwards))
    {
        for (auto& award : awards_)
        {
            // TODO: should pick one random inactive award to check
            if (award->deserved() && !award_is_active(award->type())) {
                available_award_slot->Type = award->type();
                available_award_slot->Time = 5;
                on_award_granted_(*award);
                break;
            }
        }
    }

    // Decrease award times
    std::for_each(
        std::begin(gCurrentAwards), std::end(gCurrentAwards),
        [this] (auto& award) {
            if (award.Time > 0)
            {
                --award.Time;
                if (award.Time == 0)
                    on_award_revoked_();

            }
        }
    );
}

