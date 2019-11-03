
#include <bits/stdc++.h> 
#include "lib/header/server_worker.h"
#include "router.h"

using namespace server;
using namespace router;

int main(void) {
      
      ServerWorker svr;
      Router  router;
    
      if (!svr.IsValid()) {
        printf("server has an error...\n");
        return false;
      }
      
      svr.SetBaseDir("./web");
      router.Run(svr);

      svr.ErrorHandler();
      
      svr.SetLogger();
      if(!svr.Listen("localhost", 8080)){
        return false;
      }
}
