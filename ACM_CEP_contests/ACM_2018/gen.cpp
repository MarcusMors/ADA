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
  using int_t = unsigned;
  using cint_t = const int_t;
  using Distribution = std::uniform_int_distribution<int_t>;

  Seed seed;
  Engine engine{ seed() };
  /**
   * k_max = 10'000
   * n_max = 3;
   */

  cint_t n_max = 6;
  cint_t n_min = 1;
  Distribution n_distribution(n_min, n_max);
  auto generate_n = [&]() { return n_distribution(engine); };

  cint_t k_max = 8;
  cint_t k_min = 1;
  Distribution k_distribution(k_min, k_max);
  auto generate_k = [&]() { return k_distribution(engine); };

  cint_t a_max = 30;
  cint_t a_min = 0;
  Distribution a_distribution(a_min, a_max);
  auto generate_a = [&]() { return a_distribution(engine); };

  using std::cout;
  using std::endl;

  cint_t data_size = generate_n();
  cout << data_size << " " << generate_k() << "\n";
  for (int_t i = 0; i < data_size; i++) { cout << generate_a() << " "; }
  cout << "\n";
  // out.close();
}

int main()
{
  print_random_data();

  return 0;
}
