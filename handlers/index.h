
#pragma once
#ifndef  INDEX_H
#define  INDEX_H
#include "../liberies/serverl/server_worker.h"
#include "../web/index.h"

namespace handlers
{
    using namespace httplib;
    using namespace server;
    using namespace std; 

    class Index
    {
        public:

           static bool handleList(const Request& req, Response& res){
               
                // char * content;
                // long long size = 0;
                // // inx.Container();
                // // auto s=inx.Templater();
                // // content[s.size() + 1];
	            // // strcpy(content, s.c_str());
                // content="kkk";
                
                // IndexHtml::getInstance()->Container();
               
                // char buf[BUFSIZ];
                // snprintf(buf, sizeof(buf), content, res.status);
                // res.set_content(buf, "text/html");    
            }   
    };


    //  class Singleton
    //         {
    //         private:
    //             static Singleton * p_instance;
    //             // Конструкторы и оператор присваивания недоступны клиентам
    //             Singleton() {}
    //             Singleton( const Singleton& );  
    //             Singleton& operator=( Singleton& );
    //         public:
    //             static Singleton * getInstance() {
    //                 if(!p_instance)           
    //                     p_instance = new Singleton();
    //                 return p_instance;
    //             }
    // };
}

#endif
