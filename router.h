#pragma once
#ifndef LIB_ROUTER
#define LIB_ROUTER


#include "liberies/serverl/server_worker.h"
#include "handlers/posts.h"
#include "handlers/index.h"

using namespace server;
using namespace handlers;


namespace router
{ 
   class Router
   {

   private:
      Posts  post;
      Index index;

     

   public:
      void Run(ServerWorker &sw){
         sw.ser.Get("/post",  post.handleList);
         sw.ser.Get("/index", index.handleList);
      }
   };
};
 
#endif