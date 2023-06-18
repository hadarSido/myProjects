#pragma once

#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace info_pair {

class UrlDataDownload
{
public:
    UrlDataDownload() = default;
    ~UrlDataDownload() = default;

    std::string download(std::string const& a_url);

private:
    curlpp::Easy m_request;
};

} // namespace info_pair
