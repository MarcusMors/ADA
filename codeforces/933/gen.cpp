#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>

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

void print_random_data()
{
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // supported int Types // check https://en.cppreference.com/w/cpp/header/random
  // short, int, long, long long,
  // unsigned short, unsigned int, unsigned long, or unsigned long long
  using intType = unsigned;
  using Distribution = std::uniform_int_distribution<intType>;

  Seed seed;
  Engine engine{ seed() };

  // const intType n_max = 100'000;
  // const intType t_max = 100;
  // const intType t_min = 1;

  // const intType t_max = 3;
  // const intType t_min = 1;
  // Distribution t_distribution(t_min, t_max);

  const intType n_max = 6;
  const intType n_min = 3;
  Distribution n_distribution(n_min, n_max);

  // auto generate_t = [&]() { return t_distribution(engine); };
  auto generate_n = [&]() { return n_distribution(engine); };

  using std::cout;
  using std::endl;

  int n = generate_n();
  int m = generate_n();
  int k = generate_n();

  cout << 1 << endl;
  cout << n << " " << m << " " << k << endl;
  for (intType i = 0; i < n; i++) { cout << generate_n() << ' '; }
  cout << "\n";
  for (intType i = 0; i < m; i++) { cout << generate_n() << ' '; }
  cout << "\n";
  cout << endl;
  // out.close();
}

int main()
{
  print_random_data();

  return 0;
}
