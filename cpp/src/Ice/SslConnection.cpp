// **********************************************************************
//
// Copyright (c) 2001
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#include <Ice/SslConnection.h>

void ::IceInternal::incRef(::IceSecurity::Ssl::Connection* p) { p->__incRef(); }
void ::IceInternal::decRef(::IceSecurity::Ssl::Connection* p) { p->__decRef(); }

IceSecurity::Ssl::Connection::Connection(const CertificateVerifierPtr& certificateVerifier) :
                             _certificateVerifier(certificateVerifier)
{
}

IceSecurity::Ssl::Connection::~Connection()
{
}

