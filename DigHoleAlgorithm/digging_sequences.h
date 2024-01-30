#ifndef SUDOKUGENERATORDIGHOLE_DIGGING_SEQUENCES_H
#define SUDOKUGENERATORDIGHOLE_DIGGING_SEQUENCES_H

#include "../sudokuboard.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <random>

namespace DiggingSequences {

    std::vector<std::pair<int, int>> randomized_sequence(std::mt19937& gen);

    std::vector<std::pair<int, int>> left_to_right_sequence(std::mt19937& gen);

    std::vector<std::pair<int, int>> wandering_along_S(std::mt19937& gen);

    std::vector<std::pair<int, int>> jumping_one_cell();

};
#endif //SUDOKUGENERATORDIGHOLE_DIGGING_SEQUENCES_H
