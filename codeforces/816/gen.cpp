#include <cmath>
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

template<class OutStreamType = std::ostream> void print_sinoidal_random_data(OutStreamType &out_stream)
{
  using std::endl;
  using Seed = std::random_device;
  using Engine = std::mt19937;
  using Distribution = std::normal_distribution<double>;
  using Distribution_sign = std::normal_distribution<int>;

  Seed seed;
  Engine engine(seed());
  Distribution dist(0.0, 1.0);
  Distribution sign_dist(0, 2);
  auto gen_rand = [&]() { return dist(engine) - 0.5; };
  auto gen_rand_sign = [&]() { return dist(engine); };

  const int numSamples = 200;
  const double amplitude = 10.0;// Amplitude of the sine wave
  const double frequency = 0.1;// Frequency of the sine wave

  for (int i = 0; i < numSamples; ++i) {
    const int sign = gen_rand_sign() == 1 ? 1 : -1;
    const double raw_val = sign * (amplitude * sin(2.0 * M_PI * frequency * i / numSamples)) + gen_rand();
    const int val = static_cast<int>(raw_val + 0.5);
    out_stream << val << endl;
  }
}


template<class OutStreamType = std::ostream> void print_random_data(OutStreamType &out_stream)
{
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // supported int Types // check https://en.cppreference.com/w/cpp/header/random
  // short, int, long, long long,
  // unsigned short, unsigned int, unsigned long, or unsigned long long
  using intType = int;
  using Distribution = std::uniform_int_distribution<intType>;

  // struct range
  // {
  //   intType min{};
  //   intType max{};
  // };

  Seed seed;
  Engine engine{ seed() };

  const intType n_min = 5;
  const intType n_max = 10;
  Distribution n_distribution(n_min, n_max);
  auto generate_n = [&]() { return n_distribution(engine); };

  const intType k_min = 1;
  const intType k_max = 5;
  Distribution k_distribution(k_min, k_max);
  auto generate_k = [&]() { return k_distribution(engine); };

  const intType q_min = 5;
  const intType q_max = 10;
  Distribution q_distribution(q_min, q_max);
  auto generate_q = [&]() { return q_distribution(engine); };

  const intType r_min = 10;
  const intType r_max = 100;
  Distribution r_distribution(r_min, r_max);
  auto generate_r = [&]() { return r_distribution(engine); };

  using std::endl;

  const intType n = generate_n();
  const intType q = generate_q();
  out_stream << n << " ";
  out_stream << generate_k() << " ";
  out_stream << q << "\n";

  for (intType i = 0; i < n; i++) { out_stream << generate_r() << ' ' << generate_r() << '\n'; }

  for (intType i = 0; i < q; i++) { out_stream << generate_r() << ' ' << generate_r() << '\n'; }

  out_stream << "\n";
}

int main()
{
  using std::cout;
  print_random_data(cout);

  // print_random_data();

  // std::ofstream out{ "test" };
  // print_random_data(out);

  // print_sinoidal_random_data(cout);

  return 0;
}
