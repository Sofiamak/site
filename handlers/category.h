
#pragma once
#ifndef  CATEGORY_H
#define  CATEGORY_H
#include "../lib/header/server_worker.h"


namespace handlers
{
    using namespace httplib;
    using namespace server;
    using namespace std; 

    class Category
    {
        public:
           static bool handleList(const Request& req, Response& res){
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/about.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }
    };
}

#endif
