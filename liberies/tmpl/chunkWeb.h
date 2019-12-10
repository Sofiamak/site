#pragma once
#ifndef LIB_HTMLCHUNK_H 
#define LIB_HTMLCHUNK_H 

#include <bits/stdc++.h> 
#include "htmllib.h"
#include <string>
#include <map> 

namespace chunk
{ 
 
  using namespace std;
  
  string str;

  class ChunkWEB{
     
      private:
        string Header();
        string LibCSS();
        string Footer();
        string LibJS();
        string Navbar();
       
      public:
        virtual string Container()=0;
        string Templater();
  };

  string ChunkWEB::Header() {
          str+="<!doctype html>\n";
          str+="<html lang=\"en\">\n";
          str+="<head>\n";
          str+="<meta charset=\"utf-8\">\n";
          str+="<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n";
          str+="<meta name=\"description\" content=\"description\">\n";
          str+="<meta name=\"author\" content=\"\">\n";
          str+=HTML::Title("title");
          str+="</head>\n";
    return str;
  }


  string ChunkWEB::LibCSS() {
          str+="<!-- Bootstrap core CSS -->\n";
          str+="<link href=\"vendor/bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\">\n";
          str+= "<!-- Custom styles for this template -->\n";
          str+= "<link href=\"css/modern-business.css\" rel=\"stylesheet\">\n";
    return str;
  }

  string ChunkWEB::Footer() { 
        str+="<!-- Footer -->\n";
        str+="<footer class=\"py-5 bg-dark\">\n";
        str+= "<div class=\"container\">\n";
        str+="<p class=\"m-0 text-center text-white\">Copyright &copy; Your Website 2019</p>\n";
        str+="</div>\n";
        str+="<!-- /.container -->\n";
        str+="</footer>\n";
    return str;
  }

  string ChunkWEB::LibJS(){
        str+="<!-- Bootstrap core JavaScript -->\n";
        str+="<script src=\"vendor/jquery/jquery.min.js\"></script>\n";
        str+="<script src=\"vendor/bootstrap/js/bootstrap.bundle.min.js\"></script>\n";
        str+="<!-- Contact form JavaScript -->\n";
        str+="<!-- Do not edit these files! In order to set the email-->\n";
        str+="<script src=\"js/jqBootstrapValidation.js\"></script>\n";
        str+="<script src=\"js/contact_me.js\"></script>\n";
    return str;
  }

  string ChunkWEB::Navbar(){
      str+="<!-- Navigation -->\n";
      str+="<nav class=\"navbar fixed-top navbar-expand-lg navbar-dark bg-dark fixed-top\">\n";
      str+="<div class=\"container\">\n";
      str+="<a class=\"navbar-brand\" href=\"\">GGGG</a>\n";
      str+="<button class=\"navbar-toggler navbar-toggler-right\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarResponsive\" aria-controls=\"navbarResponsive\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n";
      str+="<span class=\"navbar-toggler-icon\"></span>\n";
      str+="</button>\n";
          str+="<div class=\"collapse navbar-collapse\" id=\"navbarResponsive\">\n";
          str+="<ul class=\"navbar-nav ml-auto\">\n";
          str+="<li class=\"nav-item\">\n";
          str+="<a class=\"nav-link\" href=\"url\">name</a>\n";
          str+="</li>\n";
          str+="</ul>\n";
         str+="</div>\n";
       str+="</div>\n";
      str+="</nav>\n";
    return str;
  }

  string ChunkWEB::Templater(){
    str+=this->Header();
    str+=this->LibCSS();
    str+="<body>";
    str+="<!-- Page Content -->\n";
    str+="<div class=\"container\">\n";
    str+=this->Container();
    str+="</div>\n";
    str+=this->Footer();
    str+=this->LibJS();
    str+="</body>";
    return str;
  }

}
#endif