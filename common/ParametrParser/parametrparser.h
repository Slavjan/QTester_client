#ifndef PARAMETRPARSER_H
#define PARAMETRPARSER_H

#include <string>
#include <vector>
#include <map>
#include <functional>

using std::string;
using std::map;
using std::vector;
using std::function;

class ParametrParser
{
private:
    typedef function<void(string)> func;
    char optionLetter = '-';
    static const char parametrModificator = ':';
    static const int longOptionPrefixLength = 2;
    static const int shortOptionPrefixLength = 1;


    vector<string> _argv;
    map<string, func> _shortCallback;
    map<string, func> _longCallback;

    bool isOption(const string);
    bool isShortOption(const string);
    bool isLongOption(const string);

    bool outOfRange(const size_t i);

    string stripOptionPrefix(string);
public:
    ParametrParser(int argc, char** argv);
    void setOptionPrefix(char letter);

    void setOption(string shortKey, string longKey, func callback);
    void setShortOption(string key, func callback);
    void setLongOption(string key, func callback);
    void exec();

    class UnknownOption{
    public:
        string optionName;
        UnknownOption(string opt){optionName=opt;}
    };
};

#endif // PARAMETRPARSER_H
