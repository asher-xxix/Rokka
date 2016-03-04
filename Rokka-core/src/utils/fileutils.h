#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <fstream>
#include <string.h>

namespace rokka {

  std::string read_file(const char* filepath) {
    //reading the file in this standard C way is much faster than ifstream
    // "rt" means reading as a text file
    FILE* file = fopen(filepath, "rt"); // I know this is insecure but meh
    // find the end of the file
    fseek(file, 0, SEEK_END);
    // retrieve its length (in bytes)
    unsigned long length = ftell(file);
    char* data = new char[length + 1];
    // remove the extra bytes that ftell gives us
    memset(data, 0, length + 1); // this also removes artefacts at the end
    // now reset the seek position
    fseek(file, 0, SEEK_SET);
    // finally read the data and close the file
    fread(data, 1, length, file);
    fclose(file);

    // now read our string
    std::string result(data);
    // free the used memory
    delete[] data;

    // done
    return result;
  }


}

#endif
