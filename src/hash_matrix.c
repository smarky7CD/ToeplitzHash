/*
 * Toeplitz Hash Algorithm implementation
 * This implements the inlined functions in hash_matrix.h.
 *
 * @author Sam A. Markelon
 * @date 10/29/2019
 */
#include "hash_matrix.h"

/*
 * Generates a random bitarray. 
 * Input sz is the desired size in bits.
 */
bitarray gen_rand_bitarray(size_t sz)
{
  bitarray ba = (bitarray)  malloc(sz * sizeof(uint8_t));
  if(ba == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }
  
  /*
   * SWITCH TO CRYPTO PRG or TRULY RANDOM EVENTUALLY
   */
  
  int r, rB;
  srand(time(NULL));
  for(size_t i = 0; i < sz; i++){
      r = rand();
      rB = r & 1;
      ba[i] = (uint8_t) rB;
  }
  
  return ba; 
}

/*
 * Delete a bitarray
 */
void delete_bitarray(bitarray ba)
{
  free(ba);
  return;
}

/*
 * Generates a random Toeplitz matrix of size nxl.
 * Stored as two bitarrays of size n-1 and size l.
 */
hash_matrix* gen_hash_matrix(size_t n, size_t l)
{
  hash_matrix* m = (hash_matrix*) malloc(sizeof(hash_matrix));   
  if(m == NULL){
    fprintf (stderr, "malloc() failed. Initialization error.\n");
    exit(1);
  }

  m->n = n;
  m->l = l;
  m->n_arr = gen_rand_bitarray(n-1);
  m->l_arr = gen_rand_bitarray(l);
  
  return m;
}

/*
 * Delete a hash_matrix
 */
void delete_hash_matrix(hash_matrix* m)
{
  delete_bitarray(m->n_arr);
  delete_bitarray(m->l_arr);
  free(m);
  return;
}


/*
 * Computes the hash for a given matrix m and input x
 * returns the hash(x) as bitarray of size n 
 */
bitarray hash(hash_matrix* m, bitarray x){

  size_t hash_size = m->n;
  bitarray h = (bitarray) malloc(hash_size * sizeof(uint8_t));

  for(size_t i = 0; i < m->n; i++){

    uint8_t hb = 0;
    size_t n_check = i;

    for(size_t j = 0; j < m->l; j++){
      uint8_t ib;

      if(n_check > 0){
	ib = m->n_arr[n_check-1];
	n_check--;
      } else{
	ib = m->l_arr[j-i];
      }
      
      hb += (x[j] * ib);
    }
    h[i] = hb % 2;
  }

  return h;
}

  
