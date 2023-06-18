#pragma once
#include <string> //std::string
#include <vector>
#include <utility> //std::pair

namespace info_pair {

class PagesConnection {
public:
    explicit PagesConnection(size_t a_reserve);
    ~PagesConnection() = default; 
    PagesConnection(const PagesConnection &a_other) = default;                                      
    PagesConnection& operator=(const PagesConnection &a_other) = default;

    size_t addUrl(std::string const& a_url) noexcept;
    void addUrlPerents(size_t a_index, size_t a_perentLocation);
    void addUrlchildrens(size_t a_index, size_t a_childLocation);

    size_t findUrlIndex(std::string const& a_url) const noexcept;

    std::vector<size_t> const& getChildrens(size_t a_index) const;
    std::vector<size_t> const& getPerents(size_t a_index) const;
    std::string const& getUrlData(size_t a_index) const noexcept;

    std::vector<std::string> const& getPagesData() const noexcept;

    size_t size() const noexcept;

private:
    std::vector<std::string> m_pagesData;
    std::vector<std::vector<size_t>> m_perentsIndex;
    std::vector<std::vector<size_t>> m_childrensIndex;
};

}//info_pair
