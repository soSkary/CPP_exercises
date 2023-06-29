#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H
#include <string>

bool char_is_print(char ch);
void write_message_to_file(const std::string& message);
std::string read_message_from_file();

void caesar_encrypt();
std::string caesar_decrypt();

#endif
