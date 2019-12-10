#pragma once
#ifndef LIB_SERVER_H 
#define LIB_SERVER_H 
  
#include "httplib.h"
#include <chrono>
#include <cstdio>

namespace server
{ 
    using namespace httplib;
    using namespace std; 

    class   ServerWorker
    {
        private:
            string path;

        public:
            Server ser;
            string DumpHeaders(const Headers &headers); 
            bool Listen(const char *host, int port, int socket_flags);
            string  Logs(const Request &req, const Response &res);
            static int FileGetContents(string file_name, char *&content_file, long long &size_file);
            bool IsValid();
            void ErrorHandler();
            void SetLogger();
            bool SetBaseDir(const char *path);
    };

   string ServerWorker::DumpHeaders(const Headers &headers) {
      string s;
      char buf[BUFSIZ];

        for (auto it = headers.begin(); it != headers.end(); ++it) {
            const auto &x = *it;
            snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
            s += buf;
        }

        return s;
    }

    string  ServerWorker::Logs(const Request &req, const Response &res) {
            string s;
            char buf[BUFSIZ];

            s += "================================\n";

            snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
                    req.version.c_str(), req.path.c_str());
            s += buf;

            string query;
            for (auto it = req.params.begin(); it != req.params.end(); ++it) {
                const auto &x = *it;
                snprintf(buf, sizeof(buf), "%c%s=%s",
                        (it == req.params.begin()) ? '?' : '&', x.first.c_str(),
                        x.second.c_str());
                query += buf;
            }
            snprintf(buf, sizeof(buf), "%s\n", query.c_str());
            s += buf;

            s += this->DumpHeaders(req.headers);

            s += "--------------------------------\n";

            snprintf(buf, sizeof(buf), "%d %s\n", res.status, res.version.c_str());
            s += buf;
            s += this->DumpHeaders(res.headers);
            s += "\n";

            if (!res.body.empty()) { s += res.body; }

            s += "\n";

        return s;
    }

    bool ServerWorker::Listen(const char *host, int port=0, int socket_flags=0) {
         return  this->ser.listen(host, port,socket_flags);
    }

    bool  ServerWorker::IsValid(){ 
       return  this->ser.is_valid();
    }

   void ServerWorker::ErrorHandler(){
       this->ser.set_error_handler([](const Request & , Response &res) {
            const char *fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
            char buf[BUFSIZ];
            snprintf(buf, sizeof(buf), fmt, res.status);
            res.set_content(buf, "text/html");
        });
   }
    
   void ServerWorker::SetLogger(){
        this->ser.set_logger([](const Request &req, const Response &res) {
            ServerWorker sv;
            printf("%s", sv.Logs(req, res).c_str());
        });
    }

    bool ServerWorker::SetBaseDir(const char *path){
         return  this->ser.set_base_dir(path);
    }
    
   int ServerWorker::FileGetContents(string file_name, char *&content_file, long long &size_file)
   {
        if (file_name.empty()) {
            return -1;
        }
        fstream reader(file_name, ios::in | ios::binary);
        if (!reader) {
            cout << "n Файл не существует или его невозможно открыть на чтение! - " << file_name;
            return -2;
        }
        reader.seekg(0, ios::end);
        size_file = reader.tellg();
        reader.seekg(0, ios::beg);
        content_file = new char[size_file];
        reader.read(content_file, size_file);
        reader.close();
        if (size_file == 0) {
            return -3;
        }

       content_file[size_file] = 0;
       return 1;
   }
   
}

#endif