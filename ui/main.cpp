
#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>

#include "service/messageservice.cpp"
#include "include/crow_all.h"

using namespace std;

MessageService messageService;

int main()
{

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/")
        .name("index")([] {
            crow::mustache::context ctx;
            return crow::mustache::load("views/index.html").render();
        });

    CROW_ROUTE(app, "/assets/<path>")
        .name("assets")([] (string path){
            crow::mustache::context ctx;
            return crow::mustache::load("assets/" + path).render();
    });

    CROW_ROUTE(app, "/api-docs")
        .name("assets")([]{
            crow::mustache::context ctx;
            return crow::mustache::load("assets/swagger.json").render();
    });

    CROW_ROUTE(app, "/api/messages")
    ([](const crow::request& /*req*/, crow::response& res) {
        CROW_LOG_INFO << "find all messages";

        string body = messageService.findAll();
        res.set_header("Content-Type", "application/json;charset=UTF-8");
        res.write(body);
        res.end();
    });

    app
        .port(8080)
        .run();
}
