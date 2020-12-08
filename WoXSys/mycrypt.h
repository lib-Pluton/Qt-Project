#ifndef SIMPLECRYPT_H
#define SIMPLECRYPT_H
#include <QString>
#include <QVector>
#include <QFlags>
#include "base64.h"
#include "xor.h"
class SimpleCrypt
{
public:
    enum CompressionMode {
        CompressionAuto,    /*!< Only apply compression if that results in a shorter plaintext. */
        CompressionAlways,  /*!< Always apply compression. Note that for short inputs, a compression may result in longer data */
        CompressionNever    /*!< Never apply compression. */
    };
    enum IntegrityProtectionMode {
        ProtectionNone,    /*!< The integerity of the encrypted data is not protected. It is not really possible to detect a wrong key, for instance. */
        ProtectionChecksum,/*!< A simple checksum is used to verify that the data is in order. If not, an empty string is returned. */
        ProtectionHash     /*!< A cryptographic hash is used to verify the integrity of the data. This method produces a much stronger, but longer check */
    };
    enum Error {
        ErrorNoError,         /*!< No error occurred. */
        ErrorNoKeySet,        /*!< No key was set. You can not encrypt or decrypt without a valid key. */
        ErrorUnknownVersion,  /*!< The version of this data is unknown, or the data is otherwise not valid. */
        ErrorIntegrityFailed, /*!< The integrity check of the data failed. Perhaps the wrong key was used. */
    };
    SimpleCrypt();
    explicit SimpleCrypt(quint64 key);
    void setKey(quint64 key);
    bool hasKey() const {return !m_keyParts.isEmpty();}
    void setCompressionMode(CompressionMode mode) {m_compressionMode = mode;}
    CompressionMode compressionMode() const {return m_compressionMode;}
    void setIntegrityProtectionMode(IntegrityProtectionMode mode) {m_protectionMode = mode;}
    IntegrityProtectionMode integrityProtectionMode() const {return m_protectionMode;}
    Error lastError() const {return m_lastError;}
    QString encryptToString(const QString& plaintext) ;
    QString encryptToString(QByteArray plaintext) ;
    QByteArray encryptToByteArray(const QString& plaintext) ;
    QByteArray encryptToByteArray(QByteArray plaintext) ;
    QString decryptToString(const QString& cyphertext) ;
    QByteArray decryptToByteArray(const QString& cyphertext) ;
    QString decryptToString(QByteArray cypher) ;
    QByteArray decryptToByteArray(QByteArray cypher) ;
    enum CryptoFlag{CryptoFlagNone = 0,
                    CryptoFlagCompression = 0x01,
                    CryptoFlagChecksum = 0x02,
                    CryptoFlagHash = 0x04
                   };
    Q_DECLARE_FLAGS(CryptoFlags, CryptoFlag);
private:

    void splitKey();

    quint64 m_key;
    QVector<char> m_keyParts;
    CompressionMode m_compressionMode;
    IntegrityProtectionMode m_protectionMode;
    Error m_lastError;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(SimpleCrypt::CryptoFlags)

#endif
