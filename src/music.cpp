#include <iostream> //std::cout
#include "music.hpp"

namespace arkanoid {

Music::Music(std::string a_file) 
: m_fileName(a_file)
, m_buffer()
, m_sound()
, m_isPlaying (false)
{}

void Music::play() 
{
    if (!m_buffer.loadFromFile(m_fileName)) {
        std::cout<< "can't open music file\n";
    }
    m_sound.setVolume(50);
    m_sound.setBuffer(m_buffer);
    m_sound.setLoop(true);
    m_sound.play();
    m_isPlaying = true;
}

void Music::stop()
{
    m_sound.stop();
    m_isPlaying = false;
}

void Music::playAgain()
{
    m_sound.play();
    m_isPlaying = true;
}

void Music::setMusic(std::string a_fileName){
	m_fileName = a_fileName;
}


}//arkanoid
