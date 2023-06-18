#include <SFML/Audio.hpp> // music
namespace arkanoid {

class Music {
public:                                                            
    Music() = default;  
    explicit Music(std::string a_file) ;
    ~Music() = default;
    Music(const Music &a_other) = delete;                                      
    Music& operator=(const Music &a_other) = default;  

    void play();
    void stop();
    void playAgain();
    void setMusic(std::string a_fileName);


private:
    std::string m_fileName;
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    bool m_isPlaying = false;
    
};
} // arkanoid

