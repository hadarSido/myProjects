#pragma once
#include <string> //std::string

namespace info_pair {

class URLdata {
public:
    explicit URLdata(std::string const& a_title, std::string const& a_url);
    URLdata() = default;
    ~URLdata() = default; 
    URLdata(const URLdata &a_other) = default;                                      
    URLdata& operator=(const URLdata &a_other) = default;

    std::string const& getTitle() const noexcept;
    std::string const& getURL() const noexcept;
    size_t getTermCounter() const noexcept;
    void incrementTermCounter() noexcept;

    bool operator>(URLdata const& a_other) const noexcept;
    bool operator<(URLdata const& a_other) const noexcept;
    bool operator==(URLdata const& a_other) const noexcept;
    void operator+=(URLdata const& a_other) noexcept;

private:
    std::string m_title;
    std::string m_url;
    size_t m_termsCounter;
};

}//info_pair
