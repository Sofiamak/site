
#include <bits/stdc++.h> 
#include "lib/header/server_worker.h"
#include "router.h"
#include <bits/stdc++.h> 
#include "database/api/driver.cpp"
#include "lib/header/mysql.h"

using namespace server;
using namespace router;
using namespace driver;
using namespace mysql;

int main(void) {
      
      ServerWorker svr;
      Router  router;

      MySql ms;
      ms.HOST="127.0.0.1";
      ms.USER="root";
      ms.PASSWD="pass";
      ms.PORT=3326;
      DBDriver::init(ms).getConnect();
      // DBDriver::init(ms).test();
      // DBDriver::init(ms).close();
      
      if (!svr.IsValid()) {
        printf("server has an error...\n");
        return false;
      }
      
      svr.SetBaseDir("./web");
      router.Run(svr);

      svr.ErrorHandler();
      
      svr.SetLogger();
      
      printf("server run...\n");
      
      if(!svr.Listen("localhost", 8080)){
        return false;
      }

     
}
