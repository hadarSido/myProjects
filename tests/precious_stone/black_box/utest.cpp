#include <string>
#include <iostream>
#include "mu_test.h"
#include "black_box.hpp"
#include "console_destination.hpp"
#include "file_destination.hpp"
#include "console_source.hpp"
#include "file_source.hpp"
#include "encoder_vowel.hpp"
#include "encoder_title.hpp"
#include "encoder_caesar.hpp"
#include "udp_source.hpp"


BEGIN_TEST(change_vowel_to_star_test)
	using namespace precious_stone;
	ConsoleSource newSource{std::cout, std::cin};
	ConsoleDestination newDestination{std::cout};
	EncoderVowel newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST


BEGIN_TEST(change_words_to_title_test)
	using namespace precious_stone;
	ConsoleSource newSource{std::cout, std::cin};
	ConsoleDestination newDestination{std::cout};
	EncoderTitle newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST


BEGIN_TEST(change_words_to_caesar_test)
	using namespace precious_stone;
	ConsoleSource newSource{std::cout, std::cin};
	ConsoleDestination newDestination{std::cout};
	EncoderCaesar newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST


BEGIN_TEST(change_udp_words_to_caesar_test)
	using namespace precious_stone;
	std::string ip = "172.17.0.1";
	int port = 1025;
	UdpSource newSource{port, ip};
	ConsoleDestination newDestination{std::cout};
	EncoderCaesar newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST

BEGIN_TEST(change_read_file_words_to_caesar_test)
	using namespace precious_stone;
	FileSource newSource{"textfile.txt"};
	ConsoleDestination newDestination{std::cout};
	EncoderCaesar newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST

BEGIN_TEST(change_write_file_words_to_caesar_test)
	using namespace precious_stone;
	ConsoleSource newSource{std::cout, std::cin};
	FileDestination newDestination{"write_file.txt"};
	EncoderCaesar newEncoder{};
	BlackBox newBlackBox{newSource, newDestination, newEncoder};
	newBlackBox.executer();
	ASSERT_PASS();
	
END_TEST





TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(change_vowel_to_star_test)
	// TEST(change_words_to_title_test)
	// TEST(change_words_to_caesar_test)
	// TEST(change_udp_words_to_caesar_test)
	 //TEST(change_read_file_words_to_caesar_test)
	// TEST(change_write_file_words_to_caesar_test)
END_SUITE
