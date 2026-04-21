#include <type_traits>
#include <iostream>
#include <vector>
#include <string>

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

int main() {
    std::string s1 = "abcdabcd";
    std::string s2 = "abcdabdc";
    
    std::cout << "Строка \"abcdabcd\": ";
    if (IsTwiceSequence(s1.begin(), s1.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::cout << "Строка \"abcdabdc\": ";
    if (IsTwiceSequence(s2.begin(), s2.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
    std::cout << "Массив {1,2,3,4,1,2,3,4}: ";
    if (IsTwiceSequence(arr, arr + 8)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::vector<bool> vec = {true, false, true};
    std::cout << "Вектор {true, false, true}: ";
    if (IsTwiceSequence(vec.begin(), vec.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::vector<int> empty;
    std::cout << "Пустой вектор: ";
    if (IsTwiceSequence(empty.begin(), empty.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::vector<int> one = {5};
    std::cout << "Один элемент {5}: ";
    if (IsTwiceSequence(one.begin(), one.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::vector<int> two = {5, 5};
    std::cout << "Два одинаковых элемента {5,5}: ";
    if (IsTwiceSequence(two.begin(), two.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    std::vector<int> four = {1, 2, 1, 2};
    std::cout << "Четыре элемента {1,2,1,2}: ";
    if (IsTwiceSequence(four.begin(), four.end())) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}