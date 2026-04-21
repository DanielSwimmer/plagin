#include <type_traits>

template <typename It>
bool IsTwiceSequence(It begin, It end)
{
    int count = 0;
    It it = begin;
    while (it != end)
    {
    count++;
    ++it;
    }

    if (count % 2 != 0)
    {
        return false;
    }

    It mid = begin;
    for (int i = 0; i < count / 2; i++)
    {
        ++mid;
    }

    It it1 = begin;
    It it2 = mid;

    while (it2 != end)
    {
        if (*it1 != *it2)
        {
        return false;
        }
        ++it1;
        ++it2;
    }

    return true;
}
