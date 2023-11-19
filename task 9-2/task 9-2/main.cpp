#include <iostream>
#include <string>

class big_integer
{
public:
    big_integer(std::string line) : _line(line) {}
    big_integer(big_integer& line) : big_integer(line._line) {}
    big_integer(big_integer&& line) noexcept : _line(std::exchange(line._line, nullptr)) {}
    big_integer& operator=(const big_integer& line2)
    {
        return *this;
    }
    big_integer& operator=(big_integer&& line2) noexcept
    {
        std::swap(_line, line2._line);
        return *this;
    }
    std::string operator+(big_integer& line2)
    {
        return std::to_string(std::stoi(line2._line) + std::stoi(_line));
    }
    std::string operator+(int& a)
    {
        return std::to_string(a + std::stoi(_line));
    }
    std::string operator*(big_integer& line2)
    {
        return std::to_string(std::stoi(line2._line) * std::stoi(_line));
    }
    void print()
    {
        std::cout << _line << std::endl;
    }
private:
    std::string _line;
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;
}