#include "hash_matrix.h"

size_t power(size_t base, size_t exp)
{
  size_t i, result = 1;
  for (i = 0; i < exp; i++)
    result *= base;
  return result;
}

void gen_tester()
{
  struct timespec start, finish;
  double tt;
  size_t n,l;
  
  for(size_t i = 3; i < 8; i++){
    clock_gettime(CLOCK_MONOTONIC, &start);
    n = power(10,i-2);
    l = power(10,i);

    hash_matrix* m = gen_hash_matrix(n,l); 
    delete_hash_matrix(m);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    tt = (finish.tv_sec - start.tv_sec);
    tt += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("%lu x %lu took %f seconds to generate.\n", n,l,tt);
  }
  return;
}


void hash_tester()
{
  struct timespec start, finish;
  double tt;
  size_t n,l;

  for(size_t i = 3; i < 8; i++){
    clock_gettime(CLOCK_MONOTONIC, &start);
    n = power(10,i-2);
    l = power(10,i);

    hash_matrix* m = gen_hash_matrix(n,l); 
    bitarray x = gen_rand_bitarray(l);
    bitarray h = hash(m, x);
    delete_bitarray(x);
    delete_bitarray(h);
    delete_hash_matrix(m);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    tt = (finish.tv_sec - start.tv_sec);
    tt += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
    printf("%lu x %lu took %f seconds to generate and run hash func on random x.\n", n,l,tt);
  }
  
  return;
}


int main()
{
  gen_tester();
  hash_tester();
  return 0;
}
