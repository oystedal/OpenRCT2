#pragma once

#include "Award.h"
#include "AwardManager.h"

class UntidyAward final : public Award {
public:
    UntidyAward(
        std::function<bool (PARK_AWARD)> award_is_active,
        std::function<int ()> guest_count,
        std::function<void (std::function<void (rct_peep*)>)> for_each_guest
    ) : award_is_active_(award_is_active)
      , guest_count_(guest_count)
      , for_each_guest_(for_each_guest)
    {

    }

    bool positive() const override
    {
        return false;
    }

    PARK_AWARD type() const override
    {
        return PARK_AWARD_MOST_UNTIDY;
    }

    rct_string_id string() const override
    {
        return STR_NEWS_ITEM_AWARD_MOST_UNTIDY;
    }

    bool deserved() const override;

private:
    std::function<bool (PARK_AWARD)> award_is_active_;
    std::function<int ()> guest_count_;
    std::function<void (std::function<void (rct_peep*)>)> for_each_guest_;
};

