#include <algorithm>
#include <array>
#include <memory>
#include <print>

#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/this_coro.hpp>
#include <boost/cobalt.hpp>
#include <boost/cobalt/detached.hpp>
#include <boost/cobalt/op.hpp>
#include <boost/cobalt/promise.hpp>

#include <sys/socket.h>

using boost::asio::ip::tcp;
constexpr uint16_t port = 31415U;
using AcceptorPtr       = std::unique_ptr<tcp::acceptor>;
using SocketPtr         = std::unique_ptr<tcp::socket>;

boost::cobalt::detached resendData(SocketPtr socket)
{
    std::array<char, 1024> arrBuffer{};

    auto buffer = boost::asio::buffer(arrBuffer);
    auto sizeRead = co_await socket->async_read_some(buffer, boost::cobalt::use_op);

    std::println("Read {} bytes of data", sizeRead);

    auto sizeWrite = co_await socket->async_write_some(buffer, boost::cobalt::use_op);

    std::println("Wrote {} bytes of data", sizeWrite);

    arrBuffer = {};

    resendData(std::move(socket));

    co_return;
}

boost::cobalt::promise<void> acceptConnections(AcceptorPtr acceptor)
{
    std::println("Accepting connections on port {}", port);

    while (true)
    {
        auto socket = co_await acceptor->async_accept(boost::cobalt::use_op);

        std::println("Connection received from: {}", socket.remote_endpoint().address().to_string());

        resendData(std::make_unique<tcp::socket>(std::move(socket)));
    }

    co_return;
}

boost::cobalt::main co_main(int, char**)
{
    std::println("Hello there!");

    auto executor    = boost::cobalt::this_coro::executor;
    auto endpoint = tcp::endpoint(tcp::v4(), port);
    auto acceptorPtr = std::make_unique<tcp::acceptor>(tcp::acceptor(co_await executor, endpoint));

    co_await acceptConnections(std::move(acceptorPtr));

    co_return 0;
}
