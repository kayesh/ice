// **********************************************************************
//
// Copyright (c) 2001
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef ICE_RSA_KEY_PAIR_H
#define ICE_RSA_KEY_PAIR_H

#include <IceUtil/Config.h>
#include <IceUtil/Shared.h>
#include <string>
#include <vector>
#include <openssl/ssl.h>
#include <Ice/BuiltinSequences.h>
#include <Ice/SslRSAKeyPairF.h>
#include <Ice/SslRSACertificateGenF.h>
#include <Ice/SslRSAPrivateKeyF.h>
#include <Ice/SslRSAPublicKeyF.h>

#ifdef WIN32
#   ifdef ICE_API_EXPORTS
#       define ICE_API __declspec(dllexport)
#   else
#       define ICE_API __declspec(dllimport)
#   endif
#else
#   define ICE_API /**/
#endif

namespace IceSecurity
{

namespace Ssl
{

namespace OpenSSL
{

using namespace std;
using IceUtil::Shared;

class RSAKeyPair : public Shared
{

public:
    // Construction from Base64 encodings
    RSAKeyPair(const std::string&, const std::string&);

    // Construction from ByteSeq
    RSAKeyPair(const Ice::ByteSeq&, const Ice::ByteSeq&);

    ~RSAKeyPair();

    // Conversions to Base64 encodings
    void keyToBase64(std::string&);
    void certToBase64(std::string&);

    // Conversions to ByteSequences
    void keyToByteSeq(Ice::ByteSeq&);
    void certToByteSeq(Ice::ByteSeq&);

    // Get the key structures
    RSA* getRSAPrivateKey() const;
    X509* getX509PublicKey() const;

private:
    // RSAKeyPair(RSA*, X509*);
    RSAKeyPair(const RSAPrivateKeyPtr&, const RSAPublicKeyPtr&);

    friend class RSACertificateGen;

    // void byteSeqToKey(const Ice::ByteSeq&);
    // void byteSeqToCert(const Ice::ByteSeq&);
    // void ucharToByteSeq(unsigned char*, int, Ice::ByteSeq&);
    // unsigned char* byteSeqToUChar(const Ice::ByteSeq&);

    // RSA* _privateKey;
    // X509* _publicKey;

    RSAPrivateKeyPtr _privateKey;
    RSAPublicKeyPtr _publicKey;

};

}

}

}

#endif
