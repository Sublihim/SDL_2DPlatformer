#include "LangMgr.h"
#include <stdio.h>
#include "Debug.h"

LangMgr* LangMgr::l_mgr = 0;

LangMgr::LangMgr()
{
    lang_name = "en";
    folder_path = "lang";
    error_msg = "ok";
}

LangMgr::~LangMgr()
{
    debug() << "LangMgr end" << std::endl;
}

LangMgr* LangMgr::Init()
{
    if(l_mgr == 0)
        l_mgr = new LangMgr();
    return l_mgr;
}

bool LangMgr::reInitLangMap()
{
    std::string file_path = folder_path + "/" + lang_name + ".lng";
    FILE *in = fopen(file_path.c_str(), "r");
    std::string s_key = "";
    std::string s_val = "";
    bool b_key = true;
    char tmp_ch;
    if(in)
    {
        fscanf(in, "%c", &tmp_ch);
        while(!feof(in))
        {
            if(tmp_ch == '=')
                b_key = false;
            else if(tmp_ch == '\n' || tmp_ch == '\r')
            {
                if( s_key != "" && s_val != "")
                    m_lang[s_key] = s_val;
                s_key = "";
                s_val = "";
                b_key = true;
            }
            else
            {
                if(b_key)
                    s_key += tmp_ch;
                else s_val += tmp_ch;
            }

            fscanf(in, "%c", &tmp_ch);
        }

        if( s_key != "" && s_val != "")
            m_lang[s_key] = s_val;
        
        fclose(in);
    }
    else
    {
        error_msg = "Ошибка! Не удалось открыть языковой файл " + file_path;
        return false;
    }

    return true;
}

std::string LangMgr::getFolderPath()
{
    // Возвращает текущий путь до папки
    // с языковыми файлами
    return folder_path;
}

bool LangMgr::setFolderPath(std::string path)
{
    // Задает путь к папке
    // с языковыми файлами
    folder_path = path;
    return reInitLangMap();
}

std::string LangMgr::getLang()
{
    // Возвращаем текущий язык
    return lang_name;
}

bool LangMgr::setLang(std::string lang)
{
    // Устанавливаем текущий язык
    lang_name = lang;
    return reInitLangMap();
}

std::string LangMgr::getPhrase(std::string str_code)
{
    std::string res = "";
    auto phrase = m_lang.find(str_code);
    if(phrase != m_lang.end())
        res = phrase->second;
    return res;
}

std::string LangMgr::getError()
{
    return error_msg;
}