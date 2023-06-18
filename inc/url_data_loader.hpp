#include <string>
#include <memory> // std::shared_ptr
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace InfoPair {

class UrlDataLoader 
{
public:
    UrlDataLoader() = default;
    ~UrlDataLoader() = default;

    void getData(std::string const& a_url, std::shared_ptr<std::string>& a_data);

private:
    curlpp::Easy m_request;
};

} // namespace InfoPair
