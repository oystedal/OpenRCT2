#include <memory>
#include <functional>
#include "../common.h"
#include "../localisation/StringIds.h"
#include "../peep/Peep.h"
#include "UntidyAward.h"

bool UntidyAward::deserved() const
{
    if (award_is_active_(PARK_AWARD_MOST_BEAUTIFUL))
        return false;
    if (award_is_active_(PARK_AWARD_BEST_STAFF))
        return false;
    if (award_is_active_(PARK_AWARD_MOST_TIDY))
        return false;

    sint32 negativeCount = 0;
    for_each_guest_([&] (rct_peep* peep) {
        if (peep->outside_of_park != 0)
            return;

        if (peep->thoughts[0].freshness > 5)
            return;

        if (peep->thoughts[0].type == PEEP_THOUGHT_TYPE_BAD_LITTER ||
            peep->thoughts[0].type == PEEP_THOUGHT_TYPE_PATH_DISGUSTING ||
            peep->thoughts[0].type == PEEP_THOUGHT_TYPE_VANDALISM)
        {
            negativeCount++;
        }
    });

    return negativeCount > (guest_count_() / 16);
}


