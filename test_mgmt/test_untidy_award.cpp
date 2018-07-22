#include <gtest/gtest.h>
#include "UntidyAward.h"

class UntidyAwardTest : public testing::Test
{
public:
    UntidyAwardTest()
        : award(
            [this] (auto award) {
                return active_awards.find(award) != active_awards.end(); 
            },
            [this] { return num_guests; },
            [this] (auto f) 
            {
                for (auto& peep : peeps) {
                    f(&peep);
                }
            }
         )
       , num_guests(0)
       {
           peeps.reserve(3);
       }

    rct_peep& add_guest()
    {
        peeps.emplace_back();
        return peeps.back();
    }

protected:
    UntidyAward award;
    std::set<PARK_AWARD> active_awards;
    int num_guests;
    std::vector<rct_peep> peeps;
};

struct TestCase
{
    int num_guests;
    std::initializer_list<PARK_AWARD> active_awards;
    struct peep {
        PEEP_THOUGHT_TYPE thought;
        int thought_freshness;
        enum class disposition {
            inside_park,
            outside_park,
        } park_disposition;

        constexpr peep(PEEP_THOUGHT_TYPE t, int freshness, disposition disp)
            : thought(t)
            , thought_freshness(freshness)
            , park_disposition(disp)
        {

        };

        constexpr peep(PEEP_THOUGHT_TYPE t) 
            : thought(t)
            , thought_freshness(0)
            , park_disposition(disposition::inside_park)
        {

        };

    };
    std::initializer_list<peep> peeps;
    bool result;
};

using disposition = TestCase::peep::disposition;
constexpr const auto bad_litter = PEEP_THOUGHT_TYPE_BAD_LITTER;
constexpr const auto path_disgusting = PEEP_THOUGHT_TYPE_PATH_DISGUSTING;
constexpr const auto vandalism = PEEP_THOUGHT_TYPE_VANDALISM;
constexpr const std::initializer_list<PARK_AWARD> no_awards = {};

constexpr const std::initializer_list<TestCase> cases = {
    // No thoughts
    {0, no_awards, {}, false},
    {15, no_awards, {}, false},
    {16, no_awards, {}, false},
    {31, no_awards, {}, false},
    {32, no_awards, {}, false},

    // bad litter thoughts
    {0, no_awards, {bad_litter}, true},
    {15, no_awards, {bad_litter}, true},
    {16, no_awards, {bad_litter}, false},
    {16, no_awards, {bad_litter, bad_litter}, true},
    {31, no_awards, {bad_litter, bad_litter}, true},
    {32, no_awards, {bad_litter, bad_litter}, false},
    {32, no_awards, {bad_litter, bad_litter, bad_litter}, true},

    // path disgusting thoughts
    {0, no_awards, {path_disgusting}, true},
    {15, no_awards, {path_disgusting}, true},
    {16, no_awards, {path_disgusting}, false},
    {16, no_awards, {path_disgusting, path_disgusting}, true},
    {31, no_awards, {path_disgusting, path_disgusting}, true},
    {32, no_awards, {path_disgusting, path_disgusting}, false},
    {32, no_awards, {path_disgusting, path_disgusting, path_disgusting}, true},

    // vandalism thoughts
    {0, no_awards, {vandalism}, true},
    {15, no_awards, {vandalism}, true},
    {16, no_awards, {vandalism}, false},
    {16, no_awards, {vandalism, vandalism}, true},
    {31, no_awards, {vandalism, vandalism}, true},
    {32, no_awards, {vandalism, vandalism}, false},
    {32, no_awards, {vandalism, vandalism, vandalism}, true},

    // accept combinations of thoughts
    {16, no_awards, {bad_litter, vandalism}, true},
    {16, no_awards, {path_disgusting, vandalism}, true},
    {16, no_awards, {path_disgusting, bad_litter}, true},

    // ignore when these awards are active
    {15, {PARK_AWARD_MOST_TIDY}, {bad_litter}, false},
    {15, {PARK_AWARD_BEST_STAFF}, {bad_litter}, false},
    {15, {PARK_AWARD_MOST_BEAUTIFUL}, {bad_litter}, false},

    // thought freshness = 0
    {15, no_awards, {{bad_litter, 0, disposition::inside_park}}, true},
    {15, no_awards, {{path_disgusting, 0, disposition::inside_park}}, true},
    {15, no_awards, {{vandalism, 0, disposition::inside_park}}, true},

    // thought freshness = 5
    {15, no_awards, {{bad_litter, 5, disposition::inside_park}}, true},
    {15, no_awards, {{path_disgusting, 5, disposition::inside_park}}, true},
    {15, no_awards, {{vandalism, 5, disposition::inside_park}}, true},

    // thought freshness = 6
    {15, no_awards, {{bad_litter, 6, disposition::inside_park}}, false},
    {15, no_awards, {{path_disgusting, 6, disposition::inside_park}}, false},
    {15, no_awards, {{vandalism, 6, disposition::inside_park}}, false},

    // outside park
    {15, no_awards, {{bad_litter, 0, disposition::outside_park}}, false},
    {15, no_awards, {{path_disgusting, 0, disposition::outside_park}}, false},
    {15, no_awards, {{vandalism, 0, disposition::outside_park}}, false},
};

TEST_F(UntidyAwardTest, untidy_award_table_tests)
{
    for (const auto& test_case : cases)
    {
        active_awards = test_case.active_awards;
        peeps.clear();
        for (const auto& peep : test_case.peeps)
        {
            auto& guest = add_guest();
            guest.thoughts[0].type = peep.thought;
            guest.thoughts[0].freshness = peep.thought_freshness;
            guest.outside_of_park = 
                peep.park_disposition == disposition::outside_park ? 1 : 0;
        }
        num_guests = test_case.num_guests;
        ASSERT_EQ(award.deserved(), test_case.result);
    }
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
