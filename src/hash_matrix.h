/*
 * Toeplitz Hash Algorithm implementation
 *
 * One reprasentative bit of the key or matrix
 * is equal to one physical byte of memory.
 * 
 * @author Sam A. Markelon
 * @date 10/29/2019
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <inttypes.h>
#include <ctype.h>

typedef uint8_t* bitarray;

typedef struct{
  size_t n;
  size_t l;
  bitarray n_arr;
  bitarray l_arr;
}hash_matrix;

typedef struct{
  size_t idx; 
  hash_matrix* m; 
  bitarray x;
  bitarray h;
} hash_thread;

bitarray gen_rand_bitarray(size_t sz);
void delete_bitarray(bitarray ba);

hash_matrix* gen_hash_matrix (size_t n, size_t l);
void delete_hash_matrix(hash_matrix* m);
bitarray hash(hash_matrix* m, bitarray x);

