#include "../lib/bitset.h"
#include <assert.h>

void test_bitset_init() {
    bitset set = bitset_init();

    assert(set.data->size == 0);
    assert(set.data->capacity == 8);
    assert(set.data->bytes[0] == 0);

    bitset_free(set);
}

void test_bitset_capacity() {
    bitset set = bitset_init();

    assert(bitset_capacity(set) == 8);

    bitset_free(set);
}

void test_bitset_size() {
    bitset set = bitset_init();

    assert(bitset_size(set) == 0);

    bitset_free(set);
}

void test_bitset_resize() {
    bitset set = bitset_init();

    bitset_resize(set, 9);
    assert(bitset_capacity(set) == 16);
    assert(bitset_size(set) == 9);

    bitset_free(set);
}

void test_bitset_test() {
    bitset set = bitset_init();

    assert(bitset_test(set, 0) == 0);
    assert(bitset_test(set, 1) == 0);
    assert(bitset_test(set, 2) == 0);
    assert(bitset_test(set, 3) == 0);
    assert(bitset_test(set, 4) == 0);
    assert(bitset_test(set, 5) == 0);
    assert(bitset_test(set, 6) == 0);
    assert(bitset_test(set, 7) == 0);
    assert(bitset_test(set, 8) == 0);

    bitset_free(set);
}

void test_bitset_set() {
    bitset set = bitset_init();

    bitset_set(set, 9);

    assert(bitset_test(set, 9) == 1);
    assert(bitset_size(set) == 10);
    assert(bitset_capacity(set) == 16);

    bitset_free(set);
}

void test_bitset_reset() {
    bitset set = bitset_init();

    bitset_set(set, 9);
    assert(bitset_test(set, 9) == 1);

    bitset_reset(set, 9);
    assert(bitset_test(set, 9) == 0);

    bitset_free(set);
}

void test_bitset_flip() {
    bitset set = bitset_init();

    bitset_flip(set, 9);
    assert(bitset_test(set, 9) == 1);

    bitset_flip(set, 9);
    assert(bitset_test(set, 9) == 0);

    bitset_free(set);
}

void test_bitset_set_all() {
    bitset set = bitset_init();

    bitset_set_all(set);

    assert(bitset_all(set) == 1);

    bitset_free(set);
}

void test_bitset_reset_all() {
    bitset set = bitset_init();

    bitset_set_all(set);
    assert(bitset_all(set) == 1);

    bitset_reset_all(set);
    assert(bitset_none(set) == 1);

    bitset_free(set);
}

void test_bitset_flip_all() {
    bitset set = bitset_init();

    bitset_flip_all(set);
    assert(bitset_all(set) == 1);

    bitset_flip_all(set);
    assert(bitset_none(set) == 1);

    bitset_free(set);
}

void test_bitset_all() {
    bitset set = bitset_init();

    bitset_set_all(set);
    assert(bitset_all(set) == 1);

    bitset_free(set);
}

void test_bitset_any() {
    bitset set = bitset_init();

    bitset_set(set, 0);
    assert(bitset_any(set) == 1);

    bitset_free(set);
}

void test_bitset_none() {
    bitset set = bitset_init();

    assert(bitset_none(set) == 1);

    bitset_free(set);
}

void test_bitset_count() {
    bitset set = bitset_init();

    assert(bitset_count(set) == 0);

    bitset_set(set, 0);
    bitset_set(set, 1);

    assert(bitset_count(set) == 2);

    bitset_free(set);
}

int main() {
    test_bitset_init();
    test_bitset_capacity();
    test_bitset_size();
    test_bitset_resize();
    test_bitset_test();
    test_bitset_set();
    test_bitset_reset();
    test_bitset_flip();
    test_bitset_set_all();
    test_bitset_reset_all();
    test_bitset_flip_all();
    test_bitset_all();
    test_bitset_any();
    test_bitset_none();
    test_bitset_count();

    return 0;
}
