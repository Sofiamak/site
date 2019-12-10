#pragma once
#ifndef LIB_INDEX_HTML_H 
#define LIB_INDEX_HTML_H 

#include <bits/stdc++.h> 
#include "../liberies/tmpl/chunkWeb.h" 

using namespace std; 
using namespace chunk;

class  IndexHtml: public ChunkWEB
{
    private:
          static IndexHtml * p_instance;
          IndexHtml():ChunkWEB() {};
          IndexHtml( const IndexHtml& );  
          IndexHtml& operator=( IndexHtml& );
    
    
    public:
          static IndexHtml * getInstance() {
               if(!p_instance){       
                    p_instance = new  IndexHtml();
               }
               return p_instance;
          }
      
          string Container(){
               return "_TEST_";
          }
};


class Singleton
            {
            private:
                static Singleton * p_instance;
                // Конструкторы и оператор присваивания недоступны клиентам
                Singleton() {}
                Singleton( const Singleton& );  
                Singleton& operator=( Singleton& );
            public:
                static Singleton * getInstance() {
                    if(!p_instance)           
                        p_instance = new Singleton();
                    return p_instance;
                }
    };

#endif