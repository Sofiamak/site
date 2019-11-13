#ifndef MYSQL_LIB_H
#define MYSQL_LIB_H

#include <bits/stdc++.h> 
#include <cstdio>
#include "mysql/mysql.h"
#include "Isql.h"

namespace mysql
{

using namespace Isql;
 
 class MySql: public InterfaceSQL{

        MYSQL *con = mysql_init(NULL);
        
        public:
          
            const char *HOST;
            const char *USER;
            const char *PASSWD;
            const char *DB;
            unsigned int PORT;
            const char *UNIX_SOXKET;
            unsigned long CLIENTFLAG;

            MySql(){
                this->HOST=NULL;
                this->USER=NULL;
                this->PASSWD=NULL;
                this->DB=NULL;
                this->PORT=80;
                this->UNIX_SOXKET=NULL;
                this->CLIENTFLAG=0;
            }

            bool getConnect(){
                if (con == NULL) {
                fprintf(stderr, "%s\n", mysql_error(con));
                    return false;
                }
                
                if (mysql_real_connect(con,this->HOST,this->USER,this->PASSWD,
                    this->DB, this->PORT , this->UNIX_SOXKET , this->CLIENTFLAG) == NULL) {
                    fprintf(stderr, "%s\n", mysql_error(con));
                    mysql_close(con);
                    return false;
                }
            return true;
            }

            void test(){
                if (mysql_query(con, "CREATE DATABASE testdb12")) {
                    fprintf(stderr, "%s\n", mysql_error(con));
                    mysql_close(con);
                    exit(1);
                }
            }

            void close(){
                    mysql_close(con);
                }
            };
}
#endif