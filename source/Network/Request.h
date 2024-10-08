#ifndef REQUEST_H
#define REQUEST_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind/bind.hpp>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

using BoostTCP = boost::asio::ip::tcp;

namespace Network
{
    class Request : public boost::enable_shared_from_this<Request>
    {
    public:
        Request(boost::asio::io_service& io_service);
        Request(boost::asio::io_service& io_service, std::string path);
        void processRequest();

        std::shared_ptr<BoostTCP::socket> socket;

    private:
        boost::asio::streambuf request;
        boost::asio::streambuf response;
        std::string domainsPath;

        static std::string readFile(const std::string& path);
        void handleReadCompletion(const boost::system::error_code& ec, std::size_t bytes_transferred);
        void handleWriteCompletion(const boost::system::error_code& ec, std::size_t bytes_transferred);
    };
};

#endif // REQUEST_H
