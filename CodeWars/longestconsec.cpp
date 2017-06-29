#include <string>
#include <vector>
#include <numeric>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &stringRepository,
                                     int consecutiveLength);
};

std::string LongestConsec::longestConsec(std::vector<std::string> &stringRepository,
                                         int consecutiveLength) {
    size_t REPOSITORY_SIZE = stringRepository.size();
    std::string longestConsecutive;

    if (!REPOSITORY_SIZE || consecutiveLength > REPOSITORY_SIZE ||
        consecutiveLength <= 0) return "";

    for (auto consecutiveShift = consecutiveLength;
          consecutiveShift <= REPOSITORY_SIZE;++consecutiveShift) {
        const auto currentConsecutiveBegin = std::next(stringRepository.begin(),
                                              consecutiveShift - consecutiveLength);
        const auto currentConsecutiveEnd = std::next(currentConsecutiveBegin,
                                           consecutiveLength);
        auto currentConsecutive = std::accumulate(currentConsecutiveBegin,
                             currentConsecutiveEnd, std::string());
        if (longestConsecutive.length() < currentConsecutive.length()) {
      	      longestConsecutive = currentConsecutive;
        }
    }

    return longestConsecutive;
}
