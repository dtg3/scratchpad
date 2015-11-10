#include <openssl/sha.h>
#include <string>
#include <iostream>

int main() {

  std::string data = "HASH ME!";

  SHA_CTX context;

  if (!(SHA1_Init(&context)))
    return 1;


  if (!(SHA1_Update(&context, &data, data.length())))
    return 1;

  unsigned char md[4028];
  if (!(SHA1_Final(md, &context)))
    return 1;

  std::cout << md << "\n";
}
