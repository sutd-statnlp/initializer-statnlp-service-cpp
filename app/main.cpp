
#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>

#include "service/messageservice.cpp"
#include "crow.h"

using namespace std;

MessageService messageService;

int main()
{

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/")
    .name("index")
    ([]{
        return "StatNLP Service";
    });


    CROW_ROUTE(app, "/api/messages")
    ([](const crow::request& /*req*/, crow::response& res) {
        CROW_LOG_INFO << "find all messages";

        string body = messageService.findAll();
        res.set_header("Content-Type", "application/json;charset=UTF-8");
        res.write(body);
        res.end();
    });

    crow::logger::setLogLevel(crow::LogLevel::Debug);

    app
        .port(8080)
        .run();
}
