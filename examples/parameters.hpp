///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Tavendo GmbH, Topology LP, and contributors.
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EXAMPLES_PARAMETERS_HPP
#define EXAMPLES_PARAMETERS_HPP

#include <boost/asio/ip/tcp.hpp>
#include <cstdint>
#include <string>

class parameters
{
public:
    parameters();

    bool debug() const;
    const std::string& realm() const;
    const boost::asio::ip::tcp::endpoint& rawsocket_endpoint() const;

    void set_debug(bool enabled);
    void set_realm(const std::string& realm);
    void set_rawsocket_endpoint(const std::string& ip_address, uint16_t port);

private:
    bool m_debug;
    std::string m_realm;
    boost::asio::ip::tcp::endpoint m_rawsocket_endpoint;
};

std::unique_ptr<parameters> get_parameters(int argc, char** argv);

#endif // EXAMPLES_PARAMETERS_HPP
