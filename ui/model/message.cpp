#include <string>
#include "../include/rapidjson.h"
#include <cstdio>

using namespace rapidjson;

class Message
{
  public:
    Message(const std::string &title, const std::string &content) : title_(title), content_(content) {}
    Message(const Message &rhs) : title_(rhs.title_), content_(rhs.content_) {}
    virtual ~Message();

    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();

        writer.String("title");
#if RAPIDJSON_HAS_STDSTRING
        writer.String(title_);
#else
        writer.String(title_.c_str(), static_cast<SizeType>(title_.length()));
#endif
        writer.String("content");
#if RAPIDJSON_HAS_STDSTRING
        writer.String(content_);
#else
        writer.String(content_.c_str(), static_cast<SizeType>(content_.length()));
#endif

        writer.EndObject();
    }

  private:
    std::string title_;
    std::string content_;
};

Message::~Message()
{
}