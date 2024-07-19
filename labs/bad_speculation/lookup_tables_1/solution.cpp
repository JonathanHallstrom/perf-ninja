#include "solution.hpp"

#include <cstdint>

static std::size_t mapToBucket(std::size_t v) { // diff
    const static auto vals = [] {
        std::array<std::uint8_t, 100> ret;
        for (int v = 0; v < 100; ++v) {
            if (v >= 0 && v < 13)
                ret[v] = 0;
            else if (v >= 13 && v < 29)
                ret[v] = 1;
            else if (v >= 29 && v < 41)
                ret[v] = 2; // 12
            else if (v >= 41 && v < 53)
                ret[v] = 3; // 12
            else if (v >= 53 && v < 71)
                ret[v] = 4; // 18
            else if (v >= 71 && v < 83)
                ret[v] = 5; // 12
            else if (v >= 83 && v < 100)
                ret[v] = 6; // 17
        }
        return ret;
    }();
    return v < 100 ? vals[v] : -1; // let it crash
}

std::array<std::size_t, NUM_BUCKETS> histogram(const std::vector<int> &values) {
    std::array<std::size_t, NUM_BUCKETS> retBuckets{0};
    for (auto v: values) {
        retBuckets[mapToBucket(v)]++;
    }
    return retBuckets;
}
