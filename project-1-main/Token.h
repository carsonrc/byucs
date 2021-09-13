#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <ostream>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens - make sure to update switch with strings
    END_OF_FILE,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type = TokenType::UNDEFINED;
    std::string description;
    int lineNumber = 0;

public:
    Token(TokenType type, std::string description, int lineNumber) ;

    friend std::ostream& operator<<(std::ostream& os,const Token& token) ;

    // TODO: add other needed methods
};

#endif // TOKEN_H

