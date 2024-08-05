# Bitset, because there is no such thing as a vector of bits.

Context: [Scaling One Million Checkboxes (6:26) - ThePrimeagen](https://youtu.be/0XKYMt5mGpQ?t=386)

You can call a bitset as:

- Fancy talk for u8 array.
- Convenient operations on top of u8 array.
- Like an array of u1's, but that doesn't make any sense there must be... it... it... it...
- A vec of bits, but there's not such thing as a "vecabits" bro.

There's no such thing as a bit array, you make a bit array.

## I implemented a bitset, so I can overcomplicate it.

### Structure

Here's what makes our bitset tick:

```c
typedef struct {
    size_t capacity;   // Total number of bits we can handle
    size_t size;       // Current number of bits in use
    uint8_t *bytes;    // Array of bytes (u8 array)
} bitset_data;

typedef struct {
    bitset_data *data; // Pointer to bitset_data
} bitset;
```

### Methods

Now, let's look at the juicy methods that let you play around with bits like a pro.

#### Initialization and Cleanup

- **bitset bitset_init()**: Initializes a new bitset with a default capacity. Starts you off with 8 bits to play with.
- **void bitset_free(bitset set)**: Frees the memory allocated for the bitset. Clean up after your bit fiddling.

#### Capacity and Size

- **size_t bitset_capacity(bitset set)**: Returns the total number of bits you can currently handle. Think of it as your bit playground size.
- **size_t bitset_size(bitset set)**: Returns the number of bits you are currently using. The bits you've actively set or reset.

#### Resize

- **void bitset_resize(bitset set, size_t size)**: Changes the size of your bitset to the specified size. Expands your bit playground.

#### Bit Operations

- **uint8_t bitset_test(bitset set, size_t position)**: Checks if the bit at the specified position is set (1) or not (0). Use this to peek at your bits.
- **void bitset_set(bitset set, size_t position)**: Sets the bit at the specified position to 1. Claim your bit!
- **void bitset_reset(bitset set, size_t position)**: Resets the bit at the specified position to 0. Release your bit.
- **void bitset_flip(bitset set, size_t position)**: Toggles the bit at the specified position. Flip it good!

#### Bulk Operations

- **void bitset_set_all(bitset set)**: Sets all bits in the bitset to 1. Turn all the lights on.
- **void bitset_reset_all(bitset set)**: Resets all bits in the bitset to 0. Turn all the lights off.
- **void bitset_flip_all(bitset set)**: Toggles all bits in the bitset. Flip all the switches.

#### Query Operations
- **uint8_t bitset_all(bitset set)**: Checks if all bits are set. Are all the lights on?
- **uint8_t bitset_any(bitset set)**: Checks if any bit is set. Is at least one light on?
- **uint8_t bitset_none(bitset set)**: Checks if no bits are set. Are all the lights off?
- **uint8_t bitset_count(bitset set)**: Counts the number of bits set to 1. How many lights are on?

### Example Usage

Here's how you can use the bitset in your code:

```c
#include "bitset.h"
#include <assert.h>

int main() {
    // Initialize a bitset
    bitset set = bitset_init();

    // Set some bits
    bitset_set(set, 3);
    bitset_set(set, 5);

    // Test the bits
    assert(bitset_test(set, 3) == 1);
    assert(bitset_test(set, 5) == 1);
    assert(bitset_test(set, 7) == 0);

    // Flip a bit
    bitset_flip(set, 3);
    assert(bitset_test(set, 3) == 0);

    // Reset all bits
    bitset_reset_all(set);
    assert(bitset_none(set) == 1);

    // Free the bitset
    bitset_free(set);

    return 0;
}
```

There you have it! A bitset gives you the power to manipulate individual bits in an `u8` array, but with style and convenience. Use it wisely, and remember, there's no such thing as a "vecabits," but now you can make one!
