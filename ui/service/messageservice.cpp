#include <vector>
#include <string.h>
#include "../model/message.cpp"

using namespace std;

class MessageService
{
  public:
    string findAll()
    {
        std::vector<Message> messages;
        for (int i = 0; i < 8; i++)
        {
            messages.push_back(Message("title" + to_string(i), "content" + to_string(i)));
        }
        return toJson(messages);
    }

    string toJson(vector<Message> messages)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);

        writer.StartArray();
        for (std::vector<Message>::const_iterator messageItr = messages.begin(); messageItr != messages.end(); ++messageItr)
            messageItr->Serialize(writer);
        writer.EndArray();

        return sb.GetString();
    }
};
