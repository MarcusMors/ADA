#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>

// using namespace std;

template<typename T> T bit_number(unsigned Bytes)
{
  // static_assert(sizeof(T) < Bytes, "the type isn't able to hold that much Bytes");
  if (sizeof(T) < Bytes) {
    std::cerr << "the type isn't able to hold " << Bytes << " Bytes\n";
    std::cerr << "sizeof(T)\t: " << sizeof(T) << "\n";
    std::cerr << "Bytes\t\t: " << Bytes << " \n";
    return 0;
  }
  T n{ 1 };
  for (unsigned i = 0; i <= Bytes; i++) { n <<= 3; }

  return n;
}

template<typename T> std::string to_str(const T &number)
{
  std::stringstream ss;
  ss << number;
  std::string str;
  ss >> str;
  return str;
}

// #define int

void print_random_data()
{
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // supported int Types // check https://en.cppreference.com/w/cpp/header/random
  // short, int, long, long long,
  // unsigned short, unsigned int, unsigned long, or unsigned long long
  using int_t = int;
  using cint_t = const int_t;
  using Distribution = std::uniform_int_distribution<int_t>;

  Seed seed;
  Engine engine{ seed() };
  /**
   * k_max = 10'000
   * n_max = 3;
   */

  // cint_t n_max = 10;
  cint_t n_max = 100'000;
  cint_t n_min = 90'000;
  // cint_t n_min = 1;
  Distribution n_distribution(n_min, n_max);
  auto gen_n = [&]() { return n_distribution(engine); };

  cint_t digit_max = 9;
  cint_t digit_min = 0;
  Distribution digit_distribution(digit_min, digit_max);
  auto gen_digit = [&]() { return digit_distribution(engine); };

  using std::cout;
  using std::endl;

  cint_t data_size = gen_n();

  // cout << data_size << "\n";
  for (int_t i = 0; i < data_size; i++) { cout << gen_digit(); }
  cout << "\n";
}

int main()
{
  print_random_data();

  return 0;
}
