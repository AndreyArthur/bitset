#include "bitset.h"
#include <stdint.h>
#include <stdlib.h>
#include <strings.h>

#define BYTE 8
#define SET(BYTE, OFFSET) BYTE | (1 << (7 - OFFSET))
#define RESET(BYTE, OFFSET) BYTE & ~(1 << (7 - OFFSET))
#define GET(BYTE, OFFSET) (BYTE >> (7 - OFFSET)) & 1

bitset bitset_init() {
    bitset_data *data = malloc(sizeof(bitset_data));
    data->size = 0;
    data->capacity = BYTE;
    data->bytes = malloc(sizeof(uint8_t) * 1);

    data->bytes[0] = 0;

    bitset set = {.data = data};

    return set;
}

void bitset_free(bitset set) {
    free(set.data->bytes);
    free(set.data);
}

void bitset_resize(bitset set, size_t size) {
    size_t new_capacity;
    if (size % BYTE == 0) {
        new_capacity = size / BYTE;
    } else {
        new_capacity = size / BYTE + 1;
    }

    size_t old_capacity = bitset_capacity(set) / 8;

    set.data->capacity = new_capacity * 8;
    set.data->bytes = realloc(set.data->bytes, sizeof(uint8_t) * new_capacity);
    set.data->size = size;

    for (size_t index = old_capacity; index < new_capacity; index++) {
        set.data->bytes[index] = 0;
    }
}

size_t bitset_capacity(bitset set) { return set.data->capacity; }

size_t bitset_size(bitset set) { return set.data->size; }

uint8_t bitset_test(bitset set, size_t position) {
    size_t data_position = position / BYTE;
    size_t byte_position = position % BYTE;

    if (position < set.data->size) {
        return GET(set.data->bytes[data_position], byte_position);
    }

    return 0;
}

static void bitset_set_value(bitset set, size_t position, uint8_t value) {
    size_t data_position = position / BYTE;
    size_t byte_position = position % BYTE;

    if (position < set.data->size) {
        if (!!value == 0) {
            set.data->bytes[data_position] =
                RESET(set.data->bytes[data_position], byte_position);
        } else {
            set.data->bytes[data_position] =
                SET(set.data->bytes[data_position], byte_position);
        }
        return;
    }

    if (position < set.data->capacity) {
        set.data->size = position + 1;
        bitset_set(set, position);
        return;
    }

    size_t new_capacity = (data_position + 1) * BYTE;
    set.data->capacity = new_capacity;
    set.data->bytes =
        realloc(set.data->bytes, sizeof(uint8_t) * set.data->capacity);

    bitset_set(set, position);
}

void bitset_set(bitset set, size_t position) {
    bitset_set_value(set, position, 1);
}

void bitset_reset(bitset set, size_t position) {
    bitset_set_value(set, position, 0);
}

void bitset_flip(bitset set, size_t position) {
    bitset_set_value(set, position, !bitset_test(set, position));
}

void bitset_set_all(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        set.data->bytes[index] = 0xff;
    }
}

void bitset_reset_all(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        set.data->bytes[index] = 0x00;
    }
}

void bitset_flip_all(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        set.data->bytes[index] = ~set.data->bytes[index];
    }
}

uint8_t bitset_all(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        if (set.data->bytes[index] != 0xff) {
            return 0;
        }
    }
    return 1;
}

uint8_t bitset_any(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        if (set.data->bytes[index] != 0x00) {
            return 1;
        }
    }
    return 0;
}

uint8_t bitset_none(bitset set) {
    size_t capacity_in_bytes = bitset_capacity(set) / 8;
    for (size_t index = 0; index < capacity_in_bytes; index++) {
        if (set.data->bytes[index] != 0x00) {
            return 0;
        }
    }
    return 1;
}

uint8_t bitset_count(bitset set) {
    uint8_t count = 0;
    size_t size = bitset_size(set);
    for (size_t index = 0; index < size; index++) {
        count += bitset_test(set, index);
    }
    return count;
}
