#include <iostream>

namespace utils
{
    template<class Val>
    std::ostream& operator<<(std::ostream& os, std::pair<Val,Val>& p)
    {
        return os << "<" << p.first << ", " << p.second << ">";
    }

    template<class Iter>
    void printContainer(Iter start, Iter last)
    {
        while (start != last) {
            std::cout << *start++ << " ";
        }
        std::cout << std::endl;
    }
}
