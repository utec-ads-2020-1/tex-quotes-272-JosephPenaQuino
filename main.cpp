#include <iostream>
#include <string>
#include <stdio.h>

std::string replace(std::string text, int it, std::string new_text)
{
    std::string res;
    for (int i = 0; i < it; ++i)
        res = res + text[i];
    res = res + new_text;
    for (int i = it+1; i < text.size(); ++i)
        res = res + text[i];
    return res;
}

void replace_quote(std::string &text, int it)
{
    static bool is_first_quote = true;
    text = replace(text, it, is_first_quote ? "``" : "''" );
    is_first_quote = !is_first_quote;
}

std::string parse(std::string text)
{
    std::string parsed_text = text;
    for (int i = 0; i < parsed_text.size(); ++i)
        if (parsed_text[i] == '\"')
            replace_quote(parsed_text, i);

    return parsed_text;
}

int main()
{
    std::string text;
    bool first = true;
    while (getline(std::cin, text))
    {
        if (!first)
            std::cout << std::endl;
        first=false;
        std::string parsed_text = parse(text);
        std::cout << parsed_text ;
    }
    
}