#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <ostream>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    // TODO: add the other types of tokens - make sure to update switch with strings
    END_OF_FILE,
    PERIOD,
    QUESTION_MARK,
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
    std::string works = "kinda";
    Token(TokenType type, std::string description, int lineNumber) ;

    friend std::ostream& operator<<(std::ostream& os,const Token& token) {
        std::string tokenType;
        switch (token.type) {
            case TokenType::COLON:         tokenType = "COLON";         break;
            case TokenType::COLON_DASH:    tokenType = "COLON_DASH";    break;
            case TokenType::COMMA:         tokenType = "COMMA";         break;
            case TokenType::END_OF_FILE:   tokenType = "EOF";           break;
            case TokenType::PERIOD:        tokenType = "PERIOD";        break;
            case TokenType::QUESTION_MARK: tokenType = "QUESTION_MARK"; break;
            case TokenType::UNDEFINED:     tokenType = "UNDEFINED";     break;
        }
        os << "(" << tokenType << ",\"" << token.description << "\"," << token.lineNumber << ")" << std::endl;
        return os;
    } ;

    // TODO: add other needed methods
};

#endif // TOKEN_H

