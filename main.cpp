#pragma once

#include "Encryption.h"

int main()
{
	std::string key = "NE1YQmdkUG5HUkJVaUVpR0FYUUpDbXl5em90MGtHMjY="; // == 4MXBgdPnGRBUiEiGAXQJCmyyzot0kG26
	std::string iv = "b3V5UzVDdkxIQXFVaVdBaE9tZzNmcHJQMzVTVjFTZGg="; // == ouyS5CvLHAqUiWAhOmg3fprP35SV1Sdh
	std::string plain_text = "this string will be encrypted with aes-256 and encoded with base64";
	std::string Encrypted = EncryptString(plain_text, key, iv);
	std::string Decrypted = DecryptString(Encrypted, key, iv);
	std::cout << "Encrypted String: " << Encrypted << std::endl;
	std::cout << "Decrypted String: " << Decrypted << std::endl;

}