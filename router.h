#pragma once
#ifndef LIB_ROUTER
#define LIB_ROUTER

// #include "lib/header/server_worker.h"
// #include "handlers/product.h"
// #include "handlers/category.h"
// #include "handlers/posts.h"
// #include "handlers/portfolio.h"

#include "handlers/test.h"

using namespace server;
using namespace handlers;


namespace router
{ 
   class Router
   {

   private:
      // Product prod;
      // Category cat;
      // Posts  post;
      // Portfolio  portfolio;
      Test ts;

   public:
      void Run(ServerWorker &sw){
         // sw.ser.Get("/portfolio", prod.handleList);
         // sw.ser.Get("/products", prod.handleList);
         // sw.ser.Get("/category",cat.handleList);
         // sw.ser.Get("/posts", post.handleList);

         sw.ser.Get("/404", ts.handle404);
         sw.ser.Get("/about", ts.handleAbout);
         sw.ser.Get("/home", ts.handleHome);
         sw.ser.Get("/home2", ts.handleHome2);
         sw.ser.Get("/sidebar", ts.handleSidebar);
         sw.ser.Get("/post", ts.handleBlogPost);

      }
   };
};
 
#endif