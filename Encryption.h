#pragma once

#include "Global.h"

#include <botan/pipe.h>
#include <botan/key_filt.h>
#include <botan/hex.h>
#include <botan/base64.h>
#include <botan/aes.h>
#include <botan/cbc.h>
#include <botan/filters.h>
#pragma comment (lib, "botan.lib")

using namespace Botan;


std::string EncryptString(const std::string plain, std::string key, std::string iv)
{
	SymmetricKey key_(base64_decode(key));
	InitializationVector iv_(base64_decode(iv));
	Pipe pipe(get_cipher("AES-256/GCM", key_, iv_, ENCRYPTION), new Base64_Encoder);
	pipe.process_msg(plain);
	return pipe.read_all_as_string();
}

std::string DecryptString(const std::string str, std::string key, std::string iv)
{
	SymmetricKey key_(base64_decode(key));
	InitializationVector iv_(base64_decode(iv));
	Pipe pipe(new Base64_Decoder, get_cipher("AES-256/GCM", key_, iv_, DECRYPTION));
	pipe.process_msg(str);
	return pipe.read_all_as_string();
}
