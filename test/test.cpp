#include <assert.h>
#include "../src/calculator.h"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <cstdint>
#include <cstddef>
#include <string>

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  /*Your code here*/
  FuzzedDataProvider fuzzed_data(data, size);
  
  int a = fuzzed_data.ConsumeIntegral<int>();
  int b = fuzzed_data.ConsumeIntegral<int>();
  char op = static_cast<char>(fuzzed_data.ConsumeIntegral<uint8_t>());
  
  calculator(a, op, b);
}
