#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED

#include <memory>


namespace utils
{
    // Шаблонный клас, для создания шаредпоинтеров
    template <typename T>
    struct Creator
    {
        static std::shared_ptr<T> create()
        {
            return std::make_shared<T>();
        }
    };
}

#endif // CREATOR_H_INCLUDED