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

#include "test/wamp_test.hpp"
#include <catch2/catch.hpp>

struct Config
{
    std::string realm{"realm1"};
    std::string uri{"ws://127.0.0.1:8080/ws"};
    bool debug{false};
};

TEST_CASE_METHOD(wamp_test::fixture<Config>, "WAMP AUTH: TICKET")
{
    bool joined_realm_with_success = join_realm(
        "client1",
        wamp_test::Ticket("ticket"),
        [&](Transport& transport, Session& session)
        {
            std::string received_data;
            session.subscribe(
                "com.example.topic",
                [&received_data](const autobahn::wamp_event& event)
                {
                    received_data = event->argument<std::string>(0);
                }
            );
            REQUIRE(1 == call<int>("com.example.publish", std::tuple<>()).get());
            REQUIRE("data='1'" == received_data);
            REQUIRE(2 == call<int>("com.example.publish", std::tuple<>()).get());
            REQUIRE("data='2'" == received_data);
            REQUIRE(3 == call<int>("com.example.publish", std::tuple<>()).get());
            REQUIRE("data='3'" == received_data);
        });
    REQUIRE(true == joined_realm_with_success);
}
