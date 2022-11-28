///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Crossbar.io Technologies GmbH and contributors
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

#ifndef AUTOBAHN_WAMP_TCP_TRANSPORT_HPP
#define AUTOBAHN_WAMP_TCP_TRANSPORT_HPP

#include "boost_config.hpp"
#include "wamp_rawsocket_transport.hpp"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace autobahn {

/*!
 * A transport that provides rawsocket support over TCP.
 */
class wamp_tcp_transport :
        public wamp_rawsocket_transport<boost::asio::ip::tcp::socket>
{
public:
    wamp_tcp_transport(
            boost::asio::io_context& io_context,
            const boost::asio::ip::tcp::endpoint& remote_endpoint,
            bool debug_enabled=false);
    virtual ~wamp_tcp_transport() override;

    virtual boost::future<void> connect() override;
};

} // namespace autobahn

#include "wamp_tcp_transport.ipp"

#endif // AUTOBAHN_WAMP_TCP_TRANSPORT_HPP
