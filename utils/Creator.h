#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED

#include <memory>


namespace utils
{
    template <typename T>
    struct Creator
    {
        static std::shared_ptr<T> create()
        {
            return std::make_shared<T>();
        }
    };

    // Шаблонный клас, для создания шаредпоинтеров
    template <typename T>
    struct SharedStrategy
    {
        typedef typename T TemplateType;
        typedef typename SharedStrategy<TemplateType> SomeType;
        typedef std::shared_ptr<TemplateType> Ptr;

        static typename SomeType::Ptr create()
        {
            return std::make_shared<TemplateType>();
        }

        typedef struct T : public SomeType {} TypeHolder;
    };
}

#define DECLARE_SHARED(classname) \
typedef utils::SharedStrategy<classname> StrategyType;\
typedef StrategyType::TypeHolder classname##S; \
typedef StrategyType::Ptr  classname##Ptr;


#endif // CREATOR_H_INCLUDED