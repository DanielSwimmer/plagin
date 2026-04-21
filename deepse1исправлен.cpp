#include <type_traits>

template<typename Iterator>
bool IsTwiceSequence(Iterator first, Iterator last) {
    
    Iterator temp = first; 
    int length = 0; 
    
    while (temp != last) {
        length++;
        temp++;
    }
    
    if (length == 0) {
        return false;
    }
    
    if (length % 2 != 0) {
        return false;
    }
    
    int half = length / 2;
    
    Iterator left = first; 
    Iterator right = first; 
    
    for (int i = 0; i < half; i++) {
        right++;
    }
    
    for (int i = 0; i < half; i++) {
        if (!(*left == *right)) {
            return false;
        }
        left++;
        right++;
    }
    
    return true;
}