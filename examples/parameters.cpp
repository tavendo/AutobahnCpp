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

#include "parameters.hpp"

#include <cstdlib>
#include <boost/asio/ip/address.hpp>
#include <boost/program_options.hpp>
#include <iostream>

namespace {
const std::string LOCALHOST_IP_ADDRESS_STRING("127.0.0.1");
const boost::asio::ip::address LOCALHOST_IP_ADDRESS(
        boost::asio::ip::address::from_string(LOCALHOST_IP_ADDRESS_STRING));
const std::string DEFAULT_REALM("realm1");
const uint16_t DEFAULT_RAWSOCKET_PORT(8000);
const uint16_t DEFAULT_RAWSOCKET_SSL_PORT(8010);
const std::string DEFAULT_UDS_PATH("/tmp/crossbar.sock");
}

parameters::parameters()
    : m_debug(false)
    , m_realm(DEFAULT_REALM)
    , m_rawsocket_endpoint(LOCALHOST_IP_ADDRESS, DEFAULT_RAWSOCKET_PORT)
    , m_rawsocket_ssl_endpoint(LOCALHOST_IP_ADDRESS, DEFAULT_RAWSOCKET_SSL_PORT)
#ifdef BOOST_ASIO_HAS_LOCAL_SOCKETS
    , m_uds_endpoint(DEFAULT_UDS_PATH)
#endif
{
}

bool parameters::debug() const
{
    return m_debug;
}

const std::string& parameters::realm() const
{
    return m_realm;
}

const boost::asio::ip::tcp::endpoint& parameters::rawsocket_endpoint() const
{
    return m_rawsocket_endpoint;
}

const boost::asio::ip::tcp::endpoint& parameters::rawsocket_ssl_endpoint() const
{
    return m_rawsocket_ssl_endpoint;
}

#ifdef BOOST_ASIO_HAS_LOCAL_SOCKETS
const boost::asio::local::stream_protocol::endpoint& parameters::uds_endpoint() const
{
    return m_uds_endpoint;
}
#endif

void parameters::set_debug(bool value)
{
    m_debug = value;
}

void parameters::set_realm(const std::string& realm)
{
    m_realm = realm;
}

void parameters::set_rawsocket_endpoint(const std::string& ip_address, uint16_t port)
{
    m_rawsocket_endpoint = boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string(ip_address), port);
}

void parameters::set_rawsocket_ssl_endpoint(const std::string& ip_address, uint16_t port)
{
    m_rawsocket_ssl_endpoint = boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string(ip_address), port);
}

#ifdef BOOST_ASIO_HAS_LOCAL_SOCKETS
void parameters::set_uds_endpoint(const std::string& path)
{
    m_uds_endpoint = boost::asio::local::stream_protocol::endpoint(path);
}
#endif 

std::unique_ptr<parameters> get_parameters(int argc, char** argv)
{
    std::unique_ptr<parameters> params(new parameters);

    namespace po = boost::program_options;
    po::options_description description("options");
    description.add_options()
            ("help", "Display this help message")
            ("debug,d", po::bool_switch()->default_value(false),
                    "Enable debug logging.")
            ("realm,r", po::value<std::string>()->default_value(DEFAULT_REALM),
                    "The realm to join on the wamp router.")
            ("uds-path,u", po::value<std::string>()->default_value(DEFAULT_UDS_PATH),
                    "The unix domain socket path the wamp router is listening for connections on.")
            ("rawsocket-ip,h", po::value<std::string>()->default_value(LOCALHOST_IP_ADDRESS_STRING),
                    "The ip address of the host running the wamp router.")
            ("rawsocket-port,p", po::value<uint16_t>()->default_value(DEFAULT_RAWSOCKET_PORT),
                    "The port that the wamp router is listening for connections on.");

    po::variables_map variables;
    try {
        po::store(po::parse_command_line(argc, argv, description), variables);

        if (variables.count("help")) {
            std::cout << "Example Parameters" << std::endl
                    << description << std::endl;
            exit(0);
        }

        po::notify(variables);
    } catch(po::error& e) {
        std::cerr << "error: " << e.what() << std::endl << std::endl;
        std::cerr << description << std::endl;
        exit(-1);
    }

    params->set_debug(variables["debug"].as<bool>());
    params->set_realm(variables["realm"].as<std::string>());
    params->set_rawsocket_endpoint(
            variables["rawsocket-ip"].as<std::string>(),
            variables["rawsocket-port"].as<uint16_t>());

#ifdef BOOST_ASIO_HAS_LOCAL_SOCKETS
    params->set_uds_endpoint(
            variables["uds-path"].as<std::string>());
#endif
    return params;
}
