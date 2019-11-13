#include "../../lib/header/Isql.h"

using namespace Isql;

namespace driver
{ 
    class  DBDriver
    {
        public: 
            static InterfaceSQL& init(InterfaceSQL &in);  
    };

    InterfaceSQL& DBDriver::init(InterfaceSQL &in) {
            return  in;
    }
}
