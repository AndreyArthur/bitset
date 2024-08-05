#ifndef BITSET_H
#define BITSET_H

#include <stddef.h>
#include <stdint.h>

/**
 * Structure to hold the actual bitset data.
 * @param capacity - The total number of bits that can be stored.
 * @param size - The current number of bits set.
 * @param bytes - The array to hold the bit data.
 */
typedef struct {
    size_t capacity;
    size_t size;
    uint8_t *bytes;
} bitset_data;

/**
 * Wrapper structure for bitset data.
 * @param data - Pointer to the bitset_data structure.
 */
typedef struct {
    bitset_data *data;
} bitset;

/**
 * Initializes a new bitset.
 * @return - An initialized bitset with default capacity.
 */
bitset bitset_init();

/**
 * Frees the memory allocated for the bitset.
 * @param set - The bitset to free.
 */
void bitset_free(bitset set);

/**
 * Returns the capacity of the bitset.
 * @param set - The bitset to query.
 * @return - The capacity of the bitset.
 */
size_t bitset_capacity(bitset set);

/**
 * Returns the size of the bitset.
 * @param set - The bitset to query.
 * @return - The size of the bitset.
 */
size_t bitset_size(bitset set);

/**
 * Resizes the bitset to the specified size.
 * @param set - The bitset to resize.
 * @param size - The new size of the bitset.
 */
void bitset_resize(bitset set, size_t size);

/**
 * Tests whether a specific bit is set.
 * @param set - The bitset to query.
 * @param position - The position of the bit to test.
 * @return - 1 if the bit is set, 0 otherwise.
 */
uint8_t bitset_test(bitset set, size_t position);

/**
 * Sets a specific bit.
 * @param set - The bitset to modify.
 * @param position - The position of the bit to set.
 */
void bitset_set(bitset set, size_t position);

/**
 * Resets (clears) a specific bit.
 * @param set - The bitset to modify.
 * @param position - The position of the bit to reset.
 */
void bitset_reset(bitset set, size_t position);

/**
 * Flips (toggles) a specific bit.
 * @param set - The bitset to modify.
 * @param position - The position of the bit to flip.
 */
void bitset_flip(bitset set, size_t position);

/**
 * Sets all bits in the bitset.
 * @param set - The bitset to modify.
 */
void bitset_set_all(bitset set);

/**
 * Resets (clears) all bits in the bitset.
 * @param set - The bitset to modify.
 */
void bitset_reset_all(bitset set);

/**
 * Flips (toggles) all bits in the bitset.
 * @param set - The bitset to modify.
 */
void bitset_flip_all(bitset set);

/**
 * Checks if all bits are set.
 * @param set - The bitset to query.
 * @return - 1 if all bits are set, 0 otherwise.
 */
uint8_t bitset_all(bitset set);

/**
 * Checks if any bit is set.
 * @param set - The bitset to query.
 * @return - 1 if any bit is set, 0 otherwise.
 */
uint8_t bitset_any(bitset set);

/**
 * Checks if no bits are set.
 * @param set - The bitset to query.
 * @return - 1 if no bits are set, 0 otherwise.
 */
uint8_t bitset_none(bitset set);

/**
 * Counts the number of bits set to 1.
 * @param set - The bitset to query.
 * @return - The number of bits set to 1.
 */
uint8_t bitset_count(bitset set);

#endif
