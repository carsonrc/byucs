#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <ostream>

enum class TokenType {
    ADD,
    COLON,
    COLON_DASH,
    COMMA,
    COMMENT,
    END_OF_FILE,
    FACTS,
    ID,
    LEFT_PAREN,
    MULTIPLY,
    PERIOD,
    QUERIES,
    QUESTION_MARK,
    RIGHT_PAREN,
    RULES,
    SCHEMES,
    STRING,
    UNDEFINED,
    WHITESPACE
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
    TokenType GetType() {return type;};
    std::string GetDescription() { return description; }

    friend std::ostream& operator<<(std::ostream& os,const Token& token) {
        std::string tokenType;
        switch (token.type) {
            case TokenType::ADD:           tokenType = "ADD";           break;
            case TokenType::COLON:         tokenType = "COLON";         break;
            case TokenType::COLON_DASH:    tokenType = "COLON_DASH";    break;
            case TokenType::COMMA:         tokenType = "COMMA";         break;
            case TokenType::COMMENT:       tokenType = "COMMENT";       break;
            case TokenType::END_OF_FILE:   tokenType = "EOF";           break;
            case TokenType::FACTS:         tokenType = "FACTS";         break;
            case TokenType::ID:            tokenType = "ID";            break;
            case TokenType::LEFT_PAREN:    tokenType = "LEFT_PAREN";    break;
            case TokenType::MULTIPLY:      tokenType = "MULTIPLY";      break;
            case TokenType::PERIOD:        tokenType = "PERIOD";        break;
            case TokenType::QUERIES:       tokenType = "QUERIES";       break;
            case TokenType::QUESTION_MARK: tokenType = "Q_MARK";        break;
            case TokenType::RIGHT_PAREN:   tokenType = "RIGHT_PAREN";   break;
            case TokenType::RULES:         tokenType = "RULES";         break;
            case TokenType::SCHEMES:       tokenType = "SCHEMES";       break;
            case TokenType::STRING:        tokenType = "STRING";        break;
            case TokenType::UNDEFINED:     tokenType = "UNDEFINED";     break;
            case TokenType::WHITESPACE:     tokenType = "WHITESPACE";   break;
            // no whitespace case because there is never a whitespace token generated
        }
        os << "(" << tokenType << ",\"" << token.description << "\"," << token.lineNumber << ")";
        return os;
    } ;

    // TODO: add other needed methods
};

#endif // TOKEN_H

