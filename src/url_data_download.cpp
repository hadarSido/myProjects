#include <sstream> // std::ostringstream
#include <string>
#include <exception>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "url_data_download.hpp"

namespace info_pair {

std::string UrlDataDownload::download(std::string const& a_url)
{
    std::ostringstream responseStream;
    try {
        curlpp::Cleanup cleanAuto;
        m_request.setOpt(new curlpp::options::Url(a_url));

        m_request.setOpt(new curlpp::options::WriteStream(&responseStream));

        m_request.perform();
    }
    catch(curlpp::RuntimeError const& e) {
        throw std::runtime_error("url data loader: " + static_cast<std::string>(e.what()));
	}
	catch(curlpp::LogicError const& e) {
		throw std::runtime_error("url data loader: " + static_cast<std::string>(e.what()));
	}
    catch(...) {
        throw std::runtime_error("url data loader: Unknown Error \n");
    }
    return responseStream.str();
}

} // namespace info_pair
