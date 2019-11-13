#pragma once
#ifndef LIB_ROUTER
#define LIB_ROUTER

#include "lib/header/server_worker.h"


#include "handlers/page.h"
#include "handlers/posts.h"


using namespace server;
using namespace handlers;


namespace router
{ 
   class Router
   {

   private:
      Page  page;
      Posts  post;
   
   public:
      void Run(ServerWorker &sw){
   
         sw.ser.Get("/posts",post.handleList);
         sw.ser.Get("/page", page.handleList);

      }
   };
};
 
#endif