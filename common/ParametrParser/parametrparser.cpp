#include "parametrparser.h"


#include <iostream>

bool ParametrParser::isOption(const std::string str)
{
    if( str[0] == optionLetter )
        return true;
    return false;
}

bool ParametrParser::isShortOption(const std::string str)
{
    if( str[0] == optionLetter && str[1] != optionLetter )
        return true;
    return false;
}

bool ParametrParser::isLongOption(const std::string str)
{
    if( str[0] == optionLetter && str[1] == optionLetter )
        return true;
    return false;
}

bool ParametrParser::outOfRange(const size_t i)
{
    return i >= _argv.size();
}

string ParametrParser::stripOptionPrefix(const std::string option)
{
    int prefixLength = 0;

    if( isLongOption(option) )
        prefixLength = longOptionPrefixLength;
    else if( isShortOption(option) )
        prefixLength = shortOptionPrefixLength;

    return option.substr( prefixLength, option.length());
}

ParametrParser::ParametrParser(int argc, char **argv)
{
    for(int i = 0; i < argc; ++i){
        _argv.push_back( argv[i] );
    }
}

void ParametrParser::setOptionPrefix(char letter)
{
    optionLetter = letter;
}

void ParametrParser::setOption(std::string shortKey, std::string longKey, ParametrParser::func callback)
{
    _longCallback[longKey]   = callback;
    _shortCallback[shortKey] = callback;
}

void ParametrParser::setShortOption(std::string key, ParametrParser::func callback)
{
    _shortCallback[key] = callback;
}

void ParametrParser::setLongOption(std::string key, ParametrParser::func callback)
{
    _longCallback[key] = callback;
}

void ParametrParser::exec()
{
    string currentOption;
    try{
        for(size_t i = 0; i < _argv.size(); ++i){
            currentOption = _argv[i];

            if( ! isOption( _argv[i] ) )
                continue;

            string opt = stripOptionPrefix( _argv[i] );
            string optParametr = ( ! outOfRange(i+1) )? _argv[i+1] : ""; // #FixMe

            // map(_argv[i])[opt](optParametr);
            if( isShortOption( _argv[i] ) ){
                _shortCallback[ opt ]( optParametr );
                continue;
            }
            if( isLongOption( _argv[i] ) ){
                _longCallback[ opt ]( optParametr );
                continue;
            }
        }
    }catch( std::bad_function_call ){
        throw UnknownOption(currentOption);
    }catch(...){
        std::cerr << "Unknown error" << std::endl;
    }
}
