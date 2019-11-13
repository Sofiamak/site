#ifndef MYSQL_INTERFACE_H
#define MYSQL_INTERFACE_H


namespace Isql
{
    class InterfaceSQL{

        public:
            bool virtual getConnect()=0;
            void virtual test()=0;
            void virtual close()=0;
    };          
}

#endif
