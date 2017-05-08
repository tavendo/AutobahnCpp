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

#ifndef AUTOBAHN_WAMP_UDS_TRANSPORT_HPP
#define AUTOBAHN_WAMP_UDS_TRANSPORT_HPP

#include "wamp_rawsocket_transport.hpp"

#include <boost/asio/local/stream_protocol.hpp>

namespace autobahn {

typedef boost::asio::local::stream_protocol::socket uds_socket_type;
typedef typename uds_socket_type::lowest_layer_type::endpoint_type uds_endpoint_type;

/*!
 * A transport that provides rawsocket support over unix domain sockets (UDS).
 */
class wamp_uds_transport :
        public wamp_rawsocket_transport<uds_socket_type>
{
public:
    wamp_uds_transport(
            boost::asio::io_service& io_service,
            const uds_endpoint_type& remote_endpoint,
            bool debug_enabled=false)
    : wamp_rawsocket_transport<uds_socket_type>(
            remote_endpoint, debug_enabled)
    , m_socket(io_service) {}

    virtual uds_socket_type& socket() { return m_socket; }
    virtual const uds_socket_type& const_socket() const { return m_socket; }
private:
    uds_socket_type m_socket;
};

} // namespace autobahn

#endif // AUTOBAHN_WAMP_UDS_TRANSPORT_HPP
