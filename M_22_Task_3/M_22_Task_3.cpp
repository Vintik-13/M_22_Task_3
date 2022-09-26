/*Задание 3. Анаграммы 
 
Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true,
если первая строка является анаграммой второй (то есть можно
получить первую строку из второй путём перестановки букв местами),
и false иначе. Для достижения хорошей асимптотики решения
рекомендуется использовать std::map*/

#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> strInMap(std::string str) {
    std::map<std::string, std::string> m_tmp;
    ;
    for (int i = 0; i < str.size(); i++) {
        std::string s;
        s += str[i];
        m_tmp.emplace(s, "");
    }
        
    return m_tmp;
}

bool anagrams(std::string str1, std::string str2) {
    std::map<std::string, std::string> m_str1 = strInMap(str1);
    std::map<std::string, std::string> m_str2 = strInMap(str2);
    
    std::map<std::string, std::string>::iterator it_str1 = m_str1.begin();
    std::map<std::string, std::string>::iterator it_str2 = m_str2.begin();

    int count{ 0 };
    for (int i = 0; i < m_str1.size(); i++) {
        if (it_str1->first == it_str2->first) {
            count++;
            it_str1++; it_str2++;
        }            
    }
    if (str1.size() >= str2.size())
        return count == str2.size() ? true : false;
    else
        return count == str1.size() ? true : false;
}

int main()
{
    std::string str1;
    std::string str2;
    std::cout << "Enter the first word for comparison\n";
    std::getline(std::cin, str1);
    std::cout << "the second word\n";
    std::getline(std::cin, str2);
    bool result = anagrams(str1, str2);
    if (result)
        std::cout << "Anagram";
    else
        std::cout << "Not an anagram";    
}

