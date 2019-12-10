
#pragma once
#ifndef  POSTS_H
#define  POSTS_H
#include "../liberies/serverl/server_worker.h"


namespace handlers
{
    using namespace httplib;
    using namespace server;
    using namespace std; 

    class Posts
    {
        public:
           static bool handleList(const Request& req, Response& res){
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/hello.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }
    };
}

#endif
