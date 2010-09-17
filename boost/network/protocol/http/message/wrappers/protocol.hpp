#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PROTOCOL_HPP_20100619
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PROTOCOL_HPP_20100619

// Copyright 2010 (c) Dean Michael Berris.
// Copyright 2010 (c) Sinefunc, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/network/protocol/http/request_concept.hpp>
#include <boost/concept/requires.hpp>

namespace boost { namespace network { namespace http {

    template <class Tag>
    class basic_request;

    namespace impl {
        template <class Tag>
        struct protocol_wrapper {
            basic_request<Tag> const & message_;
            protocol_wrapper(basic_request<Tag> const & message)
                : message_(message) {}
            typedef typename basic_request<Tag>::string_type string_type;
            operator string_type() {
                return message_.protocol();
            }
        };
    }

    template <class Tag> inline
    BOOST_CONCEPT_REQUIRES(((Request<basic_request<Tag> >)),
        (impl::protocol_wrapper<Tag>))
    protocol(basic_request<Tag> const & request) {
        return impl::protocol_wrapper<Tag>(request);
    }

} // namespace http

} // namespace network

} // namespace boost

#endif // BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PROTOCOL_HPP_20100619