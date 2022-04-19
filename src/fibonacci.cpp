#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    double a = (1 + std::sqrt(5))/2;
    double b = (1 - std::sqrt(5))/2;
    //return (std::pow(a,n) - std::pow(b,n))/std::sqrt(5);
    return fib_iterative(n);
  }

  int64_t fib_iterative(int n) {
    if (n <= 1) {
      return n;}
    else {
      int fib0 = 0;
      int fib1 = 1;
      for (int i = 2; i <= n; i++) {
        int fib2 = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib2;
      }
      return fib1;
    }
  }

  int64_t fib_recursive(int n) {

    if (n <= 1) {
      return n;
    } else {
      return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    cache[2] = 1;
    if (n <= 2) {
      return cache[n];
    } else {
      if (cache[n-2] == -1) {
        cache[n-2] = fib_recursive_memoization(n-2,cache);
      }
      if (cache[n-1] == -1) {
        cache[n-1] = fib_recursive_memoization(n-1,cache);
      }
      return cache[n-1] + cache[n-2];
    }
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    Matrix2x2 P = {{{0, 1}, {1, 1}}};
    P = matrix_power(P, n-1);
    return P[0][0] + P[1][0];
  }

}  // namespace assignment
