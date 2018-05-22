#ifndef LANGMGR_H_INCLUDED
#define LANGMGR_H_INCLUDED

#include <string>
#include <unordered_map>

class LangMgr
{
private:
    std::string lang_name;
    std::string folder_path;
    std::unordered_map<std::string, std::string> m_lang;
    std::string error_msg;
    static LangMgr *l_mgr;
    LangMgr();
    bool reInitLangMap();
public:
    ~LangMgr();
    static LangMgr* Init();
    std::string getFolderPath();
    bool setFolderPath(std::string path);
    std::string getLang();
    bool setLang(std::string lang);
    std::string getPhrase(std::string str_code);
    std::string getError();
};

#endif // LANGMGR_H_INCLUDED
