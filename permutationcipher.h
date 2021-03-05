#ifndef PERMUTATIONCIPHER_H
#define PERMUTATIONCIPHER_H

#include <QString>
#include <QVector>

class PermutationCipher
{
public:
    PermutationCipher();
    ~PermutationCipher();

    QString coding(QString text);
    QString decoding(QString codetext);
};

#endif // PERMUTATIONCIPHER_H
