#include <climits>
#include <stdint.h>
#include <stdio.h>

#include <fuzzer/FuzzedDataProvider.h>
#include <libcuckoo/cuckoohash_map.hh>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  FuzzedDataProvider provider(data, size);
  std::string str = provider.ConsumeRandomLengthString(100);
  std::string str2 = provider.ConsumeRandomLengthString(100);

  libcuckoo::cuckoohash_map<std::string, std::string> Table(100);

  Table.insert(str, "hello");

  std::string out;

  Table.find(str, out);
  Table.find(str2, out);

  return 0;
}
