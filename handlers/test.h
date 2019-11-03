
#pragma once
#ifndef  TEST_H
#define  TEST_H
#include "../lib/header/server_worker.h"

namespace handlers
{
    using namespace httplib;
    using namespace server;
    using namespace std; 

    class Test
    {
        public:
           
            static bool handle404(const Request& req, Response& res) {
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/404.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }
            
            static bool handleAbout(const Request& req, Response& res){
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/about.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }
            
            static bool handleHome(const Request& req, Response& res) {
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/blog-home-1.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }

            static bool handleHome2(const Request& req, Response& res) {
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/blog-home-2.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }

            static bool handleSidebar(const Request& req, Response& res) {
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/sidebar.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }

            static bool handleBlogPost(const Request& req, Response& res){
                char * content;
                long long size = 0;
                ServerWorker::FileGetContents("web/blog-post.html", content, size);
                char buf[BUFSIZ];
                snprintf(buf, sizeof(buf), content, res.status);
                res.set_content(buf, "text/html");    
            }
    };
}

#endif