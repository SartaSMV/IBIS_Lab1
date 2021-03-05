#include "permutationcipher.h"

PermutationCipher::PermutationCipher()
{
}

PermutationCipher::~PermutationCipher()
{
}

QString PermutationCipher::coding(QString text)
{
    int n = sqrt(text.size());
    if(n*n < text.size()) n++;

    QVector<QString> figure;

    figure.resize(n);
    for(int i = 0; i < n; i++)
    {
        figure[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            if(i*n + j < text.size()) figure[i][j] = text[i*n + j];
            else  figure[i][j] = '^';
        }
    }

    QString codeText;

    int x = 0, y = 0;
    int dx[] = {-1, 1, 1, 0};
    int dy[] = { 1,-1, 0, 1};

    while(x != n - 1 || y != n - 1)
    {
        for(int i = 0; i < 2; i++)
        {
            while(x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0 && figure[x + dx[i]][y + dy[i]] != '~')
            {
                codeText.push_back(figure[x][y]); figure[x][y] = '~';
                x += dx[i];
                y += dy[i];
            }
        }
        for(int i = 2; i < 4; i++)
        {
            if(x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0 && figure[x + dx[i]][y + dy[i]] != '~')
            {
                if(!(x + dx[i] == 0 || y + dy[i] == 0 || x + dx[i] == n-1 || y + dy[i] == n - 1)) continue;
                codeText.push_back(figure[x][y]); figure[x][y] = '~';
                x += dx[i];
                y += dy[i];
                break;
            }
        }
    }
    codeText.push_back(figure[x][y]);

    return codeText;
}

QString PermutationCipher::decoding(QString codeText)
{
    int n = sqrt(codeText.size());
    if(n*n < codeText.size()) n++;

    QVector<QString> figure;

    figure.resize(n);
    for(int i = 0; i < n; i++)
    {
        figure[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            figure[i][j] = '~';
        }
    }

    int x = 0, y = 0;
    int dx[] = {-1, 1, 1, 0};
    int dy[] = { 1,-1, 0, 1};

    while(x != n - 1 || y != n - 1)
    {
        for(int i = 0; i < 2; i++)
        {
            while(x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0 && figure[x + dx[i]][y + dy[i]] == '~')
            {
                figure[x][y] = codeText.front();
                codeText.remove(0, 1);
                x += dx[i];
                y += dy[i];
            }
        }
        for(int i = 2; i < 4; i++)
        {
            if(x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0 && figure[x + dx[i]][y + dy[i]] == '~')
            {
                if(!(x + dx[i] == 0 || y + dy[i] == 0 || x + dx[i] == n-1 || y + dy[i] == n - 1)) continue;
                figure[x][y] = codeText.front();
                codeText.remove(0, 1);
                x += dx[i];
                y += dy[i];
                break;
            }
        }
    }
    figure[x][y] = codeText.front();

    QString text;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(figure[i][j] != '^') text.push_back(figure[i][j]);
        }
    }

    return text;
}

