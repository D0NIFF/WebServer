#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <thread>
#include <memory>

/* For the short record a tcp */
using BoostTCP = boost::asio::ip::tcp;

namespace Network
{
    class Request;

    class HttpServer
    {
    public:
        HttpServer(unsigned int port);
        HttpServer(unsigned int port, std::string domainsPath);
        ~HttpServer();

        void start();

        boost::asio::io_service io_service;
    private:
        
        BoostTCP::acceptor acceptor;
        std::shared_ptr<std::thread> sThread;
        std::string domainsPath;

        /*
            
        */
        void runServiceLoop();
        void beginAcceptingConnections();
        void handleNewConnection(boost::shared_ptr<Request> req, const boost::system::error_code& error);
    };
};

#endif // HTTPSERVER_H
