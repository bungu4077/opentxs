// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_CORE_CRYPTO_OTCALLBACK_HPP
#define OPENTXS_CORE_CRYPTO_OTCALLBACK_HPP

#include "opentxs/Forward.hpp"

#ifdef SWIG
// clang-format off
%feature("director") OTCallback;
// clang-format on
#endif  // SWIG

namespace opentxs
{
class OTCallback
{
public:
    OTCallback() = default;
    EXPORT virtual ~OTCallback() = default;

    // Asks for password once. (For authentication when using nym.)
    EXPORT virtual void runOne(const char* szDisplay, OTPassword& theOutput)
        const = 0;

    // Asks for password twice. (For confirmation when changing password or
    // creating nym.)
    EXPORT virtual void runTwo(const char* szDisplay, OTPassword& theOutput)
        const = 0;
};
}  // namespace opentxs
#endif
