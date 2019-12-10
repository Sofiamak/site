
#pragma once
#ifndef LIB_HTML_H 
#define LIB_HTML_H 

#include <bits/stdc++.h> 


using namespace std; 

class  HTML
{
    public:
        static string Title(string title);
        static string H1(string text);
       
};

 string  HTML::Title(string title) {
    return "<title>"+title+"</title>\n";
 }
    
string HTML::H1(string text) {
    return "<h1>"+text+"<h1>\n";
 }


#endif