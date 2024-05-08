#include <iostream>
#include <initializer_list>

template<typename T>
T average(T val) {
    return val;
}

template<typename T, typename... Args>
T average(T first, Args... args) {
    return (first + average(args...));
}

template<typename T>
T average(std::initializer_list<T> list) {
    T sum = 0;
    for (const auto& elem : list) {
        sum += elem;
    }
    return sum / list.size();
}

template<typename T>
class Array {
private:
    T* data;
    size_t size;
public:
    Array(std::initializer_list<T> init_list) : size(init_list.size()), data(new T[size]) {
        size_t i = 0;
        for (const T& elem : init_list) {
            data[i++] = elem;
        }
    }
};

template<typename T>
T minimum(T val) {
    return val;
}

template<typename T, typename... Args>
T minimum(T first, Args... args) {
    T min_of_rest = minimum(args...);
    return (first < min_of_rest) ? first : min_of_rest;
}

int main() {
    std::cout << "Average: " << average(1, 2, 3, 4, 5) / 5 << std::endl;
    Array<int> arr = { 1, 2, 3, 4, 5 };
    std::cout << "Minimum: " << minimum(3, 1, 4, 1, 5, 9) << std::endl;
    std::cout << "Average: " << average({ 1, 2, 3, 4, 5 }) << std::endl;

    return 0;
}
