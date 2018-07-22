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

#include <functional>
#include <memory>
#include "Award.h"

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
        std::function<void (const Award& award)> on_award_granted,
        std::function<void ()> on_award_revoked
    );

    void update();
    void reset();

    std::vector<Award> current_awards() const;
private:
    std::function<void (const Award& award)> on_award_granted_;
    std::function<void ()> on_award_revoked_;
    std::vector<std::unique_ptr<Award>> awards_;
};
