//generator random numbers into file like "0101110010100110110100101011110101" 10MB
//
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cstdio> 

// 使用 std::minstd_rand 
void generateRandomSequenceWithMinstdRand(const std::string& filename) {
    std::minstd_rand rng;
    rng.seed(std::random_device{}()); 

    const size_t dataSize = 10 * 1024 * 1024; 
    std::vector<char> data(dataSize);

    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = (rng() % 2) + '0'; 
    }

    freopen(filename.c_str(), "w", stdout);
    for (size_t i = 0; i < dataSize; ++i) {
        std::cout << data[i];
    }
    freopen("/dev/tty", "w", stdout);
}

// 使用 std::mt19937 
void generateRandomSequenceWithMt19937(const std::string& filename) {
    std::mt19937 rng;
    rng.seed(std::random_device{}()); 

    const size_t dataSize = 10 * 1024 * 1024;
    std::vector<char> data(dataSize);

    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = (rng() % 2) + '0';
    }

    freopen(filename.c_str(), "w", stdout);
    for (size_t i = 0; i < dataSize; ++i) {
        std::cout << data[i];
    }
    freopen("/dev/tty", "w", stdout);
}

// 使用 std::ranlux24_base 
void generateRandomSequenceWithRanlux24Base(const std::string& filename) {
    std::ranlux24_base rng;
    rng.seed(std::random_device{}());

    const size_t dataSize = 10 * 1024 * 1024;
    std::vector<char> data(dataSize);

    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = (rng() % 2) + '0'; 
    }

    freopen(filename.c_str(), "w", stdout);
    for (size_t i = 0; i < dataSize; ++i) {
        std::cout << data[i];
    }
    freopen("/dev/tty", "w", stdout);
}

int main() {
    int choice;
    std::cout << "选择随机数生成器：" << std::endl;
    std::cout << "1. std::minstd_rand" << std::endl;
    std::cout << "2. std::mt19937" << std::endl;
    std::cout << "3. std::ranlux24_base" << std::endl;
    std::cin >> choice;

    std::string filename = "mt19937.txt";

    switch (choice) {
        case 1:
            generateRandomSequenceWithMinstdRand(filename);
            break;
        case 2:
            generateRandomSequenceWithMt19937(filename);
            break;
        case 3:
            generateRandomSequenceWithRanlux24Base(filename);
            break;
        default:
            std::cout << "无效的选择！" << std::endl;
            return 1;
    }

    std::cout << "随机数序列已生成并保存到文件：" << filename << std::endl;
    return 0;
}