// Copyright (C) 2023 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <limits>

using namespace std;

unsigned power(unsigned base, const unsigned exp)
{
  if (exp == 0) { return 1; }
  const unsigned b{ base };
  for (unsigned i = 0; i < exp - 1; i++) { base *= b; }
  return base;
}

int main()
{
  const unsigned powa = power(10, 5);
  cout << "powa" << powa << endl;
  int x[powa + 1]{};
  cout << &x[0] << endl;
  cout << &x[powa] << endl;
  cout << &x[powa] - &x[0] << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  //
  // 100000
  cout << "unsigned long long max: " << std::numeric_limits<unsigned long long>::max() << endl;
  cout << "unsigned long long max: " << std::numeric_limits<unsigned long long>::max() << endl;

  // cout <<

  return 0;
}
