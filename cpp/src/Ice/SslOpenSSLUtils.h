// **********************************************************************
//
// Copyright (c) 2001
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#include <openssl/ssl.h>
#include <string>

namespace IceSecurity
{

namespace Ssl
{

namespace OpenSSL
{

std::string getGeneralizedTime(ASN1_GENERALIZEDTIME *tm);

std::string getUTCTime(ASN1_UTCTIME *tm);

std::string getASN1time(ASN1_TIME *tm);

}

}

}
