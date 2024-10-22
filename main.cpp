#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using Board = vector<vl>;

Board bd(5, vl(5));
Board check(5, vl(5, 0));

bool CheckState() {
  ll count = 0;
  // row
  for (auto i = 0; i < 5; ++i) {
    ll c = 0;
    for (auto j = 0; j < 5; ++j) {
      c += check[i][j];
    }

    if (c == 5) {
      ++count;
    }
  }
  // col
  for (auto j = 0; j < 5; ++j) {
    ll c = 0;
    for (auto i = 0; i < 5; ++i) {
      c += check[i][j];
    }

    if (c == 5) {
      ++count;
    }
  }
  // diag1
  ll c1 = 0;
  for (auto i = 0; i < 5; ++i) {
    c1 += check[i][i];
  }
  if (c1 == 5) {
    ++count;
  }
  // diag2
  ll c2 = 0;
  for (auto i = 0; i < 5; ++i) {
    c2 += check[i][4 - i];
  }
  if (c2 == 5) {
    ++count;
  }

  if (count < 3) {
    return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  for (auto i = 0; i < 5; ++i) {
    for (auto j = 0; j < 5; ++j) {
      cin >> bd[i][j];
    }
  }

  for (auto t = 0; t < 25; ++t) {
    ll x;
    cin >> x;

    auto found = false;
    for (auto i = 0; i < 5 && !found; ++i) {
      for (auto j = 0; j < 5 && !found; ++j) {
        if (bd[i][j] == x) {
          check[i][j] = 1;
          found = true;
          break;
        }
      }
    }

    const auto& done = CheckState();
    if (done) {
      cout << t + 1;
      return 0;
    }
  }

  return 0;
}