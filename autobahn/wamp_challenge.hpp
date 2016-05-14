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

#ifndef AUTOBAHN_WAMP_CHALLENGE_HPP
#define AUTOBAHN_WAMP_CHALLENGE_HPP

namespace autobahn {

/// Represents a topic subscription.
class wamp_challenge
{
public:
    wamp_challenge(
        const std::string & authmethod,
        const std::string & challenge = "",
        const std::string & salt = "",
        int iteratons = -1,
        int keylen = -1
       );

    wamp_challenge( const wamp_challenge & );

    const std::string & challenge() const;
    const std::string & authmethod() const;
    const std::string & salt() const;
    int iterations() const;
    int keylen() const;



private:
    // authmethod
    std::string m_authmethod;

    // used to "digest" the secret for transport
    std::string m_challenge;

    /////////////////////////////////////////
    // if authmethod is "wampcra"
    // and the secret is stored as a derived_key
    // with salt, iterations and a given keylen.
    std::string m_salt;
    int m_iterations;
    int m_keylen;
};

} // namespace autobahn

#include "wamp_challenge.ipp"

#endif // AUTOBAHN_WAMP_CHALLENGE_HPP