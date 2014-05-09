/*
 * MerkleTree.h
 *
 *  Created on: 02.05.2014
 *      Author: dhein
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MERKLETREE_H_
#define MERKLETREE_H_

#include "config.h"
#include "mt_err.h"
#include "mt_arr_list.h"

/*!
 * \brief defines the Merkle Tree data type
 *
 * A Merkle Tree is used for ...
 */
typedef struct merkle_tree {
  uint32_t elems;
  mt_al_t *level[TREE_LEVELS];
} mt_t;

/*!
 * \brief creates a new instance of the Merkle Tree data type
 *
 * This function tries to create a new Merkle Tree data type for ...
 */
mt_t *mt_create(void);
/*!
 *
 * \brief deletes the specified Merkle Tree instance
 *
 * \param[in] mt a pointer to the Merkle Tree instance to delete
 */
void mt_delete(mt_t *mt);

/*!
 *
 * @param mt
 * @param hash
 * @return MT_SUCCESS if printing is successful; MT_ILLEGAL_PARAM otherwise.
 */
mt_error_t mt_add(mt_t *mt, const uint8_t hash[HASH_LENGTH]);

mt_error_t mt_update(const mt_t *mt, const uint8_t hash[HASH_LENGTH],
    const uint32_t offset);

mt_error_t mt_verify(const mt_t *mt, const uint8_t hash[HASH_LENGTH],
    const uint32_t offset);

mt_error_t mt_truncate(mt_t *mt, uint32_t last_valid);

/*!
 * \brief Prints a human readable representation of a hash in hexadecimal notation
 *
 * @param hash the hash to print
 */
void mt_print_hash(const uint8_t hash[HASH_LENGTH]);

/*!
 * Print a human readable representation of the Merkle Tree
 * @param mt a pointer to the Merkle Tree data type instance to print
 */
void mt_print(const mt_t *mt);

#endif /* MERKLETREE_H_ */
#ifdef __cplusplus
}
#endif
