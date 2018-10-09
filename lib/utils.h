#include <iostream>
#include <vector>
#include <string>

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

    std::vector<int> strToVector(std::string s)
    {
        std::vector<int> res;
        if (s.empty())
            return res;

        int i = 0, n = 0, sign = 1;
        char c;

        while (i<s.size() && (!isdigit(s[i]) && s[i]!='-'))
            ++i;

        while (i < s.size()) {
            c = s[i];
            if (isdigit(c)) {
                n = n*10 + c-'0';
            } else if (c == '-') {
                sign = -1;
            } else if (c == ' ' || c == '.') {
                res.push_back(n*sign);
                n = 0;
                sign = 1;
            }
            ++i;
        }

        if (isdigit(s[i-1]))
            res.push_back(n*sign);

        return res;
    }
}
