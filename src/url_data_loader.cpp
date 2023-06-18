#include <sstream> // std::ostringstream
#include <string>
#include <memory> // std::shared_ptr
#include <exception>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "url_data_loader.hpp"

namespace InfoPair {

void UrlDataLoader::getData(std::string const& a_url, std::shared_ptr<std::string>& a_data)
{
    try {
        curlpp::Cleanup cleanAuto;
        m_request.setOpt(new curlpp::options::Url(a_url));

        std::ostringstream responseStream;
        m_request.setOpt(new curlpp::options::WriteStream(&responseStream));

        m_request.perform();
        *a_data = responseStream.str();

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
}

} // namespace InfoPair
