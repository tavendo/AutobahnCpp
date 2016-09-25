///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Tavendo GmbH
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

#ifndef AUTOBAHN_HPP
#define AUTOBAHN_HPP

#ifdef _WIN32
#define MSGPACK_DISABLE_LEGACY_CONVERT
#define MSGPACK_DEFAULT_API_VERSION 1
#define MSGPACK_DISABLE_LEGACY_CONVERT
#endif

#include "wamp_event.hpp"
#include "wamp_invocation.hpp"
#include "wamp_session.hpp"
#include "wamp_tcp_transport.hpp"
#include "wamp_ssl_transport.hpp"
#include "wamp_transport.hpp"
#ifdef BOOST_ASIO_HAS_LOCAL_SOCKETS
#include "wamp_uds_transport.hpp"
#endif
/*! \mainpage Reference Documentation
 *
 * Welcome to the reference documentation of <b>Autobahn</b>|Cpp.<br>
 *
 * For a more gentle introduction, please visit http://autobahn.ws/cpp/.
 */

#endif // AUTOBAHN_HPP
